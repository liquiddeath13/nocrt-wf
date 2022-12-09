#pragma once

////////////////////////////////////////////////
template <typename str_type>
__declspec(noinline) constexpr unsigned short hash_str(str_type data_str, int len)
{
	unsigned short crc32 = 0xFFFF;
	while (len--)
	{
		auto cur_char = *data_str++;
		if (!cur_char)
			break;

		crc32 ^= to_lower(cur_char) << 8;
		for (int i = 0; i < 8; i++)
			crc32 = crc32 & 0x8000 ? (crc32 << 1) ^ 0x8408 : crc32 << 1;

	} return crc32;
}

#define const_str_len(str) ((sizeof(str) - sizeof(str[0])) / sizeof(str[0]))
#define const_hash_str(str) [](){ constexpr unsigned short crc = hash_str(str, const_str_len(str)); return crc; }()

template <typename ptr_type>
__forceinline ptr_type encrypt_ptr(ptr_type ptr)
{
	typedef union
	{
		struct
		{
			uint16 key_1;
			uint16 key_2;
			uint16 key_3;
			uint16 key_4;
		}; ulong64 key;
	} crypt_data;

	crypt_data key
	{
		const_hash_str(__TIME__),
		const_hash_str(__DATE__),
		const_hash_str(__TIMESTAMP__),
		const_hash_str(__TIMESTAMP__)
	};

	return (ptr_type)((DWORD64)ptr ^ key.key);
}

#define e_ptr(ptr) encrypt_ptr(ptr)
////////////////////////////////////////////////

////////////////////////////////////////////////
PVOID return_address_stub = 0;
extern "C" void* _spoofer_stub();

template<typename ret = void, typename _first = void*, typename _second = void*, typename _third = void*, typename _fourth = void*, typename... _stack>
__forceinline ret spoof_call(void* function, _first a1 = _first{}, _second a2 = _second{}, _third a3 = _third{}, _fourth a4 = _fourth{}, _stack... args)
{
	struct shell_params
	{
		const void* a1;
		void* a2;
		void* a3;
	};

	shell_params call_ctx =
	{
		e_ptr(return_address_stub),
		function,
		nullptr
	};

	typedef ret(*m_shell)(_first, _second, _third, _fourth, PVOID, PVOID, _stack...);
	return ((m_shell)&_spoofer_stub)(a1, a2, a3, a4, &call_ctx, nullptr, args...);
}

__forceinline void set_spoof_stub(PVOID R15_Stub)
{
	return_address_stub = e_ptr(R15_Stub);
}

template<typename ret = void, typename... args>
__forceinline ret f_spoof_virtual(PVOID base, int index, args... add_args)
{
	return spoof_call<ret>((*(PVOID**)base)[index], base, add_args...);
}

#define f_spoof spoof_call
#define v_spoof f_spoof_virtual

p_void get_export_address(PBYTE h_dll, const wchar_t* name)
{
	PIMAGE_NT_HEADERS nt_head = (PIMAGE_NT_HEADERS)(h_dll + ((PIMAGE_DOS_HEADER)h_dll)->e_lfanew);
	PIMAGE_EXPORT_DIRECTORY exp_dir = (PIMAGE_EXPORT_DIRECTORY)(h_dll + nt_head->OptionalHeader.DataDirectory[0].VirtualAddress);

	for (ulong32 i = 0; i < exp_dir->NumberOfNames; i++)
	{
		uint16 ordinal = ((uint16*)(h_dll + exp_dir->AddressOfNameOrdinals))[i];
		const char* exp_name = (const char*)h_dll + ((ulong32*)(h_dll + exp_dir->AddressOfNames))[i];

		if (str_cmp(name, exp_name, true))
			return (p_void)(h_dll + ((ulong32*)(h_dll + exp_dir->AddressOfFunctions))[ordinal]);

	} return nullptr;
}

template <typename t, typename... args>
t c_import(const wchar_t* module_name, const wchar_t* function_name, args... add_args)
{
	PVOID f_addr = nullptr;
	if (!f_addr)
		f_addr = e_ptr(get_export_address(gmb(module_name), function_name));

	return f_spoof<t>(e_ptr(f_addr), add_args...);
}

#define call_import(Mod, Name, ...) [&](){ PVOID f_addr = nullptr; \
		if (!f_addr) f_addr = e_ptr(get_export_address(gmb(Mod), Name)); \
		return f_spoof<p_void>(e_ptr(f_addr), __VA_ARGS__); \
	}()

#define call_import_f(Mod, Name, ...) [&](){ PVOID f_addr = nullptr; \
		if (!f_addr) f_addr = e_ptr(get_export_address(gmb(Mod), Name)); \
		return f_spoof<f32>(e_ptr(f_addr), __VA_ARGS__); \
	}()

#define call_import_f64(Mod, Name, ...) [&](){ PVOID f_addr = nullptr; \
		if (!f_addr) f_addr = e_ptr(get_export_address(gmb(Mod), Name)); \
		return f_spoof<f64>(e_ptr(f_addr), __VA_ARGS__); \
	}()

#define v_import c_import
