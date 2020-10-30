#pragma warning(disable: 4996)
#include <iostream>


using namespace std;


class String
{
private:
    char* _chars;

public:
    /* explicit */ String(const char* chars) // explicit 를 사용하지 않으면 암시적으로 형변환이 된다.
        : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    /* explicit */ String(const char* s0, const char* s1)
        : _chars(new char[strlen(s0) + strlen(s1) + 1])
    {
        _chars[0] = '\0';
        strcat(_chars, s0);
        strcat(_chars, s1);
    }

    /* explicit */ String(std::initializer_list<const char*> strs)
        : _chars(nullptr)
    {
        size_t size = 0;
        for (const char* str : strs)
        {
            size += strlen(str);
        }
        _chars = new char[size + 1];
        _chars[0] = '\0';

        for (const char* str : strs)
        {
            strcat(_chars, str);
        }
    }

    ~String()
    {
        delete[] _chars;
    }

    // 논리 연산자 오버로딩 대신 bool 변환 연산자를 고려해보자
    /* explicit */ operator bool() const // explicit 가 없다면 암시적으로도 형변환이 가능해진다
    {
        return strlen(_chars) > 0;
    }

    void print() const
    {
        cout << _chars << endl;
    }
};


void func(String s)
{
    s.print();
}

int main()
{
    String s0 = "abc"; // 암시적 변환
    s0.print();

    func("abc"); // 암시적 변환

    String s1{ "abc", "efg" };
    s1.print();

    String s2{ "a", "b", "c", "d" };
    s2.print();

    String s3 = "a";
    bool result = s3; // 변환 연산자
    cout << result << endl;

    if (s3) // 변환 연산자
    {
        s3.print();
    }

    String s4 = "";
    result = s4;
    cout << result << endl;

    if (s4)
    {
        s4.print();
    }
}