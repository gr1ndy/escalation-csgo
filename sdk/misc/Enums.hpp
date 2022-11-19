#pragma once

enum ECstrike15UserMessages {
	CS_UM_VGUIMenu = 1,
	CS_UM_Geiger = 2,
	CS_UM_Train = 3,
	CS_UM_HudText = 4,
	CS_UM_SayText = 5,
	CS_UM_SayText2 = 6,
	CS_UM_TextMsg = 7,
	CS_UM_HudMsg = 8,
	CS_UM_ResetHud = 9,
	CS_UM_GameTitle = 10,
	CS_UM_Shake = 12,
	CS_UM_Fade = 13,
	CS_UM_Rumble = 14,
	CS_UM_CloseCaption = 15,
	CS_UM_CloseCaptionDirect = 16,
	CS_UM_SendAudio = 17,
	CS_UM_RawAudio = 18,
	CS_UM_VoiceMask = 19,
	CS_UM_RequestState = 20,
	CS_UM_Damage = 21,
	CS_UM_RadioText = 22,
	CS_UM_HintText = 23,
	CS_UM_KeyHintText = 24,
	CS_UM_ProcessSpottedEntityUpdate = 25,
	CS_UM_ReloadEffect = 26,
	CS_UM_AdjustMoney = 27,
	CS_UM_UpdateTeamMoney = 28,
	CS_UM_StopSpectatorMode = 29,
	CS_UM_KillCam = 30,
	CS_UM_DesiredTimescale = 31,
	CS_UM_CurrentTimescale = 32,
	CS_UM_AchievementEvent = 33,
	CS_UM_MatchEndConditions = 34,
	CS_UM_DisconnectToLobby = 35,
	CS_UM_PlayerStatsUpdate = 36,
	CS_UM_DisplayInventory = 37,
	CS_UM_WarmupHasEnded = 38,
	CS_UM_ClientInfo = 39,
	CS_UM_XRankGet = 40,
	CS_UM_XRankUpd = 41,
	CS_UM_CallVoteFailed = 45,
	CS_UM_VoteStart = 46,
	CS_UM_VotePass = 47,
	CS_UM_VoteFailed = 48,
	CS_UM_VoteSetup = 49,
	CS_UM_ServerRankRevealAll = 50,
	CS_UM_SendLastKillerDamageToClient = 51,
	CS_UM_ServerRankUpdate = 52,
	CS_UM_ItemPickup = 53,
	CS_UM_ShowMenu = 54,
	CS_UM_BarTime = 55,
	CS_UM_AmmoDenied = 56,
	CS_UM_MarkAchievement = 57,
	CS_UM_MatchStatsUpdate = 58,
	CS_UM_ItemDrop = 59,
	CS_UM_GlowPropTurnOff = 60,
	CS_UM_SendPlayerItemDrops = 61,
	CS_UM_RoundBackupFilenames = 62,
	CS_UM_SendPlayerItemFound = 63,
	CS_UM_ReportHit = 64,
	CS_UM_XpUpdate = 65,
	CS_UM_QuestProgress = 66,
	CS_UM_ScoreLeaderboardData = 67,
	CS_UM_PlayerDecalDigitalSignature = 68,
	MAX_ECSTRIKE15USERMESSAGES
};

enum EntityEffects
{
    EF_BONEMERGE = 0x001,
    EF_BRIGHTLIGHT = 0x002,
    EF_DIMLIGHT = 0x004,
    EF_NOINTERP = 0x008,
    EF_NOSHADOW = 0x010,
    EF_NODRAW = 0x020,
    EF_NORECEIVESHADOW = 0x040,
    EF_BONEMERGE_FASTCULL = 0x080,
    EF_ITEM_BLINK = 0x100,
    EF_PARENT_ANIMATES = 0x200,
};

enum InvalidatePhysicsBits_t
{
    POSITION_CHANGED = 0x1,
    ANGLES_CHANGED = 0x2,
    VELOCITY_CHANGED = 0x4,
    ANIMATION_CHANGED = 0x8,
    BOUNDS_CHANGED = 0x10,
    SEQUENCE_CHANGED = 0x20,
};

enum EFL
{
    EFL_KILLME = (1 << 0),
    EFL_DORMANT = (1 << 1),
    EFL_NOCLIP_ACTIVE = (1 << 2),
    EFL_SETTING_UP_BONES = (1 << 3),
    EFL_KEEP_ON_RECREATE_ENTITIES = (1 << 4),

    EFL_HAS_PLAYER_CHILD = (1 << 4),

    EFL_DIRTY_SHADOWUPDATE = (1 << 5),
    EFL_NOTIFY = (1 << 6),

    EFL_FORCE_CHECK_TRANSMIT = (1 << 7),

    EFL_BOT_FROZEN = (1 << 8),
    EFL_SERVER_ONLY = (1 << 9),
    EFL_NO_AUTO_EDICT_ATTACH = (1 << 10),

    EFL_DIRTY_ABSTRANSFORM = (1 << 11),
    EFL_DIRTY_ABSVELOCITY = (1 << 12),
    EFL_DIRTY_ABSANGVELOCITY = (1 << 13),
    EFL_DIRTY_SURROUNDING_COLLISION_BOUNDS = (1 << 14),
    EFL_DIRTY_SPATIAL_PARTITION = (1 << 15),

    EFL_IN_SKYBOX = (1 << 17),
    EFL_USE_PARTITION_WHEN_NOT_SOLID = (1 << 18),
    EFL_TOUCHING_FLUID = (1 << 19),

    EFL_IS_BEING_LIFTED_BY_BARNACLE = (1 << 20),
    EFL_NO_ROTORWASH_PUSH = (1 << 21),
    EFL_NO_THINK_FUNCTION = (1 << 22),
    EFL_NO_GAME_PHYSICS_SIMULATION = (1 << 23),

    EFL_CHECK_UNTOUCH = (1 << 24),
    EFL_DONTBLOCKLOS = (1 << 25),
    EFL_DONTWALKON = (1 << 26),
    EFL_NO_DISSOLVE = (1 << 27),
    EFL_NO_MEGAPHYSCANNON_RAGDOLL = (1 << 28),
    EFL_NO_WATER_VELOCITY_CHANGE = (1 << 29),
    EFL_NO_PHYSCANNON_INTERACTION = (1 << 30),
    EFL_NO_DAMAGE_FORCES = (1 << 31),
};

enum ItemDefinitionIndex
{
    WEAPON_DEAGLE = 1,
    WEAPON_ELITE,
    WEAPON_FIVESEVEN,
    WEAPON_GLOCK,
    WEAPON_AK47 = 7,
    WEAPON_AUG,
    WEAPON_AWP,
    WEAPON_FAMAS,
    WEAPON_G3SG1,
    WEAPON_GALILAR = 13,
    WEAPON_M249,
    WEAPON_M4A1 = 16,
    WEAPON_MAC10,
    WEAPON_P90 = 19,
    WEAPON_ZONE_REPULSOR,
    WEAPON_MP5SD = 23,
    WEAPON_UMP45,
    WEAPON_XM1014,
    WEAPON_BIZON,
    WEAPON_MAG7,
    WEAPON_NEGEV,
    WEAPON_SAWEDOFF,
    WEAPON_TEC9,
    WEAPON_TASER,
    WEAPON_HKP2000,
    WEAPON_MP7,
    WEAPON_MP9,
    WEAPON_NOVA,
    WEAPON_P250,
    WEAPON_SHIELD,
    WEAPON_SCAR20,
    WEAPON_SG553,
    WEAPON_SSG08,
    WEAPON_KNIFEGG,
    WEAPON_KNIFE,
    WEAPON_FLASHBANG,
    WEAPON_HEGRENADE,
    WEAPON_SMOKEGRENADE,
    WEAPON_MOLOTOV,
    WEAPON_DECOY,
    WEAPON_INCGRENADE,
    WEAPON_C4,
    ITEM_KEVLAR,
    ITEM_ASSAULTSUIT,
    ITEM_HEAVYASSAULTSUIT,
    ITEM_NVG = 54,
    ITEM_DEFUSER,
    ITEM_CUTTERS,
    WEAPON_HEALTHSHOT,
    WEAPON_KNIFE_T = 59,
    WEAPON_M4A1_SILENCER,
    WEAPON_USP_SILENCER,
    WEAPON_CZ75A = 63,
    WEAPON_REVOLVER,
    WEAPON_TAGRENADE = 68,
    WEAPON_FISTS,
    WEAPON_BREACHCHARGE,
    WEAPON_TABLET = 72,
    WEAPON_MELEE = 74,
    WEAPON_AXE,
    WEAPON_HAMMER,
    WEAPON_SPANNER = 78,
    WEAPON_KNIFE_GHOST = 80,
    WEAPON_FIREBOMB,
    WEAPON_DIVERSION,
    WEAPON_FRAG_GRENADE,
    WEAPON_SNOWBALL,
    WEAPON_BUMPMINE,
    WEAPON_KNIFE_BAYONET = 500,
    WEAPON_KNIFE_CSS = 503,
    WEAPON_KNIFE_FLIP = 505,
    WEAPON_KNIFE_GUT,
    WEAPON_KNIFE_KARAMBIT,
    WEAPON_KNIFE_M9_BAYONET,
    WEAPON_KNIFE_TACTICAL,
    WEAPON_KNIFE_FALCHION = 512,
    WEAPON_KNIFE_SURVIVAL_BOWIE = 514,
    WEAPON_KNIFE_BUTTERFLY,
    WEAPON_KNIFE_PUSH,
    WEAPON_KNIFE_CORD,
    WEAPON_KNIFE_CANIS,
    WEAPON_KNIFE_URSUS,
    WEAPON_KNIFE_GYPSY_JACKKNIFE,
    WEAPON_KNIFE_OUTDOOR,
    WEAPON_KNIFE_STILETTO,
    WEAPON_KNIFE_WIDOWMAKER,
    WEAPON_KNIFE_SKELETON = 525,
    GLOVE_STUDDED_BLOODHOUND = 5027,
    GLOVE_T_SIDE,
    GLOVE_CT_SIDE,
    GLOVE_SPORTY,
    GLOVE_SLICK,
    GLOVE_LEATHER_WRAP,
    GLOVE_MOTORCYCLE,
    GLOVE_SPECIALIST,
    GLOVE_HYDRA,
    CUSTOMPLAYER_T_MAP_BASED,
    CUSTOMPLAYER_CT_MAP_BASED,
    CUSTOMPLAYER_TM_ANARCHIST,
    CUSTOMPLAYER_TM_ANARCHIST_VARIANTA,
    CUSTOMPLAYER_TM_ANARCHIST_VARIANTB,
    CUSTOMPLAYER_TM_ANARCHIST_VARIANTC,
    CUSTOMPLAYER_TM_ANARCHIST_VARIANTD,
    CUSTOMPLAYER_TM_PIRATE,
    CUSTOMPLAYER_TM_PIRATE_VARIANTA,
    CUSTOMPLAYER_TM_PIRATE_VARIANTB,
    CUSTOMPLAYER_TM_PIRATE_VARIANTC,
    CUSTOMPLAYER_TM_PIRATE_VARIANTD,
    CUSTOMPLAYER_TM_PROFESSIONAL,
    CUSTOMPLAYER_TM_PROFESSIONAL_VAR1,
    CUSTOMPLAYER_TM_PROFESSIONAL_VAR2,
    CUSTOMPLAYER_TM_PROFESSIONAL_VAR3,
    CUSTOMPLAYER_TM_PROFESSIONAL_VAR4,
    CUSTOMPLAYER_TM_SEPARATIST,
    CUSTOMPLAYER_TM_SEPARATIST_VARIANTA,
    CUSTOMPLAYER_TM_SEPARATIST_VARIANTB,
    CUSTOMPLAYER_TM_SEPARATIST_VARIANTC,
    CUSTOMPLAYER_TM_SEPARATIST_VARIANTD,
    CUSTOMPLAYER_CTM_GIGN,
    CUSTOMPLAYER_CTM_GIGN_VARIANTA,
    CUSTOMPLAYER_CTM_GIGN_VARIANTB,
    CUSTOMPLAYER_CTM_GIGN_VARIANTC,
    CUSTOMPLAYER_CTM_GIGN_VARIANTD,
    CUSTOMPLAYER_CTM_GSG9,
    CUSTOMPLAYER_CTM_GSG9_VARIANTA,
    CUSTOMPLAYER_CTM_GSG9_VARIANTB,
    CUSTOMPLAYER_CTM_GSG9_VARIANTC,
    CUSTOMPLAYER_CTM_GSG9_VARIANTD,
    CUSTOMPLAYER_CTM_IDF,
    CUSTOMPLAYER_CTM_IDF_VARIANTB,
    CUSTOMPLAYER_CTM_IDF_VARIANTC,
    CUSTOMPLAYER_CTM_IDF_VARIANTD,
    CUSTOMPLAYER_CTM_IDF_VARIANTE,
    CUSTOMPLAYER_CTM_IDF_VARIANTF,
    CUSTOMPLAYER_CTM_SWAT,
    CUSTOMPLAYER_CTM_SWAT_VARIANTA,
    CUSTOMPLAYER_CTM_SWAT_VARIANTB,
    CUSTOMPLAYER_CTM_SWAT_VARIANTC,
    CUSTOMPLAYER_CTM_SWAT_VARIANTD,
    CUSTOMPLAYER_CTM_SAS_VARIANTA,
    CUSTOMPLAYER_CTM_SAS_VARIANTB,
    CUSTOMPLAYER_CTM_SAS_VARIANTC,
    CUSTOMPLAYER_CTM_SAS_VARIANTD,
    CUSTOMPLAYER_CTM_ST6,
    CUSTOMPLAYER_CTM_ST6_VARIANTA,
    CUSTOMPLAYER_CTM_ST6_VARIANTB,
    CUSTOMPLAYER_CTM_ST6_VARIANTC,
    CUSTOMPLAYER_CTM_ST6_VARIANTD,
    CUSTOMPLAYER_TM_BALKAN_VARIANTE,
    CUSTOMPLAYER_TM_BALKAN_VARIANTA,
    CUSTOMPLAYER_TM_BALKAN_VARIANTB,
    CUSTOMPLAYER_TM_BALKAN_VARIANTC,
    CUSTOMPLAYER_TM_BALKAN_VARIANTD,
    CUSTOMPLAYER_TM_JUMPSUIT_VARIANTA,
    CUSTOMPLAYER_TM_JUMPSUIT_VARIANTB,
    CUSTOMPLAYER_TM_JUMPSUIT_VARIANTC,
    CUSTOMPLAYER_TM_PHOENIX_HEAVY,
    CUSTOMPLAYER_CTM_HEAVY,
    CUSTOMPLAYER_TM_LEET_VARIANTA = 5100,
    CUSTOMPLAYER_TM_LEET_VARIANTB,
    CUSTOMPLAYER_TM_LEET_VARIANTC,
    CUSTOMPLAYER_TM_LEET_VARIANTD,
    CUSTOMPLAYER_TM_LEET_VARIANTE,
    CUSTOMPLAYER_TM_LEET_VARIANTG,
    CUSTOMPLAYER_TM_LEET_VARIANTH,
    CUSTOMPLAYER_TM_LEET_VARIANTI,
    CUSTOMPLAYER_TM_LEET_VARIANTF,
    CUSTOMPLAYER_TM_PHOENIX = 5200,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTA,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTB,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTC,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTD,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTH,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTF,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTG,
    CUSTOMPLAYER_TM_PHOENIX_VARIANTI,
    CUSTOMPLAYER_CTM_FBI = 5300,
    CUSTOMPLAYER_CTM_FBI_VARIANTA,
    CUSTOMPLAYER_CTM_FBI_VARIANTC,
    CUSTOMPLAYER_CTM_FBI_VARIANTD,
    CUSTOMPLAYER_CTM_FBI_VARIANTE,
    CUSTOMPLAYER_CTM_FBI_VARIANTF,
    CUSTOMPLAYER_CTM_FBI_VARIANTG,
    CUSTOMPLAYER_CTM_FBI_VARIANTH,
    CUSTOMPLAYER_CTM_FBI_VARIANTB,
    CUSTOMPLAYER_CTM_ST6_VARIANTK = 5400,
    CUSTOMPLAYER_CTM_ST6_VARIANTE,
    CUSTOMPLAYER_CTM_ST6_VARIANTG,
    CUSTOMPLAYER_CTM_ST6_VARIANTM,
    CUSTOMPLAYER_CTM_ST6_VARIANTI,
    CUSTOMPLAYER_CTM_ST6_VARIANTJ = 4619,
    CUSTOMPLAYER_CTM_ST6_VARIANTL = 4680,
    CUSTOMPLAYER_TM_BALKAN_VARIANTF = 5500,
    CUSTOMPLAYER_TM_BALKAN_VARIANTI,
    CUSTOMPLAYER_TM_BALKAN_VARIANTG,
    CUSTOMPLAYER_TM_BALKAN_VARIANTJ,
    CUSTOMPLAYER_TM_BALKAN_VARIANTH,
    CUSTOMPLAYER_TM_BALKAN_VARIANTK = 4718,
    CUSTOMPLAYER_TM_BALKAN_VARIANTL = 5505,
    CUSTOMPLAYER_CTM_SAS = 5600,
    CUSTOMPLAYER_CTM_SAS_VARIANTF,
    CUSTOMPLAYER_CTM_SWAT_VARIANTE = 4711,
    CUSTOMPLAYER_CTM_SWAT_VARIANTF,
    CUSTOMPLAYER_CTM_SWAT_VARIANTG,
    CUSTOMPLAYER_CTM_SWAT_VARIANTH,
    CUSTOMPLAYER_CTM_SWAT_VARIANTI,
    CUSTOMPLAYER_CTM_SWAT_VARIANTJ,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARF = 4726,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARF1 = 4733,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARF2,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARF3,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARF4,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARG = 4727,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARH,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARI = 4732,
    CUSTOMPLAYER_TM_PROFESSIONAL_VARJ = 4730,
};

enum ClassID
{
    CAI_BaseNPC,
    CAK47,
    CBaseAnimating,
    CBaseAnimatingOverlay,
    CBaseAttributableItem,
    CBaseButton,
    CBaseCombatCharacter,
    CBaseCombatWeapon,
    CBaseCSGrenade,
    CBaseCSGrenadeProjectile,
    CBaseDoor,
    CBaseEntity,
    CBaseFlex,
    CBaseGrenade,
    CBaseParticleEntity,
    CBasePlayer,
    CBasePropDoor,
    CBaseTeamObjectiveResource,
    CBaseTempEntity,
    CBaseToggle,
    CBaseTrigger,
    CBaseViewModel,
    CBaseVPhysicsTrigger,
    CBaseWeaponWorldModel,
    CBeam,
    CBeamSpotlight,
    CBoneFollower,
    CBRC4Target,
    CBreachCharge,
    CBreachChargeProjectile,
    CBreakableProp,
    CBreakableSurface,
    CBumpMine,
    CBumpMineProjectile,
    CC4,
    CCascadeLight,
    CChicken,
    CColorCorrection,
    CColorCorrectionVolume,
    CCSGameRulesProxy,
    CCSPlayer,
    CCSPlayerResource,
    CCSRagdoll,
    CCSTeam,
    CDangerZone,
    CDangerZoneController,
    CDEagle,
    CDecoyGrenade,
    CDecoyProjectile,
    CDrone,
    CDronegun,
    CDynamicLight,
    CDynamicProp,
    CEconEntity,
    CEconWearable,
    CEmbers,
    CEntityDissolve,
    CEntityFlame,
    CEntityFreezing,
    CEntityParticleTrail,
    CEnvAmbientLight,
    CEnvDetailController,
    CEnvDOFController,
    CEnvGasCanister,
    CEnvParticleScript,
    CEnvProjectedTexture,
    CEnvQuadraticBeam,
    CEnvScreenEffect,
    CEnvScreenOverlay,
    CEnvTonemapController,
    CEnvWind,
    CFEPlayerDecal,
    CFireCrackerBlast,
    CFireSmoke,
    CFireTrail,
    CFish,
    CFists,
    CFlashbang,
    CFogController,
    CFootstepControl,
    CFunc_Dust,
    CFunc_LOD,
    CFuncAreaPortalWindow,
    CFuncBrush,
    CFuncConveyor,
    CFuncLadder,
    CFuncMonitor,
    CFuncMoveLinear,
    CFuncOccluder,
    CFuncReflectiveGlass,
    CFuncRotating,
    CFuncSmokeVolume,
    CFuncTrackTrain,
    CGameRulesProxy,
    CGrassBurn,
    CHandleTest,
    CHEGrenade,
    CHostage,
    CHostageCarriableProp,
    CIncendiaryGrenade,
    CInferno,
    CInfoLadderDismount,
    CInfoMapRegion,
    CInfoOverlayAccessor,
    CItem_Healthshot,
    CItemCash,
    CItemDogtags,
    CKnife,
    CKnifeGG,
    CLightGlow,
    CMapVetoPickController,
    CMaterialModifyControl,
    CMelee,
    CMolotovGrenade,
    CMolotovProjectile,
    CMovieDisplay,
    CParadropChopper,
    CParticleFire,
    CParticlePerformanceMonitor,
    CParticleSystem,
    CPhysBox,
    CPhysBoxMultiplayer,
    CPhysicsProp,
    CPhysicsPropMultiplayer,
    CPhysMagnet,
    CPhysPropAmmoBox,
    CPhysPropLootCrate,
    CPhysPropRadarJammer,
    CPhysPropWeaponUpgrade,
    CPlantedC4,
    CPlasma,
    CPlayerPing,
    CPlayerResource,
    CPointCamera,
    CPointCommentaryNode,
    CPointWorldText,
    CPoseController,
    CPostProcessController,
    CPrecipitation,
    CPrecipitationBlocker,
    CPredictedViewModel,
    CProp_Hallucination,
    CPropCounter,
    CPropDoorRotating,
    CPropJeep,
    CPropVehicleDriveable,
    CRagdollManager,
    CRagdollProp,
    CRagdollPropAttached,
    CRopeKeyframe,
    CSCAR17,
    CSceneEntity,
    CSensorGrenade,
    CSensorGrenadeProjectile,
    CShadowControl,
    CSlideshowDisplay,
    CSmokeGrenade,
    CSmokeGrenadeProjectile,
    CSmokeStack,
    CSnowball,
    CSnowballPile,
    CSnowballProjectile,
    CSpatialEntity,
    CSpotlightEnd,
    CSprite,
    CSpriteOriented,
    CSpriteTrail,
    CStatueProp,
    CSteamJet,
    CSun,
    CSunlightShadowControl,
    CSurvivalSpawnChopper,
    CTablet,
    CTeam,
    CTeamplayRoundBasedRulesProxy,
    CTEArmorRicochet,
    CTEBaseBeam,
    CTEBeamEntPoint,
    CTEBeamEnts,
    CTEBeamFollow,
    CTEBeamLaser,
    CTEBeamPoints,
    CTEBeamRing,
    CTEBeamRingPoint,
    CTEBeamSpline,
    CTEBloodSprite,
    CTEBloodStream,
    CTEBreakModel,
    CTEBSPDecal,
    CTEBubbles,
    CTEBubbleTrail,
    CTEClientProjectile,
    CTEDecal,
    CTEDust,
    CTEDynamicLight,
    CTEEffectDispatch,
    CTEEnergySplash,
    CTEExplosion,
    CTEFireBullets,
    CTEFizz,
    CTEFootprintDecal,
    CTEFoundryHelpers,
    CTEGaussExplosion,
    CTEGlowSprite,
    CTEImpact,
    CTEKillPlayerAttachments,
    CTELargeFunnel,
    CTEMetalSparks,
    CTEMuzzleFlash,
    CTEParticleSystem,
    CTEPhysicsProp,
    CTEPlantBomb,
    CTEPlayerAnimEvent,
    CTEPlayerDecal,
    CTEProjectedDecal,
    CTERadioIcon,
    CTEShatterSurface,
    CTEShowLine,
    CTesla,
    CTESmoke,
    CTESparks,
    CTESprite,
    CTESpriteSpray,
    CTest_ProxyToggle_Networkable,
    CTestTraceline,
    CTEWorldDecal,
    CTriggerPlayerMovement,
    CTriggerSoundOperator,
    CVGuiScreen,
    CVoteController,
    CWaterBullet,
    CWaterLODControl,
    CWeaponAug,
    CWeaponAWP,
    CWeaponBaseItem,
    CWeaponBizon,
    CWeaponCSBase,
    CWeaponCSBaseGun,
    CWeaponCycler,
    CWeaponElite,
    CWeaponFamas,
    CWeaponFiveSeven,
    CWeaponG3SG1,
    CWeaponGalil,
    CWeaponGalilAR,
    CWeaponGlock,
    CWeaponHKP2000,
    CWeaponM249,
    CWeaponM3,
    CWeaponM4A1,
    CWeaponMAC10,
    CWeaponMag7,
    CWeaponMP5Navy,
    CWeaponMP7,
    CWeaponMP9,
    CWeaponNegev,
    CWeaponNOVA,
    CWeaponP228,
    CWeaponP250,
    CWeaponP90,
    CWeaponSawedoff,
    CWeaponSCAR20,
    CWeaponScout,
    CWeaponSG550,
    CWeaponSG552,
    CWeaponSG556,
    CWeaponShield,
    CWeaponSSG08,
    CWeaponTaser,
    CWeaponTec9,
    CWeaponTMP,
    CWeaponUMP45,
    CWeaponUSP,
    CWeaponXM1014,
    CWeaponZoneRepulsor,
    CWorld,
    CWorldVguiText,
    DustTrail,
    MovieExplosion,
    ParticleSmokeGrenade,
    RocketTrail,
    SmokeTrail,
    SporeExplosion,
    SporeTrail,
};
enum ECSPlayerBones 
{
	pelvis = 0,
	spine_0,
	spine_1,
	spine_2,
	spine_3,
	neck_0,
	head_0,
	clavicle_L,
	arm_upper_L,
	arm_lower_L,
	hand_L,
	MAX_ECSPLAYERBONES
};

enum EntityFlags {
	FL_ONGROUND = (1 << 0),
	FL_DUCKING = (1 << 1),
	FL_AIMDUCKING = (1 << 2),
	FL_WATERJUMP = (1 << 3),
	FL_ONTRAIN = (1 << 4),
	FL_INRAIN = (1 << 5),
	FL_FROZEN = (1 << 6),
	FL_ATCONTROLS = (1 << 7),
	FL_CLIENT = (1 << 8),
	FL_FAKECLIENT = (1 << 9),
	MAX_ENTITYFLAGS
};

enum LifeState : unsigned char {
	LIFE_ALIVE,
	LIFE_DYING,
	LIFE_DEAD,
	MAX_LIFESTATE
};

enum WeaponSound_t {
	EMPTY,
	SINGLE,
	SINGLE_NPC,
	WPN_DOUBLE, // Can't be "DOUBLE" because windows.h uses it.
	DOUBLE_NPC,
	BURST,
	RELOAD,
	RELOAD_NPC,
	MELEE_MISS,
	MELEE_HIT,
	MELEE_HIT_WORLD,
	SPECIAL1,
	SPECIAL2,
	SPECIAL3,
	TAUNT,
	FAST_RELOAD,
	// Add new shoot sound types here
	REVERSE_THE_NEW_SOUND,
	NUM_SHOOT_SOUND_TYPES,
	MAX_WEAPONSOUND
};

enum MoveType_t {
	MOVETYPE_NONE,
	MOVETYPE_ISOMETRIC,
	MOVETYPE_WALK,
	MOVETYPE_STEP,
	MOVETYPE_FLY,
	MOVETYPE_FLYGRAVITY,
	MOVETYPE_VPHYSICS,
	MOVETYPE_PUSH,
	MOVETYPE_NOCLIP,
	MOVETYPE_LADDER,
	MOVETYPE_OBSERVER,
	MOVETYPE_CUSTOM,
	MOVETYPE_LAST = MOVETYPE_CUSTOM,
	MOVETYPE_MAX_BITS = 4,
	MAX_MOVETYPE
};

enum Collision_Group_t {
	COLLISION_GROUP_NONE,
	COLLISION_GROUP_DEBRIS,				// Collides with nothing but world and static stuff
	COLLISION_GROUP_DEBRIS_TRIGGER,		// Same as debris, but hits triggers
	COLLISION_GROUP_INTERACTIVE_DEB,	// RIS, // Collides with everything except other interactive debris or debris
	COLLISION_GROUP_INTERACTIVE,		// Collides with everything except interactive debris or debris
	COLLISION_GROUP_PLAYER,
	COLLISION_GROUP_BREAKABLE_GLASS,
	COLLISION_GROUP_VEHICLE,
	COLLISION_GROUP_PLAYER_MOVEMENT,	// For HL2, same as Collision_Group_Player
	COLLISION_GROUP_NPC,				// Generic NPC group
	COLLISION_GROUP_IN_VEHICLE,			// for any entity inside a vehicle
	COLLISION_GROUP_WEAPON,				// for any weapons that need collision detection
	COLLISION_GROUP_VEHICLE_CLIP,		// vehicle clip brush to restrict vehicle movement
	COLLISION_GROUP_PROJECTILE,			// Projectiles!
	COLLISION_GROUP_DOOR_BLOCKER,		// Blocks entities not permitted to get near moving doors
	COLLISION_GROUP_PASSABLE_DOOR,		// Doors that the player shouldn't collide with
	COLLISION_GROUP_DISSOLVING,			// Things that are dissolving are in this group
	COLLISION_GROUP_PUSHAWAY,			// Nonsolid on client and server, pushaway in player code
	COLLISION_GROUP_NPC_ACTOR,			// Used so NPCs in scripts ignore the player.
	LAST_SHARED_COLLISION_GROUP
};

enum mp_break_t {
	MULTIPLAYER_BREAK_DEFAULT,
	MULTIPLAYER_BREAK_SERVERSIDE,
	MULTIPLAYER_BREAK_CLIENTSIDE,
	MULTIPLAYER_BREAK_BOTH
};

enum propdata_interactions_t {
	PROPINTER_PHYSGUN_WORLD_STICK,		// "onworldimpact"	"stick"
	PROPINTER_PHYSGUN_FIRST_BREAK,		// "onfirstimpact"	"break"
	PROPINTER_PHYSGUN_FIRST_PAINT,		// "onfirstimpact"	"paintsplat"
	PROPINTER_PHYSGUN_FIRST_IMPALE,		// "onfirstimpact"	"impale"
	PROPINTER_PHYSGUN_LAUNCH_SPIN_NONE,	// "onlaunch"		"spin_none"
	PROPINTER_PHYSGUN_LAUNCH_SPIN_Z,	// "onlaunch"		"spin_zaxis"
	PROPINTER_PHYSGUN_BREAK_EXPLODE,	// "onbreak"		"explode_fire"
	PROPINTER_PHYSGUN_DAMAGE_NONE,		// "damage"			"none"
	PROPINTER_FIRE_FLAMMABLE,			// "flammable"			"yes"
	PROPINTER_FIRE_EXPLOSIVE_RESIST,	// "explosive_resist"	"yes"
	PROPINTER_FIRE_IGNITE_HALFHEALTH,	// "ignite"				"halfhealth"
	PROPINTER_PHYSGUN_CREATE_FLARE,		// "onpickup"		"create_flare"
	PROPINTER_PHYSGUN_ALLOW_OVERHEAD,	// "allow_overhead"	"yes"
	PROPINTER_WORLD_BLOODSPLAT,			// "onworldimpact", "bloodsplat"
	PROPINTER_PHYSGUN_NOTIFY_CHILDREN,	// "onfirstimpact" cause attached flechettes to explode
	PROPINTER_NUM_INTERACTIONS,			// If we get more than 32 of these, we'll need a different system
};

enum ObserverType_t {
	OBS_MODE_NONE,	// not in spectator mode
	OBS_MODE_DEATHCAM,	// special mode for death cam animation
	OBS_MODE_FREEZECAM,	// zooms to a target, and freeze-frames on them
	OBS_MODE_FIXED,		// view from a fixed camera position
	OBS_MODE_IN_EYE,	// follow a player in first person view
	OBS_MODE_CHASE,		// follow a player in third person view
	OBS_MODE_ROAMING,	// free roaming

	NUM_OBSERVER_MODES,
};

enum {
	TE_BEAMPOINTS = 0x00,		// beam effect between two points
	TE_SPRITE = 0x01,	// additive sprite, plays 1 cycle
	TE_BEAMDISK = 0x02,	// disk that expands to max radius over lifetime
	TE_BEAMCYLINDER = 0x03,		// cylinder that expands to max radius over lifetime
	TE_BEAMFOLLOW = 0x04,		// create a line of decaying beam segments until entity stops moving
	TE_BEAMRING = 0x05,		// connect a beam ring to two entities
	TE_BEAMSPLINE = 0x06,
	TE_BEAMRINGPOINT = 0x07,
	TE_BEAMLASER = 0x08,		// Fades according to viewpoint
	TE_BEAMTESLA = 0x09,
};
enum {
	FBEAM_STARTENTITY = 0x00000001,
	FBEAM_ENDENTITY = 0x00000002,
	FBEAM_FADEIN = 0x00000004,
	FBEAM_FADEOUT = 0x00000008,
	FBEAM_SINENOISE = 0x00000010,
	FBEAM_SOLID = 0x00000020,
	FBEAM_SHADEIN = 0x00000040,
	FBEAM_SHADEOUT = 0x00000080,
	FBEAM_ONLYNOISEONCE = 0x00000100,		// Only calculate our noise once
	FBEAM_NOTILE = 0x00000200,
	FBEAM_USE_HITBOXES = 0x00000400,		// Attachment indices represent hitbox indices instead when this is set.
	FBEAM_STARTVISIBLE = 0x00000800,		// Has this client actually seen this beam's start entity yet?
	FBEAM_ENDVISIBLE = 0x00001000,		// Has this client actually seen this beam's end entity yet?
	FBEAM_ISACTIVE = 0x00002000,
	FBEAM_FOREVER = 0x00004000,
	FBEAM_HALOBEAM = 0x00008000,		// When drawing a beam with a halo, don't ignore the segments and endwidth
	FBEAM_REVERSED = 0x00010000,
	NUM_BEAM_FLAGS = 17	// KEEP THIS UPDATED!
};
//#define TE_BEAMPOINTS 0		// beam effect between two points

enum {
	CHAR_TEX_ANTLION = 'A',
	CHAR_TEX_BLOODYFLESH = 'B',
	CHAR_TEX_CONCRETE = 'C',
	CHAR_TEX_DIRT = 'D',
	CHAR_TEX_EGGSHELL = 'E',
	CHAR_TEX_FLESH = 'F',
	CHAR_TEX_GRATE = 'G',
	CHAR_TEX_ALIENFLESH = 'H',
	CHAR_TEX_CLIP = 'I',
	CHAR_TEX_PLASTIC = 'L',
	CHAR_TEX_METAL = 'M',
	CHAR_TEX_SAND = 'N',
	CHAR_TEX_FOLIAGE = 'O',
	CHAR_TEX_COMPUTER = 'P',
	CHAR_TEX_SLOSH = 'S',
	CHAR_TEX_TILE = 'T',
	CHAR_TEX_CARDBOARD = 'U',
	CHAR_TEX_VENT = 'V',
	CHAR_TEX_WOOD = 'W',
	CHAR_TEX_GLASS = 'Y',
	CHAR_TEX_WARPSHIELD = 'Z',
};