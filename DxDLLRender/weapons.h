
struct Ammo {
	int id[2];
	float speed;
};
struct Weapon {
	int id;
	const char* name;
	Ammo ammo[4];
	int category; //-3 - hammer, -2 - bows, -1 - eoka, 0-nopatch, 1 - meele, 2 - semiautomatic, 3 - automatic
};
Weapon info[]{
Weapon{1588298435, StrA("Bolt Action Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 656}, Ammo{{1712070256} /*HV 5.56*/, 788 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 394}}, 2 },
Weapon{-778367295, StrA("L96 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 1125}, Ammo{{1712070256} /*HV 5.56*/, 1350 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 675}}, 2 },
Weapon{-2069578888, StrA("M249"), { Ammo{{-1211166256}/*normal 5.56*/, 488}, Ammo{{1712070256} /*HV 5.56*/, 585 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 293}}, 3 },

Weapon{1318558775, StrA("MP5A4"), { Ammo{{785728077}/*normal pistol*/, 240}, Ammo{{-1691396643} /*HV pistol*/, 320}, Ammo{{51984655} /*inc pistol*/, 180}}, 3 },
Weapon{1796682209, StrA("Custom SMG"), { Ammo{{785728077}/*normal pistol*/, 240}, Ammo{{-1691396643} /*HV pistol*/, 320}, Ammo{{51984655} /*inc pistol*/, 180}}, 3 },

Weapon{-1367281941, StrA("Waterpipe Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-765183617, StrA("Double Barrel Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-41440462, StrA("Spas-12 Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{795371088, StrA("Pump Shotgun"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, 2 },
Weapon{-75944661, StrA("Eoka Pistol"), { Ammo{{-727717969, -1685290200}/*green, red*/, 225}, Ammo{{588596902, -1036635990}/*gray, blue*/, 100}}, -1 },


Weapon{28201841, StrA("M39 Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 469}, Ammo{{1712070256} /*HV 5.56*/, 563 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 281}}, 2 },

Weapon{1965232394, StrA("Crossbow"), { Ammo{{-1234735557}/*normal arrow*/, 75.f}, Ammo{{14241751} /*fire arrow*/, 60}, Ammo{{215754713} /*bone arrow*/, 68}, Ammo{{-1023065463} /*HV arrow*/, 120}}, 2 },
Weapon{884424049, StrA("Compound Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 80}}, 2 }, //TODO on zoom velocity x2
Weapon{1443579727, StrA("Hunting Bow"), { Ammo{{-1234735557}/*normal arrow*/, 50.f}, Ammo{{14241751} /*fire arrow*/, 40}, Ammo{{215754713} /*bone arrow*/, 45}, Ammo{{-1023065463} /*HV arrow*/, 80} }, -2 },


Weapon{649912614, StrA("Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{818877484, StrA("Semi-Automatic Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{-852563019, StrA("M92 Pistol"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 2 },
Weapon{1373971859, StrA("Python Revolver"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol 225*/, 210}}, 2 },
Weapon{-1758372725, StrA("Thompson"), { Ammo{{785728077}/*normal pistol*/, 300}, Ammo{{-1691396643} /*HV pistol*/, 400}, Ammo{{51984655} /*inc pistol*/, 225}}, 3 },

Weapon{-1812555177, StrA("LR-300 Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-904863145, StrA("Semi-Automatic Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 2 },
Weapon{1545779598, StrA("Assault Rifle"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },
Weapon{-1214542497, StrA("Handmade LMG"), { Ammo{{-1211166256}/*normal 5.56*/, 375}, Ammo{{1712070256} /*HV 5.56*/, 450 }, Ammo{{-1321651331, 605467368}/*inc, ex 5.56*/, 225}}, 3 },


Weapon{1090916276, StrA("Pitchfork"), {Ammo{{0}, 25}}, 1 },
Weapon{1540934679, StrA("Wooden Spear"), {Ammo{{0}, 20}}, 1 },
Weapon{1814288539, StrA("Bone Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{-363689972, StrA("Snowball"), {Ammo{{0}, 20}}, 1 },
Weapon{1789825282, StrA("Candy Cane Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1137865085, StrA("Machete"), {Ammo{{0}, 20}}, 1 },
Weapon{1711033574, StrA("Bone Club"), {Ammo{{0}, 20}}, 1 },
Weapon{-1966748496, StrA("Mace"), {Ammo{{0}, 18}}, 1 },
Weapon{-194509282, StrA("Butcher Knife"), {Ammo{{0}, 20}}, 1 },
Weapon{1326180354, StrA("Salvaged Sword"), {Ammo{{0}, 20}}, 1 },
Weapon{-1469578201, StrA("Longsword"), {Ammo{{0}, 18}}, 1 },
Weapon{-1978999529, StrA("Salvaged Cleaver"), {Ammo{{0}, 18}}, 1 },
Weapon{1602646136, StrA("Stone Spear"), {Ammo{{0}, 25}}, 1 },
Weapon{2040726127, StrA("Combat Knife"), {Ammo{{0}, 30}}, 1 },
Weapon{963906841, StrA("Rock"), {Ammo{{0}, 18}}, 1 },

Weapon{1953903201, StrA("Nailgun"), { Ammo{{-2097376851}/*nails*/, 50}}, 2 },
Weapon{-1123473824, StrA("Multiple Grenade Launcher"), { Ammo{{915408809, 349762871}/*smoke, exp*/, 100}, Ammo{{1055319033}, 225}/*shotgun*/}, 2 },
Weapon{442886268, StrA("Rocket Launcher"), 0, 0 },
Weapon{-1215753368, StrA("Flame Thrower"), 0, 0 },
Weapon{200773292, StrA("Hammer"), {0}, -3 }
};