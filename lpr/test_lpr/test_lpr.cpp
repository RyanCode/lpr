#include <iostream>
#include <Windows.h>

#include "winstr.h"

int main()
{
    const char* test = "12345中文";
    wchar_t* wchar = Cchar2Wchar(test);
    setlocale(LC_CTYPE, setlocale(LC_ALL, ""));
    printf("转换后的宽字节unicode编码字符串长度是：%lld,内容是:%ws\n",wcslen(wchar), wchar);

    char* cchar = Wchar2Cchar(wchar);
    printf("转换后的单字节ASCII编码字符串长度是：%lld,内容是:%s\n", strlen(cchar), cchar);

    printf("ccchar 是否是Unicode编码:%d\n", IsTextUnicode(cchar, sizeof(cchar), NULL));

    wchar_t* w_char = AllocateWchar(10);
    if (w_char)
    {
        WStrCat(w_char, wchar);
        free(wchar);
        printf("w_char 是:%ws\n", w_char);
    }

    /*use calloc to allocate buffer for source,or MemoryZero source before*/
    char* c_char = AllocateCchar(10);
    if (c_char)
    {
        CStrCat(c_char, cchar);
        free(cchar);
        printf("c_char 是:%s\n", c_char);
    }

    return 0;
}