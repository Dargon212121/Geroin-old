#include <d3d9.h>

#include "../ImGUI/imgui_internal.h"
Vector2 screen_center = { 0, 0 };

D3DCOLOR rainbow() {

	static float x = 0, y = 0;
	static float r = 0, g = 0, b = 0;

	if (y >= 0.0f && y < 255.0f) {
		r = 255.0f;
		g = 0.0f;
		b = x;
	}
	else if (y >= 255.0f && y < 510.0f) {
		r = 255.0f - x;
		g = 0.0f;
		b = 255.0f;
	}
	else if (y >= 510.0f && y < 765.0f) {
		r = 0.0f;
		g = x;
		b = 255.0f;
	}
	else if (y >= 765.0f && y < 1020.0f) {
		r = 0.0f;
		g = 255.0f;
		b = 255.0f - x;
	}
	else if (y >= 1020.0f && y < 1275.0f) {
		r = x;
		g = 255.0f;
		b = 0.0f;
	}
	else if (y >= 1275.0f && y < 1530.0f) {
		r = 255.0f;
		g = 255.0f - x;
		b = 0.0f;
	}

	x += Visuals::time;//скорость изменения цветов
	if (x >= 255.0f)
		x = 0.0f;

	y += Visuals::time; //скорость изменения цветов
	if (y > 1530.0f)
		y = 0.0f;


	return D3DCOLOR_ARGB((int)r, (int)g, (int)b, 255);
}

D3DCOLOR FLOAT4TOD3DCOLOR(float Col[])
{
	ImU32 col32_no_alpha = ImGui::ColorConvertFloat4ToU32(ImVec4(Col[0], Col[1], Col[2], Col[3]));
	float a = (col32_no_alpha >> 24) & 255;
	float r = (col32_no_alpha >> 16) & 255;
	float g = (col32_no_alpha >> 8) & 255;
	float b = col32_no_alpha & 255;
	return D3DCOLOR_ARGB((int)a, (int)b, (int)g, (int)r);
}

void Skeleton(BasePlayer* player) {
	auto head_pos = player->GetBoneByID(head);
	auto spine4_pos = player->GetBoneByID(spine4);
	auto l_clavicle_pos = player->GetBoneByID(l_clavicle);
	auto l_upperarm_pos = player->GetBoneByID(l_upperarm);
	auto l_forearm_pos = player->GetBoneByID(l_forearm);
	auto l_hand_pos = player->GetBoneByID(l_hand);
	auto r_clavicle_pos = player->GetBoneByID(r_clavicle);
	auto r_upperarm_pos = player->GetBoneByID(r_upperarm);
	auto r_forearm_pos = player->GetBoneByID(r_forearm);
	auto r_hand_pos = player->GetBoneByID(r_hand);
	auto pelvis_pos = player->GetBoneByID(pelvis);
	auto l_hip_pos = player->GetBoneByID(l_hip);
	auto l_knee_pos = player->GetBoneByID(l_knee);
	auto l_ankle_scale_pos = player->GetBoneByID(l_ankle_scale);
	auto l_foot_pos = player->GetBoneByID(l_foot);
	auto r_hip_pos = player->GetBoneByID(r_hip);
	auto r_knee_pos = player->GetBoneByID(r_knee);
	auto r_ankle_scale_pos = player->GetBoneByID(r_ankle_scale);
	auto r_foot_pos = player->GetBoneByID(r_foot);

	Vector2 head, spine, l_clavicle, l_upperarm, l_forearm, l_hand, r_clavicle, r_upperarm, r_forearm, r_hand, pelvis, l_hip, l_knee, l_ankle_scale, l_foot, r_hip, r_knee, r_ankle_scale, r_foot;
	if (w2s(head_pos, head) &&
		w2s(spine4_pos, spine) &&
		w2s(l_clavicle_pos, l_clavicle) &&
		w2s(l_upperarm_pos, l_upperarm) &&
		w2s(l_forearm_pos, l_forearm) &&
		w2s(l_hand_pos, l_hand) &&
		w2s(r_clavicle_pos, r_clavicle) &&
		w2s(r_upperarm_pos, r_upperarm) &&
		w2s(r_forearm_pos, r_forearm) &&
		w2s(r_hand_pos, r_hand) &&
		w2s(pelvis_pos, pelvis) &&
		w2s(l_hip_pos, l_hip) &&
		w2s(l_knee_pos, l_knee) &&
		w2s(l_ankle_scale_pos, l_ankle_scale) &&
		w2s(l_foot_pos, l_foot) &&
		w2s(r_hip_pos, r_hip) &&
		w2s(r_knee_pos, r_knee) &&
		w2s(r_ankle_scale_pos, r_ankle_scale) &&
		w2s(r_foot_pos, r_foot)) {

		Render::Object.LineP(head, spine, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(spine, l_upperarm, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(l_upperarm, l_forearm, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(l_forearm, l_hand, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(spine, r_upperarm, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(r_upperarm, r_forearm, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(r_forearm, r_hand, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(spine, pelvis, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(pelvis, l_hip, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(l_hip, l_knee, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(l_knee, l_foot, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(pelvis, r_hip, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(r_hip, r_knee, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
		Render::Object.LineP(r_knee, r_foot, FLOAT4TOD3DCOLOR(Colors::SkeletonColor), 1.5f, true);
	}
}
void CornerBox(float Entity_x, float Entity_y, float Entity_w, float Entity_h, D2D1::ColorF color) {
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / PlayerEsp::cornerfloat, Entity_y }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x + Entity_w / PlayerEsp::cornerfloat, Entity_y }, color);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / PlayerEsp::cornerfloat }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y }, { Entity_x,Entity_y + Entity_h / PlayerEsp::cornerfloat }, color);

	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / PlayerEsp::cornerfloat, Entity_y }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { (Entity_x + Entity_w) - Entity_w / PlayerEsp::cornerfloat, Entity_y }, color);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / PlayerEsp::cornerfloat }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y }, { Entity_x + Entity_w,Entity_y + Entity_h / PlayerEsp::cornerfloat }, color);

	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / PlayerEsp::cornerfloat, Entity_y + Entity_h }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { (Entity_x + Entity_w) - Entity_w / PlayerEsp::cornerfloat, Entity_y + Entity_h }, color);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / PlayerEsp::cornerfloat }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x + Entity_w, Entity_y + Entity_h }, { Entity_x + Entity_w,(Entity_y + Entity_h) - Entity_h / PlayerEsp::cornerfloat }, color);

	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / PlayerEsp::cornerfloat, Entity_y + Entity_h }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x + Entity_w / PlayerEsp::cornerfloat, Entity_y + Entity_h }, color);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / PlayerEsp::cornerfloat }, D2D1::ColorF::Black, 3.f);
	Render::Object.Line({ Entity_x, Entity_y + Entity_h }, { Entity_x,(Entity_y + Entity_h) - Entity_h / PlayerEsp::cornerfloat }, color);
}
    bool OOF(BasePlayer* ply) {
        Vector3 pos = ply->GetBoneByID(head);
        Vector2 screen;

        if (!w2s(pos, screen))
            return true;

        float num = Math::Distance_2D(screen_center, screen);
        return num > 1000.f;
    }
	void OOF(BasePlayer* ply, ImColor color) {
		if (!ply) return;
		if (!LocalPlayer.BasePlayer->isCached()) return;

		if (PlayerEsp::oof_arrows) {
			if (OOF(ply)) {
				Vector3 local = LocalPlayer.BasePlayer->GetBoneByID(head);
				float y = local.x - ply->GetBoneByID(head).x;
				float x = local.z - ply->GetBoneByID(head).z;
				Vector2 eulerAngles = LocalPlayer.BasePlayer->GetVA();
				float num = atan2(y, x) * 57.29578f - 180.f - eulerAngles.y;
				Vector2 point = Render::Object.CosTanSinLineH(num, 5.f, screen_center.x, screen_center.y, 200.f);
				Vector2 tp0 = Render::Object.CosTanSinLineH(num, 5.f, Global::ScreenWidth / 2, Global::ScreenHigh / 2, 150.f);
				Vector2 tp1 = Render::Object.CosTanSinLineH(num + 2.f, 5.f, Global::ScreenWidth / 2, Global::ScreenHigh / 2, 140.f);
				Vector2 tp2 = Render::Object.CosTanSinLineH(num - 2.f, 5.f, Global::ScreenWidth / 2, Global::ScreenHigh / 2, 140.f);

				/*Renderer::RectangleFillPoint(point, 9.f, 9.f, D2D1::ColorF(0.06f, 0.06f, 0.06f, 0.94f));
				Renderer::RectanglePoint(point, 9.f, 9.f, color);*/
				ImGui::GetBackgroundDrawList()->AddTriangleFilled({ tp0.x,tp0.y }, { tp1.x,tp1.y }, { tp2.x,tp2.y }, color);
			}

		}
	}
class CBounds {
public:
	Vector3 center;
	Vector3 extents;
};
typedef bool(__stdcall* IsDucked)(BasePlayer*);
void Box3D(BasePlayer* player, D2D1::ColorF color) {
	CBounds bounds = CBounds();

	IsDucked ducked = (IsDucked)(Storage::gBase + O::BasePlayer::IsDucked);
	if (ducked(player)) {
		bounds.center = player->GetBoneByID(l_foot).midPoint(player->GetBoneByID(r_foot)) + Vector3(0.0f, 0.55f, 0.0f);
		bounds.extents = Vector3(0.4f, 0.65f, 0.4f);
	}
	else {
		if (player->HasFlags(PlayerFlags::Wounded) || player->HasFlags(PlayerFlags::Sleeping)) {
			bounds.center = player->GetBoneByID(pelvis);
			bounds.extents = Vector3(0.9f, 0.2f, 0.4f);
		}
		else {
			bounds.center = player->GetBoneByID(l_foot).midPoint(player->GetBoneByID(r_foot)) + Vector3(0.0f, 0.85f, 0.0f);
			bounds.extents = Vector3(0.4f, 0.9f, 0.4f);
		}
	}

	float y = Math::EulerAngles(player->eyest()->get_rotation()).y;
	Vector3 center = bounds.center;
	Vector3 extents = bounds.extents;
	Vector3 frontTopLeft = Math::RotatePoint(center, Vector3(center.x - extents.x, center.y + extents.y, center.z - extents.z), y);
	Vector3 frontTopRight = Math::RotatePoint(center, Vector3(center.x + extents.x, center.y + extents.y, center.z - extents.z), y);
	Vector3 frontBottomLeft = Math::RotatePoint(center, Vector3(center.x - extents.x, center.y - extents.y, center.z - extents.z), y);
	Vector3 frontBottomRight = Math::RotatePoint(center, Vector3(center.x + extents.x, center.y - extents.y, center.z - extents.z), y);
	Vector3 backTopLeft = Math::RotatePoint(center, Vector3(center.x - extents.x, center.y + extents.y, center.z + extents.z), y);
	Vector3 backTopRight = Math::RotatePoint(center, Vector3(center.x + extents.x, center.y + extents.y, center.z + extents.z), y);
	Vector3 backBottomLeft = Math::RotatePoint(center, Vector3(center.x - extents.x, center.y - extents.y, center.z + extents.z), y);
	Vector3 backBottomRight = Math::RotatePoint(center, Vector3(center.x + extents.x, center.y - extents.y, center.z + extents.z), y);

	Vector2 frontTopLeft_2d, frontTopRight_2d, frontBottomLeft_2d, frontBottomRight_2d, backTopLeft_2d, backTopRight_2d, backBottomLeft_2d, backBottomRight_2d;
	if (w2s(frontTopLeft, frontTopLeft_2d) &&
		w2s(frontTopRight, frontTopRight_2d) &&
		w2s(frontBottomLeft, frontBottomLeft_2d) &&
		w2s(frontBottomRight, frontBottomRight_2d) &&
		w2s(backTopLeft, backTopLeft_2d) &&
		w2s(backTopRight, backTopRight_2d) &&
		w2s(backBottomLeft, backBottomLeft_2d) &&
		w2s(backBottomRight, backBottomRight_2d)) {

		Render::Object.LineP(frontTopLeft_2d, frontTopRight_2d, color, 1.5f, true);
		Render::Object.LineP(frontTopRight_2d, frontBottomRight_2d, color, 1.5f, true);
		Render::Object.LineP(frontBottomRight_2d, frontBottomLeft_2d, color, 1.5f, true);
		Render::Object.LineP(frontBottomLeft_2d, frontTopLeft_2d, color, 1.5f, true);//1.5f
		Render::Object.LineP(backTopLeft_2d, backTopRight_2d, color, 1.5f, true);
		Render::Object.LineP(backTopRight_2d, backBottomRight_2d, color, 1.5f, true);
		Render::Object.LineP(backBottomRight_2d, backBottomLeft_2d, color, 1.5f, true);
		Render::Object.LineP(backBottomLeft_2d, backTopLeft_2d, color, 1.5f, true);
		Render::Object.LineP(frontTopLeft_2d, backTopLeft_2d, color, 1.5f, true);
		Render::Object.LineP(frontTopRight_2d, backTopRight_2d, color, 1.5f, true);
		Render::Object.LineP(frontBottomRight_2d, backBottomRight_2d, color, 1.5f, true);
		Render::Object.LineP(frontBottomLeft_2d, backBottomLeft_2d, color, 1.5f, true);
	}
}
namespace string
{

	inline char buffer[512];

	inline const char* format(const char* fmt, ...) {
		va_list args;
		va_start(args, fmt);
		LI_FIND(vsnprintf)(buffer, 512, fmt, args);
		va_end(args);
		return buffer;
	}
}

namespace Vars1 {
	namespace Radar {
		bool ShowRadarNpc = false;
		bool Enable1 = false;
		bool Enable = false;
		bool ShowRadarBackground = false;
		bool ShowRadarPlayer = false;
		bool ShowRadarSleeper = false;
		float Pos_X = 0;
		float Pos_Y = 0;
		float Radar_Size = 200.f;
		float Radar_Range = 300.f;
		bool EnableDinamicRadar = false;
		bool ShowRadarNpcname = false;
	}
}


double deg2rad(double degrees) {
	return degrees * 4.0 * atan(1.0) / 180.0;
}

inline D2D1::ColorF ConverToRGB(float R, float G, float B)
{
	return (D2D1::ColorF::ColorF(R / 255.f, G / 255.f, B / 255.f));
}
//typedef bool(__stdcall* IsDucked)(BasePlayer*);
void ESP(BasePlayer* BP, BasePlayer* LP)
{
	bool PlayerSleeping = BP->HasFlags(16);
	bool PlayerWounded = BP->HasFlags(64);
	if (PlayerEsp::sleeperignore && PlayerSleeping)
		return;

	if (PlayerEsp::skeleton && !BP->IsNpc())
		Skeleton(BP);

	Vector2 tempFeetR, tempFeetL;

	if (LocalPlayer.WorldToScreen(BP->GetBoneByID(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(BP->GetBoneByID(l_foot), tempFeetL))
	{
		if (tempFeetR.x == 0 && tempFeetR.y == 0) return;

		Vector2 ScreenPos;
		Vector2 tempHead;
		if (LocalPlayer.WorldToScreen(BP->GetBoneByID(jaw) + Vector3(0.f, 0.16f, 0.f), tempHead))
		{
			Vector2 leftTopCorner = tempHead - Vector2(0.4f, 0.f);
			Vector2 rightBottomCorner = tempFeetR;


			Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
			float Entity_h = tempHead.y - tempFeet.y;
			float w = Entity_h / 4;
			float Entity_x = tempFeet.x - w;
			float Entity_y = tempFeet.y;
			float Entity_w = Entity_h / 2;
			Vector3 middlePointWorld = BP->GetBoneByID(l_foot).midPoint(BP->GetBoneByID(r_foot));
			int CurPos = 0;
			auto* TargetPlayer = reinterpret_cast<BasePlayer*>(Storage::closestPlayer);
			Vector2 middlePointPlayerTop;
			Vector2 middlePointPlayerFeet;
			if (LocalPlayer.WorldToScreen(middlePointWorld + Vector3(0, 2, 0), middlePointPlayerTop) && LocalPlayer.WorldToScreen(middlePointWorld, middlePointPlayerFeet))
			{
				if (PlayerEsp::box) {
					if (PlayerEsp::boxstyle == 0 ) {
						if ((int)BP->GetHealth() > 0)
						{

							if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
							{
								CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::LimeGreen);
							}
							else
							{
								CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, FLOAT4TOD3DCOLOR(Colors::BoxColor));
							}
						}
						else
						{
							CornerBox(Entity_x, Entity_y, Entity_w, Entity_h, D2D1::ColorF::OrangeRed);
						}

					}
					if (PlayerEsp::boxstyle == 1 ) {
						if ((int)BP->GetHealth() > 0)
						{
							if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
							{
								Box3D(BP, D2D1::ColorF::LimeGreen);
							}
							else
							{
								Box3D(BP, FLOAT4TOD3DCOLOR(Colors::BoxColor));
							}
						}
						else
						{
							Box3D(BP, D2D1::ColorF::OrangeRed);
						}
					}
				}

				if (PlayerEsp::healthbar)
				{
					float maxheal = 100.f;
					int health = BP->GetHealth();
					Render::Object.FillRectangle({ Entity_x + (Entity_w / 2) + -50, Entity_y + 30 }, { 100, 5 }, D2D1::ColorF::Black);
					//Render::Object.FillRectangle({ Entity_x + (Entity_w / 2) + -49, Entity_y + 32  }, { 99 * (health / maxheal), 7 }, D2D1::ColorF::Yellow);
					if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), BP->GetBoneByID(r_foot)) < 301)
					{
						if ((int)BP->GetHealth() <= 33)
						{
							Render::Object.FillRectangle({ Entity_x + (Entity_w / 2) + -50, Entity_y + 30 }, { 100 * (health / maxheal), 5 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 34 && (int)BP->GetHealth() <= 66)
						{
							Render::Object.FillRectangle({ Entity_x + (Entity_w / 2) + -50, Entity_y + 30 }, { 100 * (health / maxheal), 5 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 67)
						{
							Render::Object.FillRectangle({ Entity_x + (Entity_w / 2) + -50, Entity_y + 30 }, { 100 * (health / maxheal), 5 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
						}
					}
				}
				if (PlayerEsp::healthbar1)
				{
					int health = (int)BP->GetHealth();
					float maxheal = 100.f;
					if ((int)Math::Calc3D_Dist(LocalPlayer.BasePlayer->GetBoneByID(head), BP->GetBoneByID(head)) < 201)
					{
						if ((int)BP->GetHealth() <= 33)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 34 && (int)BP->GetHealth() <= 66)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
						}
						if ((int)BP->GetHealth() >= 67)
						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h * (health / maxheal) }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
						}
						Render::Object.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 5, Entity_h }, D2D1::ColorF::Black, 0.5f);
					}
				}
				if (PlayerEsp::healthbar2) {
					int health = (int)BP->GetHealth();
					float maxheal = 100.f;
					//float maxheal = (BP->IsNpc() ? 300.f : 100.f);
					if ((int)BP->GetHealth() <= 33) {
						Render::Object.FillRectangle(Vector2{ middlePointPlayerFeet.x - 15, middlePointPlayerFeet.y + CurPos + 5 }, Vector2{ 30 * (health / maxheal), 3 }, D2D1::ColorF(255.f, 0.f, 0.f, 0.8f));
					}
					if ((int)BP->GetHealth() >= 34 && (int)BP->GetHealth() <= 66) {
						Render::Object.FillRectangle(Vector2{ middlePointPlayerFeet.x - 15, middlePointPlayerFeet.y + CurPos + 5 }, Vector2{ 30 * (health / maxheal), 3 }, D2D1::ColorF(255.f, 202.f, 0.f, 0.8f));
					}
					if ((int)BP->GetHealth() >= 67) {
						Render::Object.FillRectangle(Vector2{ middlePointPlayerFeet.x - 15, middlePointPlayerFeet.y + CurPos + 5 }, Vector2{ 30 * (health / maxheal), 3 }, D2D1::ColorF(0.f, 255.f, 0.f, 0.8f));
					}
					Render::Object.Rectangle(Vector2{ middlePointPlayerFeet.x - 15, middlePointPlayerFeet.y + CurPos + 5 }, Vector2{ 30, 3 }, D2D1::ColorF::Black, 0.5f);
				}
				if (PlayerEsp::Namedistheath1)
				{
					Vector2 tempFeetR, tempFeetL, tempHead;

					if (LocalPlayer.WorldToScreen(BP->GetBoneByID(r_foot), tempFeetR) && LocalPlayer.WorldToScreen(BP->GetBoneByID(l_foot), tempFeetL) && LocalPlayer.WorldToScreen(BP->GetBoneByID(jaw) + Vector3(0.f, 0.17f, 0.f), tempHead))
					{
						Vector2 tempFeet = (tempFeetR + tempFeetL) / 2.f;
						float Entity_h = tempHead.y - tempFeet.y;
						float w = Entity_h / 4;
						float Entity_x = tempFeet.x - w;
						float Entity_y = tempFeet.y;
						float Entity_w = Entity_h / 2;
						float flHeight = Entity_h / PlayerEsp::separators;
						float health = BP->GetHealth();
						float maxheal = 100.f;

						D2D1::ColorF HpColor = D2D1::ColorF::Green;
						if (health > 75)
							HpColor = D2D1::ColorF::Green;
						else
						{
							if (health < 45)
								HpColor = D2D1::ColorF::Red;
							else
								HpColor = D2D1::ColorF::Orange;
						}

						{
							Render::Object.FillRectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 4 ,Entity_h * (health / maxheal) }, HpColor);
							Render::Object.Rectangle(Vector2{ Entity_x + Entity_w - 8.f, Entity_y }, Vector2{ 4 ,Entity_h }, D2D1::ColorF::Black, 0.5f);
							for (int i = 1; i < PlayerEsp::separators; i++)
								Render::Object.Line(Vector2{ Entity_x + Entity_w - 8.f, Entity_y + i * flHeight }, Vector2{ Entity_x + Entity_w - 4.f ,Entity_y + i * flHeight }, D2D1::ColorF::Black());
							int i = i - 1;
						}
					}
				}
				ImU32 color = ImColor(0, 255, 0);
				if (LocalPlayer.BasePlayer->is_visible()) {
					color = FLOAT4TOD3DCOLOR(Colors::boxvisible);
				}
				else {
					color = FLOAT4TOD3DCOLOR(Colors::boxnotvisible);
				}
				if (PlayerEsp::name)// а здесь я зделал цвет визибл инвизибл но не тестил
				{
					int health = (int)BP->GetHealth();
					wchar_t name[64];
					_swprintf(name, L"%s  [%dM]", BP->GetName(), (int)Math::Calc3D_Dist(LP->GetBoneByID(head), BP->GetBoneByID(head)));
					Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 15.f }, name, color, true, true);// 15.f//FLOAT4TOD3DCOLOR(Colors::NameColor)

					CurPos += 15;
				}
				if (PlayerEsp::weapon)///я такой гений что BP->InNps крашило и я нахуй вырезал залупу
				{
					int health = (int)BP->GetHealth();
					const wchar_t* ActiveWeaponName;
					WeaponData* ActWeapon = BP->GetActiveWeapon();
					ActiveWeaponName = ActWeapon->GetName();
					if (!ActWeapon)
					{

						ActiveWeaponName = L"None";
					}
					else
					{
						ActiveWeaponName = ActWeapon->GetName();
					}

					Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 30.f }, ActiveWeaponName, FLOAT4TOD3DCOLOR(Colors::WeaponColor), true, true);//30

				}

				if (PlayerEsp::wounded)
				{
					bool PlayerWounded = BP->HasFlags(64);
					wchar_t wounded[64];
					if (!PlayerWounded) {
						_swprintf(wounded, L"", BP->HasFlags(64));
						Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 45.f }, wounded, FLOAT4TOD3DCOLOR(Colors::Wounded), true, true);
					}
					else {
						_swprintf(wounded, L"*Wounded*", BP->HasFlags(64));
						Render::Object.String(Vector2{ middlePointPlayerFeet.x, middlePointPlayerFeet.y + 60.f }, wounded, FLOAT4TOD3DCOLOR(Colors::Wounded), true, true);//60
					}
				}
				if (PlayerEsp::tracers && !PlayerSleeping)
				{
					static float screenX = GetSystemMetrics(SM_CXSCREEN);
					static float screenY = GetSystemMetrics(SM_CYSCREEN);
					static Vector2 startPos = Vector2(screenX / 2.f, screenY - 2.f);
					if ((int)BP->GetHealth() > 0)
					{
						if (LocalPlayer.BasePlayer->IsTeamMate(BP->GetSteamID()))
						{
							Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, D2D1::ColorF::LimeGreen, 0.5f);
						}
						else
						{
							Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, FLOAT4TOD3DCOLOR(Colors::Target_text), 0.5f);
						}
					}
					else
					{
						Render::Object.Line(startPos, Vector2{ Entity_x + Entity_w / 2.f, Entity_y }, D2D1::ColorF::Red, 0.5f);
					}
				}
			}
		}
	}
}
	
inline void RenderActiveSlot(BasePlayer* player)
{
	if (!player->IsNpc() && !player->IsDead()) {
		ImGui::SetNextWindowSize(ImVec2(160, 180));
		ImGui::Begin("EEE", NULL, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration);
		ImVec2 pos = ImGui::GetWindowPos();
		const float Height = 180.f;
		const float With = 160.f;
		Render::Object.FillRoundedRectangle({ pos.x, pos.y }, { With, Height }, D2D1::ColorF::Black, 2);
		Render::Object.RenderString({ pos.x + (With / 2), pos.y + 5 }, player->GetName(), true, D2D1::ColorF::White);
		float Pos = 0;
		Render::Object.Line({ pos.x, pos.y + 20 }, { pos.x + With, pos.y + 20 }, D2D1::ColorF::White, 3);
		for (int i = 0; i < 6; i++)
		{
			WeaponData* GetWeaponInfo = player->GetWeaponInfo(i);
			if (GetWeaponInfo)
			{
				const wchar_t* Item = player->GetWeaponInfo(i)->GetName();
				if (wcslen(Item) < 20)
				{
					Render::Object.RenderString({ pos.x + (With / 2), pos.y + 40 + Pos }, Item, true);
				}
			}
			else
			{
				Render::Object.RenderString({ pos.x + (With / 2), pos.y + 40 + Pos }, L"---", true, D2D1::ColorF::White);
			}
			Pos += 15;
		}
		float health = player->GetHealth();
		float maxheal = 100.f;
		D2D1::ColorF::Enum colorf;
		if (health > 75 && health < 100)
			colorf = D2D1::ColorF::Lime;
		else if (health > 50 && health < 75)
			colorf = D2D1::ColorF::Yellow;
		else if (health > 25 && health < 50)
			colorf = D2D1::ColorF::Orange;
		else if (health > 0 && health < 25)
			colorf = D2D1::ColorF::Tomato;

		Render::Object.Rectangle({ pos.x + (With / 2) - 50, pos.y + 40 + Pos }, { 100, 15 }, D2D1::ColorF::LightSlateGray);
		Render::Object.FillRectangle({ pos.x + (With / 2) + -49, pos.y + 41 + Pos }, { 96 * (health / maxheal), 13 }, colorf);

		ImGui::End();
	}
}
inline void RadarPlayer(BasePlayer* player)
{
	if (LocalPlayer.BasePlayer && Vars1::Radar::Enable && (Vars1::Radar::ShowRadarPlayer || Vars1::Radar::ShowRadarSleeper))
	{
		if (!player->IsDead() && player->GetHealth() >= 0.2f)
		{
			ImGui::SetNextWindowSize(ImVec2(Vars1::Radar::Radar_Size, Vars1::Radar::Radar_Size));
			ImGui::Begin("xxx", NULL, ImGuiWindowFlags_NoBackground | ImGuiWindowFlags_NoDecoration);
			ImVec2 pos = ImGui::GetWindowPos();
			if (Vars1::Radar::ShowRadarBackground) {
				Render::Object.FillCircle({ pos.x + Vars1::Radar::Radar_Size / 2, pos.y + Vars1::Radar::Radar_Size / 2 }, D2D1::ColorF(0.f, 0.f, 0.f, 0.05f), Vars1::Radar::Radar_Size / 2);
			}
			Render::Object.Сircle({ pos.x + Vars1::Radar::Radar_Size / 2, pos.y + Vars1::Radar::Radar_Size / 2 }, ConverToRGB(91, 91, 91), Vars1::Radar::Radar_Size / 2, 0.7f);
			const Vector3 LocalPos = LocalPlayer.BasePlayer->GetPosition();
			const Vector3 PlayerPos = player->GetPosition();
			const float Distance = Math::Calc3D_Dist(LocalPos, PlayerPos);
			const float y = LocalPos.x - PlayerPos.x;
			const float x = LocalPos.z - PlayerPos.z;
			Vector2 LocalEulerAngles = LocalPlayer.BasePlayer->GetVA();
			const float num = atan2(y, x) * 57.29578f - 270.f - LocalEulerAngles.y;
			float PointPos_X = Distance * cos(num * 0.0174532924f);
			float PointPos_Y = Distance * sin(num * 0.0174532924f);
			PointPos_X = PointPos_X * (Vars1::Radar::Radar_Size / Vars1::Radar::Radar_Range) / 2.f;
			PointPos_Y = PointPos_Y * (Vars1::Radar::Radar_Size / Vars1::Radar::Radar_Range) / 2.f;
			Render::Object.FillCircle({ pos.x + Vars1::Radar::Radar_Size / 2, pos.y + Vars1::Radar::Radar_Size / 2 }, D2D1::ColorF::Green, 3);
			if (!player->HasFlags(16) && Vars1::Radar::ShowRadarPlayer)
			{
				if (Distance <= Vars1::Radar::Radar_Range)
				{
					Render::Object.FillCircle({ pos.x + Vars1::Radar::Radar_Size / 2.f + PointPos_X - 3.f, pos.y + Vars1::Radar::Radar_Size / 2.f + PointPos_Y - 3.f }, D2D1::ColorF::Red, 3.f);
				}
			}
			else if (player->HasFlags(16) && Vars1::Radar::ShowRadarSleeper)
			{
				if (Distance <= Vars1::Radar::Radar_Range)
				{
					Render::Object.FillCircle({ pos.x + Vars1::Radar::Radar_Size / 2.f + PointPos_X - 3.f, pos.y + Vars1::Radar::Radar_Size / 2.f + PointPos_Y - 3.f }, D2D1::ColorF::Yellow, 3.f);
				}
			}
			ImGui::End();
		}
	}
}

