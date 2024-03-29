// This is an independent project of an individual developer. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "..\hooks.hpp"
#include "..\..\features\lagcompensation\local_animations.h"
#include "..\..\features\misc\prediction_system.h"

_declspec(noinline)bool hooks::setupbones_detour(void* ecx, matrix3x4_t* bone_world_out, int max_bones, int bone_mask, float current_time)
{
	auto result = true;

	static auto r_jiggle_bones = m_cvar()->FindVar(crypt_str("r_jiggle_bones"));
	auto r_jiggle_bones_backup = r_jiggle_bones->GetInt();

	r_jiggle_bones->SetValue(0);

	if (!ecx)
		result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
	else if (!g_cfg.ragebot.enable && !g_cfg.legitbot.enabled)
		result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
	else
	{
		auto player = (player_t*)((uintptr_t)ecx - 0x4);

		if (!player->valid(false, false))
			result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
		else
		{
			auto animstate = player->get_animation_state();
			auto previous_weapon = animstate ? animstate->m_pLastBoneSetupWeapon : nullptr;

			if (previous_weapon)
				animstate->m_pLastBoneSetupWeapon = animstate->m_pActiveWeapon; //-V1004

			if (globals.g.setuping_bones)
				result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
			else if (g_cfg.legitbot.enabled && player != globals.local())
				result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
			else if (!globals.local()->is_alive())
				result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
			else if (player == globals.local())
				result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
			else if (!player->m_CachedBoneData().Count()) //-V807
				result = ((SetupBonesFn)original_setupbones)(ecx, bone_world_out, max_bones, bone_mask, current_time);
			else if (bone_world_out && max_bones != -1)
				memcpy(bone_world_out, player->m_CachedBoneData().Base(), player->m_CachedBoneData().Count() * sizeof(matrix3x4_t));

			if (previous_weapon)
				animstate->m_pLastBoneSetupWeapon = previous_weapon;
		}
	}

	r_jiggle_bones->SetValue(r_jiggle_bones_backup);
	return result;
}

bool __fastcall hooks::hooked_setupbones(void* ecx, void* edx, matrix3x4_t* bone_world_out, int max_bones, int bone_mask, float current_time)
{
	return setupbones_detour(ecx, bone_world_out, max_bones, bone_mask, current_time);
}

_declspec(noinline)void hooks::standardblendingrules_detour(player_t* player, int i, CStudioHdr* hdr, Vector* pos, Quaternion* q, float curtime, int boneMask)
{
	auto backup_effects = player->m_fEffects();

	if (player == globals.local())
		player->m_fEffects() |= 8;

	((StandardBlendingRulesFn)original_standardblendingrules)(player, hdr, pos, q, curtime, boneMask);

	if (player == globals.local())
		player->m_fEffects() = backup_effects;
}

void __fastcall hooks::hooked_standardblendingrules(player_t* player, int i, CStudioHdr* hdr, Vector* pos, Quaternion* q, float curtime, int boneMask)
{
	return standardblendingrules_detour(player, i, hdr, pos, q, curtime, boneMask);
}

_declspec(noinline)void hooks::doextrabonesprocessing_detour(player_t* player, CStudioHdr* hdr, Vector* pos, Quaternion* q, const matrix3x4_t& matrix, uint8_t* bone_list, void* context)
{

}

void __fastcall hooks::hooked_doextrabonesprocessing(player_t* player, void* edx, CStudioHdr* hdr, Vector* pos, Quaternion* q, const matrix3x4_t& matrix, uint8_t* bone_list, void* context)
{
	return doextrabonesprocessing_detour(player, hdr, pos, q, matrix, bone_list, context);
}

_declspec(noinline)void hooks::updateclientsideanimation_detour(player_t* player)
{
	if (globals.g.updating_animation && m_clientstate()->iDeltaTick > 0)
		return ((UpdateClientSideAnimationFn)original_updateclientsideanimation)(player);

	if (globals.g.updating_animation)
		return ((UpdateClientSideAnimationFn)original_updateclientsideanimation)(player);

	if (player == globals.local())
		return ((UpdateClientSideAnimationFn)original_updateclientsideanimation)(player);
	
	if (!g_cfg.ragebot.enable)
		return ((UpdateClientSideAnimationFn)original_updateclientsideanimation)(player);

	if (!player->valid(false, false))
		return ((UpdateClientSideAnimationFn)original_updateclientsideanimation)(player);
}

void __fastcall hooks::hooked_updateclientsideanimation(player_t* player, uint32_t i)
{
	return updateclientsideanimation_detour(player);
}

_declspec(noinline)void hooks::physicssimulate_detour(player_t* player)
{
	auto m_nSimulationTick = *(int*)((uintptr_t)player + 0x2AC); //get simulation tick
	auto cctx = reinterpret_cast<C_CommandContext*>(uintptr_t(player) + 0x34FC); //GetCommandContext
	auto cctx_srv = reinterpret_cast<CUtlVector<C_CommandContext>*>(uintptr_t(player) + 0x34FC); //GetCommandContext

	if (player != globals.local() || !globals.local()->is_alive() || m_globals()->m_tickcount == m_nSimulationTick || !cctx->needsprocessing || m_engine()->IsPlayingDemo() || m_engine()->IsHLTV() || player->m_fFlags() & 0x40)
	{
		((PhysicsSimulateFn)original_physicssimulate)(player);
		return;
	}


	// if invalid tickcount store data
	if (cctx->cmd.m_tickcount == 0x7FFFFFFF)
	{
		// get current record and store data.
		StoredData_t* ndata = &engineprediction::get().m_data[cctx->cmd.m_command_number % MULTIPLAYER_BACKUP];
		engineprediction::get().store(ndata, cctx, cctx->cmd.m_tickcount);
		m_nSimulationTick = m_globals()->m_tickcount;
		cctx->needsprocessing = false;
		return;
	}
	else
	{
		// get record data and apply
		StoredData_t* data = &engineprediction::get().m_data[(cctx->cmd.m_command_number - 1) % MULTIPLAYER_BACKUP];
		if (data && data->m_command_number == (cctx->cmd.m_command_number - 1) && std::abs(data->m_command_number - cctx->cmd.m_command_number) <= MULTIPLAYER_BACKUP)
			engineprediction::get().apply(cctx->cmd.m_command_number - 1);

		// fix velocity modifier to update
		if (cctx->cmd.m_command_number == (m_clientstate()->iCommandAck + 1) && engine_prediction::m_misc.m_bOverrideModifier)
			player->m_flVelocityModifier() = engine_prediction::m_stored_variables.m_flVelocityModifier;

		// detect prediction error and repredict
		if (data && data->m_command_number == (cctx->cmd.m_command_number - 1) && std::abs(data->m_command_number - cctx->cmd.m_command_number) <= MULTIPLAYER_BACKUP)
			engineprediction::get().detect_prediction_error(data, cctx->cmd.m_command_number - 1);

		// call original
		((PhysicsSimulateFn)original_physicssimulate)(player);

		// get current record and store data.
		StoredData_t* ndata = &engineprediction::get().m_data[cctx->cmd.m_command_number % MULTIPLAYER_BACKUP];
		engineprediction::get().store(ndata, cctx, m_globals()->m_tickcount);
	}
}

void __fastcall hooks::hooked_physicssimulate(player_t* player)
{
	return physicssimulate_detour(player);
}

_declspec(noinline)void hooks::modifyeyeposition_detour(c_baseplayeranimationstate* state, Vector& position)
{
	if (state && globals.g.in_createmove)
		return ((ModifyEyePositionFn)original_modifyeyeposition)(state, position);
}

void __fastcall hooks::hooked_modifyeyeposition(c_baseplayeranimationstate* state, void* edx, Vector& position)
{
	return modifyeyeposition_detour(state, position);
}

_declspec(noinline)void hooks::calcviewmodelbob_detour(player_t* player, Vector& position)
{
	if (!g_cfg.esp.removals[REMOVALS_LANDING_BOB] || player != globals.local() || !globals.local()->is_alive())
		return ((CalcViewmodelBobFn)original_calcviewmodelbob)(player, position);
}

void __fastcall hooks::hooked_calcviewmodelbob(player_t* player, void* edx, Vector& position)
{
	return calcviewmodelbob_detour(player, position);
}

bool __fastcall hooks::hooked_shouldskipanimframe()
{
	return false;
}

int hooks::processinterpolatedlist()
{
	static auto allow_extrapolation = *(bool**)(util::FindSignature(crypt_str("client.dll"), crypt_str("A2 ? ? ? ? 8B 45 E8")) + 0x1);

	if (allow_extrapolation)
		*allow_extrapolation = false;

	return ((ProcessInterpolatedListFn)original_processinterpolatedlist)();
}