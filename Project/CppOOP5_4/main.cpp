#include <iostream>

using std::cout;
using std::endl;


// 소멸자는 기본적으로 noexcept 함수

void func() noexcept // 해당 함수에서는 예외가 나지 않는다고 선언, 컴파일러가 최적화 할 수 있다
{
    //throw 1; // noexcept 선언한 함수에서 throw 된다고 하더라도 try catch로 처리할 수 없다
}

int main()
{
    try
    {
        func();
    }
    catch (int e)
    {

    }

    // 몇몇 STL 함수에서는 noexcept로 지정된 함수가 제공되지 않는 경우 성능 손실이 생길 수 있다
}