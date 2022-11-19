#include "animation_system.h"
#include "..\ragebot\aim.h"

void resolver::initialize(player_t* e, adjust_data* record, const float& goal_feet_yaw, const float& pitch)
{
	player = e;
	player_record = record;

	original_goal_feet_yaw = math::normalize_yaw(goal_feet_yaw);
	original_pitch = math::normalize_pitch(pitch);
}


void resolver::lagcomp_initialize(player_t* player, Vector& origin, Vector& velocity, int& flags, bool on_ground)
{
	lagcompensation::get().extrapolate(player, origin, velocity, flags, on_ground);
}

void resolver::reset()
{
	player = nullptr;
	player_record = nullptr;

}

float_t get_backward_side(player_t* player)
{
	return math::calculate_angle(globals.local()->m_vecOrigin(), player->m_vecOrigin()).y;	// получаем backward сторону (yaw назад)
}

static auto resolve_update_animations(player_t* e)
{
	e->update_clientside_animation();
};

Vector GetHitboxPos(player_t* player, matrix3x4_t* mat, int hitbox_id)
{
	if (!player)
		return Vector();

	auto hdr = m_modelinfo()->GetStudioModel(player->GetModel());

	if (!hdr)
		return Vector();

	auto hitbox_set = hdr->pHitboxSet(player->m_nHitboxSet());

	if (!hitbox_set)
		return Vector();

	auto hitbox = hitbox_set->pHitbox(hitbox_id);

	if (!hitbox)
		return Vector();

	Vector min, max;

	math::vector_transform(hitbox->bbmin, mat[hitbox->bone], min);
	math::vector_transform(hitbox->bbmax, mat[hitbox->bone], max);

	return (min + max) * 0.5f;
}

float_t MaxYawModificator(player_t* enemy)
{
	auto animstate = enemy->get_animation_state();

	if (!animstate)
		return 0.0f;

	auto speedfactor = math::clamp(animstate->m_flFeetSpeedForwardsOrSideWays, 0.0f, 1.0f);
	auto avg_speedfactor = (animstate->m_flStopToFullRunningFraction * -0.3f - 0.2f) * speedfactor + 1.0f;

	auto duck_amount = animstate->m_fDuckAmount;

	if (duck_amount)
	{
		auto max_velocity = math::clamp(animstate->m_flFeetSpeedUnknownForwardOrSideways, 0.0f, 1.0f);
		auto duck_speed = duck_amount * max_velocity;

		avg_speedfactor += duck_speed * (0.5f - avg_speedfactor);
	}

	return animstate->yaw_desync_adjustment() * avg_speedfactor;
}

float_t GetBackwardYaw(player_t* player) {

	return math::calculate_angle(player->m_vecOrigin(), player->m_vecOrigin()).y;
}

void resolver::resolve_yaw()
{
	player_info_s player_info; // player info t - антипаста
	auto choked = abs(TIME_TO_TICKS(player->m_flSimulationTime() - player->m_flOldSimulationTime()) - 1);  // choked противника

	if (!m_engine()->GetPlayerInfo(player->EntIndex(), &player_info))
		return;

	if (!globals.local()->is_alive() || player->m_iTeamNum() == globals.local()->m_iTeamNum())
		return;

	if (player->get_move_type() == MOVETYPE_LADDER || player->get_move_type() == MOVETYPE_NOCLIP)
		return; // не ресольвим на лестнице

	int playerint = player->EntIndex();

	auto animstate = player->get_animation_state();

	float new_body_yaw_pose = 0.0f;
	auto m_flCurrentFeetYaw = player->get_animation_state()->m_flCurrentFeetYaw;
	auto m_flGoalFeetYaw = player->get_animation_state()->m_flGoalFeetYaw;
	auto m_flEyeYaw = player->get_animation_state()->m_flEyeYaw;
	float flMaxYawModifier = MaxYawModificator(player);
	float flMinYawModifier = player->get_animation_state()->pad10[512];
	auto anglesy = math::normalize_yaw(player->m_angEyeAngles().y - original_goal_feet_yaw);

	auto valid_lby = true;

	auto speed = player->m_vecVelocity().Length2D();

	float m_lby = player->m_flLowerBodyYawTarget() * 0.574f;

	auto player_stand = player->m_vecVelocity().Length2D();
	player_stand = 0.f;

	float m_flLastClientSideAnimationUpdateTimeDelta = 0.0f;
	auto trace = false;

	auto v54 = animstate->m_fDuckAmount;
	auto v55 = ((((*(float*)((uintptr_t)animstate + 0x11C)) * -0.30000001) - 0.19999999) * animstate->m_flFeetSpeedForwardsOrSideWays) + 1.0f;

	bool bWasMovingLastUpdate = false;
	bool bJustStartedMovingLastUpdate = false;

	auto unknown_velocity = *(float*)(uintptr_t(animstate) + 0x2A4);

	auto first_matrix = player_record->matrixes_data.first;
	auto second_matrix = player_record->matrixes_data.second;
	auto central_matrix = player_record->matrixes_data.zero;
	auto leftPose = GetHitboxPos(player, first_matrix, HITBOX_HEAD);
	auto rightPose = GetHitboxPos(player, second_matrix, HITBOX_HEAD);
	auto centralPose = GetHitboxPos(player, central_matrix, HITBOX_HEAD);

	auto fire_first = autowall::get().wall_penetration(globals.g.eye_pos, player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.first), player);
	auto fire_second = autowall::get().wall_penetration(globals.g.eye_pos, player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.second), player);
	auto fire_third = autowall::get().wall_penetration(globals.g.eye_pos, player->hitbox_position_matrix(HITBOX_HEAD, player_record->matrixes_data.zero), player);

	static const float resolve_list[3] = { 0.f, player->m_angEyeAngles().y + player->get_max_desync_delta(), player->m_angEyeAngles().y - player->get_max_desync_delta() };	  // в случае, если произошло более 2х или 3 миссов.

	int missed_player = player->EntIndex();

	auto delta = math::AngleDiff(animstate->m_flGoalFeetYaw, animstate->m_flEyeYaw);

	///////////////////// [ ANIMLAYERS ] /////////////////////
	int i = player->EntIndex();	// создаем переменную i, которая будет отвечать за индекс игрока, чтобы не ресольвить всех
	AnimationLayer layers[13];
	AnimationLayer movelayers[3][13];
	memcpy(layers, player->get_animlayers(), player->animlayer_count() * sizeof(AnimationLayer));  // обозначаем переменной layers область данных, относящуюся за получение анимлееров с размером класса AnimatioLayer * 13(всего лееров) 
	
	// p.s суть анимлееров в том, чтобы чекать разницу между текущими (layers) и записью (player_record), а конкретнее - разницу между ними.
	
	if (globals.g.missed_shots[i] > 2) // строка 149
	{
		animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + resolve_list[globals.g.missed_shots[i] % 3]);
	}

	if (player->m_fFlags() & FL_ONGROUND)
	{
		if (speed <= 1.f || player_record->layers[3].m_flWeight == layers[3].m_flWeight)	// если скорость игрока меньше 1.f (стенды)
		{
			int m_side = 2 * (m_lby > 0.f) ? -1 : 1; // создаем переменную m_side, кстати очень действенный способ, лучше, чем чекать просто лбу
			animstate->m_flGoalFeetYaw = (player->m_angEyeAngles().y + 58.f) * m_side; // добавляем к глазам игрока 58 градусов, и умножаем на m_side
			if (globals.g.missed_shots[i] > 2) // строка 149
			{
				animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + resolve_list[globals.g.missed_shots[i] % 3]);
			}
		}
     	else if (speed > 1.f && (!(player_record->layers[12].m_flWeight) && (player_record->layers[6].m_flWeight == layers[6].m_flWeight)))	 // в скобочках выполняется первее условие. чекаем разницу между рекордом и layers
		{
			lagcompensation::get().setupvelocity(player, player_record); // вызываем сетапвелосити с двумя аргументами (player, player_record)
			float delta_rotate_first = abs(layers[6].m_flPlaybackRate - movelayers[0][6].m_flPlaybackRate);		 // центральная дельта
			float delta_rotate_second = abs(layers[6].m_flPlaybackRate - movelayers[2][6].m_flPlaybackRate);	// левая дельта
			float delta_rotate_third = abs(layers[6].m_flPlaybackRate - movelayers[1][6].m_flPlaybackRate);		// правая дельта

			if (delta_rotate_first < delta_rotate_second || delta_rotate_second <= delta_rotate_third || delta_rotate_second)
			{
				if (delta_rotate_first >= delta_rotate_third && delta_rotate_second > delta_rotate_third && !(delta_rotate_third))
				{
					animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + player->get_max_desync_delta());
					switch (globals.g.missed_shots[i] % 2) // брутим каждый второй мисс
					{
					case 0:	animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y - player->get_max_desync_delta());
						break;
					case 1:
						animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + resolve_list[globals.g.missed_shots[i] % 3]);
						break;
					default:
						break;
					}
				}
			}			
			else
			{
				animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y - player->get_max_desync_delta());
				switch (globals.g.missed_shots[i] % 2)	// брутим каждый второй мисс
				{
				case 0:	animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + player->get_max_desync_delta());
					break;
				case 1:
					animstate->m_flGoalFeetYaw = math::normalize_yaw(player->m_angEyeAngles().y + resolve_list[globals.g.missed_shots[i] % 3]);
					break;
				default:
					break;
				}
			}
		}
	}   ///////////////////// [ ANIMLAYERS ] /////////////////////
}

float resolver::resolve_pitch()
{
	return original_pitch;
}

