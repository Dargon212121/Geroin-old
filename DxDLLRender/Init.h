#include <time.h>

void InitCheat()
{
	Vector2 kek = Render::Object.CanvasSize();
	Global::ScreenWidth = kek.x;
	Global::ScreenHigh = kek.y;
	if (AimBot::Crosshair) {
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys + 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs + 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys - 4 }, D2D1::ColorF::White, 0.7f);
		Render::Object.Line(Vector2{ xs, ys }, Vector2{ xs - 4, ys + 4 }, D2D1::ColorF::White, 0.7f);

		Render::Object.Line(Vector2{ xs + 4, ys + 4 }, Vector2{ xs + 4 + 4, ys + 4 + 4 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2), 0.7f);
		Render::Object.Line(Vector2{ xs + 4, ys - 4 }, Vector2{ xs + 4 + 4, ys - 4 - 4 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2), 0.7f);
		Render::Object.Line(Vector2{ xs - 4, ys - 4 }, Vector2{ xs - 4 - 4, ys - 4 - 4 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2), 0.7f);
		Render::Object.Line(Vector2{ xs - 4, ys + 4 }, Vector2{ xs - 4 - 4, ys + 4 + 4 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2), 0.7f);
	}
	if (Visuals::Russua) {
		float xs1 = Global::ScreenWidth / 1000, ys1 = Global::ScreenHigh / 1000;
		Render::Object.FillRectangle(Vector2{ xs1 - 0, ys1 - 0 }, Vector2{ 1920, 360 }, D2D1::ColorF::White);
		Render::Object.FillRectangle(Vector2{ xs1 - 0, ys1 - -360 }, Vector2{ 1920, 360 }, D2D1::ColorF::Blue);
		Render::Object.FillRectangle(Vector2{ xs1 - 0, ys1 - -720 }, Vector2{ 1920, 360 }, D2D1::ColorF::Red);
	}
	if (Visuals::SKET) {
		float xs1 = Global::ScreenWidth / 1000, ys1 = Global::ScreenHigh / 1000;
		Render::Object.FillRectangle(Vector2{ xs1 - 0, ys1 - 0 }, Vector2{ 1921, 30 }, D2D1::ColorF::Black);

	}

	if (AimBot::svaston)// свастон от ланера
	{
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		// This is special, requires some calculations!
		static float rotation_degree = 0.f;
		if (rotation_degree > 89.f)
			rotation_degree = 0.f;
		rotation_degree += Misc::speed;//Скорость вращен?
		int length = (int)(Global::ScreenWidth / Misc::razmer / 15);//размер зиги
		float gamma = atan(length / length);
		int i = 0;
		while (i < 4)
		{
			std::vector <int> p
			{
				int(length * sin(deg2rad(rotation_degree + (i * 90)))),
				int(length * cos(deg2rad(rotation_degree + (i * 90)))),
				int((length / cos(gamma)) * sin(deg2rad(rotation_degree + (i * 90) + RAD2DEG(gamma)))),
				int((length / cos(gamma)) * cos(deg2rad(rotation_degree + (i * 90) + RAD2DEG(gamma))))
			};
			Render::Object.Line({ xs, ys }, { xs + p[0], ys - p[1] }, FLOAT4TOD3DCOLOR(Colors::Crosshair2));
			Render::Object.Line({ xs + p[0], ys - p[1] }, { xs + p[2], ys - p[3] }, FLOAT4TOD3DCOLOR(Colors::Crosshair2));
			i++;
		}

	}

	if (AimBot::CustomCrosshair)
	{
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		if (AimBot::dot) {
			Render::Object.FillRectangle(Vector2{ xs , ys }, Vector2{ 2, 2 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2));
		}
		// i did it ! lol
		Render::Object.FillRectangle(Vector2{ xs + AimBot::Gap, ys }, Vector2{ AimBot::Longht, 2 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2)); // right
		Render::Object.FillRectangle(Vector2{ xs - AimBot::Gap + 2, ys }, Vector2{ -AimBot::Longht , 2 }, FLOAT4TOD3DCOLOR(Colors::Crosshair2)); // left
		Render::Object.FillRectangle(Vector2{ xs , ys - AimBot::Gap + 2 }, Vector2{ 2 , -AimBot::Longht }, FLOAT4TOD3DCOLOR(Colors::Crosshair2)); // up
		Render::Object.FillRectangle(Vector2{ xs , ys + AimBot::Gap }, Vector2{ 2 , AimBot::Longht }, FLOAT4TOD3DCOLOR(Colors::Crosshair2)); // down
	}
	if (AimBot::DrawFov) {
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;

		Render::Object.Сircle(Vector2{ xs, ys }, FLOAT4TOD3DCOLOR(Colors::Fov), AimBot::Fov, 1.f);
		if (AimBot::FillFov) {
			Render::Object.FillCircle(Vector2{ xs, ys }, D2D1::ColorF(0, 0, 0, 0.45), AimBot::Fov / AimBot::FillFov);
		}
		
	}
//	if (show) {

		//Render::Object.FillRoundedRectangle({ 1200, 300 }, { 200,  300 }, D2D1::ColorF::Black, 4);// 1 ГОРИЗ ///////////////////задний фон версия 0.0000000000000001

		//}
	if (Storage::closestPlayer != 100)
	{
		auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		static Vector2 startPos = Vector2(xs - 2, ys - 2);
		Vector2 ScreenPos;
		if (PlayerEsp::targetline)
		{
			if (!(TargetPlayer->GetBoneByID(spine1).x == 0 && TargetPlayer->GetBoneByID(spine1).y == 0 && TargetPlayer->GetBoneByID(spine1).z == 0)) {
				if (LocalPlayer.WorldToScreen(TargetPlayer->GetBoneByID(head), ScreenPos))
					Render::Object.Line(startPos, ScreenPos, FLOAT4TOD3DCOLOR(Colors::LineEsp), 1.f);
			}
		}

	if (PlayerEsp::targettext) {
		float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
		wchar_t name[64];

		if (Storage::closestPlayer != NULL)
		{
			_swprintf(name, L"Target: %s", TargetPlayer->GetName());
		}
		else
		{
			_swprintf(name, L"No target");
		}
		Render::Object.String(Vector2{ xs - 0, ys - 20 }, name, FLOAT4TOD3DCOLOR(Colors::Textesp), 1.f);
	}
}


	auto* TargetPlayerA = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
	wchar_t name[64];
	if (Other::InfoTopLeft)
	{
		if (Storage::closestPlayer != NULL)
		{
			float curhealth = (int)TargetPlayerA->GetHealth();
			if (!TargetPlayerA->IsNpc())
			{
				float maxheal = 100.f;
				if ((int)TargetPlayerA->GetHealth() <= 33)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 34 && (int)TargetPlayerA->GetHealth() <= 66)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 67)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxheal), 15 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
				}
			}
			else
			{
				float maxhealxd = 150.f;
				if ((int)TargetPlayerA->GetHealth() <= 33)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 34 && (int)TargetPlayerA->GetHealth() <= 66)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
				}
				if ((int)TargetPlayerA->GetHealth() >= 67)
				{
					Render::Object.FillRectangle(Vector2{ 100, 90 }, Vector2{ 150 * (curhealth / maxhealxd), 15 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
				}
			}
			WeaponData* ActWeapon = TargetPlayerA->GetActiveWeapon();
			Render::Object.Rectangle(Vector2{ 100, 90 }, Vector2{ 150, 15 }, D2D1::ColorF::Black, 0.5f);
			if (!ActWeapon)
			{
				_swprintf(name, L"%s [%d m] [%d HP]", TargetPlayerA->GetName(), (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayerA->GetBoneByID(head)), (int)TargetPlayerA->GetHealth());
			}
			else
			{
				_swprintf(name, L"%s [%d m] [%d HP] [%s]", TargetPlayerA->GetName(), (int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), TargetPlayerA->GetBoneByID(head)), (int)TargetPlayerA->GetHealth(), ActWeapon->GetName());
			}
		}
		else
		{
			_swprintf(name, L"No target");
		}
		Render::Object.String(Vector2(100, 70), name, D2D1::ColorF::White , true);
	}
	float xs = Global::ScreenWidth / 2, ys = Global::ScreenHigh / 2;
	if (Visuals::crosshair)
	{
		Render::Object.Line(Vector2{ xs, ys - -10 }, Vector2{ xs , ys + 5 }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ xs - -10, ys }, Vector2{ xs + 5, ys }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ xs, ys - 4 }, Vector2{ xs , ys + -10 }, D2D1::ColorF::Red, 0.5f);
		Render::Object.Line(Vector2{ xs - 4, ys }, Vector2{ xs + -10, ys }, D2D1::ColorF::Red, 0.5f);
	}

	if (Visuals::Watermark) {// самопис ватермарк от меня

		Render::Object.FillRoundedRectangle({ 16, 5 }, { 179,  22 }, D2D1::ColorF::Black, 4);// 1 ГОРИЗ 
		Render::Object.FillRoundedRectangle({ 15, 5 }, { 180,  4 }, D2D1::ColorF::Purple, 4);// 1 ГОРИЗ 
	//	Render::Object.FillRoundedRectangle({ 15, 27 }, { 180,  2 }, D2D1::ColorF::DarkBlue, 4);// 1 ГОРИЗ 
	//	Render::Object.FillRoundedRectangle({ 15, 5 }, { 2,  22 }, D2D1::ColorF::DarkBlue, 4);// 1 ГОРИЗ 
	//	Render::Object.FillRoundedRectangle({ 193, 5 }, { 2,  22 }, D2D1::ColorF::DarkBlue, 4);// 1 ГОРИЗ 
		Render::Object.Stringf({ 20, 11 }, (L"❤Geroin.solution❤"), D2D1::ColorF::LightGreen);

		//print(os.date('%d.%m.%Y %H:%M:%S', os.time())) or print(os.date());

		}


	//uintptr_t bn = read(Storage::gBase + 0x323F1E8, uintptr_t);//+ BaseNet
	//if (!bn) {
	//	Render::Object.Stringf(Vector2(99, 10), xorstr(L"Cheat Not Worked"), D2D1::ColorF::Red);
	//	return;
	//}
	//else {
	//	Render::Object.Stringf(Vector2(99, 10), xorstr(L"Cheat Worked"), D2D1::ColorF::Green);
	//}

	if (AimBot::Fov > (kek.y - 3)) AimBot::Fov = (kek.y - 3);
	if (AntiAim::anti_aim && AntiAim::anti_aim_indicator) {// калл индикатор который не робит
		int radius = 80;
		float range = 5;
		int LineLength = 50;
		POINT p;
		if (GetCursorPos(&p)) {
			if (p.x >= indicator_x - radius && p.x <= indicator_x + radius) {
				if (p.y >= indicator_y - radius && p.y <= indicator_y + radius) {
					if (GetAsyncKeyState(VK_LBUTTON) && show) {
						indicator_x = p.x;
						indicator_y = p.y;
					}
				}
			}
		}
		Render::Object.FillCircle(Vector2(indicator_x, indicator_y), D2D1::ColorF(0.13, 0.13, 0.13, 0.6), radius);//this draws that grey circle u see :]
		float origyaw = AntiAim::anti_aim_;
		Render::Object.CosTanSinLine(origyaw, range, indicator_x, indicator_y, LineLength, D2D1::ColorF::Red);//this the function from b4 btw
	}
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
	if (Visuals::visualize_prediction && TargetPlayerA->IsValid()) {
		Vector2 t;
		if (!(TargetPlayerA->GetBoneByID(spine1).x == 0 && TargetPlayerA->GetBoneByID(spine1).y == 0 && TargetPlayerA->GetBoneByID(spine1).z == 0)) {
			if (w2s(a::get_aim_point(GetBulletSpeed(), GetGravity(LocalPlayer.BasePlayer->GetActiveWeapon()->LoadedAmmo())), t)) {
				Render::Object.Сircle(t, D2D1::ColorF::Green, 4.5f);
			}
		}
	}

	//if (GetKeyState(Keys::menu) && AimBot::menu) {
	//
	//	Render::Object.FillRoundedRectangle({ 0, 0 }, { 1920,  1080 }, D2D1::ColorF(48, 44, 44, 150), 4);// типо затемнение

		
	if (GetAsyncKeyState(Keys::aimKey) && AimBot::Activate) {
		Render::Object.String(Vector2{ xs - 0, ys - 30 }, L"Holding Aimbot", D2D1::ColorF::Yellow, true, true);// спастил с китикита

	}
	else {
		Render::Object.String(Vector2{ xs - 0, ys - 30 }, L"", D2D1::ColorF::Yellow, true, true);
	}
	if (GetAsyncKeyState(Keys::speedKey) && Misc::speedhack) {
		Render::Object.String(Vector2{ xs - 0, ys - 40 }, L"Holding SpeedHack", D2D1::ColorF::RosyBrown, true, true);
	}
	else {
		Render::Object.String(Vector2{ xs - 0, ys - 40 }, L"", D2D1::ColorF::RosyBrown, true, true);
	}
	if (GetAsyncKeyState(Misc::Zoomkey) && Misc::Zoom) {
		Render::Object.String(Vector2{ xs - 0, ys - 50 }, L"Holding Zoom", D2D1::ColorF::Blue, true, true);
	}
	else {
		Render::Object.String(Vector2{ xs - 0, ys - 50 }, L"", D2D1::ColorF::Blue, true, true);
	}
	//Render::Object.Line({ 0, 0 }, { 1920,  4 }, rainbow() );


	EntityZaLoop();
}