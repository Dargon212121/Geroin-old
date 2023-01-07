HANDLE handle2;
bool init, show = false;
float indicator_x = 100;
float indicator_y = 100;
namespace menu
{
	bool m_bInitialized;
	bool m_bIsOpened;
	int m_nCurrentTab;
}
namespace Global
{
	float flyhack = 0.f;
	float hor_flyhack = 0.f;
	float max_flyhack = 0.f;
	float max_hor_flyhack = 0.f;
	bool Panic = false;
	inline float ScreenHigh = 0;
	inline float ScreenWidth = 0;
	bool Loadem = false;
	HWND hWindow = nullptr;
	WNDPROC oWindproc = nullptr;
	float BoneToAim = 0.5;
	inline BOOL g_bMenu = true;
	int BoneToAim2 = 1;
	DWORD64 PresentDelta = 0;
	char ConfigName[0x100] = "cfg";
}
namespace Test {
	float gravityTest = 0.75f;
}
namespace Keys
{
	int suicide{ 0x07 }; // VK_RMOUSE
	int weaponspam{ 0x07 }; // VK_RMOUSE
	int terrainShootKey{ 0x4E };
	int speedKey{ 0x04 };
	int menu = VK_INSERT;
	int interactivedebug{ 0x42 };
	int aimKey{ 0x07 }; // VK_RMOUSE
	int gravityKey{ 0x04 };
	int walkonWaterKey{ 0x06 };
	int zoomKey{ 0x42 };
	int manipulatorkey{ 0x42 };
}
namespace Storage
{
	namespace O
	{
		__declspec(selectany) uintptr_t BaseNetworkable = NULL;
	}
	__declspec(selectany) uintptr_t gBase = NULL;
	uintptr_t closestHeli = NULL;
	__declspec(selectany) uintptr_t closestPlayer = NULL;
	__declspec(selectany) uintptr_t generalPlayer = NULL;
	int entityCount = NULL;
	float gravityModifier = 0.f;
	//BasePlayer* closestPlayer = NULL;
}
namespace Other
{
	int anti_aim_ = 0;
	float testFloat = 0.f;
	bool cfgSaved = false;
	bool cfgLoaded = false;
	bool InfoTopLeft = false;
}
namespace GG {

	bool rainbow = false;
	float  time = 0.f;
}
namespace CFG
{
	bool LEGITCFGBYFe1zep = false;
	bool RAGECFGBYFe1zep = false;
	bool SBROSCFGBYFe1zep = false;
	bool n1ntendo = false;
	bool n1ntendolegit = false;
}
namespace AimBot
{
	bool RCS = false;
	bool menu = true;
	bool eyeoffset = true;
	bool NoRecoil = false;
	int psilent = 0;
	bool psilentonkey = false;
	int psilenttarget = 0;
	float NRp = 100.f;
	int psilenter{ 0x50 }; // P key
	bool Standalone = false;
	float RCSx = 1.f;
	float RCSy = 1.f;
	bool legit = false;
	bool randhitbox = false;
	bool smooth = false;
	float smooth_factor = 1.f;
	bool AutoShoot = false;
	bool dot = false;
	bool AimAssist = false;
	bool svaston = false;
	float Velocity = 1.480f;
	bool CustomCrosshair = false;
	float Gap = 1.f;
	float Longht = 1.f;
	bool IgnoreSleepers = false;
	bool IgnoreTeam = false;
	bool IgnoreNpc = false;
	bool AlwaysHeadshot = false;
	bool BodyAim = false;
	bool ShowPredict = false;
	bool pSilent = false;
	bool pBody = false;
	bool ThroughWall = false;
	bool silentAim = false;
	bool Activate = false;
	bool VisibleCheck = false;
	bool DrawFov = false;
	bool Crosshair = false;
	bool FastBullet = false;
	float SpeedBullets = 3.f;
	float font = 10.f;
	float RapidFireSpeed = 0.9f;
	float Range = 400.f;
	bool SilentHeli = false;
	bool FillFov = false;
	float Fov = 100.f;
}

namespace Weapons
{
	bool magicbullet = false;
	bool canHoldItems = false;
	bool SpoofHitDistance = false;
	bool instakill = false;
	bool spoof_hitdistance = false;
	float hitdistance = 100.f;
	float FatBulletpov = 1.80f;
	bool HammerSpam = false;
	bool FatHand = false;
	bool LongHand = false;
	bool NoRicochet = false;
	float ricochetChance = 0.f;
	bool NoRecoil = false;
	bool AntiSpread = false;
	float spread = 0.f;
	bool Automatic = false;
	bool FatBullet = false;
	bool NoSway = false;
	bool RapidFire = false;
	bool SuperBow = false;
	bool SuperEoka = false;
	bool jumpAim = false;
}

namespace PlayerEsp
{
	int boxstyle = 0;
	float cornerfloat = 1.f;
	bool safe = false;
	bool Visible = false;
	bool wounded = false;
	bool ахунамиеблан = false;
	bool healthbar4 = false;
	bool Material = false;
	bool targetlineot = false;
	bool Namedistheath = false;
	bool box = false;
	int tracers_pos = 0;
	bool skeleton = false;
	float separators = 0;
	bool targettext = false;
	bool name = false;
	bool health = false;
	bool tracersPOS = false;
	bool healthbar1 = false;
	bool healthbar2 = false;
	bool Namedistheath1 = false;
	bool healthbar3 = false;
	bool HP = false;
	bool cornerbox = false;
	bool oof_arrows = false;
	bool healthbar = false;
	bool weapon = false;
	bool distance = false;
	bool Ignoretteam = false;
	bool sleeperignore = false;
	bool tracers = false;
	bool targetline = false;
	bool fillbox = false;
}
namespace BotsEsp
{
	bool box = false;
	bool skeleton = false;
	bool health = false;
	bool healthbar = false;
	bool name = false;
	bool distance = false;
	bool weapons = false;
}

namespace Ores
{
	bool Stone = false;
	bool Sulfur = false;
	bool Metal = false;
	bool showDistance = false;
	float oreDrawDistance = 300.f;
}
namespace Positions
{
	Vector3 heliPos = { 0.f,0.f,0.f };
}
namespace Visuals
{
	bool ActiveSlotRender = false;
	bool Keybinds = false;
	bool cheatinfo = true;
	bool Berry = false;
	bool visattack = false;
	bool VladimirPutin = false;
	bool visualize_prediction = false;
	bool PatrolHeli = false;
	bool Keycard = false;
	bool Lineesp = false;
	float KeycardDistance = 300.f;
	bool Polha = false;

	bool crosshair = false;
	bool drawKeycardDistance = false;
	bool ykpaina = false;
	bool Russua = false;
	bool Watermark1 = false;
	bool Watermark = true;
	bool Minicopter = false;
	bool ScrapHeli = false;
	bool Boat = false;
	bool RHIB = false;
	bool vehicleDistance = false;
	float drawVehicleDistance = 300.f;

	bool NightMode = false;

	bool AutoTurret = false;
	bool FlameTurret = false;
	bool ShotgunTurret = false;
	bool Landmine = false;
	bool BearTrap = false;
	bool trapDistance = false;
	float drawTrapDistance = 300.f;

	bool Corpse = false;
	bool Stash = false;
	bool Hemp = false;
	bool otherDistance = false;
	float drawOtherDistance = 300.f;
	bool rainbow = true;
	float  time = 0.8f;
	bool Supply = false;
	bool Chinook = false;
	bool crateDistance = false;
	float drawCrateDistance = 300.f;
	bool Boar = false;
	bool Bear = false;
	bool Horse = false;
	bool Chicken = false;
	bool AnimalsDistance = false;
	float drawAnimalsDistance = 300.f;
	bool Boomer = false;
	bool BoomerDistance = false;
	float drawBoomerDistance = 300.f;
	bool EatDistance = false;
	float drawEatDistance = 300.f;
	bool Mushrooms = false;
	bool DistanceWeapon = false;
	float drawWeaponDistance = 300.f;
	bool KeycardRed = false;
	bool KeycardRedDistance = false;
	bool drawKeycardRedDistance = false;
	bool KeycardBlue = false;
	bool KeycardBlueDistance = false;
	bool drawKeycardBlueDistance = false;
	bool KeycardGreen = false;
	bool KeycardGreenDistance = false;
	bool drawKeycardGreenDistance = false;
	bool Weapon = false;
	bool Loot = false;
	bool Medical = false;
	bool Tool = false;
	bool Foodbox = false;
	bool Elite = false;
	bool Militiry = false;
	float drawBoxDistance = 300.f;
	bool DistanceBox = false;
	bool Mine = false;
	bool SKET = false;
	bool Wardrobe = false;
	bool furnaceDistance = false;
	float drawfurnaceDistance = 300.f;
	bool furnace = false;
	bool TransportDistance = false;
	float drawTransportDistance = 300.f;
	bool Transport = false;
	bool WorkBenchDistance = false;
	float drawWorkBenchDistance = 300.f;
	bool WorkBench = false;
	bool RaidDistance = false;
	float drawRaidDistance = 300.f;
	bool Raid = false;
}



namespace Colors
{
	float CSnapColor[] = { 255.f,255.f,255.f,255.f };
	float boxnotvisible[] = { 255.f, 0.f, 0.f };
	float boxvisible[] = { 255.f, 0.f, 0.f };

	float HandChams[] = { 0, 255, 0 };
	float Fov[] = { 255.f, 255.f, 255.f };
	float Visible[] = { 255.f, 255.f, 255.f };
	float weaponactivslot1[] = { 255.f, 255.f, 255.f };
	//float SilentFovColor[] = { 0.f, 0.f, 0.f };
	float Line1[] = { 255.f, 255.f, 255.f };
	float TriggerFovColor[] = { 0.f, 0.f, 0.f };
	float Name1[] = { 255.f, 255.f, 255.f };
	float Watermark[] = { 255, 0, 0 };
	float normalbox[] = { 0, 255, 0 };
	float TextColor[] = { 0, 0, 0 };
	float TextColor2[] = { 255, 255, 255 };
	float mine[] = { 0, 255, 0 };
	float unactiv1[] = { 255.f, 255.f, 255.f };
	float elite[] = { 0, 255, 0 };
	float plaeyrChams[] = { 0, 255, 0 };
	float food[] = { 0, 255, 0 };
	float toolbox[] = { 0, 255, 0 };
	float Traisetspos[] = { 0, 255, 0 };
	float medicalbox[] = { 0, 255, 0 };
	float Textesp[] = { 0, 255, 0 };
	float normalbox2[] = { 0, 255, 0 };
	float Ambient[] = { 1.f,1.f,1.f,1.f };
	/// <summary>
	float BerryBlueEsp[] = { 0.f, 6.f, 255.f };
	float StoneEsp[] = { 255.f, 0.f, 0.f };
	float SulfurEsp[] = { 255.f, 0.f, 0.f };
	float SilentColor1[] = { 255.f, 0.f, 0.f };
	float MetalEsp[] = { 255.f, 0.f, 0.f };
	float Workbench[] = { 255.f, 0.f, 0.f };
	float Name[] = { 255.f, 0.f, 0.f };
	float ambientLightcolor[] = { 255.f, 0.f, 0.f };
	float unactiv[] = { 255.f, 0.f, 0.f };
	float weaponactivslot[] = { 255.f, 0.f, 0.f };
	float Line[] = { 255.f, 0.f, 0.f };
	float StashEsp[] = { 255.f, 0.f, 0.f };
	float Shkaf[] = { 255.f, 0.f, 0.f };
	float ShkafDIST[] = { 255.f, 0.f, 0.f };
	float MinicopterEsp[] = { 255.f, 0.f, 0.f };
	float PatrulEsp[] = { 255.f, 0.f, 0.f };
	float FillBox[] = { 255.f, 0.f, 0.f };
	float BradleyEsp[] = { 255.f, 0.f, 0.f };
	float TrapsEsp[] = { 255.f, 0.f, 0.f };
	float CollapseColor[] = { 255.f, 0.f, 0.f };
	float HempEsp[] = { 255.f, 0.f, 0.f };
	float FillFovColors[] = { 0.f, 0.f, 0.f, 0.f };
	float SupplyEsp[] = { 255.f, 0.f, 0.f };
	float CorpseEsp[] = { 255.f, 0.f, 0.f };
	float CrateEsp[] = { 255.f, 0.f, 0.f };
	float BoxColors[] = { 255.f, 255.f, 255.f };
	float show_WeaponsEsp[] = { 255.f, 0.f, 0.f };
	/// </summary>
	float SkeletonColor[] = { 255.f, 0.f, 0.f };
	float LineEsp[] = { 255.f, 0.f, 0.f };
	float BoxColor[] = { 255.f, 0.f, 0.f };
	float Wounded[] = { 255.f, 0.f, 0.f };
	float window[] = { 255.f, 0.f, 0.f };
	float Mushrooms[] = { 255.f, 0.f, 0.f };
	float NameColor[] = { 255.f, 0.f, 0.f };
	float PlayerHeath[] = { 255.f, 0.f, 0.f };
	float DistanceColor[] = { 255.f, 0.f, 0.f };
	float WeaponColor[] = { 255.f, 0.f, 0.f };
	float SnapColors[] = { 255.f, 0.f, 0.f };
	float CircleCrosshair[] = { 255.f,255.f,255.f,255.f };
	float CrosshairColor[] = { 0.f, 255.f, 0.f };
	float CrosshairColors[] = { 255.f, 255.f, 255.f };
	float ChamsESP[] = { 255.f, 255.f, 255.f };
	float Crosshair1[] = { 255.f, 255.f, 255.f };
	float Crosshair2[] = { 255.f, 255.f, 255.f };
	float Crosshair3[] = { 255.f, 255.f, 255.f };
	float SEXCrosshair[] = { 255.f,255.f,255.f,255.f };
	float SEXXCrosshair[] = { 255.f,255.f,255.f,255.f };
	float SEXXXCrosshair[] = { 255.f,255.f,255.f,255.f };
	float Crosshair11[] = { 255.f, 255.f, 255.f };

	float helfbarcolorpreviw[] = { 0, 255, 0 };

	float Target_text[] = { 181.f,0.f,0.f,1.f };


	float Fonts[] = { 255, 255, 255 };
	float Namecolor1[] = { 0, 255, 0 };
	float BotColor[] = { 255, 0, 255 };
	float SilentColor[] = { 255, 255, 0 };
	float ColorPreview[] = { 25, 30, 35 };
	float Steep[] = { 255, 0, 255 };
	float playercolors[4] = { 1,1,1,1 };
	float invisplayercolors[4] = { 1,0,0,1 };
	float sleepercolors[4] = { 1,0.5,0,1 };
	float crosshairfovcolors[4] = { 1,1,1,1 };
	float botcolors[4] = { 1,1,0,1 };
	float teamcolors[4] = { 0,1,0,1 };

	float stoneore[4] = { 0.78, 0.78 ,0.78 , 1 };
	float sulfurore[4] = { 1, 0.78 ,0.13 , 1 };
	float metalore[4] = { 0.54, 0.19 ,0 , 1 };

	float patrolhelicopter[4] = { 0.27 , 0.27 , 1 , 1 };
	float airdrop[4] = { 0 , 0.20 , 0.43 , 1 };
	float chinook[4] = { 0.34 , 0 , 0 , 1 };
	float minicopter[4] = { 0.5 , 0.45 , 0 , 1 };
	float scrapheli[4] = { 0 , 0.5 , 0 , 1 };
	float boat[4] = { 0 , 0.8 , 0.8 , 1 };
	float rhib[4] = { 0.34 , 0.34 , 0.34 , 1 };
	float turret[4] = { 1 , 0.34 , 0 , 1 };
	float flame[4] = { 1 , 0.78 , 0 , 1 };
	float shotgun[4] = { 0.61 , 0.68 , 1 , 1 };
	float landmine[4] = { 0 , 0 , 1 , 1 };
	float beartrap[4] = { 0.32 , 0 , 0.65 , 1 };
	float hemp[4] = { 0.56 , 1 , 0.34 , 1 };
	float corpse[4] = { 0.5 , 0.21 , 0.34 , 1 };
	float stash[4] = { 0 , 0.5 , 0 , 1 };


	float fovsegments = 15;
	float boxRoundness = 0;
}
namespace Hit
{
	bool HitSound = true;
	bool HitSound1 = false;
	bool HitSound2 = false;
	bool HitSound3 = false;
	bool CustomHitSound = false;
}
namespace Misc
{
	bool instarevive = false;
	bool mass_suicide = false;
	bool interactivedebug = false;
	bool suicide = false;
	bool chams1 = false;
	int manipulatorkey = 0; // VK_RMOUSE
	bool manipulator = false;
	bool weapon_spam = false;
	int Meleeatackkey = 0; // VK_RMOUSE
	bool SetSwim = false;
	bool rayleigh_changer = false;
	bool farmbot = false;
	bool eggbot = false;
	int LongNeckkey2 = 0;
	int LongNeckkey1 = 0;
	float JumpValue = 1.f;
	float separatorr = 1.f;
	float RapidFirevalye = 0.11f;
	bool flyhack_indicator = false;
	bool pulse_chams = false;
	float rayleigh = 10.f;
	bool swiming = false;
	float LongNeckvolue = 2.f;//2.5
	float LongNeckvolue1 = 4.f;
	float LongNeckvolue2 = 4.f;
	bool OnlyVisible = false;
	bool AutoFarmBarrel = false;
	bool health_chams = false;
	float uptime = 15.f;
	bool rainbow_chams = false;
	bool DoorKnocker = false;
	float speed = 2.0f;
	float chamsclr[3] = { 255, 0, 0 };
	float rainbowSpeed = 0.001;
	int razmer = 10;
	bool Fastshot = false;
	bool PeekAssist = false;
	bool sidepeekvalue = 2.5f;//2.5f
	bool PeekAssistIndicator = false;
	bool SwimOnGround = false;

	bool flyindocatos = false;
	bool remove_attack_anim = false;
	bool AutoHeal = false;
	bool RapidFire = false;
	bool LongHand = false;
	bool FastHeal = false;
	bool InfJump = false;
	bool gravity = false;
	float max;
	bool chams = false;
	bool chams2 = false;
	bool speedhack = false;
	bool AutoFarm = false;
	bool AutoFarmOre = false;
	bool AutoFarmTree = false;
	bool Meleeatack = false;
	float SpeedValue = 5;
	bool Tracebullet = false;
	float NeckScale = 1.f;
	bool LongNeck = false;
	int swim = 0;
	int longKey = 0;

	bool Desync = false;
	int Desynckey = 0;

	bool LongNeckLeft = false;
	int LongNeckkey = 0;

	bool LongNeckright = false;
	bool AutoPickUp = false;
	bool FastLoot = false;
	float NoRecoilCondition = 0.5f;
	bool AntiAim = false;
	bool FakeLag = false;
	bool no_playercollision = false;
	bool SexyFuckingFov = false;
	bool zoomtoggle = false;
	float SexyFuckingFovValue = 90.f;
	bool Gravity = false;
	float GravityModifier = 0.f;
	bool HighJump = false;
	bool SlideWalk = false;
	int highkey = 0;

	float xc = 3.f;
	float yc = 3.f;
	float zc = 0.f;

	float xx = 3.f;
	float yy = 3.f;
	float zz = 0.f;

	bool CustomFov = false;
	float FovRange = 90.f;
	bool Zoom = false;
	int Zoomkey = 0;
	float Zoomvalue = 20.f;

	bool SpiderMan = false;
	bool WalkOnWater = false;
	bool omniSprint = false;
	bool FakeAdmin = false;
	bool CustomTime = false;
	float Time = 10.0f;
	bool WaterBoost = false;
	bool SilentWalk = false;
}
namespace AntiAim
{
	bool anti_aim = false;
	int anti_aim_speed = 10;
	int anti_aim_yaw = false;
	bool anti_aim_indicator = false;

	int anti_aim_ = 0;
}
namespace Radar
{
	float ActiveSlotPos_X = 63.f;
	float ActiveSlotPos_Y = 315.f;
	bool ActiveSlot = false;
	bool Enable = false;
	bool infobarleft = false;
	bool ShowRadarBackground = false;
	bool ShowRadarPlayer = false;
	bool ShowRadarSleeper = false;
	bool ShowRadarStoneOre = false;
	bool ShowRadarMettalOre = false;
	bool ShowRadarSulfureOre = false;
	float Pos_X = 0;
	float Pos_Y = 0;
	float Radar_Size = 250.f;
	float Radar_Range = 300.f;
	bool EnableDinamicRadar = false;
}
