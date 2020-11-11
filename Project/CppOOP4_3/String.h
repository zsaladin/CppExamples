#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

class String
{
private:
    char* _chars;

public:
    String(const char* chars)
        : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    // 기존 구현(중복 코드)
    //char& operator[](int index)
    //{
    //    return _chars[index];
    //}

    //const char& operator[](int index) const
    //{
    //    return _chars[index];
    //}

    // const_cast를 이용하여 중복 삭제
    char& operator[](int index)
    {
        const String& s = *this;
        const char& c = s[index];
        return const_cast<char&>(c);
    }

    const char& operator[](int index) const
    {
        return _chars[index];
    }
};


void stringFunc()
{
    String s0("abc");
    std::cout << s0[0] << std::endl;

    const String& s1 = s0;
    std::cout << s1[0] << std::endl;
}
