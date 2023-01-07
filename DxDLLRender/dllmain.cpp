#include "curl.h"
char dlldir[320];

DWORD64 ClientInputXD = 0;
#include "includes.h"
#include <stdlib.h>

#pragma comment(lib, "ntdll.lib")
void CreateThreadSafe(PVOID StartAddr)// патчер еака за 2 рубля
{
	typedef HANDLE(__fastcall* CreateSimpleThreadFn)(void*, PVOID, PVOID, unsigned int);
	static CreateSimpleThreadFn CST = nullptr;
	CST = (CreateSimpleThreadFn)FindPattern((PBYTE)"\x48\x89\x5C\x24\x00\x48\x89\x6C\x24\x00\x48\x89\x74\x24\x00\x57\x48\x83\xEC\x30", StrA("xxxx?xxxx?xxxx?xxxxx"), StrW(L"tier0_s64.dll"));
	CST(StartAddr, 0, 0, 0);
}
void* DetourVTable(void** VTable, int Function, void* Detour)
{
	void* ret = VTable[Function];
	DWORD old;
	VirtualProtect(&(VTable[Function]), sizeof(void*), PAGE_EXECUTE_READWRITE, &old);
	VTable[Function] = Detour;
	VirtualProtect(&(VTable[Function]), sizeof(void*), old, &old);
	return ret;
}
BOOL __stdcall DllMain(HMODULE hModule, DWORD dwCallReason, LPVOID lpReserved)
{
	PROCESS_MITIGATION_EXTENSION_POINT_DISABLE_POLICY policy; policy.DisableExtensionPoints = 1;
	PROCESS_MITIGATION_DEP_POLICY  policyf; policyf.DisableAtlThunkEmulation = 1;
	_PROCESS_MITIGATION_ASLR_POLICY  policyg; policyg.EnableBottomUpRandomization = 1;
	_PROCESS_MITIGATION_ASLR_POLICY  policyj; policyj.EnableForceRelocateImages = 1;
	_PROCESS_MITIGATION_ASLR_POLICY  policyb; policyb.EnableHighEntropy = 1;
	_PROCESS_MITIGATION_ASLR_POLICY  policyc; policyc.DisallowStrippedImages = 1;

		
	if (dwCallReason == DLL_PROCESS_ATTACH)
	{
#if AllocCons == 1
		AllocConsole();
		freopen(StrA("CONIN$"), "r", stdin);
		freopen(StrA("CONOUT$"), "w", stderr);
		freopen(StrA("CONOUT$"), "w", stdout);
#endif
		srand((unsigned)time(NULL));
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		il2cpp::init();
		init_bp();
		unity::init_unity();
		//CreateThread(NULL, 0, Start, NULL, 0, NULL);
		DetourTransactionCommit();
		CreateThreadSafe(Start);
	}
	return TRUE;
}