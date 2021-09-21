#include <iostream>

using std::cout;
using std::endl;

int f() { return 20; }
int func() { return 10; }

struct Person
{
    float weight;
    float height;
};

struct Wrapper0
{
    int value;
    int getValue() const
    {
        return value;
    }
};

struct Wrapper1
{
    float value;
    float& getValue()
    {
        return value;
    }
};

template<typename T>
auto getValue(T& t) -> decltype(auto) // decltype(t.getValue())
{
    return t.getValue();
}

int main()
{
    decltype(1) num0 = 10; // decltype 내부의 표현식의 타입을 컴파일 타입에 추론

    decltype(num0) num1 = 20;
    decltype(num1)& num2 = num1;

    const decltype(num0)& num3 = 10;
    const decltype(num0)& num4 = num2;

    decltype((num0)) num5 = num0; // int&
    decltype(1 + 22.2f) num6 = 1.f;

    int nums0[] = { 1, 2, 3 };
    decltype(nums0) nums1 = { 1, 2, 3 };

    decltype(func) f; // 함수를 선언한 것과 동일, 즉 func의 함수의 모양의 f 함수를 선언한 것, int f(); 와 동일
    cout << f() << endl; // 20 // 구현체가 없다면 에러 발생

    decltype(func)& f0 = func;
    cout << f0() << endl; // 10

    decltype(func)* f1 = func;
    cout << f1() << endl; // 10

    decltype(func()) num7 = 20;  // func() 가 실행되는 것은 아님. 단지 반환형의 타입만 컴파일 시간에 추론 됨

    Person p;
    decltype(p.weight) weight0;
    decltype(Person::weight) weight1;


    int n0 = 10;
    auto n1 = 20;
    decltype(n0) n2 = 30;
    decltype(auto) n3 = 30; // auto는 30에 의해서 int로 추론

    Wrapper0 w0{ 0 };
    Wrapper1 w1{ 1 };

    getValue(w0); // 값
    getValue(w1) = 10;
}