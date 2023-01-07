
#pragma once
#include <direct.h>

CSimpleIniA cfg; //инициализируем объект

#pragma region Config Color

void SaveColorValue(const char* pSection, std::string name, float a_Value[4])
{
    int R, G, B, A;
    R = a_Value[0] * 1000;
    G = a_Value[1] * 1000;
    B = a_Value[2] * 1000;
    A = a_Value[3] * 1000;
    cfg.SetLongValue(pSection, (name + "_R").c_str(), R);
    cfg.SetLongValue(pSection, (name + "_G").c_str(), G);
    cfg.SetLongValue(pSection, (name + "_B").c_str(), B);
    cfg.SetLongValue(pSection, (name + "_A").c_str(), A);
}

void LoadColorValue(const char* pSection, std::string name, float a_Value[4])
{
    float R, G, B, A;
    R = cfg.GetLongValue(pSection, (name + "_R").c_str(), a_Value[0]);
    G = cfg.GetLongValue(pSection, (name + "_G").c_str(), a_Value[1]);
    B = cfg.GetLongValue(pSection, (name + "_B").c_str(), a_Value[2]);
    A = cfg.GetLongValue(pSection, (name + "_A").c_str(), a_Value[3]);
    a_Value[0] = R / 1000; a_Value[1] = G / 1000; a_Value[2] = B / 1000; a_Value[3] = A / 1000;
}

#pragma endregion 

inline bool folder_exists(const char* foldername)
{
    struct stat st;
    stat(foldername, &st);
    return st.st_mode & S_IFDIR;
}
void SaveCFG(const char* FileName)
{
    DWORD SerialNumber;

    GetVolumeInformation(L"C:\\", 0, 0, &SerialNumber, 0, 0, 0, 0);

    char Path[0x100];
    sprintf(Path, ("C:\\Hit\\cfg\\"));

    if (!folder_exists(Path))
        _mkdir(Path);
    cfg.SetUnicode();
    char result[0x100];
    sprintf(result, ("C:\\Hit\\cfg\\%s.ini"), FileName);

#pragma region AimBot
    cfg.SetBoolValue("zalypa", "Always HS", AimBot::AlwaysHeadshot);
    cfg.SetBoolValue("zalypa", "Always Body", AimBot::pBody);
    cfg.SetBoolValue("lEGIT", "DrawFov", AimBot::DrawFov);
    cfg.SetBoolValue("lEGIT", "smooth", AimBot::smooth);
    cfg.SetLongValue("lEGIT", "smooth_factor", AimBot::smooth_factor);
    cfg.SetBoolValue("lEGIT", "FillFov", AimBot::FillFov);
    cfg.SetLongValue("zalypa", "Fov", AimBot::Fov);
    cfg.SetBoolValue("Rage", "pSilent", AimBot::pSilent);
    cfg.SetBoolValue("zalypa", "SilentHeli", AimBot::SilentHeli);
    cfg.SetBoolValue("zalypa", "IgnoreNpc", AimBot::IgnoreNpc);
    cfg.SetBoolValue("zalypa", "IgnoreTeam", AimBot::IgnoreTeam);
    cfg.SetBoolValue("zalypa", "IgnoreSleepers", AimBot::IgnoreSleepers);
    cfg.SetBoolValue("zalypa", "name", PlayerEsp::name);
    cfg.SetBoolValue("zalypa", "box", PlayerEsp::box);
    //cfg.SetLongValue("zalypa", "boxstyle", PlayerEsp::boxstyle);
    cfg.SetLongValue("zalypa", "cornerfloat", PlayerEsp::cornerfloat);
    cfg.SetBoolValue("zalypa", "fillbox", PlayerEsp::fillbox);
    cfg.SetBoolValue("zalypa", "healthbar1", PlayerEsp::healthbar1);
    cfg.SetBoolValue("zalypa", "healthbar2", PlayerEsp::healthbar2);
    cfg.SetBoolValue("zalypa", "visualize_prediction", Visuals::visualize_prediction);
    cfg.SetBoolValue("zalypa", "chams", Misc::chams);
    cfg.SetLongValue("zalypa", "red", Misc::xc);
    cfg.SetLongValue("zalypa", "green", Misc::yc);
    cfg.SetLongValue("zalypa", "blue", Misc::zc);
    cfg.SetBoolValue("zalypa", "rainbow_chams", Misc::rainbow_chams);
    cfg.SetBoolValue("zalypa", "health_chams", Misc::health_chams);
    cfg.SetBoolValue("zalypa", "OnlyVisible", Misc::OnlyVisible);
    cfg.SetLongValue("zalypa", "uptime", Misc::uptime);
    cfg.SetBoolValue("zalypa", "tracers", PlayerEsp::tracers);
    cfg.SetBoolValue("zalypa", "targetline", PlayerEsp::targetline);
    cfg.SetBoolValue("zalypa", "weapon", PlayerEsp::weapon);
    cfg.SetBoolValue("zalypa", "wounded", PlayerEsp::wounded);
    cfg.SetBoolValue("zalypa", "targettext", PlayerEsp::targettext);
    cfg.SetBoolValue("zalypa", "sleeperignore", PlayerEsp::sleeperignore);
    cfg.SetBoolValue("zalypa", "name", BotsEsp::name);
    cfg.SetBoolValue("zalypa", "box", BotsEsp::box);
    cfg.SetBoolValue("zalypa", "skeleton", BotsEsp::skeleton);
    cfg.SetBoolValue("zalypa", "health", BotsEsp::health);
    cfg.SetBoolValue("zalypa", "weapons", BotsEsp::weapons);
    cfg.SetBoolValue("zalypa", "svaston", AimBot::svaston);
    cfg.SetLongValue("zalypa", "razmer", Misc::razmer);
    cfg.SetLongValue("zalypa", "speed", Misc::speed);
    cfg.SetBoolValue("zalypa", "CustomCrosshair", AimBot::CustomCrosshair);
    cfg.SetLongValue("zalypa", "Gap", AimBot::Gap);
    cfg.SetLongValue("zalypa", "Longht", AimBot::Longht);
    cfg.SetBoolValue("zalypa", "dot", AimBot::dot);
    cfg.SetBoolValue("zalypa", "ActiveSlotRender", Visuals::ActiveSlotRender);
    cfg.SetBoolValue("zalypa", "Zoom", Misc::Zoom);
    cfg.SetLongValue("zalypa", "Zoomvalue", Misc::Zoomvalue);
    cfg.SetLongValue("zalypa", "Zoomkey", Misc::Zoomkey);
    cfg.SetBoolValue("zalypa", "suicide", Misc::suicide);
    cfg.SetLongValue("zalypa", "suicidekey", Keys::suicide);
    cfg.SetBoolValue("zalypa", "CustomFov", Misc::CustomFov);
    cfg.SetLongValue("zalypa", "FovRange", Misc::FovRange);
    cfg.SetBoolValue("zalypa", "mass_suicide", Misc::mass_suicide);
    cfg.SetBoolValue("zalypa", "Meleeatack", Misc::Meleeatack);
    cfg.SetLongValue("zalypa", "Meleeatackkey", Misc::Meleeatackkey);
    cfg.SetBoolValue("zalypa", "InfJump", Misc::InfJump);
    cfg.SetBoolValue("zalypa", "CustomTime", Misc::CustomTime);
    cfg.SetLongValue("zalypa", "Time", Misc::Time);
    cfg.SetBoolValue("zalypa", "FakeAdmin", Misc::FakeAdmin);
    cfg.SetBoolValue("zalypa", "omniSprint", Misc::omniSprint);
    cfg.SetBoolValue("zalypa", "AutoPickUp", Misc::AutoPickUp);
    cfg.SetBoolValue("zalypa", "speedhack", Misc::speedhack);
    cfg.SetLongValue("zalypa", "speedKey", Keys::speedKey);
    cfg.SetBoolValue("zalypa", "AutoFarm", Misc::AutoFarm);
    cfg.SetBoolValue("zalypa", "AutoFarmTree", Misc::AutoFarmTree);
    cfg.SetBoolValue("zalypa", "AutoFarmOre", Misc::AutoFarmOre);
    cfg.SetBoolValue("zalypa", "AutoFarmBarrel", Misc::AutoFarmBarrel);
    cfg.SetBoolValue("zalypa", "SwimOnGround", Misc::SwimOnGround);
    cfg.SetBoolValue("zalypa", "HighJump", Misc::HighJump);
    cfg.SetLongValue("zalypa", "JumpValue", Misc::JumpValue);
    cfg.SetLongValue("zalypa", "highkey", Misc::highkey);
    cfg.SetBoolValue("zalypa", "anti_zalypa", AntiAim::anti_aim);
    cfg.SetLongValue("zalypa", "anti_zalypa_speed", AntiAim::anti_aim_speed);
    cfg.SetLongValue("zalypa", "anti_zalypa_yaw", AntiAim::anti_aim_yaw);
    cfg.SetBoolValue("zalypa", "SpiderMan", Misc::SpiderMan);
    cfg.SetBoolValue("zalypa", "no_playercollision", Misc::no_playercollision);
    cfg.SetBoolValue("zalypa", "NightMode", Visuals::NightMode);
    cfg.SetBoolValue("zalypa", "CustomHitSound", Hit::CustomHitSound);
    cfg.SetBoolValue("zalypa", "canHoldItems", Weapons::canHoldItems);
    cfg.SetBoolValue("zalypa", "AntiSpread", Weapons::AntiSpread);
    cfg.SetBoolValue("zalypa", "NoSway", Weapons::NoSway);
    cfg.SetBoolValue("zalypa", "Automatic", Weapons::Automatic);
    cfg.SetBoolValue("zalypa", "RapidFire", Weapons::RapidFire);
    cfg.SetBoolValue("zalypa", "SuperEoka", Weapons::SuperEoka);
    cfg.SetBoolValue("zalypa", "SuperBow", Weapons::SuperBow);
    cfg.SetBoolValue("zalypa", "FatBullet", Weapons::FatBullet);
    cfg.SetBoolValue("zalypa", "LongHand", Weapons::LongHand);
    cfg.SetBoolValue("zalypa", "spoof_hitdistance", Weapons::spoof_hitdistance);
    cfg.SetLongValue("zalypa", "hitdistance", Weapons::hitdistance);
    cfg.SetBoolValue("zalypa", "FastBullet", AimBot::FastBullet);
    cfg.SetLongValue("zalypa", "SpeedBullets", AimBot::SpeedBullets);
   
#pragma region Player Color
    //  SaveColorValue("Player", "Name", Color::NameColor);
    SaveColorValue("Player", "Fov", Colors::Fov);
    SaveColorValue("Player", "Name", Colors::NameColor);
    SaveColorValue("Player", "BoxColor", Colors::BoxColor);
    SaveColorValue("Player", "DistanceColor", Colors::DistanceColor);
    SaveColorValue("Player", "PlayerHeath", Colors::PlayerHeath);
    SaveColorValue("Player", "WeaponColor", Colors::WeaponColor);
    SaveColorValue("Player", "LineEsp", Colors::LineEsp);
    SaveColorValue("Player", "SkeletonColor", Colors::SkeletonColor);
    SaveColorValue("Player", "Wounded", Colors::Wounded);
    SaveColorValue("Player", "Target_text", Colors::Target_text);
    SaveColorValue("Player", "Textesp", Colors::Textesp);
    SaveColorValue("Player", "Crosshair", Colors::Crosshair2);
    SaveColorValue("Player", "Fonts", Colors::Fonts);
    SaveColorValue("Player", "TextColor", Colors::TextColor);
    SaveColorValue("Player", "TextColor2", Colors::TextColor2);
    /*SaveColorValue("Player - Color", "Player Fill Box Color", Bools::PlayerColor::PlayerFillBoxColor);
    SaveColorValue("Player - Color", "Player Dead Color", Bools::PlayerColor::PlayerDeadColor);
    SaveColorValue("Player - Color", "Player Backpack Color", Bools::PlayerColor::PlayerBackpackColor);*/
#pragma endregion

#pragma region Resourse Color
    /* SaveColorValue("Resourse - Color", "Stone - Ore Color", Bools::ResourcesColor::StoneOreColor);
     SaveColorValue("Resourse - Color", "Mettal - Ore Color", Bools::ResourcesColor::MettalOreColor);
     SaveColorValue("Resourse - Color", "Sulfure - Ore Color", Bools::ResourcesColor::SulfureOreColor);*/
#pragma endregion

#pragma region Construction Color
     /*
     SaveColorValue("Construction - Color", "Cupboard Color", Bools::ConstructionColor::CupboardColor);
     SaveColorValue("Construction - Color", "Large Wood Box Color", Bools::ConstructionColor::LargeWoodBoxColor);
     SaveColorValue("Construction - Color", "Small Stash Color", Bools::ConstructionColor::SmallStashColor);*/
#pragma endregion 

    cfg.SaveFile(result);
}


void Initialize()
{
    //szPath = "C:\\FrogGang.pw\\";
    //Setup();
}

void LoadCFG(const char* FileName)
{

    DWORD SerialNumber;

    GetVolumeInformation(L"C:\\", 0, 0, &SerialNumber, 0, 0, 0, 0);

    char Path[0x100];
    sprintf(Path, ("C:\\Hit\\cfg\\"));

    if (!folder_exists(Path))
        _mkdir(Path);
    cfg.SetUnicode();
    char result[0x100];
    sprintf(result, ("C:\\Hit\\cfg\\%s.ini"), FileName);
    cfg.LoadFile(result);

#pragma region AimBot
    AimBot::AlwaysHeadshot = cfg.GetBoolValue("zalypa", "Always HS", AimBot::AlwaysHeadshot);
    AimBot::pBody = cfg.GetBoolValue("zalypa", "Always Body", AimBot::pBody);
    AimBot::DrawFov = cfg.GetBoolValue("lEGIT", "DrawFov", AimBot::DrawFov);
    AimBot::smooth = cfg.GetBoolValue("lEGIT", "smooth", AimBot::smooth);
    AimBot::smooth_factor = cfg.GetLongValue("lEGIT", "smooth_factor", AimBot::smooth_factor);
    AimBot::FillFov = cfg.GetBoolValue("lEGIT", "FillFov", AimBot::FillFov);
    AimBot::Fov = cfg.GetLongValue("zalypa", "Fov", AimBot::Fov);
    AimBot::pSilent = cfg.GetBoolValue("Rage", "pSilent", AimBot::pSilent);
    AimBot::SilentHeli = cfg.GetBoolValue("zalypa", "SilentHeli", AimBot::SilentHeli);
    AimBot::IgnoreNpc = cfg.GetBoolValue("zalypa", "IgnoreNpc", AimBot::IgnoreNpc);
    AimBot::IgnoreTeam = cfg.GetBoolValue("zalypa", "IgnoreTeam", AimBot::IgnoreTeam);
    AimBot::IgnoreSleepers = cfg.GetBoolValue("zalypa", "IgnoreSleepers", AimBot::IgnoreSleepers);
    PlayerEsp::name = cfg.GetBoolValue("zalypa", "name", PlayerEsp::name);
    PlayerEsp::box = cfg.GetBoolValue("zalypa", "box", PlayerEsp::box);
  // PlayerEsp::boxstyle = cfg.SetLongValue("zalypa", "boxstyle", PlayerEsp::boxstyle);
   PlayerEsp::cornerfloat = cfg.GetLongValue("zalypa", "cornerfloat", PlayerEsp::cornerfloat);
    PlayerEsp::fillbox = cfg.GetBoolValue("zalypa", "fillbox", PlayerEsp::fillbox);
    PlayerEsp::healthbar1 = cfg.GetBoolValue("zalypa", "healthbar1", PlayerEsp::healthbar1);
    PlayerEsp::healthbar2 = cfg.GetBoolValue("zalypa", "healthbar2", PlayerEsp::healthbar2);
    Visuals::visualize_prediction = cfg.GetBoolValue("zalypa", "visualize_prediction", Visuals::visualize_prediction);
    Misc::chams = cfg.GetBoolValue("zalypa", "chams", Misc::chams);
    Misc::xc = cfg.GetLongValue("zalypa", "red", Misc::xc);
    Misc::yc = cfg.GetLongValue("zalypa", "green", Misc::yc);
    Misc::zc = cfg.GetLongValue("zalypa", "blue", Misc::zc);
    Misc::rainbow_chams = cfg.GetBoolValue("zalypa", "rainbow_chams", Misc::rainbow_chams);
    Misc::health_chams = cfg.GetBoolValue("zalypa", "health_chams", Misc::health_chams);
    Misc::OnlyVisible = cfg.GetBoolValue("zalypa", "OnlyVisible", Misc::OnlyVisible);
    Misc::uptime = cfg.GetLongValue("zalypa", "uptime", Misc::uptime);
    PlayerEsp::tracers = cfg.GetBoolValue("zalypa", "tracers", PlayerEsp::tracers);
    PlayerEsp::targetline = cfg.GetBoolValue("zalypa", "targetline", PlayerEsp::targetline);
    PlayerEsp::weapon = cfg.GetBoolValue("zalypa", "weapon", PlayerEsp::weapon);
    PlayerEsp::wounded = cfg.GetBoolValue("zalypa", "wounded", PlayerEsp::wounded);
    PlayerEsp::targettext = cfg.GetBoolValue("zalypa", "targettext", PlayerEsp::targettext);
    PlayerEsp::sleeperignore = cfg.GetBoolValue("zalypa", "sleeperignore", PlayerEsp::sleeperignore);
    BotsEsp::name = cfg.GetBoolValue("zalypa", "name", BotsEsp::name);
    BotsEsp::box = cfg.GetBoolValue("zalypa", "box", BotsEsp::box);
    BotsEsp::skeleton = cfg.GetBoolValue("zalypa", "skeleton", BotsEsp::skeleton);
    BotsEsp::health = cfg.GetBoolValue("zalypa", "health", BotsEsp::health);
    BotsEsp::weapons = cfg.GetBoolValue("zalypa", "weapons", BotsEsp::weapons);
    AimBot::svaston = cfg.GetBoolValue("zalypa", "svaston", AimBot::svaston);
    Misc::razmer = cfg.GetLongValue("zalypa", "razmer", Misc::razmer);
    Misc::speed = cfg.GetLongValue("zalypa", "speed", Misc::speed);
    AimBot::CustomCrosshair = cfg.GetLongValue("zalypa", "CustomCrosshair", AimBot::CustomCrosshair);
    AimBot::Gap = cfg.GetLongValue("zalypa", "Gap", AimBot::Gap);
    AimBot::Longht = cfg.GetLongValue("zalypa", "Longht", AimBot::Longht);
    AimBot::dot = cfg.GetLongValue("zalypa", "dot", AimBot::dot);
    Visuals::ActiveSlotRender = cfg.GetBoolValue("zalypa", "ActiveSlotRender", Visuals::ActiveSlotRender);
    Misc::Zoom = cfg.GetBoolValue("zalypa", "Zoom", Misc::Zoom);
    Misc::Zoomvalue = cfg.GetLongValue("zalypa", "ActiveSlotRender", Misc::Zoomvalue);
    Misc::Zoomkey = cfg.GetLongValue("zalypa", "ActiveSlotRender", Misc::Zoomkey);
    Misc::suicide = cfg.GetBoolValue("zalypa", "suicide", Misc::suicide);
    Keys::suicide = cfg.GetLongValue("zalypa", "suicidekey", Keys::suicide);
    Misc::CustomFov = cfg.GetBoolValue("zalypa", "CustomFov", Misc::CustomFov);
    Misc::FovRange = cfg.GetLongValue("zalypa", "FovRange", Misc::FovRange);
    Misc::mass_suicide = cfg.GetBoolValue("zalypa", "mass_suicide", Misc::mass_suicide);
    Misc::Meleeatack = cfg.GetBoolValue("zalypa", "Meleeatack", Misc::Meleeatack);
    Misc::Meleeatackkey = cfg.GetLongValue("zalypa", "Meleeatackkey", Misc::Meleeatackkey);
    Misc::InfJump = cfg.GetBoolValue("zalypa", "InfJump", Misc::InfJump);
    Misc::CustomTime = cfg.GetBoolValue("zalypa", "CustomTime", Misc::CustomTime);
    Misc::Time = cfg.GetLongValue("zalypa", "Time", Misc::Time);
    Misc::FakeAdmin = cfg.GetBoolValue("zalypa", "FakeAdmin", Misc::FakeAdmin);
    Misc::omniSprint = cfg.GetBoolValue("zalypa", "omniSprint", Misc::omniSprint);
    Misc::AutoPickUp = cfg.GetBoolValue("zalypa", "AutoPickUp", Misc::AutoPickUp);
    Misc::speedhack = cfg.GetBoolValue("zalypa", "speedhack", Misc::speedhack);
    Keys::speedKey = cfg.GetLongValue("zalypa", "speedKey", Keys::speedKey);
    Misc::AutoFarm = cfg.GetBoolValue("zalypa", "AutoFarm", Misc::AutoFarm);
    Misc::AutoFarmTree = cfg.GetBoolValue("zalypa", "AutoFarmTree", Misc::AutoFarmTree);
    Misc::AutoFarmOre = cfg.GetBoolValue("zalypa", "AutoFarmOre", Misc::AutoFarmOre);
    Misc::AutoFarmBarrel = cfg.GetBoolValue("zalypa", "AutoFarmBarrel", Misc::AutoFarmBarrel);
    Misc::SwimOnGround = cfg.GetBoolValue("zalypa", "SwimOnGround", Misc::SwimOnGround);
    Misc::HighJump = cfg.GetBoolValue("zalypa", "HighJump", Misc::HighJump);
    Misc::JumpValue = cfg.GetLongValue("zalypa", "JumpValue", Misc::JumpValue);
    Misc::highkey = cfg.GetLongValue("zalypa", "highkey", Misc::highkey);
    AntiAim::anti_aim = cfg.GetBoolValue("zalypa", "anti_zalypa", AntiAim::anti_aim);
    AntiAim::anti_aim_speed = cfg.GetLongValue("zalypa", "anti_zalypa_speed", AntiAim::anti_aim_speed);
    AntiAim::anti_aim_yaw = cfg.GetLongValue("zalypa", "anti_zalypa_yaw", AntiAim::anti_aim_yaw);
    Misc::SpiderMan = cfg.GetBoolValue("zalypa", "SpiderMan", Misc::SpiderMan);
    Misc::no_playercollision = cfg.GetBoolValue("zalypa", "no_playercollision", Misc::no_playercollision);
    Visuals::NightMode = cfg.GetBoolValue("zalypa", "NightMode", Visuals::NightMode);
    Hit::CustomHitSound = cfg.GetBoolValue("zalypa", "CustomHitSound", Hit::CustomHitSound);
    Weapons::canHoldItems = cfg.GetBoolValue("zalypa", "canHoldItems", Weapons::canHoldItems);
    Weapons::AntiSpread = cfg.GetBoolValue("zalypa", "AntiSpread", Weapons::AntiSpread);
    Weapons::NoSway = cfg.GetBoolValue("zalypa", "NoSway", Weapons::NoSway);
    Weapons::Automatic = cfg.GetBoolValue("zalypa", "Automatic", Weapons::Automatic);
    Weapons::RapidFire = cfg.GetBoolValue("zalypa", "RapidFire", Weapons::RapidFire);
    Weapons::SuperEoka = cfg.GetBoolValue("zalypa", "SuperEoka", Weapons::SuperEoka);
    Weapons::SuperBow = cfg.GetBoolValue("zalypa", "SuperBow", Weapons::SuperBow);
    Weapons::FatBullet = cfg.GetBoolValue("zalypa", "FatBullet", Weapons::FatBullet);
    Weapons::LongHand = cfg.GetBoolValue("zalypa", "LongHand", Weapons::LongHand);
    Weapons::spoof_hitdistance = cfg.GetBoolValue("zalypa", "spoof_hitdistance", Weapons::spoof_hitdistance);
    Weapons::hitdistance = cfg.GetLongValue("zalypa", "hitdistance", Weapons::hitdistance);
    AimBot::FastBullet = cfg.GetBoolValue("zalypa", "FastBullet", AimBot::FastBullet);
    AimBot::SpeedBullets = cfg.GetBoolValue("zalypa", "SpeedBullets", AimBot::SpeedBullets);

#pragma region Player Color
    //  SaveColorValue("Player", "Name", Color::NameColor);
    LoadColorValue("Player", "Fov", Colors::Fov);
    LoadColorValue("Player", "Name", Colors::NameColor);
    LoadColorValue("Player", "BoxColor", Colors::BoxColor);
    LoadColorValue("Player", "DistanceColor", Colors::DistanceColor);
    LoadColorValue("Player", "PlayerHeath", Colors::PlayerHeath);
    LoadColorValue("Player", "WeaponColor", Colors::WeaponColor);
    LoadColorValue("Player", "SkeletonColor", Colors::SkeletonColor);
    LoadColorValue("Player", "LineEsp", Colors::LineEsp);
    LoadColorValue("Player", "Wounded", Colors::Wounded);
    LoadColorValue("Player", "Target_text", Colors::Target_text);
    LoadColorValue("Player", "Textesp", Colors::Textesp);
    LoadColorValue("Player", "Crosshair", Colors::Crosshair2);
    LoadColorValue("Player", "Fonts", Colors::Fonts);
    LoadColorValue("Player", "TextColor", Colors::TextColor);
    LoadColorValue("Player", "TextColor2", Colors::TextColor2);
    /*SaveColorValue("Player - Color", "Player Fill Box Color", Bools::PlayerColor::PlayerFillBoxColor);
    SaveColorValue("Player - Color", "Player Dead Color", Bools::PlayerColor::PlayerDeadColor);
    SaveColorValue("Player - Color", "Player Backpack Color", Bools::PlayerColor::PlayerBackpackColor);*/
#pragma endregion
   

#pragma endregion

#pragma region Resourse Color
    //LoadColorValue("Resourse - Color", "Stone - Ore Color", Bools::ResourcesColor::StoneOreColor);
    //LoadColorValue("Resourse - Color", "Mettal - Ore Color", Bools::ResourcesColor::MettalOreColor);
    //LoadColorValue("Resourse - Color", "Sulfure - Ore Color", Bools::ResourcesColor::SulfureOreColor);
#pragma endregion

#pragma region Construction Color
         /*LoadColorValue("Construction - Color", "Cupboard Color", Bools::ConstructionColor::CupboardColor);
         LoadColorValue("Construction - Color", "Large Wood Box Color", Bools::ConstructionColor::LargeWoodBoxColor);
         LoadColorValue("Construction - Color", "Small Stash Color", Bools::ConstructionColor::SmallStashColor);*/
#pragma endregion 
};