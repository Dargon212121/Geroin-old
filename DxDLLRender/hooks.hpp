#pragma once
enum class Signal {
	Attack,
	Alt_Attack,
	DryFire,
	Reload,
	Deploy,
	Flinch_Head,
	Flinch_Chest,
	Flinch_Stomach,
	Flinch_RearHead,
	Flinch_RearTorso,
	Throw,
	Relax,
	Gesture,
	PhysImpact,
	Eat,
	Startled
};
enum class layer : uint32_t {
	Default = 0,
	TransparentFX = 1,
	Ignore_Raycast = 2,
	Reserved1 = 3,
	Water = 4,
	UI = 5,
	Reserved2 = 6,
	Reserved3 = 7,
	Deployed = 8,
	Ragdoll = 9,
	Invisible = 10,
	AI = 11,
	PlayerMovement = 12,
	Vehicle_Detailed = 13,
	Game_Trace = 14,
	Vehicle_World = 15,
	World = 16,
	Player_Server = 17,
	Trigger = 18,
	Player_Model_Rendering = 19,
	Physics_Projectile = 20,
	Construction = 21,
	Construction_Socket = 22,
	Terrain = 23,
	Transparent = 24,
	Clutter = 25,
	Debris = 26,
	Vehicle_Large = 27,
	Prevent_Movement = 28,
	Prevent_Building = 29,
	Tree = 30,
	Unused2 = 31
};
__declspec(selectany) uintptr_t TargetPSilentPlayer = NULL;
DWORD64 HitSND = 0;
static auto IgnoreLayerCollision = reinterpret_cast<void(*)(layer, layer, bool)>(il2cpp::methods::resolve_icall(xorstr("UnityEngine.Physics::IgnoreLayerCollision()")));
void init_unity() {
	IgnoreLayerCollision = reinterpret_cast<void(*)(layer, layer, bool)>(il2cpp::methods::resolve_icall(xorstr("UnityEngine.Physics::IgnoreLayerCollision()")));
}
typedef void(__fastcall* SendProjectileAttack_fn)(void*, void*);
inline SendProjectileAttack_fn original_sendprojectileattack{ };

typedef uintptr_t(__fastcall* create_projectile_fn)(void*, void*, Vector3, Vector3, Vector3);
inline create_projectile_fn original_create_projectile{ };

typedef bool(__fastcall* can_attack_fn)(void*, void*);
inline can_attack_fn original_canattack;

typedef void(__fastcall* clientinput_fn)(DWORD64, DWORD64);
inline clientinput_fn original_clientinput;

typedef float(__fastcall* GetSpeed)(float* a1, float* a2);
inline GetSpeed Orig_GetSpeed;

typedef bool(__fastcall* sendclienttick)(void*);
inline sendclienttick original_sendclienttick;

typedef Vector3(__fastcall* modifiedaimconedirection)(float, Vector3, bool);
inline modifiedaimconedirection original_aimconedirection;

typedef void(__fastcall* SetFlying_fn)(void*, void*);
inline SetFlying_fn original_setflying{};

typedef void(__fastcall* HandleRunning_fn)(void* a1, void* a2, bool);
inline HandleRunning_fn orig_handleRunning;

typedef pUncStr(__fastcall* consoleRun)(uintptr_t, pUncStr, DWORD64);
inline consoleRun original_consolerun{};

typedef void(__fastcall* block_sprint_fn)(void*);
inline block_sprint_fn original_blocksprint;

typedef bool(__fastcall* cancan)(void*, void*);
inline cancan original_canholditems;

typedef bool(__fastcall* issemiauto)(DWORD64);
inline issemiauto original_issemiauto;

typedef void(__fastcall* HandleRunning_fn)(void*, void*, bool);
inline HandleRunning_fn original_handleRunning{};

typedef void(_fastcall* NightMode_)(void* a1, void* a2);
inline NightMode_ original_mode;

typedef void(__fastcall* hitsound_fn)(BaseCombatEntity*, HitInfo*);
inline hitsound_fn original_sound;

typedef void(__fastcall* viewmodelPlay)(ViewModel*, pUncStr, int);
inline viewmodelPlay original_viewmodelplay{ };

typedef bool(__fastcall* Is_Admin)(void*, void*);
inline Is_Admin Orig_IsAdmin;




int yeet = 0;
int flick = 0;
int yaw = 100;

typedef void(__fastcall* LaunchProjectileClientside)(void*, void*, int, float, void*);
inline LaunchProjectileClientside original_LaunchProjectileClientside;//"Signature": "void BaseProjectile__LaunchProjectileClientside (BaseProjectile_o* __this, ItemDefinition_o* ammo, int32_t projectileCount, float projSpreadaimCone, const MethodInfo* method);"
typedef bool(__fastcall* IsDown)(void*, int, void*);//"Signature": "bool InputState__IsDown (InputState_o* __this, int32_t btn, const MethodInfo* method);"
inline IsDown original_IsDown;
bool visible = false;

//float GetBulletSpeedPS(Weapon tar, int ammo)
//{
//	if (ammo == 0) return tar.ammo[0].speed;
//	for (Ammo am : tar.ammo) {
//		for (int id : am.id) {
//			if (id == ammo) {
//				return am.speed;
//			}
//		}
//		if (am.id[0] == 0) return am.speed;
//	}
//	return 250.f;
//}
//1055129610551296
//float GetGravityPS(int ammoid) {
//	switch (ammoid) {
//	case 14241751:
//		return 1.f;
//	case -1234735557:
//		return 0.75f;
//	case 215754713:
//		return 0.75f;
//	case -1023065463:
//		return 0.5f;
//	case -2097376851:
//		return 0.75f;
//	case -1321651331:
//		return 1.25f;
//	default:
//		return 1.f;
//	}
//}

typedef bool(__stdcall* OLineOfSight)(Vector3, Vector3, int, float, void*);
inline OLineOfSight WLineOfSight;
bool __fastcall LineOfSight(Vector3 p1, Vector3 p2, int i, float f = 0.f, void* v = 0)
{
	//return WLineOfSight(p1, p2, i, f, v);
	if (!p1.x || !p1.y || !p1.z || !p2.x || !p2.y || !p2.z || i < 1 || f < 0.f)
	{
		printf("LOS Error_F\n");
		return false;
	}
	try {
		bool r = WLineOfSight(p1, p2, i, f, v);
		return r;
	}
	catch (...)
	{
		printf("LOS Error\n");
		return false;
	}
}
void __fastcall NightMode(void* a1, void* a2)
{
	if (Visuals::NightMode)
	{
		typedef void(__stdcall* F)(float);
		typedef void(__stdcall* I)(int);
		typedef void(__stdcall* C)(D2D1::ColorF);
		((I)(GetModBase(StrW(L"GameAssembly.dll")) + 0x1C245E0))(3); //public static void set_ambientMode(AmbientMode value) { }
		((F)(GetModBase(StrW(L"GameAssembly.dll")) + 0x1C24520))(1.f); // public static void set_ambientIntensity(float value) { }
		((C)(GetModBase(StrW(L"GameAssembly.dll")) + 0x1C245A0))(D2D1::ColorF(1.0f, 1.0f, 1.0f, 1.0f)); //public static void set_ambientLight(Color value) { }

	}
	return  original_mode(a1, a2);
}

bool __fastcall SendClientTick(BasePlayer* baseplayer) {
	if (!baseplayer) return original_sendclienttick(baseplayer);
	if (AntiAim::anti_aim) {
		auto input = read(baseplayer + O::BasePlayer::input, uintptr_t);
		auto state = read(input + 0x20, uintptr_t);
		auto current = read(state + 0x10, uintptr_t); if (!current) { return original_sendclienttick(baseplayer); }
		yeet += AntiAim::anti_aim_speed;
		if (yeet >= 999) { // reset number
			yeet = 0;
		}
		if (AntiAim::anti_aim_yaw == 0) {
			yaw = 100;
		}
		if (AntiAim::anti_aim_yaw == 1) {
			yaw = -100;
		}
		if (AntiAim::anti_aim_yaw == 2) {
			yaw = 0;
		}
		write(current + 0x18, Vector3(yaw, yeet, 0), Vector3);
	}
	return original_sendclienttick(baseplayer);
}
inline uintptr_t __fastcall CreateProjectile(void* BaseProjectile, void* prefab_pathptr, Vector3 pos, Vector3 forward, Vector3 velocity) {
	uintptr_t projectile = original_create_projectile(BaseProjectile, prefab_pathptr, pos, forward, velocity);
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	write(projectile + 0x114, true, bool);
	if (Weapons::FatBullet) {
		write(projectile + 0x2C, Weapons::FatBulletpov, float);
	}
	else {
		write(projectile + 0x2C, 0.1f, float);
	}
	return projectile;
}
inline bool __fastcall CanAttack(void* a1, void* a2) {
	if (Weapons::jumpAim)
		return true;

	return original_canattack(a1, a2);
}

pUncStr __fastcall Run(uintptr_t options, pUncStr strCommand, DWORD64 args) {
	bool IsFromServer = read(options + 0x6, bool);
	if (IsFromServer) {
		std::wstring cmd = std::wstring(strCommand->str);
		if (cmd.find(L"noclip") != std::wstring::npos || cmd.find(L"debugcamera") != std::wstring::npos || cmd.find(L"camspeed") != std::wstring::npos || cmd.find(L"admintime") != std::wstring::npos) {
			strCommand = nullptr;
		}
	}
	return original_consolerun(options, strCommand, args);
}
void HitSound(BaseCombatEntity* entity, HitInfo* Info) {
	if (entity->IsPlayer()) {
		if (Hit::HitSound) {
			if (Hit::CustomHitSound) {
				PlaySoundA("C:\\Hit\\sound.wav", NULL, SND_ASYNC | SND_FILENAME);
			}
		}
	}
	return original_sound(entity, Info);
}

class AimResult {
public:
	bool valid;
	BasePlayer* entity;
	Vector3 pos;
	float dist = 10000.f;
	float realdist = 0.f;
	float fov = 10000.f;

	bool teammate = false;

	bool operator<(const AimResult& b) {
		if (fov == 10000.f) {
			return this->dist < b.dist;
		}
		else {
			return this->fov < b.fov;
		}
	}

	AimResult() {
		this->valid = false;
		this->fov = 10000.f;
	}
	AimResult(Vector3 target) {
		this->valid = false;
		this->pos = target;
	}

};
struct Ray {
	Vector3 origin;
	Vector3 dir;
	Ray(Vector3 o, Vector3 d) {
		origin = o;
		dir = d;
	}
	Ray() {}
};


DWORD64 hkMelee = 0;
void DoMeleeAttack(AimResult target, DWORD64 active, bool transform = true) {
	if (!target.valid || !active) return;

	Vector3 lp = LocalPlayer.BasePlayer->GetPosition();
	typedef float(__stdcall* A)();

	float time = ((A)(Storage::gBase + O::UnityEngine_Time::get_time))();
	if (read(active + O::AttackEntity::nextAttackTime, float) >= time) { //nextattacktime
		return;
	}

	if (read(active + O::AttackEntity::timeSinceDeploy, float) < read(active + O::AttackEntity::deployDelay, float)) {
		return;
	}

	//HitTest
	auto hit_test_class = il2cpp::init_class(("HitTest"));
	if (!hit_test_class) return;

	typedef DWORD64(__stdcall* NNew)(DWORD64);
	auto HitTest = ((NNew)il2cpp::methods::object_new(hit_test_class));

	Ray ray = Ray(lp, (target.pos - lp).Normalized());
	write(HitTest + O::HitTest::MaxDistance, 1000.f, float); //MaxDistance
	DWORD64 trans;
	if (transform) {
		trans = target.entity->GetTransform(BoneList::head);
	}
	else {
		typedef DWORD64(__stdcall* GetTr)(DWORD64);
		trans = ((GetTr)(Storage::gBase + O::UnityEngine_Component::get_transform))((DWORD64)target.entity);
	}
	if (!trans) return;

	write(HitTest + O::HitTest::HitTransform, trans, DWORD64); //HitTransform
	write(HitTest + O::HitTest::AttackRay, ray, Ray);
	//write(HitTest + 0xC0, Str(xorstr(L"Flesh")), Str); //HitMaterial
	write(HitTest + O::HitTest::DidHit, true, bool); //DidHit
	write(HitTest + O::HitTest::HitEntity, target.entity, BasePlayer*); //HitEntity
	typedef Vector3(__stdcall* ITP)(DWORD64, Vector3);
	Vector3 hitpoint = ((ITP)(Storage::gBase + O::UnityEngine_Transform::InverseTransformPoint))(trans, target.pos);
	write(HitTest + O::HitTest::HitPoint, hitpoint, Vector3); //HitPoint
	write(HitTest + O::HitTest::HitNormal, Vector3(0, 0, 0), Vector3); //HitNormal
	write(HitTest + O::HitTest::damageProperties, read(active + O::BaseMelee::damageProperties, DWORD64), DWORD64);
	typedef void(__stdcall* Atk)(DWORD64, DWORD64);
	float kd = read(active + O::AttackEntity::repeatDelay, float);
	typedef void(__stdcall* StartKD)(DWORD64, float);
	((StartKD)(Storage::gBase + O::AttackEntity::StartAttackCooldown))(active, kd);
	/*if (Misc::Tracebullet) {
		vis_attack::Trace_bullet();
	}*/
	return ((Atk)(Storage::gBase + O::BaseMelee::ProcessAttack))(active, (DWORD64)HitTest);
}
bool PLOS(Vector3 a, Vector3 b) {
	typedef bool(__stdcall* LOS)(Vector3, Vector3, int, float);
	return ((LOS)(Storage::gBase + O::GamePhysics::LineOfSight))(a, b, 2162688, 0.f);
}
float MaxMeleeDist(DWORD64 melee, bool hren) {
	float pad = 0.1f;
	typedef float(__stdcall* RetF)();
	float time = ((RetF)(Storage::gBase + O::UnityEngine_Time::get_time))();

	float desyncTime = max(time - LocalPlayer.BasePlayer->GetTickTime() - 0.0325f, 0.f);
	float res = pad + desyncTime * 5.5f;
	if (hren) {
		res += (1.5f * read(melee + 0x298, float)); //maxDistance
	}
	return max(res, 0.05f);
}
AimResult TargetMeleeTest(BasePlayer* Player, DWORD64 melee, DWORD64 IgnoreTeam11) {
	AimResult res = AimResult();
	if (!Player || !Player->IsValid()) return res;
	//if (!Player->HasFlags(16)) return res;
	//if (!Player->IsTeamMate(Player)) return res;

	typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
	Vector3 prepos = Player->GetPosition();
	Vector3 closest_entity = ((CPoint)(Storage::gBase + O::BaseEntity::ClosestPoint))(LocalPlayer.BasePlayer, prepos);
	Vector3 closest_local = ((CPoint)(Storage::gBase + O::BaseEntity::ClosestPoint))(Player, closest_entity);

	float disttoentity = MaxMeleeDist(melee, false);
	float distfromlocal = MaxMeleeDist(melee, true);

	float maxdist = distfromlocal + disttoentity;

	float realdist = (closest_local - closest_entity).Length();

	if (realdist > maxdist) return res;

	Vector3 target;
	if (realdist <= disttoentity) {
		target = closest_entity;
	}
	else {
		Vector3 dir = (closest_entity - closest_local).Normalized();
		target = closest_local + dir * disttoentity;
	}

	res.valid = PLOS(closest_local, target);
	if (!res.valid) return res;

	Vector3 lppos = LocalPlayer.BasePlayer->GetPosition();
	res.valid = PLOS(lppos, target);
	if (!res.valid) return res;

	res.dist = realdist;
	res.entity = Player;
	res.pos = target;
	return res;
}
typedef void(__fastcall* FatLoot)(uintptr_t sourceContainer, DWORD64 action);
inline FatLoot FatLootoriginal_mode;
float LastUpdate = 0.f;
void update_chams() {
	if (LocalPlayer.BasePlayer->GetTickTime() > LastUpdate + Misc::uptime) {
		reinterpret_cast<void(*)()>(Storage::gBase + O::PlayerModel::RebuildAll)();
		LastUpdate = LocalPlayer.BasePlayer->GetTickTime();
	}
}
uintptr_t shader;

auto chams1(BasePlayer* player, bool draw = true) -> void
{
	bool PlayerSleeping = player->HasFlags(16);
	if (PlayerEsp::sleeperignore && PlayerSleeping)
		return;
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases)
	{
	case 0: { r -= 0.05f; if (r <= 0) cases += 1; break; }
	case 1: { g += 0.05f; b -= 0.05f; if (g >= 1) cases += 1; break; }
	case 2: { r += 0.05f; if (r >= 1) cases += 1; break; }
	case 3: { b += 0.05f; g -= 0.05f; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}
	if (draw) {
		if (Misc::chams) {
			const auto multiMesh = *reinterpret_cast<std::uintptr_t*>(player->get_player_model() + O::PlayerModel::_multiMesh);

			if (!multiMesh)
				return;
			auto render = get_Renderers(multiMesh);
			for (size_t idx{ 0 }; idx < render->get_size(); idx++)
			{
				auto renderer = render->get_value(idx);
				if (renderer)
				{
					auto material = get_material(renderer);
					if (material) {
						if (shader != unity::get_shader(material)) {
							if (!shader)
								shader = Find((L"Hidden/Internal-Colored"));//Hidden/Internal-Colored
							unity::set_shader(material, shader);
							if (!Misc::OnlyVisible) {
								SetInt(material, (L"_ZTest"), 8); // through walls
							}
							if (Misc::rainbow_chams) {
								SetColor(material, (L"_Color"), col(r, g, b, 1));
							}
							else if (Misc::health_chams) {
								int health = (int)player->GetHealth();
								float maxheal = 100.f;
								if ((int)player->GetHealth() <= 33) {
									SetColor(material, (L"_Color"), col(3, 0, 0, 1));
								}
								if ((int)player->GetHealth() >= 34 && (int)player->GetHealth() <= 66) {
									SetColor(material, (L"_Color"), col(3, 3, 0, 1));
								}
								if ((int)player->GetHealth() >= 67) {
									SetColor(material, (L"_Color"), col(0, 3, 0, 1));
								}
							}
							else {
								SetColor(material, (L"_Color"), col(Misc::xc, Misc::yc, Misc::zc, 1));
							}
							//SetColor(material, xorstr(L"_ColorVisible")), Color(Settings::Visuals::Players::Colors::VisibleChams[0], Settings::Visuals::Players::Colors::VisibleChams[1], Settings::Visuals::Players::Colors::VisibleChams[2], Settings::Visuals::Players::Colors::VisibleChams[3]));
							//SetColor(material, xorstr(L"_ColorBehind")), Color(Settings::Visuals::Players::Colors::InVisibleChams[0], Settings::Visuals::Players::Colors::InVisibleChams[1], Settings::Visuals::Players::Colors::InVisibleChams[2], Settings::Visuals::Players::Colors::InVisibleChams[3]));
							

						}
					}
				}
			}
		}
	}
}
auto chams(BasePlayer* player, bool draw = true) -> void
{
	bool PlayerSleeping = player->HasFlags(16);
	if (PlayerEsp::sleeperignore && PlayerSleeping)
		return;
	static int cases = 0;
	static float r = 1.00f, g = 0.00f, b = 1.00f;
	switch (cases)
	{
	case 0: { r -= 0.05f; if (r <= 0) cases += 1; break; }
	case 1: { g += 0.05f; b -= 0.05f; if (g >= 1) cases += 1; break; }
	case 2: { r += 0.05f; if (r >= 1) cases += 1; break; }
	case 3: { b += 0.05f; g -= 0.05f; if (b >= 1) cases = 0; break; }
	default: { r = 1.00f; g = 0.00f; b = 1.00f; break; }
	}
	if (draw) {
		if (Misc::chams1) {
			const auto multiMesh = *reinterpret_cast<std::uintptr_t*>(player->get_player_model() + O::PlayerModel::_multiMesh);

			if (!multiMesh)
				return;
			auto render = get_Renderers(multiMesh);
			for (size_t idx{ 0 }; idx < render->get_size(); idx++)
			{
				auto renderer = render->get_value(idx);
				if (renderer)
				{
					auto material = get_material(renderer);
					if (material) {
						if (shader != unity::get_shader(material)) {
							if (!shader)
								shader = Find((L"Classic"));//Hidden/Internal-Colored
							unity::set_shader(material, shader);
							if (!Misc::OnlyVisible) {
								SetInt(material, (L"_ZTest"), 8); // through walls
							}
							if (Misc::rainbow_chams) {
								SetColor(material, (L"_Color"), col(r, g, b, 1));
							}
							else if (Misc::health_chams) {
								int health = (int)player->GetHealth();
								float maxheal = 100.f;
								if ((int)player->GetHealth() <= 33) {
									SetColor(material, (L"_Color"), col(3, 0, 0, 1));
								}
								if ((int)player->GetHealth() >= 34 && (int)player->GetHealth() <= 66) {
									SetColor(material, (L"_Color"), col(3, 3, 0, 1));
								}
								if ((int)player->GetHealth() >= 67) {
									SetColor(material, (L"_Color"), col(0, 3, 0, 1));
								}
							}
							else {
								SetColor(material, (L"_Color"), col(Misc::xc, Misc::yc, Misc::zc, 1));
							}
							//SetColor(material, xorstr(L"_ColorVisible")), Color(Settings::Visuals::Players::Colors::VisibleChams[0], Settings::Visuals::Players::Colors::VisibleChams[1], Settings::Visuals::Players::Colors::VisibleChams[2], Settings::Visuals::Players::Colors::VisibleChams[3]));
							//SetColor(material, xorstr(L"_ColorBehind")), Color(Settings::Visuals::Players::Colors::InVisibleChams[0], Settings::Visuals::Players::Colors::InVisibleChams[1], Settings::Visuals::Players::Colors::InVisibleChams[2], Settings::Visuals::Players::Colors::InVisibleChams[3]));


						}
					}
				}
			}
		}
	}
}
void __fastcall FastLoot(uintptr_t sourceContainer, DWORD64 action)
{
	if (Misc::FastLoot)
		1.f;
	return FatLootoriginal_mode(sourceContainer, action);
}
bool waslagging = false;
void __fastcall ClientInput(DWORD64 baseplayah, DWORD64 ModelState) {
	float FOV = AimBot::Fov;
	float CurFOV;
	bool LP_isValid = false;
	if (!waslagging && Misc::FakeLag) {
		write(LocalPlayer.BasePlayer + O::BasePlayer::clientTickInterval, 0.4f, float);
		waslagging = true;
	}
	else if (waslagging && !Misc::FakeLag) {
		write(LocalPlayer.BasePlayer + O::BasePlayer::clientTickInterval, 0.05f, float);
		waslagging = false;
	}
	if (Misc::SilentWalk)
		LocalPlayer.BasePlayer->SetRemoveFlag(4);
	else {
		(Storage::gBase + O::UnityEngine_Time::set_timeScale); //set_timescale
		(1);
	}
	if (Misc::interactivedebug && GetAsyncKeyState(Keys::interactivedebug) ) {
		LocalPlayer.BasePlayer->AddFlag(512);
	}
	if (Misc::SwimOnGround) {
		LocalPlayer.BasePlayer->SetWaterLevel(0.65f);
	}
	//if (Misc::rayleigh_changer) {
	//	reinterpret_cast<void(__fastcall*)(float)>(Storage::gBase + 0x40A950)(Misc::rayleigh);
	//}
	//else {
	//	reinterpret_cast<void(__fastcall*)(float)>(Storage::gBase + 0x40A950)(0.f);
	//}
	if (Misc::mass_suicide) {
		reinterpret_cast<void(_fastcall*)(BasePlayer*, float)>(Storage::gBase + O::BasePlayer::OnLand)(LocalPlayer.BasePlayer, -50);
	}
	if (Misc::suicide && GetAsyncKeyState(Keys::suicide) && LocalPlayer.BasePlayer->GetHealth() > 0 && !LocalPlayer.BasePlayer->IsMenu()) {
		reinterpret_cast<void(_fastcall*)(BasePlayer*, float)>(Storage::gBase + O::BasePlayer::OnLand)(LocalPlayer.BasePlayer, -50);
	}
	WeaponData* Weapon = LocalPlayer.BasePlayer->GetActiveWeapon();
	DWORD64 active = Weapon->Held();
	char* classname = Weapon->ClassName();
	if (active && Misc::weapon_spam) {
		if (GetAsyncKeyState(Keys::weaponspam) && !LocalPlayer.BasePlayer->IsMenu()) {
			reinterpret_cast<void(*)(uintptr_t, Signal, Str)>(Storage::gBase + O::BaseEntity::SendSignalBroadcast)(active, Signal::Attack, Str(xorstr(L"")));
		}
	}
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	Vector3 startPos = LocalPlayer.BasePlayer->GetBoneByID(head);
	Vector3 endPos = ((BasePlayer*)TargetPlayer)->GetBoneByID(head);
	if (true) {

		DWORD64 BaseNetworkable;
		BaseNetworkable = read(Storage::gBase + 0x36567B8, DWORD64); //BN 
		DWORD64 EntityRealm = read(BaseNetworkable + 0xB8, DWORD64);
		DWORD64 ClientEntities = read(EntityRealm, DWORD64);
		DWORD64 ClientEntities_list = read(ClientEntities + 0x10, DWORD64);
		DWORD64 ClientEntities_values = read(ClientEntities_list + 0x28, DWORD64);
		if (!ClientEntities_values) return;
		int EntityCount = read(ClientEntities_values + 0x10, int);
		DWORD64 EntityBuffer = read(ClientEntities_values + 0x18, DWORD64);
		for (int i = 0; i <= EntityCount; i++)
		{
			DWORD64 Entity = read(EntityBuffer + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = read(Entity + 0x10, DWORD64);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = read(Object + 0x30, DWORD64);
			if (ObjectClass <= 100000) continue;
			pUncStr name = read(ObjectClass + 0x60, pUncStr);
			if (!name) continue;
			char* buff = name->stub;
			BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
			if (strstr(buff, StrA("Local"))) {
				Player = (BasePlayer*)read(Object + 0x28, DWORD64);
				if (!read(Player + playerModel, DWORD64)) continue;
				if (Player != LocalPlayer.BasePlayer) {
					printf("LocalPlayer %lld\n", Player->GetSteamID());
					mfound = false;
				}
				LocalPlayer.BasePlayer = Player;
				LP_isValid = true;
			}
			else  if (strstr(buff, "player.prefab") && (!strstr(buff, "prop") && (!strstr(buff, "corpse"))))
			{
				BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
				BasePlayer* Local = (BasePlayer*)read(Object + 0x28, DWORD64);
				if (!read(Player + O::BasePlayer::playerModel, DWORD64)) continue;
				update_chams();
				chams(Player);
				chams1(Player);



			}
		}


	}

	WeaponPatch();
	MiscFuncs();
	if (Misc::Meleeatack) {
		DWORD64 BaseNetworkable;
		BaseNetworkable = read(GetModBase(StrW((L"GameAssembly.dll"))) + 0x36567B8, DWORD64);
		DWORD64 EntityRealm = read(BaseNetworkable + 0xB8, DWORD64);
		DWORD64 ClientEntities = read(EntityRealm, DWORD64);
		DWORD64 ClientEntities_list = read(ClientEntities + 0x10, DWORD64);
		DWORD64 ClientEntities_values = read(ClientEntities_list + 0x28, DWORD64);
		if (!ClientEntities_values) return;
		int EntityCount = read(ClientEntities_values + 0x10, int);
		DWORD64 EntityBuffer = read(ClientEntities_values + 0x18, DWORD64);
		WeaponData* weapon = LocalPlayer.BasePlayer->GetActiveWeapon();
		DWORD64 active = read(weapon + O::Item::heldEntity, DWORD64);

		for (int i = 0; i <= EntityCount; i++)
		{
			DWORD64 Entity = read(EntityBuffer + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = read(Entity + 0x10, DWORD64);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = read(Object + 0x30, DWORD64);
			if (ObjectClass <= 100000) continue;
			pUncStr name = read(ObjectClass + 0x60, pUncStr);
			if (!name) continue;
			char* buff = name->stub;
			char* classname = weapon->ClassName();
			bool weaponmelee = weapon && classname && (m_strcmp(classname, ("BaseMelee")) || m_strcmp(classname, ("Jackhammer")));
			if (weaponmelee) {
				if (Misc::Meleeatack && !LocalPlayer.BasePlayer->IsTeamMate(LocalPlayer.BasePlayer->GetSteamID()) && m_strstr(buff, ("player.prefab"))) {
					BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
					BasePlayer* Local = (BasePlayer*)read(Object + 0x28, DWORD64);
					if (!read(Player + O::BasePlayer::playerModel, DWORD64)) continue;
					bool IgnoreTeam11 = LocalPlayer.BasePlayer->IsTeamMate(Player->GetSteamID());
					DWORD64 ent = read(Object + 0x28, UINT64);
					UINT64 gameObject = read(ObjectClass + 0x30, UINT64);
					UINT64 Trans = read(gameObject + 0x8, UINT64);
					UINT64 Vec = read(Trans + 0x38, UINT64);
					Vector3 pos = read(Vec + 0x90, Vector3);
					AimResult target = TargetMeleeTest(Player, active, IgnoreTeam11);
					DoMeleeAttack(target, active);

				}

			}

		}
	}
	if (Misc::AutoFarm) {
		//auto entity = O::HitTest::HitEntity;

		//if (!Misc::AutoFarm || !entity)
		//	return O::BaseMelee::ProcessAttack);

		//if (entity->class_name_hash() == STATIC_CRC32("OreResourceEntity")) {
		//	BaseNetworkable* marker = BaseNetworkable::clientEntities()->FindClosest(STATIC_CRC32("OreHotSpot"), entity, 5.0f);
		//	if (marker) {
		//		entity = marker;
		//		hit->HitTransform() = marker->transform();
		//		hit->HitPoint() = marker->transform()->InverseTransformPoint(marker->transform()());
		//		hit->HitMaterial() = String::New(xorstr("MetalOre"));
		//	}
		//}
		//else if (entity->class_name_hash() == STATIC_CRC32("TreeEntity")) {
		//	BaseNetworkable* marker = BaseNetworkable::clientEntities()->FindClosest(STATIC_CRC32("TreeMarker"), entity, 5.0f);
		//	if (marker) {
		//		hit->HitTransform() = marker->transform();
		//		hit->HitPoint() = marker->transform()->InverseTransformPoint(marker->transform()());
		//		hit->HitMaterial() = String::New(xorstr("Wood"));
		//	}
		//}

		DWORD64 BaseNetworkable;
		BaseNetworkable = read(GetModBase(StrW((L"GameAssembly.dll"))) + 0x36567B8, DWORD64);
		DWORD64 EntityRealm = read(BaseNetworkable + 0xB8, DWORD64);
		DWORD64 ClientEntities = read(EntityRealm, DWORD64);
		DWORD64 ClientEntities_list = read(ClientEntities + 0x10, DWORD64);
		DWORD64 ClientEntities_values = read(ClientEntities_list + 0x28, DWORD64);
		if (!ClientEntities_values) return;
		int EntityCount = read(ClientEntities_values + 0x10, int);
		DWORD64 EntityBuffer = read(ClientEntities_values + 0x18, DWORD64);
		WeaponData* weapon = LocalPlayer.BasePlayer->GetActiveWeapon();
		DWORD64 active = read(weapon + O::Item::heldEntity, DWORD64);
		char* classname = weapon->ClassName();
		bool weaponmelee = weapon && classname && (m_strcmp(classname, xorstr("BaseMelee")) || m_strcmp(classname, xorstr("Jackhammer")));
		for (int i = 0; i <= EntityCount; i++)
		{
			DWORD64 Entity = read(EntityBuffer + 0x20 + (i * 0x8), DWORD64);
			if (Entity <= 100000) continue;
			DWORD64 Object = read(Entity + 0x10, DWORD64);
			if (Object <= 100000) continue;
			DWORD64 ObjectClass = read(Object + 0x30, DWORD64);
			if (ObjectClass <= 100000) continue;
			pUncStr name = read(ObjectClass + 0x60, pUncStr);
			if (!name) continue;
			char* buff = name->stub;
			DWORD64 ent = read(Object + 0x28, UINT64);
			if (Misc::AutoFarm) {
				if (Misc::AutoFarmTree && weaponmelee && m_strstr((char*)read(read(ent, DWORD64) + 0x10, DWORD64), xorstr("TreeEntity"))) {
					char* name = (char*)read(read(ent, DWORD64) + 0x10, DWORD64);
					UINT64 gameObject = read(ObjectClass + 0x30, UINT64);
					UINT64 Trans = read(gameObject + 0x8, UINT64);
					UINT64 Vec = read(Trans + 0x38, UINT64);
					Vector3 pos = read(Vec + 0x90, Vector3);
					typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
					Vector3 local = ((CPoint)(Storage::gBase + O::BaseEntity::ClosestPoint))(LocalPlayer.BasePlayer, pos);
					if (Math::Calc3D_Dist(local, pos) >= 2.f) {
						continue;
					}
					AimResult target = AimResult();
					target.valid = true;
					target.pos = pos;
					target.entity = (BasePlayer*)ent;
					DoMeleeAttack(target, active, false);
				}
				if (Misc::AutoFarmOre && m_strstr((char*)read(read(ent, DWORD64) + 0x10, DWORD64), xorstr("OreHotSpot"))) {
					char* name = (char*)read(read(ent, DWORD64) + 0x10, DWORD64);
					UINT64 gameObject = read(ObjectClass + 0x30, UINT64);
					UINT64 Trans = read(gameObject + 0x8, UINT64);
					UINT64 Vec = read(Trans + 0x38, UINT64);
					Vector3 pos = read(Vec + 0x90, Vector3); //TODO Hit tree marker
					typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);

					Vector3 local = ((CPoint)(Storage::gBase + O::BaseEntity::ClosestPoint))(LocalPlayer.BasePlayer, pos);
					if (Math::Calc3D_Dist(local, pos) >= 2.f) {
						continue;
					}

					AimResult target = AimResult();
					target.valid = true;
					target.pos = pos;
					target.entity = (BasePlayer*)ent;
					DoMeleeAttack(target, active, false);
				}
				if (Misc::AutoFarmBarrel && m_strstr((char*)read(read(ent, DWORD64) + 0x10, DWORD64), xorstr("LootContainer"))) {
					char* name = (char*)read(read(ent, DWORD64) + 0x10, DWORD64);
					UINT64 gameObject = read(ObjectClass + 0x30, UINT64);
					UINT64 Trans = read(gameObject + 0x8, UINT64);
					UINT64 Vec = read(Trans + 0x38, UINT64);
					Vector3 pos = read(Vec + 0x90, Vector3); //TODO Hit tree marker
					typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);

					Vector3 local = ((CPoint)(Storage::gBase + O::BaseEntity::ClosestPoint))(LocalPlayer.BasePlayer, pos);
					if (Math::Calc3D_Dist(local, pos) >= 2.f) {
						continue;
					}

					AimResult target = AimResult();
					target.valid = true;
					target.pos = pos;
					target.entity = (BasePlayer*)ent;
					DoMeleeAttack(target, active, false);
				}
			}
		}
	}
	typedef void(__stdcall* Laner)(float);
	if (Misc::speedhack && GetAsyncKeyState(Keys::speedKey)) {
		Laner ss = (Laner)(Storage::gBase + O::UnityEngine_Time::set_timeScale); //set_timescale
		ss(2);
	}
	else {
		Laner ss = (Laner)(Storage::gBase + O::UnityEngine_Time::set_timeScale); //set_timescale
		ss(1);
	}

	IgnoreLayerCollision(layer::PlayerMovement, layer::Water, !Misc::no_playercollision);
	IgnoreLayerCollision(layer::PlayerMovement, layer::Tree, Misc::no_playercollision);
	IgnoreLayerCollision(layer::PlayerMovement, layer::AI, Misc::no_playercollision);

	return original_clientinput(baseplayah, ModelState);
}
bool __fastcall CanHoldItems(void* a1, void* a2) {
	if (Weapons::canHoldItems)
		return true;
	return original_canholditems(a1, a2);
}
inline float __fastcall Fake_GetSpeed(float* a1, float* a2)
{
	if (Misc::speedhack && GetAsyncKeyState(Keys::speedKey));
	return true;
	return  Orig_GetSpeed(a1, a2);
}
inline void __fastcall SendProjectileAttack(void* a1, void* a2) {
	uintptr_t PlayerAttack = read((uintptr_t)a2 + 0x18, uintptr_t); // PlayerAttack playerAttack;
	uintptr_t Attack = read(PlayerAttack + 0x18, uintptr_t); // public Attack attack;
	if (Weapons::spoof_hitdistance) {
		write(a2 + 0x2C, Weapons::hitdistance, float);
	}
	if (AimBot::silentAim) {
		if (Storage::closestPlayer != NULL) {
			write(Attack + 0x30, 698017942, uint32_t); // public uint hitBone;
			write(Attack + 0x64, 16144115, uint32_t); // public uint hitPartID;
			if (AimBot::ThroughWall) {
				write(Attack + 0x4C, Vector3(0.f, -1000.f, 0.f) * -10000.f, Vector3); // public Vector3 hitNormalWorld;
			}
			write(Attack + 0x2C, read(read(Storage::closestPlayer + 0x50, uintptr_t) + 0x10, uintptr_t), uint32_t); // public uint hitID; 
		}
	}
	if (AimBot::AlwaysHeadshot) {
		write(Attack + 0x30, 698017942, uint32_t); // public uint hitBone;
	}
	if (AimBot::randhitbox) {
		switch (my_rand() % 3) {

		case 1:
			write(Attack + 0x30, 1031402764, uint32_t);
			write(Attack + 0x64, 1750816991, uint32_t);

			break;
		case 2:
			write(Attack + 0x30, 182688154, uint32_t);
			write(Attack + 0x64, 1750816991, uint32_t);

			break;
		case 3:

			write(Attack + 0x30, 102231371, uint32_t);
			write(Attack + 0x64, 1750816991, uint32_t);
			break;
		}
		write(Attack + 0x60, Vector3(-.1f, -.1f, 0), Vector3); //hitPositionLocal
		write(Attack + 0x78, Vector3(0, -1, 0), Vector3); //hitNormalLocal
	}
	return original_sendprojectileattack(a1, a2);
}
void Play(ViewModel* viewmodel, pUncStr name, int layer = 0) {
	if (Misc::remove_attack_anim) {
		if (!CALLED_BY(O::BaseProjectile::DoAttack, 0x296) || LocalPlayer.BasePlayer->GetActiveWeapon()->GetID() == -75944661) {
			return original_viewmodelplay(viewmodel, name, layer);
		}
	}
	else {
		return original_viewmodelplay(viewmodel, name, layer);
	}
}


Vector3 __fastcall GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = true) { // wanna hang myself
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	Vector3 dir = (PredictionP(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayer, neck) - LocalPlayer.BasePlayer->GetBoneByID(head)).Normalized();
	if (AimBot::pSilent && Storage::closestPlayer != NULL) {
		inputVec = dir;
	}
	float gravity;
	if (LocalPlayer.BasePlayer->GetActiveWeapon()->GetID() == 1540934679 || LocalPlayer.BasePlayer->GetActiveWeapon()->GetID() == 1602646136) {
		gravity = 1.9f;
	}
	else {
		gravity = GetGravity(LocalPlayer.BasePlayer->GetActiveWeapon()->LoadedAmmo());
	}
	Vector3 Local = LocalPlayer.BasePlayer->GetPosition();
	Vector3 target = AimBot::pBody ? TargetPlayer->GetBoneByID(spine1) : TargetPlayer->GetBoneByID(head);
	a::Prediction(Local, target, TargetPlayer->GetVelocity(), GetBulletSpeed(), gravity);

	Vector3 playerDir = (target - Local).Normalized();

	if (AimBot::psilent) {
		if (AimBot::psilentonkey) {
			if (AimBot::psilenttarget == 0 && Storage::closestPlayer != NULL) {
				inputVec = playerDir;
			}
		}
		else {
			if (GetAsyncKeyState(AimBot::psilenter)) {
				if (AimBot::psilenttarget == 0 && Storage::closestPlayer != NULL) {
					inputVec = playerDir;;
				}
			}
		}
	}
	if (Weapons::AntiSpread) {
		aimCone *= Weapons::spread / 100.f;
	}
	return original_aimconedirection(aimCone, inputVec, anywhereInside);
}
void __fastcall HandleRunning(void* a1, void* a2, bool wantsRun) {
	//wantsRun = GetAsyncKeyState(0x10) && !GetAsyncKeyState(0x41) && !GetAsyncKeyState(0x53) && !GetAsyncKeyState(0x44);
	if (Misc::omniSprint)
		return original_handleRunning(a1, a2, true);

	return original_handleRunning(a1, a2, wantsRun);
}

typedef Vector3(__fastcall* EyePosition)(void*, void*);
inline EyePosition original_EyePosition; //"Signature": "UnityEngine_Vector3_o PlayerEyes__get_position (PlayerEyes_o* __this, const MethodInfo* method);" 11942384
typedef Vector3(__fastcall* MainCamGetPos)(void*);//"Signature": "UnityEngine_Vector3_o MainCamera__get_position (const MethodInfo* method);"
inline MainCamGetPos original_MainCamGetPos;
void __fastcall SetFlying(void* a1, void* a2)
{
	if (Misc::FakeAdmin)
		return;
}


Vector3 __fastcall fake_EyePosition(void* eyes, void* method)
{
	Vector3 og = original_EyePosition(eyes, method);
	if (fake_eyes)
	{
		auto pos = (read(cam, uintptr_t), StrW("position"), false);
		if (cam)
		{
			if (!real_eyes_pos.x && !real_eyes_pos.y && !real_eyes_pos.z)
			{
				return og;
			}
			write(pos, real_eyes_pos, Vector3);
		}
		return fake_eyes_pos;
	}
	return og;
}

#include "offsets(sam).h"
bool __fastcall fake_IsDown(void* inputstate, int button, void* method)
{
	//printf("fake_isDown, visible: %s\nautoshoot: %s\nbutton: %i\n", visible ? "true" : "false", Vars::AimBot::autoshoot ? "true" : "false", button);
	auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	if (button == 1024 && TargetPlayer && visible && AimBot::AutoShoot)
	{
		return true;
	}
	return original_IsDown(inputstate, button, method);
}
void __fastcall Fake_handleRunning(void* a1, void* a2, bool wantsRun)
{
	if (Misc::SlideWalk)
		return orig_handleRunning(a1, a2, true);
	return orig_handleRunning(a1, a2, wantsRun);
}
void __fastcall fake_LaunchProjectileClientside(void* BaseProjectile, void* Ammo, int projectile_count, float aimcone, void* method)
{
	if (Misc::PeekAssist && Storage::closestPlayer)
	{
		printf("1\n");
		Vector3 startPos = (fake_eyes ? fake_eyes_pos : original_EyePosition((void*)read(LocalPlayer.BasePlayer + O::BasePlayer::eyes, uintptr_t), method));
		Vector3 endPos = ((BasePlayer*)Storage::closestPlayer)->GetBoneByID(head);
		float d = endPos.y - startPos.y;
		Vector3 realPos = startPos;
		printf("1\n");
		typedef bool(__stdcall* V)(Vector3, Vector3, int, float, void*);
		V s = (V)(Storage::gBase + offsets::LineOfgish);
		printf("1\n");
		if (s(startPos, endPos, 10551296, 0.f, 0))

		{
			printf("1\n");
			//printf("(DIRECT LOS)\nRealPos: (%ff, %ff, %ff)\nStartPos: (%ff, %ff, %ff)\nEndPos: (%ff, %ff, %ff)\n---------------\n", realPos.x, realPos.y, realPos.z, startPos.x, startPos.y, startPos.z, endPos.x, endPos.y, endPos.z);
			fake_eyes = true;
			real_eyes_pos = realPos;
			fake_eyes_pos = startPos;
			auto pos = (read(cam, uintptr_t), StrW("position"), false);
			if (cam)
			{
				write(pos, real_eyes_pos, Vector3);
			}
			original_LaunchProjectileClientside(BaseProjectile, Ammo, projectile_count, aimcone, method);
			fake_eyes = false;
			return;
		}
		startPos.y = startPos.y + Misc::LongNeckvolue;

		if (s(startPos, endPos, 10551296, 0.f, 0))
		{
			//printf("(UP)\nRealPos: (%ff, %ff, %ff)\nStartPos: (%ff, %ff, %ff)\nEndPos: (%ff, %ff, %ff)\n---------------\n", realPos.x, realPos.y, realPos.z, startPos.x, startPos.y, startPos.z, endPos.x, endPos.y, endPos.z);
			fake_eyes = true;
			real_eyes_pos = realPos;
			fake_eyes_pos = startPos;
			auto pos = (read(cam, uintptr_t), StrW("position"), false);
			if (cam)
			{
				write(pos, real_eyes_pos, Vector3);
			}
			original_LaunchProjectileClientside(BaseProjectile, Ammo, projectile_count, aimcone, method);
			fake_eyes = false;
			return;
		}

		startPos.y = startPos.y - Misc::LongNeckvolue;
		startPos.x = startPos.x + Misc::sidepeekvalue;
		if (s(startPos, endPos, 10551296, 0.f, 0))
		{
			//printf("(LEFT)\nRealPos: (%ff, %ff, %ff)\nStartPos: (%ff, %ff, %ff)\nEndPos: (%ff, %ff, %ff)\n---------------\n", realPos.x, realPos.y, realPos.z, startPos.x, startPos.y, startPos.z, endPos.x, endPos.y, endPos.z);
			//set player eyes location to startpos and keep playereyes camera at same position
			fake_eyes = true;
			real_eyes_pos = realPos;
			fake_eyes_pos = startPos;
			auto pos = (read(cam, uintptr_t), StrW("position"), false);
			if (cam)
			{
				write(pos, real_eyes_pos, Vector3);
			}
			original_LaunchProjectileClientside(BaseProjectile, Ammo, projectile_count, aimcone, method);
			fake_eyes = false;
			return;
		}
		startPos.x = startPos.x - (Misc::sidepeekvalue * 2.f);
		if (s(startPos, endPos, 10551296, 0.f, 0))
		{
			//printf("(RIGHT)\nRealPos: (%ff, %ff, %ff)\nStartPos: (%ff, %ff, %ff)\nEndPos: (%ff, %ff, %ff)\n---------------\n", realPos.x, realPos.y, realPos.z, startPos.x, startPos.y, startPos.z, endPos.x, endPos.y, endPos.z);
			//set player eyes location to startpos and keep playereyes camera at same position
			fake_eyes = true;
			real_eyes_pos = realPos;
			fake_eyes_pos = startPos;

			auto pos = (read(cam, uintptr_t), StrW("position"), false);
			if (cam)
			{
				write(pos, real_eyes_pos, Vector3);
			}
			original_LaunchProjectileClientside(BaseProjectile, Ammo, projectile_count, aimcone, method);
			fake_eyes = false;
			return;
		}
	}
	original_LaunchProjectileClientside(BaseProjectile, Ammo, projectile_count, aimcone, method);
	return;
}

inline bool __fastcall Fake_IsAdmin(void* a1, void* a2)
{
	if (Misc::FakeAdmin)
		return true;

	return Orig_IsAdmin(a1, a2);
}

bool __fastcall get_isSemiAuto(DWORD64 BaseProjectile) {
	if (Weapons::Automatic)
		return false;
	return original_issemiauto(BaseProjectile);
}
Vector3 __fastcall fake_MainCamGetPos(void* method)
{
	if (fake_eyes)
	{
		return real_eyes_pos;
	}
	return original_MainCamGetPos(method);
}
namespace vis_attack {
	struct bullet_tracer {
		Vector3 m_start = read(this + O::HitInfo::PointStart, Vector3);
		Vector3 m_end = read(this + O::HitInfo::PointEnd, Vector3);

		bullet_tracer(Vector3 st, Vector3 en) {
			this->m_start = st;
			this->m_end = en;
		}
	};

	std::vector<bullet_tracer> activetrace = std::vector<bullet_tracer>();

	void log_trace(Vector3 start, Vector3 end) {
		activetrace.push_back(bullet_tracer(start, end));
		if (activetrace.size() > 3)
			activetrace.erase(activetrace.begin());
	}
	void render_trace() {
		if (Visuals::visattack) {
			for (int i = 0; i < activetrace.size(); i++) {
				auto trace = activetrace[i];
				static float screenX = GetSystemMetrics(SM_CXSCREEN);
				static float screenY = GetSystemMetrics(SM_CYSCREEN);
				Vector2 m_start = Vector2(screenX / 2.f, screenY - 200.f);
				Vector2 m_end;
				if (LocalPlayer.WorldToScreen(trace.m_end, m_end), LocalPlayer.WorldToScreen(trace.m_start, m_start)) {
					Render::Object.Line(m_start, m_end, D2D1::ColorF::Red);
				}
			}
		}
	}
}
typedef float(__fastcall* FastBullet)(void*);
inline FastBullet original_FastBullet; //"Signature": "UnityEngine_Vector3_o PlayerEyes__get_position (PlayerEyes_o* __this, const MethodInfo* method);" 11942384
float GetRandomVelocity_hk(void* self) {
	float modifier = 1.f;

	if (Misc::Fastshot)
		modifier += 0.4f;

	return original_FastBullet(self);
}

void HookFunction(void* Function, void** Original, void* Detour, bool autoEnable = true) {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) { std::cout << ("Failed to initialize MinHook") << std::endl; return; }
	MH_CreateHook(Function, Detour, Original);
	if (autoEnable)
		MH_EnableHook(Function);
}
inline void InitHook() {
	if (MH_Initialize() != MH_OK && MH_Initialize() != MH_ERROR_ALREADY_INITIALIZED) {
		std::cout << "Failed to initialize Hook" << std::endl;
		return;
	}
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BaseCombatEntity::DoHitNotify), (void**)&original_sound, HitSound);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0xC01980), (void**)&original_aimconedirection, GetModifiedAimConeDirection);////public static Vector3 GetModifiedAimConeDirection(float aimCone, Vector3 inputVec, bool anywhereInside = True) { }
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 0x2549D10), (void**)&original_consolerun, Run);//public static string Run(ConsoleSystem.Option options, string strCommand, object[] args) { }
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 10868112), (void**)&original_FastBullet, GetRandomVelocity_hk);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::TOD_Sky::get_Instance), (void**)&original_mode, NightMode);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::ModelState::set_flying), (void**)&original_setflying, SetFlying);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BasePlayer::SendProjectileAttack /*no change */), (void**)&original_sendprojectileattack, SendProjectileAttack);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BasePlayer::CanAttack /*no change */), (void**)&original_canattack, CanAttack);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BasePlayer::SendClientTick /*no change */), (void**)&original_sendclienttick, SendClientTick);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::PlayerWalkMovement::HandleRunDuckCrawl /*no change */), (void**)&original_handleRunning, HandleRunning);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BaseProjectile::CreateProjectile), (void**)&original_create_projectile, CreateProjectile);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BaseMountable::CanHoldItems /*no change */), (void**)&original_canholditems, CanHoldItems);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BasePlayer::ClientInput /*no change */), (void**)&original_clientinput, ClientInput); // internal virtual void ClientInput(InputState state) { }
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BaseProjectile::get_isSemiAuto /*no change */), (void**)&original_issemiauto, get_isSemiAuto); // internal virtual void ClientInput(InputState state) { }

	HookFunction(reinterpret_cast<void*>(static_cast<uintptr_t>(GetModBase(L"GameAssembly.dll") + O::BasePlayer::get_IsAdmin)), reinterpret_cast<void**>(&Orig_IsAdmin), Fake_IsAdmin); //public bool get_IsAdmin() { }
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::BaseProjectile::LaunchProjectileClientside /*no change */), (void**)&original_LaunchProjectileClientside, fake_LaunchProjectileClientside);
	//HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + 6856352), (void**)&original_MainCamGetPos, fake_MainCamGetPos); //краш на 2345 
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::PlayerEyes::get_position /*no change */), (void**)&original_EyePosition, fake_EyePosition);
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::GamePhysics::LineOfSight /*no change */), (void**)&WLineOfSight, LineOfSight); // internal virtual void ClientInput(InputState state) { }
	HookFunction((void*)(uintptr_t)(GetModBase(L"GameAssembly.dll") + O::InputState::IsDown /*no change */), (void**)&original_IsDown, fake_IsDown); // internal virtual void ClientInput(InputState state) { }
}