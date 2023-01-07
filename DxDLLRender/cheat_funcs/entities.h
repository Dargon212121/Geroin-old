bool mfound = false;
int npeek = 0;
uintptr_t cam = 0;
bool fake_eyes = false;
Vector3 real_eyes_pos = {};
Vector3 fake_eyes_pos = {};
#include "../hooks.hpp"
void RadarPlayer(BasePlayer* player);
inline void RenderActiveSlot(BasePlayer* player, float Pos_x, float Pos_Y);
void FindMatrix() {
	UINT64 ObjMgr = read(GetModBase(StrW((L"UnityPlayer.dll"))) + 0x17C1F18, UINT64);
	UINT64 end = read(ObjMgr, UINT64);
	for (UINT64 Obj = read(ObjMgr + 0x8, UINT64); (Obj && (Obj != end)); Obj = read(Obj + 0x8, UINT64))
	{
		UINT64 GameObject = read(Obj + 0x10, UINT64);
		WORD Tag = read(GameObject + 0x54, WORD);
		if (Tag == 5)
		{
			UINT64 ObjClass = read(GameObject + 0x30, UINT64);
			UINT64	Entity = read(ObjClass + 0x18, UINT64);
			LocalPlayer.pViewMatrix = (Matrix4x4*)(Entity + 0x2E4);
			printf(StrA("Found matrix!\n"));
			mfound = true;
			return;
		}
		else if (Tag == 20011 && Misc::CustomTime) {
			UINT64 ObjClass = read(GameObject + 0x30, UINT64);
			UINT64	Entity = read(ObjClass + 0x18, UINT64);
			DWORD64 Dome = read(Entity + 0x28, DWORD64);
			DWORD64 TodCycle = read(Dome + 0x38, DWORD64);
			write(TodCycle + 0x10, Misc::Time, float);
		}

	}


}
inline void RenderActiveSlot(BasePlayer* player, float Pos_x, float Pos_Y);

void PickupItem(DWORD64 item)
{
	typedef void(__stdcall* Pick)(DWORD64, Str);
	return ((Pick)(GetModBase(L"GameAssembly.dll") + 0xC7B730))(item, Str(L"Pickup")); // public void ServerRPC(string funcName) { }
}
void miscvis(DWORD64 ObjectClass, char* buff, bool boolean, bool showDistance, float drawDistance, const char* substring, const wchar_t* targettext, D2D1::ColorF color) {
	if (boolean && strstr(buff, substring)) {
		DWORD64 gameObject = read(ObjectClass + 0x30, DWORD64);
		DWORD64 transform = read(gameObject + 0x8, DWORD64);
		DWORD64 vector = read(transform + 0x38, DWORD64);
		Vector3 game_Pos = read(vector + 0x90, Vector3);
		Vector2 screen_Pos;
		if (LocalPlayer.WorldToScreen(game_Pos, screen_Pos)) {
			if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos) <= drawDistance) {
				wchar_t distance[64];
				_swprintf(distance, L"[ %d m ]", (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), game_Pos));
				wchar_t text[64];
				_swprintf(text, targettext);
				Render::Object.String({ screen_Pos.x, screen_Pos.y }, text, color, true, true);
				if (showDistance) {
					Render::Object.String(screen_Pos + Vector2(0, 15), distance, color, true, true);
				}
			}
		}
	}
}
void EntityZaLoop()
{
	float CurFOV;
	float FOV = AimBot::Fov;
	bool LP_isValid = false;
	if (!LocalPlayer.pViewMatrix || !mfound) {
		FindMatrix();
	}
	DWORD64 BaseNetworkable;  //31D2CB8
	BaseNetworkable = read(Storage::gBase + 0x36567B8, DWORD64); // BaseNetworkable_c* 
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
		DWORD64 ent = read(Object + 0x28, UINT64);
		if (ObjectClass <= 100000) continue;
		pUncStr name = read(ObjectClass + 0x60, pUncStr);
		if (!name) continue;
		char* buff = name->stub;
		BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
		if (strstr(buff, StrA("Local"))) {
			Player = (BasePlayer*)read(Object + 0x28, DWORD64);
			if (!read(Player + O::BasePlayer::playerModel, DWORD64)) continue;
			if (Player != LocalPlayer.BasePlayer) {
				printf("LocalPlayer %lld\n", Player->GetSteamID());
				mfound = false;
			}
			LocalPlayer.BasePlayer = Player;
			LP_isValid = true;

		}
		if (Misc::AutoPickUp && m_strstr(buff, ("/collectable/"))) {
			uintptr_t ent = *reinterpret_cast<uintptr_t*>(Object + 0x28);
			uintptr_t gameObject = *reinterpret_cast<uintptr_t*>(ObjectClass + 0x30);
			uintptr_t Trans = *reinterpret_cast<uintptr_t*>(gameObject + 0x8);
			uintptr_t Vec = *reinterpret_cast<uintptr_t*>(Trans + 0x38);
			Vector3 pos = read(Vec + 0x90, Vector3);
			typedef Vector3(__stdcall* CPoint)(BasePlayer*, Vector3);
			Vector3 local = ((CPoint)(GetModBase(L"GameAssembly.dll") + O::BaseEntity::ClosestPoint))(LocalPlayer.BasePlayer, pos);
			if (Math::Calc3D_Dist(local, pos) < 3.f) { PickupItem(ent); }
		}
		else  if (strstr(buff, "player.prefab") && (!strstr(buff, "prop") && (!strstr(buff, "corpse"))))// || (strstr(buff, "scientist")) || (strstr(buff, "tunneldweller"))
		{
			auto Player = reinterpret_cast<BasePlayer*>(Entity);// хуета фикс от кседы
			//BasePlayer* Player = (BasePlayer*)read(Object + 0x28, DWORD64);
			BasePlayer* Local = (BasePlayer*)read(Object + 0x28, DWORD64);
			if (!read(Player + O::BasePlayer::playerModel, DWORD64)) continue;
			ESP(Player, LocalPlayer.BasePlayer);
			RadarPlayer(Player);
			if (Visuals::ActiveSlotRender && GetFov(Player, head) <= 150) {
				RenderActiveSlot(Player);
			}
			//if (Radar::ActiveSlot && GetFov(Player, head) <= Storage::closestPlayer)
			//	RenderActiveSlot(Player, Radar::ActiveSlotPos_X, Radar::ActiveSlotPos_Y);
			if (PlayerEsp::sleeperignore && Player->HasFlags(16)) continue;
			//if (AimBot::IgnoreNpc && Player->IsNpc()) continue;
			if (AimBot::IgnoreTeam && Player->IsTeamMate(LocalPlayer.BasePlayer->GetSteamID())) continue;
			if (AimBot::VisibleCheck && !Player->is_visible()) continue;
			//if (AimBot::VisibleCheck && !Player->I()) continue;
			if (Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), Player->GetBoneByID(head)) > AimBot::Range) continue;

			if (FOV > (CurFOV = GetFov(Player, BoneList(Global::BoneToAim))) && !Player->IsDead()) {
				FOV = CurFOV; Storage::closestPlayer = (uintptr_t)Player, !Player->IsTeamMate(LocalPlayer.BasePlayer->GetSteamID());
			}
		}
		miscvis(ObjectClass, buff, Ores::Stone, Ores::showDistance, Ores::oreDrawDistance, "stone-ore.prefab", L"Stone Ore", D2D1::ColorF::Gray);
		miscvis(ObjectClass, buff, Ores::Stone, Ores::showDistance, Ores::oreDrawDistance, "stone-collectable.prefab", L"Stone Collectable", D2D1::ColorF::Gray);
		miscvis(ObjectClass, buff, Ores::Sulfur, Ores::showDistance, Ores::oreDrawDistance, "sulfur-ore.prefab", L"Sulfur Ore", D2D1::ColorF::Gold);
		miscvis(ObjectClass, buff, Ores::Sulfur, Ores::showDistance, Ores::oreDrawDistance, "sulfur-collectable.prefab", L"Sulfur Collectable", D2D1::ColorF::Gold);
		miscvis(ObjectClass, buff, Ores::Metal, Ores::showDistance, Ores::oreDrawDistance, "metal-ore.prefab", L"Metal Ore", D2D1::ColorF::SaddleBrown);
		miscvis(ObjectClass, buff, Ores::Metal, Ores::showDistance, Ores::oreDrawDistance, "metal-collectable.prefab", L"Metal Collectable", D2D1::ColorF::SaddleBrown);
		miscvis(ObjectClass, buff, Visuals::Supply, Visuals::crateDistance, Visuals::drawCrateDistance, "supply_drop.prefab", L"Airdrop", D2D1::ColorF::DarkCyan);
		miscvis(ObjectClass, buff, Visuals::Chinook, Visuals::crateDistance, Visuals::drawCrateDistance, "codelockedhackablecrate.prefab", L"Chinook Crate", D2D1::ColorF::DarkRed);
		miscvis(ObjectClass, buff, Visuals::Minicopter, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "minicopter.entity.prefab", L"Minicopter", D2D1::ColorF::Blue);
		miscvis(ObjectClass, buff, Visuals::ScrapHeli, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "scraptransporthelicopter.prefab", L"Scrap Heli", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Boat, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "rowboat.prefab", L"Boat", D2D1::ColorF::LightBlue);
		miscvis(ObjectClass, buff, Visuals::RHIB, Visuals::vehicleDistance, Visuals::drawVehicleDistance, "rhib.prefab", L"RHIB", D2D1::ColorF::LightCyan);
		miscvis(ObjectClass, buff, Visuals::AutoTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "autoturret_deployed.prefab", L"Auto Turret", D2D1::ColorF::Orange);
		miscvis(ObjectClass, buff, Visuals::FlameTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "flameturret.deployed.prefab", L"Flame Turret", D2D1::ColorF::DarkOrange);
		miscvis(ObjectClass, buff, Visuals::ShotgunTurret, Visuals::trapDistance, Visuals::drawTrapDistance, "guntrap.deployed.prefab", L"Shotgun Trap", D2D1::ColorF::DimGray);
		miscvis(ObjectClass, buff, Visuals::Landmine, Visuals::trapDistance, Visuals::drawTrapDistance, "landmine.prefab", L"Landmine", D2D1::ColorF::BlueViolet);
		miscvis(ObjectClass, buff, Visuals::BearTrap, Visuals::trapDistance, Visuals::drawTrapDistance, "beartrap.prefab", L"Beartrap", D2D1::ColorF::Brown);
		miscvis(ObjectClass, buff, Visuals::Hemp, Visuals::otherDistance, Visuals::drawOtherDistance, "hemp.entity.prefab", L"Hemp", D2D1::ColorF::LimeGreen);
		miscvis(ObjectClass, buff, Visuals::Corpse, Visuals::otherDistance, Visuals::drawOtherDistance, "player_corpse.prefab", L"Corpse", D2D1::ColorF::Red);
		miscvis(ObjectClass, buff, Visuals::Stash, Visuals::otherDistance, Visuals::drawOtherDistance, "small_stash_deployed.prefab", L"Stash", D2D1::ColorF::Yellow);
		miscvis(ObjectClass, buff, Visuals::PatrolHeli, Visuals::otherDistance, 4500.f, "assets/prefabs/npc/patrol helicopter/patrolhelicopter.prefab", L"Patrol Helicopter", D2D1::ColorF(0.3f, 0.34f, 1.f));
		miscvis(ObjectClass, buff, Visuals::Bear, Visuals::AnimalsDistance, Visuals::drawAnimalsDistance, "bear.prefab", L"Bear", D2D1::ColorF::SandyBrown);
		miscvis(ObjectClass, buff, Visuals::Boar, Visuals::AnimalsDistance, Visuals::drawAnimalsDistance, "boar.prefab", L"Caban", D2D1::ColorF::SaddleBrown);
		miscvis(ObjectClass, buff, Visuals::Chicken, Visuals::AnimalsDistance, Visuals::drawAnimalsDistance, "chicken.prefab", L"Сhicken", D2D1::ColorF::DarkViolet);
		miscvis(ObjectClass, buff, Visuals::Horse, Visuals::AnimalsDistance, Visuals::drawAnimalsDistance, "horse.prefab", L"Horse", D2D1::ColorF::MintCream);
		miscvis(ObjectClass, buff, Visuals::Boomer, Visuals::BoomerDistance, Visuals::drawBoomerDistance, "firework.boomer.blue", L"Blue Boomer", D2D1::ColorF::Blue);
		miscvis(ObjectClass, buff, Visuals::Boomer, Visuals::BoomerDistance, Visuals::drawBoomerDistance, "firework.boomer.green", L"Green Boomer", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Boomer, Visuals::BoomerDistance, Visuals::drawBoomerDistance, "firework.boomer.orange", L"Orange Boomer	", D2D1::ColorF::Orange);
		miscvis(ObjectClass, buff, Visuals::Boomer, Visuals::BoomerDistance, Visuals::drawBoomerDistance, "firework.boomer.red	", L"Red Boomer", D2D1::ColorF::Red);
		miscvis(ObjectClass, buff, Visuals::Mushrooms, Visuals::EatDistance, Visuals::drawEatDistance, "mushroom-cluster-5.prefab", L"Mushrooms", D2D1::ColorF::DarkGray);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "rifle.ak", L"AK-47 Rifle", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "rifle.lr300", L"LR300 Rifle", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "rifle.l96", L"L96 Sniper", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "rifle.m39", L"M39 Rifle", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "bow.compound	", L"Bow Compound", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "rifle.semiauto", L"Semi Auto Rifle", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "smg.mp5", L"MP5 SMG", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "smg.2", L"SMG Auto", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "smg.thompson", L"smg.thompson", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.nailgun", L"Nailgun Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.eoka", L"EOKA Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.m92", L"M92 Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.python", L"Python Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.revolver", L"Revolver Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "pistol.semiauto", L"Semi Auto Pistol", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "shotgun.pump", L"Shotgun Pump", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "shotgun.double", L"Double Shotgun", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Loot, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_normal_2.prefab", L"Loot Box", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "grenade.f1", L"grenade.f1", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "multiplegrenadelauncher", L"multiplegrenadelauncher", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "bow.compound", L"bow", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "crossbow", L"crossbow", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "bow.hunting", L"bow.hunting", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "hmlmg", L"HMLMG", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "spear.stone", L"spear.stone", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "spear.wooden", L"spear.wooden", D2D1::ColorF::DarkBlue);
		miscvis(ObjectClass, buff, Visuals::Weapon, Visuals::DistanceWeapon, Visuals::drawWeaponDistance, "shotgun.double", L"shotgun.double", D2D1::ColorF::DarkBlue); 
		miscvis(ObjectClass, buff, Visuals::Medical, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_normal_2_medical.prefab", L"Medical Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Tool, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_tools.prefab", L"Tool Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Foodbox, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_normal_2_food.prefab", L"Food Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Elite, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_elite.prefab", L"Elite Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Mine, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_mine.prefab", L"Mine Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Militiry, Visuals::DistanceBox, Visuals::drawBoxDistance, "crate_normal.prefab", L"Military Box", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Wardrobe, Visuals::otherDistance, Visuals::drawOtherDistance, "cupboard.tool.deployed.prefab", L"Wardrobe", D2D1::ColorF::LimeGreen);
		miscvis(ObjectClass, buff, Visuals::Berry, Visuals::EatDistance, Visuals::drawEatDistance, "berry-green-collectable.prefab", L"Green berries", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Berry, Visuals::EatDistance, Visuals::drawEatDistance, "berry-red-collectable.prefab", L"Red berries", D2D1::ColorF::Red);
		miscvis(ObjectClass, buff, Visuals::Berry, Visuals::EatDistance, Visuals::drawEatDistance, "berry-blue-collectable.prefab", L"Blue berries", D2D1::ColorF::Blue);
		miscvis(ObjectClass, buff, Visuals::Berry, Visuals::EatDistance, Visuals::drawEatDistance, "berry-white-collectable.prefab", L"White berries", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::furnace, Visuals::furnaceDistance, Visuals::drawfurnaceDistance, "furnace", L"Furnace", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::furnace, Visuals::furnaceDistance, Visuals::drawfurnaceDistance, "furnace.large", L"Big Furnace", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::WorkBench, Visuals::WorkBenchDistance, Visuals::drawWorkBenchDistance, "workbench1", L"Workbench Level 1", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::WorkBench, Visuals::WorkBenchDistance, Visuals::drawWorkBenchDistance, "workbench2", L"Workbench Level 2", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::WorkBench, Visuals::WorkBenchDistance, Visuals::drawWorkBenchDistance, "workbench3", L"Workbench Level 3", D2D1::ColorF::White);
		//miscvis(ObjectClass, buff, Visuals::Transport, Visuals::TransportDistance, Visuals::drawTransportDistance, "snowmobiletomaha", L"Snowmobile", D2D1::ColorF::White);
		miscvis(ObjectClass, buff, Visuals::Raid, Visuals::RaidDistance, Visuals::drawRaidDistance, "c4_explosion.prefab", L"Raid C4", D2D1::ColorF::White);
		miscvis(ObjectClass, buff, Visuals::Keycard, Visuals::KeycardDistance, Visuals::drawKeycardDistance, "keycard_red", L"Red Keycard", D2D1::ColorF::Red);
		miscvis(ObjectClass, buff, Visuals::Keycard, Visuals::KeycardDistance, Visuals::drawKeycardDistance, "keycard_green", L"Green Keycard", D2D1::ColorF::Green);
		miscvis(ObjectClass, buff, Visuals::Keycard, Visuals::KeycardDistance, Visuals::drawKeycardDistance, "keycard_blue", L"Blue Keycard", D2D1::ColorF::Blue);
		miscvis(ObjectClass, buff, Visuals::Corpse, Visuals::otherDistance, Visuals::drawOtherDistance, "item_drop_backpack.prefab", L"Backpack", D2D1::ColorF::Black);
	}
	if (Misc::flyhack_indicator) {
		Render::Object.FillRectangle(Vector2(Global::ScreenWidth / 2 - 214, 200), Vector2(428 * (Global::flyhack / Global::max_flyhack), 10), D2D1::ColorF::Lime);
		Render::Object.Rectangle(Vector2(Global::ScreenWidth / 2 - 214, 200), Vector2(428, 10), D2D1::ColorF::Black);

		Render::Object.FillRectangle(Vector2(Global::ScreenWidth / 2 - 214, 230), Vector2(428 * (Global::hor_flyhack / Global::max_hor_flyhack), 10), D2D1::ColorF::Lime);
		Render::Object.Rectangle(Vector2(Global::ScreenWidth / 2 - 214, 230), Vector2(428, 10), D2D1::ColorF::Black);
	}
					
	if (Misc::PeekAssist && GetAsyncKeyState(Keys::manipulatorkey))
	{
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		D2D1::ColorF ccolor = D2D1::ColorF::Red;
		visible = false;
		if (Storage::closestPlayer != NULL && npeek++ >= 25 && Misc::PeekAssist && GetAsyncKeyState(Keys::manipulatorkey)) {
			npeek = 0;
			Vector3 startPos = (fake_eyes ? fake_eyes_pos : original_EyePosition((void*)read(LocalPlayer.BasePlayer + O::BasePlayer::eyes, uintptr_t), 0));
			BasePlayer* tp = (BasePlayer*)Storage::closestPlayer;
			Vector3 target = tp->GetBoneByID(head);

			typedef bool(__stdcall* V)(Vector3, Vector3, int, float, void*);
			V LineOfSight2 = (V)(Storage::gBase + 0x8E67D0);// public static bool LineOfSight(Vector3 p0, Vector3 p1, int layerMask, float padding, BaseEntity ignoreEntity) { }
			if (LineOfSight2(startPos, target, 10551296, 0.f, 0))
			{
				ccolor = D2D1::ColorF::Lime;
				visible = true;
				goto done;
			}
			startPos.y = startPos.y + Misc::LongNeckvolue;
			if (LineOfSight2(startPos, target, 10551296, 0.f, 0))
			{
				ccolor = D2D1::ColorF::Lime;
				
				visible = true;
				goto done;
			}
			startPos.y = startPos.y - Misc::LongNeckvolue;
			startPos.x = startPos.x + Misc::sidepeekvalue;
			if (LineOfSight2(startPos, target, 10551296, 0.f, 0))
			{
				
				ccolor = D2D1::ColorF::Lime;
				visible = true;
				goto done;
			}

			startPos.x = startPos.x - (Misc::sidepeekvalue * 2.f);//2,f
			if (LineOfSight2(startPos, target, 10551296, 0.f, 0))
			{

				ccolor = D2D1::ColorF::Lime;
				visible = true;
				goto done;
			}
		}
	done:
		if (Misc::PeekAssist && GetAsyncKeyState(Keys::manipulatorkey))
		{

			Render::Object.FillRoundedRectangle({ xs -60, ys - 30  }, { 120,  5 }, ccolor, 4);// 1 ГОРИЗ 
			//Render::Object.String(Vector2{ xs - 0, ys + 40.f }, Peek, ccolor, true, true);
		}
	}
	if (Storage::closestPlayer)
	{
		if (FOV < (CurFOV = GetFov((BasePlayer*)Storage::closestPlayer, BoneList(Global::BoneToAim))))
		{
			Storage::closestPlayer = 0;
		}
	}
	if (LP_isValid)
	{
		if (Storage::closestPlayer && !LocalPlayer.BasePlayer->IsMenu()) {
			if (GetAsyncKeyState(Keys::aimKey)) {
				do_aimbot(reinterpret_cast<BasePlayer*>(Storage::closestPlayer));
			}
		}
	}
	else LocalPlayer.BasePlayer = nullptr;
}