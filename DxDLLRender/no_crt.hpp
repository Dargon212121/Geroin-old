#pragma once
#include <cstdlib>
#include <intrin.h>

int _purecall(void);

namespace std
{

	[[noreturn]] inline void __cdecl _Xbad_function_call() { __ud2(); }
	[[noreturn]] inline void __cdecl _Xbad_alloc() { __ud2(); }
	[[noreturn]] inline void __cdecl _Xlength_error(char const*) { __ud2(); }
	[[noreturn]] inline void __cdecl _Xout_of_range(char const*) { __ud2(); }
	[[noreturn]] inline void __cdecl  __security_check_cookie() { __ud2(); }
} // namespace std

#ifndef _DEBUG
extern "C" void __chkstk() {} // Disables stack allocation size limits.
extern "C" void __CxxFrameHandler4() { __ud2(); }
extern "C" void __std_terminate() { __ud2(); }
extern "C" void _fltused() { __ud2(); }
#endif

#define _Xlength_error(x) __ud2()
#define ABS(N) ((N<0)?(-N):(N))



unsigned my_rand()
{
	if (!lfsr) {
		lfsr = 0xACE1u; bit = 0;
	}
	bit = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5)) & 1;
	return lfsr = (lfsr >> 1) | (bit << 15);
}

char* m_strstr(char* input, const char* find)
{
	do {
		const char* p, * q;
		for (p = input, q = find; *q != '\0' && *p == *q; p++, q++) {}
		if (*q == '\0') {
			return input;
		}
	} while (*(input++) != '\0');
	return 0;
}
