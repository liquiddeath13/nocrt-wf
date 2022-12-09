#pragma once

size_t f_wcslen(const wchar_t* str)
{
	return v_import<size_t>(xor_w(L"msvcrt"), xor_w(L"wcslen"), str);
}

void* f_calloc(size_t number, size_t size)
{
	return v_import<void*>(xor_w(L"msvcrt"), xor_w(L"calloc"), number, size);
}

void* f_malloc(size_t size)
{
	return v_import<void*>(xor_w(L"msvcrt"), xor_w(L"malloc"), size);
}

void* vswprintf_ms(wchar_t* _Buffer, wchar_t const* _Format, va_list _ArgList)
{
	return v_import<void*>(xor_w(L"msvcrt"), xor_w(L"vswprintf_s"), _Buffer, _Format, _ArgList);
}

void* f_free(void* memblock)
{
	return v_import<void*>(xor_w(L"msvcrt"), xor_w(L"free"), memblock);
}

float f_powf(float x, float y)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"powf"), x, y);
}

float f_cosf(float x)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"cosf"), x);
}

float f_sinf(float x)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"sinf"), x);
}

float f_acosf(float x)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"acosf"), x);
}

float f_asinf(float x)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"asinf"), x);
}

float f_atanf(float x)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"atanf"), x);
}

float f_atan2f(float x, float y)
{
	return v_import<float>(xor_w(L"msvcrt"), xor_w(L"atan2f"), x, y);
}

char* f_strcat(char* dest, const char* source)
{
	return v_import<char*>(xor_w(L"msvcrt"), xor_w(L"strcat"), dest, source);
}

void* m_memcpy(void* dest, void* src, unsigned int len)
{
	unsigned int i;
	char* char_src = (char*)src;
	char* char_dest = (char*)dest;
	for (i = 0; i < len; i++)
	{
		char_dest[i] = char_src[i];
	}
	return dest;
}

void* m_memset(void* dest, char c, unsigned int len)
{
	unsigned int i;
	unsigned int fill;
	unsigned int chunks = len / sizeof(fill);
	char* char_dest = (char*)dest;
	unsigned int* uint_dest = (unsigned int*)dest;
	fill = (c << 24) + (c << 16) + (c << 8) + c;

	for (i = len; i > chunks * sizeof(fill); i--)
	{
		char_dest[i - 1] = c;
	}

	for (i = chunks; i > 0; i--)
	{
		uint_dest[i - 1] = fill;
	}

	return dest;
}

int _stdcall m_is_bad_read_ptr(const void* lp, unsigned int ucb)
{
	return (ucb && (!lp || (char*)lp + ucb - 1 < lp));
}

int _stdcall m_is_bad_code_ptr(FARPROC lpfn)
{
	return m_is_bad_read_ptr(lpfn, 1u);
}

char* __cdecl m_strstr(const char* str1, const char* str2)
{
	char* cp = (char*)str1;
	char* s1, * s2;

	if (!*str2)
		return((char*)str1);

	while (*cp)
	{
		s1 = cp;
		s2 = (char*)str2;

		while (*s1 && *s2 && !(*s1 - *s2))
			s1++, s2++;

		if (!*s2)
			return(cp);

		cp++;
	}

	return(0);
}

char* __cdecl m_strchr(const char* string, int ch)
{
	while (*string && *string != (char)ch)
		string++;
	if (*string == (char)ch)
		return((char*)string);
	return(NULL);
}

int m_strcmp(const char* src, const char* dst)
{
	int ret = 0;
	unsigned char* p1 = (unsigned char*)src;
	unsigned char* p2 = (unsigned char*)dst;
	while (!(ret = *p1 - *p2) && *p2)
		++p1, ++p2;

	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;

	return ret;
}

char* m_strcpy(char* dest, const char* src)
{
	char* ret = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return ret;
}

unsigned m_strlen(const char* str)
{
	int cnt = 0;
	if (!str)
		return 0;
	for (; *str != '\0'; ++str)
		++cnt;
	return cnt;
}

unsigned m_strlen_w(const wchar_t* str)
{
	int cnt = 0;
	if (!str)
		return 0;
	for (; *str != '\0'; ++str)
		++cnt;
	return cnt;
}

void m_read_data(const uint64_t address, void* p_data, int32_t size)
{
	if (!m_is_bad_read_ptr((void*)address, size))
		m_memcpy(p_data, (void*)address, size);
}

bool m_prefix(const char* pre, const char* str)
{
	char cp;
	char cs;

	if (!*pre)
		return 1;

	while ((cp = *pre++) && (cs = *str++))
	{
		if (cp != cs)
			return 0;
	}

	if (!cs)
		return 0;

	return 1;
}
