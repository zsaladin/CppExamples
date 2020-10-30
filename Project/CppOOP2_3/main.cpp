#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;


class String
{
private:
    char* _chars;


public:
    String(const char* chars) : _chars(new char[strlen(chars) + 1])
    {
        strcpy(_chars, chars);
    }

    bool operator!() const
    {
        return strlen(_chars) == 0;
    }

    bool operator||(bool b) const
    {
        return strlen(_chars) > 0 || b;
    }
};

bool func()
{
    cout << "func" << endl;
    return true;
}

// 논리 연산자 오버로딩은 주의해야한다
int main()
{
    String s("");
    if (!s) // 된다
    {

    }

    //if (s) // 안 된다
    //{

    //}


    String s0("abc");
    if (s0 || func()) // s0가 true로 평가 됐지만 func가 실행 된다. (Short-circuit evaluation 안 됨)
    {// s0, func()의 평가 순서 보장이 안 된다. (|| 를 오버로딩함으로서 시퀀스 포인트가 아니게 됨)
        cout << "!!" << endl;
    }
    // && 오버로딩도 || 오버로딩과 같은 문제점을 가지고 있다
}