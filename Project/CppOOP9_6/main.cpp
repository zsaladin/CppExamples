#include <iostream>
#include <type_traits>


void goo(int&& value)
{
    std::cout << "goo(int&&)" << std::endl;
}

void goo(int& value)
{
    std::cout << "goo(int&)" << std::endl;
}

void foo(int&& value) // r-value reference 는 l-value
{
    goo(std::move(value)); // std::move를 이용해 void goo(int&&)로 넘겨주자
}

void lref(int&) {}
void rref(int&&) {}

template<typename T>
void uref(T&& t) {}


template<typename T>
void func(T&& t)
{
    // Reference collapsing
    // && + & -> &
    // & + && -> &
    // && + && -> &&

    std::cout << "lvalue ref T : " << std::is_lvalue_reference_v<T> << std::endl;
    std::cout << "rvalue ref T : " << std::is_rvalue_reference_v<T> << std::endl;

    std::cout << "lvalue ref T& : " << std::is_lvalue_reference_v<T&> << std::endl;
    std::cout << "rvalue ref T& : " << std::is_rvalue_reference_v<T&> << std::endl;

    std::cout << "lvalue ref T&& : " << std::is_lvalue_reference_v<T&&> << std::endl;
    std::cout << "rvalue ref T&& : " << std::is_rvalue_reference_v<T&&> << std::endl;
}

template<typename T>
void func0(T&& value)
{
    func1(std::forward(value)); // 완벽 전달
}

void func1(int&& value)
{

}

void func1(int& value)
{

}

int main()
{
    std::move(10);

    int num = 10;
    std::move(num);

    // 위 두 std::move 가 같은 함수.
    // 내부적으로 T&& 와 같은 형식으로 받음(보편 참조)
    // 템플릿 타입 파라메터, auto와 같이 타입 추론이 발생하는 곳에 &&가 붙으면 보편 참조


    //lref(10); // 안 됨
    lref(num);

    rref(10);
    //rref(num); // 안 됨
    
    uref(10);
    uref(num);

    func(num);
    std::cout << std::endl;

    int& num0 = num;
    func(num0);
    std::cout << std::endl;

    func(10);
    std::cout << std::endl;
}