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

    ~String()
    {
        delete[] _chars;
    }

    char operator[](int index) const
    {
        return _chars[index];
    }

    char& operator[](int index)
    {
        return _chars[index];
    }

    friend std::ostream& operator<<(std::ostream& os, const String& s)
    {
        os << s._chars;
        return os;
    }
};

