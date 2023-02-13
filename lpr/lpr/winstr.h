#pragma once

#ifndef WINSTR_H
#define WINSTR_H

#include "lpr.h"

LPR_API char* AllocateCchar(int size);
LPR_API wchar_t* AllocateWchar(int size);

LPR_API wchar_t* Cchar2Wchar(const char* cchar);
LPR_API char* Wchar2Cchar(const wchar_t* wchar);

LPR_API BOOL CStrCat(char* dst, char* source);
LPR_API BOOL WStrCat(wchar_t* dst, wchar_t* source);

#endif // !WINSTR_H
