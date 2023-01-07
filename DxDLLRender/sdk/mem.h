template <typename T>
T Read(DWORD64 address) {
	if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000) {
		return *(T*)(address);
	}
	else {
		return T{};
	}
}
template <typename T>
void Write(DWORD64 address, T data) {
	if (address > 0x40000 && (address + sizeof(T)) < 0x7FFFFFFF0000) {
		*(T*)(address) = data;
	}
}
#define read(Addr, Type) Read<Type>((DWORD64)Addr)
#define write(Addr, Data, Type) Write<Type>((DWORD64)Addr, Data);
#define CALLED_BY(func,off) (reinterpret_cast<std::uint64_t>(_ReturnAddress()) > func && reinterpret_cast<std::uint64_t>(_ReturnAddress()) < func + off)
#define OFFSETFIELD(type, name, offset) struct {unsigned char _pad##__COUNTER__[offset]; type name;}
#define memcpy(Dst, Src, Size) memcpy_wrapper(((ULONG64)Dst), ((ULONG64)Src), Size)
void memcpy_wrapper(ULONG64 Dst, ULONG64 Src, ULONG Sz)
{
	if ((((ULONG64)Dst) > 0x400000) && (((ULONG64)Dst + Sz) < 0x00007FFFFFFF0000))
	{
		while (true)
		{
			if (Sz >= 8)
			{
				*(ULONG64*)Dst = *(ULONG64*)Src;
				Dst += 8; Src += 8; Sz -= 8;
			}
			else if (Sz >= 4)
			{
				*(ULONG*)Dst = *(ULONG*)Src;
				Dst += 4; Src += 4; Sz -= 4;
			}
			else if (Sz >= 2)
			{
				*(WORD*)Dst = *(WORD*)Src;
				Dst += 2; Src += 2; Sz -= 2;
			}
			else if (Sz)
			{
				*(BYTE*)Dst = *(BYTE*)Src;
				break;
			}
			else
				break;
		}
	}
}

