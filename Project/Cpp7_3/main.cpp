#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;


int main()
{
    {
        // 문자 배열(문자열)을 포인터로 가리킴
        char str0[] = "abcd";
        char* str1 = str0;

        cout << str0 << endl;
        cout << str1 << endl;
    }
    {
        // 문자열 리터럴
        const char* str2 = "hello";
        cout << str2 << endl;

        cout << typeid("hello").name() << endl;
    }
    {
        char str0[100] = "abcd";
        char* str1 = str0;
        const char* str2 = "hello";

        cout << strlen(str2) << endl;
        strcpy(str0, str2);
        cout << str0 << endl;

        cout << strcmp(str0, str2) << endl;
    }
}