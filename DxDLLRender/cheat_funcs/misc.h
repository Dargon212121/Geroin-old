void WeaponPatch() {
    USHORT Hash = 0;
    WeaponData* Weapon = LocalPlayer.BasePlayer->GetActiveWeapon();
    if (Weapon) Hash = Weapon->GetNameHash();
    switch (Hash) {
    case 0: return;
    case 0x5A9F:
        if (Weapons::SuperBow)
            Weapon->SuperBow();
        break;
    case 0x6B1:
    case 0x74F5:
    case 0x67DA:
    case 0x3146:
    case 0x79C4:
    case 0x573C:
    case 0xB32A:
    case 0xC196:
        Weapon->RapidFire();
        Weapon->SetAutomatic();
        Weapon->NoRecoil();
    case 0x7983:
    case 0xE5EA:
    case 0x77E9:
    case 0xE97D:
    case 0xC2DD:
    case 0x52F7:
    case 0xFDC3:
    case 0x62E5:
    case 0x6A09:
    case 0x3511:
    case 0xCFA1:
    case 0xF87E:
        Weapon->RapidFire();
        Weapon->NoRecoil();
    case 0xB0A0:
    case 0x435E:
    {
        if (Hash == 0x435E)
        {
            Weapon->RapidFire();
            Weapon->SetAutomatic();
            Weapon->SuperEoka();
            Weapon->AntiSpread();
            Weapon->NoRecoil();
        }
    } break;
    Weapon->RapidFire();
    Weapon->NoRecoil();
    case 0xF3B9:
        Weapon->NoRecoil();
        break;
    case 0xCBD8:
    case 0xAB85:
    case 0xFB2B:
    case 0x6104:
    case 0xC859:
    case 0x96D3:
    case 0x7340:
    case 0xC68B:
    case 0x2F12:
    case 0x65B4:
    case 0x1F2D:
    case 0x2658:
    case 0xAC02:
    case 0x282A:
    case 0x8151:
    case 0xFACE:
    case 0x7296:
    case 0x4B0A:
    case 0xCD:
    case 0x2333:
        //    if (Misc::longhand) {
        //        Weapon->FatHand();
        //        Weapon->LongHand();
        //        Weapon->RunOnHit();
        //    }
        //break;
        break;
    }
}

void MiscFuncs() {
	LocalPlayer.BasePlayer->SetFov();
	if (Misc::SpiderMan)
		LocalPlayer.BasePlayer->SpiderMan();

	if (Misc::CustomFov)
		LocalPlayer.BasePlayer->SetFov();
	if (Misc::Zoom)
		LocalPlayer.BasePlayer->Zoom();
	if (Misc::InfJump) {
		if (GetAsyncKeyState(VK_SPACE)) {
			LocalPlayer.BasePlayer->InfinityJump();
		}
	}
	if (Misc::CustomTime) {
		LocalPlayer.BasePlayer->Admintime();
	}
	if (Weapons::NoSway)
		LocalPlayer.BasePlayer->NoSway();
	if (Misc::SilentWalk)
		LocalPlayer.BasePlayer->SetRemoveFlag(4);
	if (Misc::FakeAdmin)
		LocalPlayer.BasePlayer->FakeAdmin();


	if (Misc::HighJump) {
		if (FC(user32, GetAsyncKeyState, Misc::highkey))
			LocalPlayer.BasePlayer->SetGravity(Misc::JumpValue);
		else LocalPlayer.BasePlayer->SetGravity(3.0f);
	}
	if (AimBot::RCS)
		LocalPlayer.BasePlayer->SetRA();
    if (Misc::LongNeck) {
        if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey))
            LocalPlayer.BasePlayer->LongNeck(1.4f);
    }
    if (Misc::LongNeckLeft) {
        if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey1))
            LocalPlayer.BasePlayer->LongNeckrLeft();
    }
    if (Misc::LongNeckright) {
        if (FC(user32, GetAsyncKeyState, Misc::LongNeckkey2))
            LocalPlayer.BasePlayer->LongNeckright();
    }

}
