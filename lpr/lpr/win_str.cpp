#include "pch.h"
#include <winstring.h>
#include <corecrt_malloc.h>
#include <stdio.h>

#include "winstr.h"

/*
* in this file,every wstr or cstr always end with '\0'
*/

char* AllocateCchar(int size)
{
	return (char*)calloc(size, 1);
}

wchar_t* AllocateWchar(int size)
{
	return (wchar_t*)calloc(size, sizeof(wchar_t));
}

wchar_t* Cchar2Wchar(const char* cchar)
{
	int len = MultiByteToWideChar(CP_ACP, NULL, cchar, -1, NULL, 0);
	wchar_t* new_wchar = (wchar_t*)malloc(len * sizeof(wchar_t));

	MultiByteToWideChar(CP_ACP, NULL, cchar, -1, new_wchar, len);
	return new_wchar;
}

char* Wchar2Cchar(const wchar_t* wchar)
{
	int len = WideCharToMultiByte(CP_ACP, NULL, wchar, -1, NULL, 0, NULL,NULL);
	char* new_char = (char*)malloc(len);

	WideCharToMultiByte(CP_ACP, NULL, wchar, -1, new_char, len, NULL, NULL);
	return new_char;
}

BOOL CStrCat(char* dst, char* source)
{
	size_t len = strlen(dst) + strlen(source) + 1;
	strcat_s(dst, len, source);
	return TRUE;
}

BOOL WStrCat(wchar_t* dst, wchar_t* source)
{
	size_t len = wcslen(dst) + wcslen(source) + 1;
	wcscat_s(dst, len, source);
	return TRUE;
}
