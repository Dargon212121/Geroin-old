#include <map>
namespace a {
	double CalcBulletDrop(double height, double DepthPlayerTarget, float velocity, float gravity) {
		double pitch = (Vector3::my_atan2(height, DepthPlayerTarget));
		double BulletVelocityXY = velocity * Vector3::my_cos(pitch);
		double Time = DepthPlayerTarget / BulletVelocityXY;
		double TotalVerticalDrop = (0.4905f * gravity * Time * Time);
		return TotalVerticalDrop * 10;
	}
	void Prediction(Vector3 local, Vector3& target, Vector3 targetvel, float bulletspeed, float gravity) {
		float Dist = Math::Distance_3D(target, local);
		float BulletTime = Dist / bulletspeed;
		Vector3 vel = Vector3(targetvel.x, 0, targetvel.z) * 0.75f;
		Vector3 PredictVel = vel * BulletTime;
		target += PredictVel;
		double height = target.y - local.y;
		Vector3 dir = target - local;
		float DepthPlayerTarget = Vector3::my_sqrt((dir.x * dir.x) + (dir.z * dir.z));
		float drop = CalcBulletDrop(height, DepthPlayerTarget, bulletspeed, gravity);
		target.y += drop;
	}
	Vector3 get_aim_point(float speed, float gravity) {
		Vector3 ret = reinterpret_cast<BasePlayer*>(Storage::closestPlayer)->GetBoneByID(head);
		Prediction(LocalPlayer.BasePlayer->GetBoneByID(head), ret, reinterpret_cast<BasePlayer*>(Storage::closestPlayer)->GetVelocity(), speed, gravity);
		return ret;
	}
}
float GetBulletSpeedP(Weapon tar, int ammo)
{
	if (ammo == 0) return tar.ammo[0].speed; //melee
	for (Ammo am : tar.ammo)
	{
		for (int id : am.id)
		{
			if (id == ammo)
			{
				return am.speed;
			}
		}
		if (am.id[0] == 0) return am.speed;
	}
	return 250.f;
}

float GetFov(BasePlayer* Entity, BoneList Bone) {
	Vector2 ScreenPos;
	if (!LocalPlayer.WorldToScreen(Entity->GetBoneByID(Bone), ScreenPos)) return 1000.f;
	return Math::Calc2D_Dist(Vector2(Global::ScreenWidth / 2, Global::ScreenHigh / 2), ScreenPos);
}
float GetGravity(int ammoid) {
	switch (ammoid) {
	case 14241751:
		return 1.f;
	case -1234735557:
		return 0.75f;
	case 215754713:
		return 0.75f;
	case -1023065463:
		return 0.5f;
	case -2097376851:
		return 0.75f;
	case -1321651331:
		return 1.25f;
	default:
		return 1.f;
	}
}
float GetBulletSpeed() {
	WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
	Weapon tar = active->Info();
	int ammo = active->LoadedAmmo();
	if (ammo == 0) return Misc::Fastshot ? tar.ammo[0].speed * 1.3 + Other::testFloat : tar.ammo[0].speed + Other::testFloat;
	for (Ammo am : tar.ammo) {
		for (int id : am.id) {
			if (id == ammo) {
				return Misc::Fastshot ? am.speed * 1.3 + Other::testFloat : am.speed + Other::testFloat;
			}
		}
		if (am.id[0] == 0) return Misc::Fastshot ? am.speed * 1.3 + Other::testFloat : am.speed + Other::testFloat;
	}
	return Misc::Fastshot ? 250.f * 1.3 + Other::testFloat : 250.f + Other::testFloat;
}

Vector3 PredictionP(Vector3 LP_Pos, BasePlayer* Player, BoneList Bone)
{
	WeaponData* active = LocalPlayer.BasePlayer->GetActiveWeapon();
	Weapon tar = active->Info();
	int ammo = active->LoadedAmmo();
	Vector3 BonePos = Player->GetBoneByID(Bone);
	if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey)) {
		BonePos = Player->GetBoneByID(Bone) - Vector3(0, 1.4, 0);
	if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey1)) {
		BonePos = Player->GetBoneByID(Bone) - Vector3(-1, 0, 0);
		if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey2)) {
			BonePos = Player->GetBoneByID(Bone) - Vector3(1, 0, 0);
		}
		}
	}
	float Dist = Math::Calc3D_Dist(LP_Pos, BonePos);
	if (Dist > 0.001f) {
		float speed = GetBulletSpeedP(tar, ammo);//float speed = GetBulletSpeedP(tar, ammo);
		if (!speed) speed = 250.f;
		float BulletTime = Dist / speed;
		Vector3 vel = Player->GetVelocity();
		Vector3 PredictVel = vel * BulletTime * 0.75f;
		BonePos += PredictVel;
		float gravity = GetGravity(ammo);
		BonePos.y += (4.905f * BulletTime * BulletTime) * gravity;
	}
	return BonePos;
}
void StepConstant(Vector2& angles) {
	bool smooth = AimBot::smooth;
	Vector2 angles_step = angles - LocalPlayer.BasePlayer->viewangles();
	Math::Normalize(angles_step.x, angles_step.y);

	if (smooth) {
		float factor_pitch = (AimBot::smooth_factor / 10.f);
		if (angles_step.x < 0.f) {
			if (factor_pitch > std::abs(angles_step.x)) {
				factor_pitch = std::abs(angles_step.x);
			}
			angles.x = LocalPlayer.BasePlayer->viewangles().x - factor_pitch;
		}
		else {
			if (factor_pitch > angles_step.x) {
				factor_pitch = angles_step.x;
			}
			angles.x = LocalPlayer.BasePlayer->viewangles().x + factor_pitch;
		}
	}
	if (smooth) {
		float factor_yaw = (AimBot::smooth_factor / 10.f);
		if (angles_step.y < 0.f) {
			if (factor_yaw > std::abs(angles_step.y)) {
				factor_yaw = std::abs(angles_step.y);
			}
			angles.y = LocalPlayer.BasePlayer->viewangles().y - factor_yaw;
		}
		else {
			if (factor_yaw > angles_step.y) {
				factor_yaw = angles_step.y;
			}
			angles.y = LocalPlayer.BasePlayer->viewangles().y + factor_yaw;
		}
	}
}

void do_aimbot(BasePlayer* player) {// а тут аимбот с плюсминус олд
	if (!LocalPlayer.BasePlayer || !player) { return; }
	if (!LocalPlayer.BasePlayer->GetActiveWeapon() || player->IsDestroyed()) { return; }
	bool long_neck = Misc::LongNeck && GetAsyncKeyState(Misc::LongNeckkey);
	Vector3 local = long_neck ? LocalPlayer.BasePlayer->GetBoneByID(head) + Vector3(0, 1.15, 0) : LocalPlayer.BasePlayer->GetBoneByID(head);
	Vector3 target = AimBot::pBody ? player->GetBoneByID(spine1) : player->GetBoneByID(head);
	a::Prediction(local, target, player->GetVelocity(), GetBulletSpeed(), GetGravity(LocalPlayer.BasePlayer->GetActiveWeapon()->LoadedAmmo()));
	Vector2 Offset = Math::CalcAngle(local, target) - LocalPlayer.BasePlayer->viewangles();
	Math::Normalize(Offset.y, Offset.x);
	Vector2 AngleToAim = LocalPlayer.BasePlayer->viewangles() + Offset;
	if (AimBot::smooth) {
		StepConstant(AngleToAim);
	}
	Math::Normalize(AngleToAim.y, AngleToAim.x);
	LocalPlayer.BasePlayer->SetVA(AngleToAim);
}
