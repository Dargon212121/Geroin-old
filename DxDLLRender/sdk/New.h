
//FACE NoImporter v2
#define FC_NTDLL(Name, ...) [&](){static DWORD64 FAddr;if(!FAddr)FAddr=GetExport(GetModBase(((const wchar_t*)1)),StrA(#Name));return((decltype(Name(__VA_ARGS__))(*)(...))FAddr)(__VA_ARGS__);}()
#define FC(Mod, Name, ...) [&](){static DWORD64 FAddr;if(!FAddr)FAddr=GetExport(LoadLibUnc({sizeof(L#Mod)-2,sizeof(L#Mod),(PWSTR)(StrW(L#Mod))}),StrA(#Name));return((decltype(Name(__VA_ARGS__))(*)(...))FAddr)(__VA_ARGS__);}()



//FACE Str Helper v2
#define FC_FORMAT_A(...) [&](){wchar_t Str[64];FC_NTDLL(_swprintf, Str, __VA_ARGS__);return Str;}()
#define FC_FORMAT_W(...) [&](){wchar_t Str[64];FC_NTDLL(_swprintf, Str, __VA_ARGS__);return Str;}()
#define FC_WCHAR(a) [&](){wchar_t Str[64];for(int i=0;;i++){if(!(Str[i]=a[i]))break;}return Str;}()

//FACE DBG Helper v2
//#define printf(...) { char* Str = FC_FORMAT_A(__VA_ARGS__); WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), Str, FC_NTDLL(strlen, Str), NULL, NULL); }
#define dp(a) { char Buff[32]; FC_NTDLL(sprintf, Buff, "Dec (%d): %d\n",  __LINE__, (a)); WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), Buff, FC_NTDLL(strlen, Buff), NULL, NULL); }
#define hp(a) { char Buff[32]; FC_NTDLL(sprintf, Buff, "Hex (%d): %p\n",  __LINE__, (a)); WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), Buff, FC_NTDLL(strlen, Buff), NULL, NULL); }
#define sp(a) { char Buff[32]; FC_NTDLL(sprintf, Buff, "Str (%d): %s\n",  __LINE__, (a)); WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), Buff, FC_NTDLL(strlen, Buff), NULL, NULL); }
#define v3p(a) { char Buff[32]; FC_NTDLL(sprintf, Buff, "Vec3 (%d): %d %d %d\n",  __LINE__, (int)a.x, (int)a.y, (int)a.z); WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE), Buff, FC_NTDLL(strlen, Buff), NULL, NULL);
#define v3p_crt(a) printf("Vec3 (%d): %f %f %f\n", __LINE__, a.x, a.y, a.z);
