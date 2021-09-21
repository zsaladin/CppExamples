#include <iostream>
#include <functional>

void foo(std::function<void(void)> func)
{

}

void goo(int)
{

}

struct Func // 사실 람다는 함수객체
{
    int value;
    void operator()() const // mutable 시 함수 객체 삭제 됨
    {

    }
};

struct Test
{
    int num = 10;
    auto func()
    {
        return [num = num] { // 캡쳐하는 위치에서 초기화
            return num;
        };
    }
};

int main()
{
    // 기본적인 lambda의 형태
    [/*캡쳐*/](/*파라메터*/) /*반환형*/
    {
    };

    int value = 10;
    // foo(goo); 넘겨줄 수 없음
    foo([value]() // 캡쳐해서 넘겨줄 수 있음
        {
            goo(value);
        });
    foo([&value]() // 참조로 캡쳐
        {
            goo(value);
        });

    foo([value]() mutable // 함수객체에서 const를 삭제
        {
            value = 20;
            goo(value);
        });

    Func func;
    func.value = value;
    foo(func); // 람다의 사용은 이것과 유사함


    int num = 10;
    auto func0 = [num]() mutable
    {
        ++num;
        return num;
    };
    // 일반적으로 함수 호출 시 내부의 값이 변하게 되면 의도하지 않은 상황이 발생할 수 있다. 때문에 기본적으로 mutable이 아님
    std::cout << func0() << std::endl; // 11
    std::cout << func0() << std::endl; // 12


    int num0 = 10;
    int num1 = 20;

    [=]() // 모든 녀석을 값으로 캡쳐 가능
    {
    };

    [&]() // 모든 변수를 참조로 캡쳐 가능
    {
    };


    void (*f)(int) = [](int) {};  // 캡쳐 없는 람다는 함수 포인터와 호환 됨

    auto f0 = [](int) {};  // 선언 시 auto 사용
    std::function<void(int)> f1 = [](int) {}; // 선언 시 std::function 사용

    auto f2 = [](auto value) // Generic 람다
    {
        return value;
    };

    auto f3 = []<typename T>(T value) // 템플릿 람다, C++20
    {
        return value;
    };

}