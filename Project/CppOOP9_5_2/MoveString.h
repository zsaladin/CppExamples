#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>


class MoveString
{
private:
    char* _str;

public:
    MoveString(const char* str)
        : _str(new char[strlen(str) + 1])
    {
        strcpy(_str, str);
        std::cout << "MoveString Construct : " << _str << std::endl;
    }

    MoveString(const MoveString& other)
        : _str(new char[strlen(other._str) + 1])
    {
        strcpy(_str, other._str);
        std::cout << "MoveString Copy Construct : " << _str << std::endl;
    }

    MoveString(MoveString&& other) noexcept
        : _str(std::move(other._str))
    {
        std::cout << "Move Construct : " << _str << std::endl;
        other._str = nullptr;
    }

    ~MoveString()
    {
        std::cout << "MoveString Destruct : " << (_str ? _str : "") << std::endl;
    }

    MoveString& operator=(const MoveString& other)
    {
        std::cout << "MoveString Copy operator : " << _str << " = " << other._str << std::endl;
        delete[] _str;

        _str = new char[strlen(other._str) + 1];
        strcpy(_str, other._str);
        return *this;
    }

    MoveString& operator=(MoveString&& other) noexcept // && 우측값 참조, 이동 연산자 오버로딩
    {
        std::cout << "MoveString Move operator : " << (_str ? _str : "") << " = " << other._str << std::endl;
        delete[] _str;
        _str = std::move(other._str);
        other._str = nullptr;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, MoveString& str)
    {
        return (os << str._str);
    }
};
