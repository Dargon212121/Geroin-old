
using namespace ImGui;
ImFont* font_main;
ImFont* font_menu;
bool eng = true;
bool rus = false;
ImFont* icons = nullptr;
ImFont* info_big = nullptr;
ImFont* two = nullptr;
ImFont* three = nullptr;
ImFont* tabsf = nullptr;
ImFont* ee = nullptr;
static bool english = true;
ImVec2 pos;
ImDrawList* draw;
ImFont* rere = nullptr;
ImFont* tb = nullptr;
ImFont* g_pMenuFont;
extern ImFont* g_pMenuFont;
ImFont* tbl = nullptr;ImFont* NameFont;


ImFont* TabsFont;
ImFont* MainFont;
ImFont* IconsFont;
#include <mutex>
#include <iomanip>
#include <tchar.h>
#include "Font.h"
static const char* box_style[]{
	"Cornered",
	"3D",
};
static const char* anti_aim_yaw[]{
	"Down",
	"Up",
	"Norm",
};
ImGuiColorEditFlags ColorFlag = ImGuiColorEditFlags_NoLabel | ImGuiColorEditFlags_NoInputs | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_AlphaBar;
static bool sh_save_cfg = false;
static bool sh_load_cfg = false;
long getMils() {
	auto duration = std::chrono::system_clock::now().time_since_epoch();

	return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
}
namespace Anime {// а это хуета рендерит квадратик с нанимацией
	bool reverse = false;
	//bool done = false;
	int offset = 0;
	bool show_popup = false;

	void Popup(const char* text, int onScreenMils, bool* done) {
		if (!done)
			show_popup = true;

		ImGuiIO& io = ImGui::GetIO();
		int Wd = io.DisplaySize.x;

		static long oldTime = -1;

		ImGui::SetNextWindowPos(ImVec2(Wd - offset, 980));
		ImGui::Begin("PopUp Window", &show_popup, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoTitleBar);
		ImGui::BeginChild(xorstr("##linerender"), ImVec2(120, 1)); ImGui::EndChild();
		long currentTime_ms = getMils();

		ImVec2 txtSz = ImGui::CalcTextSize(text);
		ImGui::SetCursorPosY(ImGui::GetWindowHeight() / 2 - txtSz.y / 2);
		ImGui::Text(text);

		/*if (ImGui::Button("Close Me")) {
			reverse = true;
		}*/
		if (!reverse)
		{
			if (offset < ImGui::GetWindowWidth())
				offset += (ImGui::GetWindowWidth() + 5) * ((1000.0f / ImGui::GetIO().Framerate) / 90);

			if (offset >= ImGui::GetWindowWidth() && oldTime == -1)
			{

				oldTime = currentTime_ms;
			}
		}
		//ImGui::Text("ot: %d", oldTime);

		if (currentTime_ms - oldTime >= onScreenMils && oldTime != -1) // close after x mils
			reverse = true;

		if (reverse)
		{
			if (offset > 0)
				offset -= (ImGui::GetWindowWidth() + 5) * ((1000.0f / ImGui::GetIO().Framerate) / 90);
			if (offset <= 0)
			{
				offset = 0;
				reverse = false;
				*done = true;
				oldTime = -1;
				show_popup = false;

			}
		}

		ImGui::End();
	}
}

bool lang(const char* label)
{
	ImGuiWindow* window = ImGui::GetCurrentWindow();
	if (window->SkipItems)
		return false;

	ImGuiContext& g = *GImGui;
	const ImGuiStyle& style = g.Style;
	const ImGuiID id = window->GetID(label);
	const ImVec2 label_size = ImGui::CalcTextSize(label, NULL, true);

	ImVec2 pos = window->DC.CursorPos;
	ImVec2 size = ImGui::CalcItemSize(label_size, label_size.x + style.FramePadding.x * 2.0f, label_size.y + style.FramePadding.y * 2.0f);

	const ImRect bb(pos, pos + size);
	ImGui::ItemSize(size, style.FramePadding.y);
	if (!ImGui::ItemAdd(bb, id))
		return false;

	bool hovered, held;
	bool pressed = ImGui::ButtonBehavior(bb, id, &hovered, &held, NULL);

	if (hovered || held)
		ImGui::SetMouseCursor(0);

	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(129 / 255.f, 129 / 255.f, 129 / 255.f, 255 / 255.f));
	ImGui::RenderText(ImVec2(bb.Min.x, bb.Min.y), label);
	ImGui::PopStyleColor();

	return pressed;
}

void InitImGui()
{
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 12.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());

	ImFontConfig font_config;
	font_config.OversampleH = 1;
	font_config.OversampleV = 1;
	font_config.PixelSnapH = true;

	static const ImWchar ranges[] =
	{
		0x0020, 0x00FF,
		0x0400, 0x044F,
		0,
	};

	ImFont* TabsFont;
	ImFont* MenuFont;
	ImFont* NameFont;
	ImFont* first;
	ImFont* IconsFont;







	io.Fonts->AddFontDefault();
	TabsFont = io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 15.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	NameFont = io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 19.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	MenuFont = io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 14.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFontConfig icons_config; icons_config.MergeMode = true; icons_config.PixelSnapH = true;
	io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 15.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 19.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 14.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	ImFont* font = io.Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	IM_ASSERT(font != NULL);

	// Our state
	auto clear_color = ImVec4(0.1f, 0.1f, 0.1f, 1.00f);

	// Main loop
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));

	ImGuiStyle* style = &ImGui::GetStyle();
	ImVec4* colors = style->Colors;
	style->WindowPadding = ImVec2(0, 0);
	style->FramePadding = ImVec2(4, 3);
	style->ItemSpacing = ImVec2(0, 10);
	style->ItemInnerSpacing = ImVec2(4, 4);
	style->IndentSpacing = 21;
	style->ScrollbarSize = 1;
	style->GrabMinSize = 1;
	style->WindowBorderSize = 1;
	style->ChildBorderSize = 1;
	style->PopupBorderSize = 1;
	style->FrameBorderSize = 1;
	style->WindowRounding = 0;
	style->ChildRounding = 0;
	style->FrameRounding = 0;
	style->PopupRounding = 0;
	style->ScrollbarRounding = 0;
	style->GrabRounding = 0;
	style->SelectableTextAlign = ImVec2(0.5f, 0.5f);


	colors[ImGuiCol_Text] = ImVec4(0.900000f, 0.900000f, 0.900000f, 1.000000f);
	colors[ImGuiCol_TextDisabled] = ImVec4(0.600000f, 0.600000f, 0.600000f, 1.000000f);
	colors[ImGuiCol_WindowBg] = ImVec4(0.129412f, 0.133333f, 0.137255f, 0.992157f);
	colors[ImGuiCol_ChildBg] = ImVec4(0.000000f, 0.000000f, 0.000000f, 0.000000f);
	colors[ImGuiCol_PopupBg] = ImVec4(0.110000f, 0.110000f, 0.140000f, 0.920000f);
	colors[ImGuiCol_Border] = ImVec4(0.501961f, 0.501961f, 0.501961f, 0.011765f);
	colors[ImGuiCol_BorderShadow] = ImVec4(0.000000f, 0.000000f, 0.000000f, 0.000000f);
	colors[ImGuiCol_FrameBg] = ImVec4(0.430000f, 0.430000f, 0.430000f, 0.390000f);
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.470000f, 0.470000f, 0.690000f, 0.400000f);
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.420000f, 0.410000f, 0.640000f, 0.690000f);
	colors[ImGuiCol_TitleBg] = ImVec4(0.270000f, 0.270000f, 0.540000f, 0.830000f);
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.320000f, 0.320000f, 0.630000f, 0.870000f);
	colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.400000f, 0.400000f, 0.800000f, 0.200000f);
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.400000f, 0.400000f, 0.550000f, 0.800000f);
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.200000f, 0.250000f, 0.300000f, 0.600000f);
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.400000f, 0.400000f, 0.800000f, 0.300000f);
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.400000f, 0.400000f, 0.800000f, 0.400000f);
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.410000f, 0.390000f, 0.800000f, 0.600000f);
	colors[ImGuiCol_CheckMark] = ImVec4(0.900000f, 0.900000f, 0.900000f, 0.500000f);
	colors[ImGuiCol_SliderGrab] = ImVec4(1.000000f, 1.000000f, 1.000000f, 0.300000f);
	colors[ImGuiCol_SliderGrabActive] = ImVec4(0.410000f, 0.390000f, 0.800000f, 0.600000f);
	colors[ImGuiCol_Button] = ImVec4(0.350000f, 0.400000f, 0.610000f, 0.620000f);
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.400000f, 0.480000f, 0.710000f, 0.790000f);
	colors[ImGuiCol_ButtonActive] = ImVec4(0.460000f, 0.540000f, 0.800000f, 1.000000f);
	colors[ImGuiCol_Header] = ImVec4(0.400000f, 0.400000f, 0.900000f, 0.450000f);
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.450000f, 0.450000f, 0.900000f, 0.800000f);
	colors[ImGuiCol_HeaderActive] = ImVec4(0.530000f, 0.530000f, 0.870000f, 0.800000f);
	colors[ImGuiCol_Separator] = ImVec4(0.500000f, 0.500000f, 0.500000f, 0.600000f);
	colors[ImGuiCol_SeparatorHovered] = ImVec4(0.600000f, 0.600000f, 0.700000f, 1.000000f);
	colors[ImGuiCol_SeparatorActive] = ImVec4(0.700000f, 0.700000f, 0.900000f, 1.000000f);
	colors[ImGuiCol_ResizeGrip] = ImVec4(1.000000f, 1.000000f, 1.000000f, 0.160000f);
	colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.780000f, 0.820000f, 1.000000f, 0.600000f);
	colors[ImGuiCol_ResizeGripActive] = ImVec4(0.780000f, 0.820000f, 1.000000f, 0.900000f);
	colors[ImGuiCol_TextSelectedBg] = ImVec4(0.000000f, 0.000000f, 1.000000f, 0.350000f);
	colors[ImGuiCol_DragDropTarget] = ImVec4(1.000000f, 1.000000f, 0.000000f, 0.900000f);






	ImGui_ImplWin32_Init(window);
	ImGui_ImplDX11_Init(pDevice, pContext);
}
void apply_fonts() {
	ImGui::CreateContext();
	font_main = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 18.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
	font_menu = ImGui::GetIO().Fonts->AddFontFromMemoryTTF(TopFont, sizeof(TopFont), 14.f, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
}

void HelpMarker(const char* desc) {
	ImGui::TextDisabled("[?]");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(desc);
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}
void HelpCheckbox(const char* desc, bool* v, const char* helptext) { ImGui::Checkbox(desc, v); ImGui::SameLine(); HelpMarker(helptext); }

#include <mutex>
#include <tchar.h>
#include "FontAwesomeTttf.h"
#include "Screen.h"
//#include "AutherLibrary.h"
void invis()
{
	auto flags = ImGuiWindowFlags_NoTitleBar | NULL | NULL | NULL | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | NULL | NULL | NULL;
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
	{
		ImGui::SetNextWindowPos({ 0,0 });
		ImGui::SetNextWindowSize(ImGui::GetIO().DisplaySize);
		static float Alpha = 0.0f;
		int screenWidthX = GetSystemMetrics(SM_CXSCREEN);
		int screenHeightY = GetSystemMetrics(SM_CYSCREEN);
		auto back = ImGui::GetBackgroundDrawList();
		if (Alpha < 0.65f)
			Alpha += 0.005f;
		back->AddRectFilled(ImVec2(0, 0), ImVec2(screenWidthX, screenHeightY), ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, Alpha)));
		ImGui::PushStyleColor(ImGuiCol_WindowBg, { 0,0,0,0 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);
		ImGui::Begin("##menu2", nullptr, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove);
		{

				dot_draw();

		}
		ImGui::End();
		ImGui::PopStyleColor();
		ImGui::PopStyleVar();

	}ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0,0 });
	ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0);

	ImGui::SetNextWindowSize({ 545,440 });
    #include <winnt.h>
	ImGui::Begin("##menu", nullptr, flags);
	{
		float dpi_scale = 1.f;


			ImDrawList* draw = ImGui::GetWindowDrawList();
			ImVec2 pos = ImGui::GetWindowPos();

			static int x = 545 * dpi_scale, y = 355 * dpi_scale;;
			
			draw->AddText(ImVec2(pos.x + 15, pos.y + 17), ImColor(Colors::TextColor2), "Geroin ");/// ну типо под героином пастил
			//draw->AddText(ImVec2(pos.x + 15, pos.y + 17), ImColor(32, 142, 226), "                           Beta");


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
		auto t = std::chrono::system_clock::now();
		std::time_t time = std::chrono::system_clock::to_time_t(t);
		std::string time_str = std::ctime(&time);
		time_str.resize(time_str.size() - 1);
		//ImGui::Text(time_str.c_str());
		//draw->AddText({ pos.x + 710 - ImGui::CalcTextSize(time_str.c_str()).x,pos.y + 15 + 15 - ImGui::CalcTextSize(time_str.c_str()).y / 2 }, ImColor(255, 255, 255), time_str.c_str());
		//draw->AddText({ pos.x + 710 - ImGui::CalcTextSize("https://discord.gg/BaGZhYD4NF").x,pos.y + 470 + 10 - ImGui::CalcTextSize("https://discord.gg/BaGZhYD4NF").y / 2 }, ImColor(134, 156, 255, 0.8), "https://discord.gg/BaGZhYD4NF");

		ImDrawList* windowDrawList = ImGui::GetWindowDrawList();


			//This function was not made by me (xo1337), i found it off unknown cheats.
			float rainbowSpeed = 0.00060;
			static float staticHue = 0;
			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			ImVec2 panelPos = ImGui::GetWindowPos();
			staticHue -= rainbowSpeed;
			if (staticHue < -1.f) staticHue += 1.f;
			for (int i = 0; i < 1200; i++)
			{
				float hue = staticHue + (1.f / (float)1200) * i;
				if (hue < 0.f) hue += 1.0f;
				ImColor cRainbow = ImColor::HSV(hue, 1.f, 1.f);
				draw_list->AddRectFilled(ImVec2(panelPos.x + i, panelPos.y + 2), ImVec2(panelPos.x + i + 1, panelPos.y + 4), cRainbow);
			}
	//	draw->AddRectFilled(ImVec2(pos.x + 0, pos.y + 0), ImVec2(pos.x + 830, pos.y + 3), ImColor(r, g, b, 111.f));
		//draw->AddText({ pos.x + 720 - ImGui::CalcTextSize("____________________________________________________________________________________________________________________").x,pos.y + 14 + 30 - ImGui::CalcTextSize("____________________________________________________________________________________________________________________").y / 2 }, ImColor(r, g, b, 111.f), "____________________________________________________________________________________________________________________");
		//draw->AddRectFilled(ImVec2(pos.x + 3, pos.y + 800), ImVec2(pos.x +  70, pos.y + 66), ImColor(47, 156, 246, 255), 0, 15);

		static int tab = 17;
		static int subtab = 18;

		ImGui::SetCursorPos({ 170,413 });
		ImGui::BeginGroup();
		{
			if (tab == 0)
			{

				if (SubTab((english ? "Legit" : u8"Легит"), ImVec2(60, 25), subtab == 1 ? true : false))
					subtab = 1;
				ImGui::SetCursorPos({ 233,413 });
				if (SubTab((english ? "Rage" : u8"Рейдж"), ImVec2(60, 25), subtab == 2 ? true : false))
					subtab = 2;
				ImGui::SetCursorPos({ 296,413 });
				if (SubTab((english ? "Weapon" : u8"Отдельн"), ImVec2(60, 25), subtab == 3 ? true : false))
					subtab = 3;

			}
			if (tab == 1)
			{
				if (SubTab((english ? "Player " : u8"Игроки "), ImVec2(64, 25), subtab == 4 ? true : false))
					subtab = 4;
				ImGui::SetCursorPos({ 233,413 });
				if (SubTab((english ? "Other  " : u8"Отдельн "), ImVec2(70, 25), subtab == 6 ? true : false))
					subtab = 6;
			}
			if (tab == 2)
			{
				if (SubTab((english ? "Player" : u8"Игроки"), ImVec2(60, 25), subtab == 8 ? true : false))
					subtab = 8;
				ImGui::SetCursorPos({ 233,413 });
				if (SubTab((english ? "Weapon" : u8"Оружие"), ImVec2(60, 25), subtab == 9 ? true : false))
					subtab = 9;
			}
			if (tab == 8)
			{
				if (SubTab((english ? "Colorvisual" : u8"ЦветаВизуал"), ImVec2(76, 25), subtab == 8 ? true : false))
					subtab = 8;


			}
			if (tab == 5)
			{


			}

			if (tab == 17)
			{
				if (SubTab((";("), ImVec2(60, 25), subtab == 18 ? true : false))
					subtab = 18;


			}
			if (tab == 20)
			{
				if (SubTab(("Config"), ImVec2(60, 25), subtab == 100 ? true : false))
					subtab = 100;


			}
			if (tab == 9)
			{
				if (SubTab(("Secret"), ImVec2(60, 25), subtab == 19 ? true : false))
					subtab = 19;


			}
	
		}
		ImGui::EndGroup();
		ImGui::SetCursorPos({ 10,63 });
		ImGui::BeginGroup();
		{
			if (Tab("", ("AimBot"), ("Psilent"), ImVec2(96, 50), tab == 0 ? true : false))
				tab = 0;
			ImGui::SameLine();
			ImGui::SetCursorPos({ 10,110 });
			if (Tab("", ("Visuals"), ("ESP"), ImVec2(96, 50), tab == 1 ? true : false))
				tab = 1;
			ImGui::SameLine();
			ImGui::SetCursorPos({ 10,160 });
			if (Tab("", ("Misc"), ("Player"), ImVec2(95, 50), tab == 2 ? true : false))
				tab = 2;
			ImGui::SameLine();
			ImGui::SetCursorPos({ 10,210 });
			if (Tab("", ("Colors"), ("ColVisu"), ImVec2(95, 50), tab == 8 ? true : false))
				tab = 8;
			ImGui::SameLine();
			ImGui::SetCursorPos({ 10,260 });
			if (Tab("", ("Config"), (""), ImVec2(95, 50), tab == 20 ? true : false))
				tab = 20;
			ImGui::SameLine();
			ImGui::SetCursorPos({ 10,310 });
			if (Tab("", ("Menu"), ("Other"), ImVec2(95, 50), tab == 9 ? true : false))
				tab = 9;
			ImGui::SameLine();
			if (Tab("", (""), (""), ImVec2(99, 1), tab == 17 ? true : false))
				tab = 17;
			ImGui::SetCursorPos({ 10,419 });
			//ImGui::SetCursorPos(ImVec2(670, 50 / 2 - ImGui::CalcTextSize(english ? "EN" : "RU").y / 2));
			if (lang(english ? "" : "RU")) english = !english;

		}
		ImGui::EndGroup();


		ImGui::SetCursorPos({ 140,4 });
		ImGui::BeginGroup();
		{
			ImGui::BeginChild("items", { 400, 395 });
			{
				//draw->AddRectFilled(ImGui::GetWindowPos(), { ImGui::GetWindowPos().x + 530,ImGui::GetWindowPos().y + 400 }, ImColor(30, 35, 40, 200), 8.f);
				
				ImGui::SetCursorPos({ 10,20 });
				ImGui::BeginGroup();
				{
					if (tab == 0)
					{ //bool RCS = false;
						if (subtab == 1)
						{   //Misc::chams2
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Checkbox((english ? "Enable" : u8"Включить"), &AimBot::Activate);
							Hotkey((english ? "Aim-Key" : u8"Кнопка Аима"), &Keys::aimKey, ImVec2(120.f, 0));
							ImGui::Checkbox((english ? "Draw Fov" : u8"Показать Радиус"), &AimBot::DrawFov);
							ImGui::Checkbox((english ? "Smooth" : u8"Плавность"), &AimBot::smooth);
							//Checkbox("Recoil system control", &AimBot::RCS);
							if (AimBot::smooth) {
							ImGui::SliderFloat((english ? "Smooth Factor" : u8"Выбор  Плавности"), &AimBot::smooth_factor, 0.f, 10.f);
							}
							ImGui::Checkbox((english ? "Fill Fov" : u8"Полный Радиус"), &AimBot::FillFov);
							if (AimBot::Activate || AimBot::pSilent) {
							ImGui::SliderFloat((english ? " Set Fov" : u8"Выбор  Радиуса"), &AimBot::Fov, 20.f, 1077.f);
							ImGui::SliderFloat(("Aim Dist"), &AimBot::Range, 0.f, 400.f);
							}
							ImGui::PopStyleColor();


						}
						if (subtab == 2)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Checkbox((english ? "pSilent" : u8"Псалент"), &AimBot::pSilent);
							if (AimBot::pSilent) {
							ImGui::SliderFloat((english ? " Set Fov" : u8"Выбор  Радиуса"), &AimBot::Fov, 20.f, 1077.f);
							ImGui::Checkbox((english ? "Draw Fov" : u8"Показать Радиус"), &AimBot::DrawFov);
							ImGui::SliderFloat(("Aim Dist"), &AimBot::Range, 0.f, 400.f);
							}
							ImGui::Checkbox((english ? "SilentHeli" : u8"Сайлент на Вертолёт"), &AimBot::SilentHeli);
							ImGui::PopStyleColor();
						}
						if (subtab == 3)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							if (ImGui::BeginCombo(english ? "CheckBox", "CheckBox" : u8"Кости", "Кости")) {
								ImGui::Checkbox(english ? "AlwaysHeadshot" : u8"Всегда Голова", &AimBot::AlwaysHeadshot);
								ImGui::Checkbox(english ? "AlwaysBody" : u8"Всегда Тело", &AimBot::pBody);
							//	ImGui::Checkbox(english ? "RandHitBoxs" : u8"Рандомизированный", &AimBot::randhitbox);
								ImGui::EndCombo();
							}
						//	ImGui::Checkbox((english ? "IgnoreNpc" : u8"Игнорировать Ботов"), &AimBot::IgnoreNpc);
							ImGui::Checkbox((english ? "IgnoreTeam" : u8"Игнорировать Тимейтов"), &AimBot::IgnoreTeam);
							ImGui::Checkbox((english ? "IgnoreSleepers" : u8"Игнорировать Спящих"), &AimBot::IgnoreSleepers);
							ImGui::PopStyleColor();
						}

					}
					if (tab == 1)
					{
						if (subtab == 4)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Text("Players Esp");
							ImGui::Checkbox((english ? "Name + dist" : u8"Никнейм и Дистанция"), &PlayerEsp::name);
							ImGui::Checkbox((english ? "Box" : u8"Коробка"), &PlayerEsp::box);
							if (PlayerEsp::box) {
								ImGui::PushItemWidth(100);
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Combo((english ? "" : u8""), &PlayerEsp::boxstyle, box_style, IM_ARRAYSIZE(box_style));
								ImGui::SliderFloat((english ? "Corner - float" : u8"Выбор Флоата"), &PlayerEsp::cornerfloat, 1.f, 7.f);
								
						
								ImGui::PopItemWidth();
							}
							ImGui::Spacing();
							ImGui::Spacing();
						
							ImGui::Checkbox((english ? "Skeleton" : u8"Скелет"), &PlayerEsp::skeleton);
							if (ImGui::BeginCombo(english ? "Healthbar", "Healthbar" : u8"Жизни", "Жизни")) {
								ImGui::Checkbox((english ? "healthbar-left" : u8"Жизни Слева"), &PlayerEsp::healthbar1);
								ImGui::Checkbox((english ? "healthbar-bottom" : u8"Жизни Снизу"), &PlayerEsp::healthbar2);
								//ImGui::Checkbox(("healthbar-Separator(left)"), &PlayerEsp::Namedistheath1);

	                     	End();
	                        }
							ImGui::Checkbox((english ? "Visualize Prediction" : u8"Визуальный Предикт Аимбота"), &Visuals::visualize_prediction);
						//	ImGui::Checkbox((english ? "oof_arrows" : u8"Чамсы"), &PlayerEsp::oof_arrows);
							ImGui::Checkbox((english ? "Chams Material" : u8"Чамсы матерьял"), &Misc::chams1);
							ImGui::Checkbox((english ? "Chams Def" : u8"Чамсы Деф"), &Misc::chams);
							if (Misc::chams ) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Red##1" : u8"Красный##1"), &Misc::xc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Green##1" : u8"Зелёный##1"), &Misc::yc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Blue##1" : u8"Синий##1"), &Misc::zc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::Checkbox((english ? "Rainbow Chams##1" : u8"Разноцветные Чамсы##1"), &Misc::rainbow_chams);
								ImGui::Checkbox((english ? "Health Chams##1" : u8"Жизненные Чамсы##1"), &Misc::health_chams);
								ImGui::Checkbox((english ? "OnlyVisible Chams##1" : u8"Только видимые Чамсы##1"), &Misc::OnlyVisible);
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Up-Time##1" : u8"Время ОБновления##1"), &Misc::uptime, 0.f, 15.f);
							}
							if (Misc::chams1) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Red##1" : u8"Красный##1"), &Misc::xc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Green##1" : u8"Зелёный##1"), &Misc::yc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Blue##1" : u8"Синий##1"), &Misc::zc, 0.f, 5.f);
								ImGui::Spacing();
								ImGui::Checkbox((english ? "Rainbow Chams##1" : u8"Разноцветные Чамсы##1"), &Misc::rainbow_chams);
								ImGui::Checkbox((english ? "Health Chams##1" : u8"Жизненные Чамсы##1"), &Misc::health_chams);
								ImGui::Checkbox((english ? "OnlyVisible Chams##1" : u8"Только видимые Чамсы##1"), &Misc::OnlyVisible);
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "Up-Time##1" : u8"Время ОБновления##1"), &Misc::uptime, 0.f, 15.f);
							}
							ImGui::Checkbox((english ? "Tracers" : u8"Трайсера"), &PlayerEsp::tracers);
							ImGui::Checkbox((english ? "Target Tracers" : u8" Таргет Трайсера"), &PlayerEsp::targetline);
							ImGui::Checkbox((english ? "Weapon" : u8"Оружие"), &PlayerEsp::weapon);
							ImGui::Checkbox((english ? "Wounded" : u8"Показывает Когда Ноукоутирован Игрок"), &PlayerEsp::wounded);
							ImGui::Checkbox((english ? "Target Name" : u8"Таргет Имя"), &PlayerEsp::targettext);
							ImGui::Checkbox((english ? "Sleepers Ignore" : u8"Игнор Спящих"), &PlayerEsp::sleeperignore);
							//ImGui::SliderFloat((english ? "The size font" : u8"Размер Шрифта"), &AimBot::font, 7.f, 14.f);
						   // if (ImGui::Button((english ? "Apple" : u8"Применить"), ImVec2(100.f, 0))) 
							//{
							//	RenderClass::NewFrame::InitRender();
							//}

							if (ImGui::BeginCombo(english ? "Crosshairs", "Crosshairs" : u8"Прицелы", "Прицелы")) {

								ImGui::Checkbox((english ? "Crosshair" : u8"Прицел"), &AimBot::Crosshair);
								ImGui::Checkbox((english ? "Svastika " : u8"Свастика"), &AimBot::svaston);
								if (AimBot::svaston)
								{
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::SliderInt((english ? "The Size" : u8"Размер"), &Misc::razmer, 1, 25);
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::SliderFloat((english ? "Speed" : u8"Скорость"), &Misc::speed, 0.1f, 10.f);

								}
								ImGui::Checkbox((english ? "Custom Crosshair" : u8"Кастомный Прицел"), &AimBot::CustomCrosshair);
								if (AimBot::CustomCrosshair)
								{
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::SliderFloat((english ? "Gap" : u8"Разделение"), &AimBot::Gap, 1.f, 50.f);
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::SliderFloat((english ? "Longht" : u8"Длина"), &AimBot::Longht, 1.f, 50.f);
									ImGui::Checkbox((english ? "Dot" : u8"Точка"), &AimBot::dot);
								}
								End();
								ImGui::PopStyleColor();
							}

						}
						if (subtab == 6)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Checkbox((english ? "Activity Slot" : u8"Активные Слоты"), &Visuals::ActiveSlotRender);


							if (ImGui::CollapsingHeader((english ? "Ores" : u8"Камни" )))
							{
								ImGui::Checkbox((english ? "Stone" : u8"Камень"), &Ores::Stone);
								ImGui::Checkbox((english ? "Sulfur" : u8"Сера"), &Ores::Sulfur);
								ImGui::Checkbox((english ? "Metal" : u8"Метал"), &Ores::Metal);
								if (Ores::Sulfur || Ores::Stone || Ores::Metal)
								{
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::Spacing();
									ImGui::SliderFloat((english ? "Ore ESP Distance" : u8"Выбор дистанции Камня"), &Ores::oreDrawDistance, 5.f, 400.f);
									ImGui::Checkbox((english ? "Show Distance" : u8"Показывать Дистанцию"), &Ores::showDistance);
								}
							}
							if (ImGui::CollapsingHeader((english ? "Other" : u8"Отдельное")))
							{
								if (ImGui::CollapsingHeader((english ? "Crates" : u8"Крейты")))
								{
									ImGui::Checkbox((english ? "Airdrops" : u8"Аирдроп"), &Visuals::Supply);
									ImGui::Checkbox((english ? "Chinook Crates" : u8"Чинук Крейты"), &Visuals::Chinook);
									if (Visuals::Supply || Visuals::Chinook)
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Crate ESP Distance" : u8"Выбор дистанции Крейтов"), &Visuals::drawCrateDistance, 5.f, 3000.f);
										ImGui::Checkbox((english ? "Show Distance " : u8"Показывать Дистанцию "), &Visuals::crateDistance);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Vehicles" : u8"Транспорт")))
								{
									ImGui::Checkbox((english ? "Minicopters" : u8"Мини-Вертолёт"), &Visuals::Minicopter);
									ImGui::Checkbox((english ? "Scrap Helis" : u8"Большой-Вертолёт"), &Visuals::ScrapHeli);
									ImGui::Checkbox((english ? "Boats" : u8"Лодка"), &Visuals::Boat);
									ImGui::Checkbox((english ? "RHIB's" : u8"Элитная Лодка"), &Visuals::RHIB);
									if (Visuals::Minicopter || Visuals::ScrapHeli || Visuals::Boat || Visuals::RHIB)
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Vehicle ESP Distance" : u8"Выбор дистанции Транспорта"), &Visuals::drawVehicleDistance, 5.f, 3000.f);
										ImGui::Checkbox((english ? "Show Distance  " : u8"Показывать Дистанцию  "), &Visuals::vehicleDistance);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Traps" : u8"Ловушки")))
								{
									ImGui::Checkbox((english ? "Auto Turrets" : u8"Турелли"), &Visuals::AutoTurret);
									ImGui::Checkbox((english ? "Flame Turrets" : u8"Огненная Турелли"), &Visuals::FlameTurret);
									ImGui::Checkbox((english ? "Shotgun Traps" : u8"Гантраб"), &Visuals::ShotgunTurret);
									ImGui::Checkbox((english ? "Landmines" : u8"Наземные мины"), &Visuals::Landmine);
									ImGui::Checkbox((english ? "Beartraps" : u8"Капканы"), &Visuals::BearTrap);
									if (Visuals::AutoTurret || Visuals::FlameTurret || Visuals::ShotgunTurret || Visuals::Landmine || Visuals::BearTrap)
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Trap ESP Distance" : u8"Выбор дистанции Ловушек"), &Visuals::drawTrapDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance   " : u8"Показывать Дистанцию   "), &Visuals::trapDistance);
									}
								}  
								if (ImGui::CollapsingHeader((english ? "Misc" : u8"Миск")))
								{  

									ImGui::Checkbox((english ? "Patrol Heli" : u8"Патрульный Вертолёт"), &Visuals::PatrolHeli);
									ImGui::Checkbox((english ? "Hemp" : u8"Конопля"), &Visuals::Hemp);
									ImGui::Checkbox((english ? "Corpses" : u8"Трупы"), &Visuals::Corpse);
									ImGui::Checkbox((english ? "Stashes" : u8"Стэши"), &Visuals::Stash);
									if (Visuals::Corpse || Visuals::Stash || Visuals::Hemp || Visuals::PatrolHeli)
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Misc ESP Distance" : u8"Выбор дистанции Миск"), &Visuals::drawOtherDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance    " : u8"Показывать Дистанцию    "), &Visuals::otherDistance);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Weapon" : u8"Оружие")))
								{
									ImGui::Checkbox((english ? "Weapon " : u8"Оружие "), &Visuals::Weapon);
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Weapon ESP Distance      " : u8"Выбор дистанции Оружия      "), &Visuals::drawWeaponDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance      " : u8"Показывать Дистанцию      "), &Visuals::DistanceWeapon);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Box  " : u8"Лут    ")))
								{
									ImGui::Checkbox((english ? "LootBox" : u8"Ящик с добычей "), &Visuals::Loot);
									ImGui::Checkbox((english ? "MedicalBox" : u8"Медицинский ящик"), &Visuals::Medical);
									ImGui::Checkbox((english ? "ToolBox" : u8"Ящик с Инструментами"), &Visuals::Tool);
									ImGui::Checkbox((english ? "Foodbox" : u8"Коробка с Едой"), &Visuals::Foodbox);
									ImGui::Checkbox((english ? "EliteBox" : u8"Элитный ящик"), &Visuals::Elite);
									ImGui::Checkbox((english ? "MineBox" : u8"Минный ящик"), &Visuals::Mine);
									ImGui::Checkbox((english ? "MilitiryBox" : u8"Военный ящик"), &Visuals::Militiry);
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Box ESP Distance" : u8"Выбор дистанции Ящика    "), &Visuals::drawBoxDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance    " : u8"Показывать Дистанцию    "), &Visuals::DistanceBox);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Keycards" : u8"Ключ-Карты")))
								{
									ImGui::Checkbox((english ? "Keycards " : u8"Ключ-Карты "), &Visuals::Keycard);
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? " Keycard Distance" : u8"Выбор Ключ-Карты"), &Visuals::KeycardDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Draw Keycard Distance" : u8"Показывать Ключ-Карты"), &Visuals::drawKeycardDistance);
									}
								}
								if (ImGui::CollapsingHeader((english ? "Eat" : u8"Еда")))
								{
									ImGui::Checkbox((english ? "Berrys" : u8"Ягоды"), &Visuals::Berry);
									ImGui::Checkbox((english ? "Mushrooms" : u8"Грибы"), &Visuals::Mushrooms);
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Eat ESP Distance" : u8"Выбор Еды"), &Visuals::drawEatDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance     " : u8"Показать Дистанцию     "), &Visuals::EatDistance);
									}
									}
								if (ImGui::CollapsingHeader((english ? "Animals" : u8"Животные ")))
								{
									ImGui::Checkbox((english ? "Bear" : u8"Медведь"), &Visuals::Bear);
									ImGui::Checkbox((english ? "Boar" : u8"Кабанчик"), &Visuals::Boar);
									ImGui::Checkbox((english ? "Chicken" : u8"Курица"), &Visuals::Chicken);
									ImGui::Checkbox((english ? "Horse" : u8"Лошадь"), &Visuals::Horse);
									if (Visuals::Bear || Visuals::Boar || Visuals::Chicken || Visuals::Horse)
									{
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::Spacing();
										ImGui::SliderFloat((english ? "Animals ESP Distance" : u8"Выбор Животных"), &Visuals::drawAnimalsDistance, 5.f, 400.f);
										ImGui::Checkbox((english ? "Show Distance    " : u8"Показать Дистанцию   "), &Visuals::AnimalsDistance);
									}
									ImGui::PopStyleColor();
								}
							}
						}
					}
					if (tab == 2)
					{
						if (subtab == 8)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Checkbox(english ? "Zoom" : u8"Приблежеие", &Misc::Zoom);
							if (Misc::Zoom)
							{
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "Zoom Value" : u8"Фактор Приблежения", &Misc::Zoomvalue, 60.f, 10.f);
								Hotkey(english ? "Zoom Key" : u8"Кнопка Приблежения", &Misc::Zoomkey, ImVec2(150, 30));
							}
							ImGui::Checkbox(english ? "Suicide" : u8"Смерть", &Misc::suicide);
							if (Misc::suicide) {
								ImGui::Spacing();
								Hotkey(english ? "Suicide Key" : u8"Кнопка Смерти", &Keys::suicide, ImVec2(150, 20));
							}
							ImGui::Checkbox(english ? "CustomFov onli c Zoom" : u8"Кастомный Фов Только с Приблежением", &Misc::CustomFov);
							if (Misc::CustomFov) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "CustomFov Value" : u8"Фактор Кастомного Фова", &Misc::FovRange, 0.f, 120.f);
							}
							ImGui::Checkbox(english ? "Mass Suicide" : u8"Массовое Убийство", &Misc::mass_suicide);
							ImGui::Checkbox((english ? "Meleeatack" : u8"Рукопашная атака"), &Misc::Meleeatack);
							ImGui::Checkbox((english ? "InfinityJump" : u8"Бесконечный Прыжок"), &Misc::InfJump);
							ImGui::Checkbox((english ? "Long neck right" : u8"Длинная Шея Направо"), &Misc::LongNeckright);
							if (Misc::LongNeckright) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey("LongNeck Key2", &Misc::LongNeckkey2, ImVec2(150, 15));
							}
							ImGui::Checkbox((english ? "Long neck left" : u8"Длинная Шея Налево"), &Misc::LongNeckLeft);
							if (Misc::LongNeckLeft) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey("LongNeck Key1", &Misc::LongNeckkey1, ImVec2(150, 15));
							}
							ImGui::Checkbox((english ? "Manipulator" : u8"Манипулятор"), &Misc::PeekAssist);
							if (Misc::PeekAssist) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey((english ? "Manipulator-Key" : u8"Кнопка Манипулятора"), &Keys::manipulatorkey, ImVec2(120.f, 0));
							}
							ImGui::Checkbox((english ? "AutoShoot" : u8"Авто Выстрел"), &AimBot::AutoShoot);
							//ImGui::Checkbox((english ? "flyhack_indicator" : u8"Длинная Шея"), &Misc::flyhack_indicator);
							ImGui::Checkbox((english ? "Long neck" : u8"Длинная Шея"), &Misc::LongNeck);
							if (Misc::LongNeck) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey("LongNeck Key", &Misc::LongNeckkey, ImVec2(150, 15));
							}
							//ImGui::Checkbox(("Trace Bullet"), &Visuals::visattack);
							//HelpCheckbox(xorstr("Rayleigh Changer"), &Misc::rayleigh_changer, xorstr("Makes your sky look pretty when day."));
							//if (Misc::rayleigh_changer) {
							//	ImGui::Spacing();
							//	ImGui::Spacing();
							//	ImGui::Spacing();
							//	ImGui::SliderFloat(xorstr("Rayleigh Amount"), &Misc::rayleigh, 1.f, 50.f);
							//}
							ImGui::Checkbox((english ? "Custom Time" : u8"Кастомный фов"), &Misc::CustomTime);
							if (Misc::CustomTime) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat((english ? "CustomTime" : u8"Выбор Тайма"), &Misc::Time, 0.f, 12.f);
							}
							//ImGui::Checkbox(("BulletTracers"), &Visuals::visattack);
							ImGui::Checkbox((english ? "Fake-Admin" : u8"Фейковый Админ"), &Misc::FakeAdmin);
							ImGui::Checkbox((english ? "Omni-Sprint" : u8"Онли Спринт"), &Misc::omniSprint);
							ImGui::Checkbox((english ? "AutoPickUp" : u8"АвтоПоднятие"), &Misc::AutoPickUp);
							ImGui::Checkbox((english ? "Speed-hack" : u8"Спидххак"), &Misc::speedhack);
							if (Misc::speedhack) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey((english ? "Speed Key" : u8"Спидххак Кнопка"), &Keys::speedKey, ImVec2(145.f, 0));
							}
							ImGui::Checkbox((english ? "interactive debug" : u8"Интерактив дебаг"), &Misc::interactivedebug);
							if (Misc::interactivedebug) {
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								Hotkey((english ? "interactive debug Key" : u8"Интерактив Кнопка"), &Keys::interactivedebug, ImVec2(145.f, 0));
							}
							ImGui::Checkbox((english ? "AutoFarm" : u8"АвтоДобыча"), &Misc::AutoFarm);
							if (Misc::AutoFarm == true) {
								ImGui::Checkbox((english ? "FarmTree" : u8"Автофарм Дерева"), &Misc::AutoFarmTree);
								ImGui::Checkbox((english ? "FarmOre" : u8"Автофарм Камней"), &Misc::AutoFarmOre);
								ImGui::Checkbox((english ? "AutoFarmBarrel" : u8"Автофарм Бочек"), &Misc::AutoFarmBarrel);
							}
							ImGui::Checkbox(english ? "SwimOnGround" : u8"Плавать на Земле", &Misc::SwimOnGround);
							//ImGui::Checkbox("instarevive", &Misc::instarevive);
							ImGui::Checkbox(english ? "HighJump" : u8"Изменение Гравитации", &Misc::HighJump);
							if (Misc::HighJump)
							{
								ImGui::SliderFloat(english ? "HighJump Value" : u8" Выбор Изменение Гравитации ", &Misc::JumpValue, 0.f, 2.5f);
								Hotkey(english ? "HighJump Key" : u8"Кнопка Изменение Гравитации", &Misc::highkey, ImVec2(150, 30));
							}
							HelpCheckbox((english ? "Anti-Aiming" : u8"Анти-Аимы"), &AntiAim::anti_aim, (english ? "Makes you look like you're spinning on other people's screens" : u8"Заставляет вас выглядеть так, будто вы вращаетесь на экранах других людей"));
							if (AntiAim::anti_aim) {
								ImGui::SliderInt((english ? "Spin Speed" : u8"Спин Скоросить"), &AntiAim::anti_aim_speed, 1, 150);
								ImGui::PushItemWidth(100);
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Combo((english ? "Yaw" : u8"Выбор Отклонения"), &AntiAim::anti_aim_yaw, anti_aim_yaw, IM_ARRAYSIZE(anti_aim_yaw));
								//ImGui::Checkbox(("Anti-Aim Indicator"), &AntiAim::anti_aim_indicator);
								ImGui::PopItemWidth();
							}
							ImGui::Checkbox((english ? "Spiderman" : u8"Паучёк"), &Misc::SpiderMan);
							ImGui::Checkbox((english ? "No Colision" : u8"Отключения Колизии"), &Misc::no_playercollision);
							ImGui::Checkbox((english ? "Ambient" : u8"Амблиент"), &Visuals::NightMode);
							ImGui::Checkbox((english ? "Hit Sound" : u8"Звуки Попадания"), &Hit::CustomHitSound);
							if (Hit::CustomHitSound) {
								ImGui::Spacing();
								ImGui::Text(english ? "Transfer to C:\Hit" : u8"Перекинуть в  C:\Hit");
								if (ImGui::Button((english ? "Download" : u8"Скачать"), ImVec2(100.f, 0))) {
									system("start https://cdn.discordapp.com/attachments/802922718311874561/824387814162169906/sound.wav");
									
								}
								ImGui::PopStyleColor();
							}


						}
						if (subtab == 9)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							//ImGui::Text((english ? "Norecoil Kill" : u8"Без отдачи Нету"));
							ImGui::Checkbox((english ? "Aiming On Hellicopter" : u8"Аиммить На Вертолёте"), &Weapons::canHoldItems);
							ImGui::Checkbox((english ? "Automatic" : u8"Автоматик"), &Weapons::Automatic);
							ImGui::Checkbox((english ? "NoSpread" : u8"Без Сприда"), &Weapons::AntiSpread);
							ImGui::Checkbox((english ? "NoRecoil" : u8"Без Отдачи"), &Weapons::NoRecoil);
							ImGui::Checkbox((english ? "RapidFire" : u8"Быстрая Стрельба"), &Misc::RapidFire);
							if (Misc::RapidFire)
							{
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "speed##1" : u8"Скорость##1", & Misc::RapidFirevalye, -10.f, 0.3f);
							}
							ImGui::Checkbox((english ? "SuperEoka" : u8"Супер Еока"), &Weapons::SuperEoka);
							ImGui::Checkbox((english ? "FastBow" : u8"Быстрый Лук"), &Weapons::SuperBow);
							//ImGui::Checkbox(("NoAnimation"), &Misc::remove_attack_anim);
							ImGui::Checkbox((english ? "JumpAim" : u8"Стрелять в Прыжке"), &Weapons::jumpAim);
							ImGui::Checkbox((english ? "FatBullet" : u8"Толстая Пуля"), &Weapons::FatBullet);
							if (Weapons::FatBullet)
							{
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "FatBulletFloat" : u8"Выбор толстой пули", &Weapons::FatBulletpov, 1.80f, 2.f);
							}
							ImGui::Checkbox((english ? "LongHand" : u8"Длинные Руки"), &Weapons::LongHand);
							ImGui::Checkbox((english ? "Spoof Hit Distance" : u8"Изменение Дистанции на Убийтво"), &Weapons::spoof_hitdistance);
							if (Weapons::spoof_hitdistance)
							{
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "FAKEDISTATIONKILLFLOAT" : u8"Выбор Дистанции", &Weapons::hitdistance, 0.f, 10000.f);
							}
							ImGui::Checkbox((english ? "FastBullet" : u8"Быстрая Пуля"), &AimBot::FastBullet);
							if (AimBot::FastBullet)
							{
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::Spacing();
								ImGui::SliderFloat(english ? "SpeedBullets Value" : u8"Выбор Скорости", &AimBot::SpeedBullets, 0.f, 3.f);
							}
							ImGui::PopStyleColor();
						}

						}
				if (tab == 8)
				{
					if (subtab == 8)
					{
						ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));

						ImGui::ColorEdit4(english ? "FovColor" : u8"Радиус Цвет", Colors::Fov);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "Nam2eColor" : u8"Имя Цвет", Colors::boxnotvisible);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "NameColor" : u8"Имя Цвет", Colors::boxvisible);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "BoxColor" : u8"Коробка Цвет", Colors::BoxColor);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "SkeletonColor" : u8"Скелет Цвет", Colors::SkeletonColor);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "WeaponColor" : u8"Оружие Цвет", Colors::WeaponColor);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "WoundedColor" : u8"Ноукнутый Цвет", Colors::Wounded);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "CrosshairColor" : u8"Прицел Цвет", Colors::Crosshair2);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "LineColor" : u8"Таргет Цвет", Colors::LineEsp);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "TextTargetColor" : u8"Таргет Имя Цвет", Colors::Textesp);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "TracersColor" : u8"Трайсера Цвет", Colors::Target_text);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "TextColor" : u8"Цвет Текста в Меню", Colors::Fonts);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "FontsColor" : u8"Задний Фон в Меню", Colors::TextColor);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(english ? "MenuColor" : u8"Цвет Названия в Меню", Colors::TextColor2);
						ImGui::SetColorEditOptions(ImGuiColorEditFlags_Float | ImGuiColorEditFlags_PickerHueWheel | ImGuiColorEditFlags_NoInputs);
						ImGui::PopStyleColor();
					}


					}
					if (tab == 17)
					{
						if (subtab == 18)
						{
							ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
							ImGui::Text((english ? "it can crash on some servers" : u8"Может Вылетать На некоторых Серверах"));
					        ImGui::PopStyleColor();
								}
							}

					if (tab == 9)
					{
						if (subtab == 19)
						{
							
							
								Hotkey("Menu Key", &Keys::menu, ImVec2(150, 15));//перибинживание кнопочки меню
								ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
								if (ImGui::Button((english ? "Panic" : u8"Выгрузить"), ImVec2(100.f, 0))) {
									Global::Panic = true;
									Misc::FakeAdmin = false;

								}
								if (ImGui::Button((english ? "Discord" : u8"Дискорд Сервер"), ImVec2(100.f, 0))) {
									system("start https://discord.gg/Z7PncQSNN2");
								}
								ImGui::Text((english ? "Support Poves#4495" : u8"Помошник  Poves#4495"));
								ImGui::PopStyleColor();
						  }
						}
						if (tab == 20)
						{
							if (subtab == 100)
							{


								ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(Colors::Fonts));
								ImGui::InputText((""), Global::ConfigName, 0x100);
								if (ImGui::Button((english ? "Save Config" : u8"Сохранить Конфиг"), ImVec2(100.f, 0))) {
									SaveCFG(Global::ConfigName);
								sh_save_cfg = true;
							}
								ImGui::SameLine();
								if (ImGui::Button((english ? "Load Config" : u8"Загрузить Конфиг"), ImVec2(100.f, 0))) {
									LoadCFG(Global::ConfigName);
								sh_load_cfg = true;
						}
								ImGui::EndGroup();
								ImGui::SameLine();
								if (ImGui::Button((english ? "Open folder" : u8"Открыть Папку"), ImVec2(100.f, 0))) {
									system("start C:\\Hit\\cfg");
								}

								ImGui::PopStyleColor();

							}
					}

				}
				if (sh_save_cfg)
				{
					//save ur cfg
					bool done = false;
					Anime::Popup("Config Saved!", 2000, &done);// крч текс при лоадинге кфг
					if (done)
						sh_save_cfg = false;
				}

				if (sh_load_cfg)
				{
					//load ur cfg
					bool done = false;
					Anime::Popup("Config Loaded!", 2000, &done);
					if (done)
						sh_load_cfg = false;
				}
				ImGui::EndGroup();
			}
			ImGui::EndChild();
		}
		ImGui::EndGroup();


	}
}
ImFont* initx;
void Init()
{

	// Setup
	auto front = ImGui::GetForegroundDrawList(); // also you can use GetWindowDrawList() or GetBackgroundDrawList()
	ImVec2 center = ImGui::GetIO().DisplaySize / 2.f;
	static ImColor fore_color(100, 0, 255);
	static ImColor back_color(0, 0, 0, 25);
	static float arc_size = 0.45f; // 0.f < x < 2.f
	static float radius = 30.f;
	static float thickness = 4.f;
	static float Alpha = 0.0f;
	int screenWidthX = GetSystemMetrics(SM_CXSCREEN);
	int screenHeightY = GetSystemMetrics(SM_CYSCREEN);
	auto back = ImGui::GetBackgroundDrawList();

	if (Alpha < 0.65f)
		Alpha += 0.005f;
	back->AddRectFilled(ImVec2(0, 0), ImVec2(screenWidthX, screenHeightY), ImGui::GetColorU32(ImVec4(0.0f, 0.0f, 0.0f, Alpha)));


	// Animation
	static float position = 0.f;
	position = ImLerp(position, IM_PI * 2.f, ImGui::GetIO().DeltaTime * 2.3f);

	// Background
	front->PathClear();
	front->PathArcTo(center, radius, 0.f, 2.f * IM_PI, 35.f);
	front->PathStroke(ImGui::GetColorU32(back_color.Value), 0, thickness);

	// Foreground
	front->PathClear();
	front->PathArcTo(center, radius, IM_PI * 1.5f + position, IM_PI * (1.5f + arc_size) + position, 35.f);
	front->PathStroke(ImGui::GetColorU32(fore_color.Value), 0, thickness);
	ImGui::PushFont(initx);
	ImVec2 inject = ImGui::CalcTextSize(xorstr(u8"Initialization Geroin.solution"));
	ImVec2 discord = ImGui::CalcTextSize(xorstr(u8"Poves#4495"));
	auto MiddleX = Global::ScreenWidth / 2;
	auto MiddleY = Global::ScreenHigh / 2;
	front->AddText({ MiddleX - inject.x / 2 + 3, MiddleY + 35 }, ImColor(255, 255, 255), xorstr(u8"Initialization Geroin.solution"));//№точнонеспастилсоskylinev2
	front->AddText({ MiddleX - discord.x / 2 + 3, MiddleY + -47 }, ImColor(255, 255, 255), xorstr(u8"Poves#4495"));
	ImGui::PopFont();

	// Reset animation
	if (position >= IM_PI * 1.90f)
		position = 0.f;
}
void MenuSteep() {
	ImGui::StyleColorsDark();

	CreateDirectoryA("C:\\Hit", NULL);
	CreateDirectoryA("C:\\Hit\\cfg", NULL);

}
