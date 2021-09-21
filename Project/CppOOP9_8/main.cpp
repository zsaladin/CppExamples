#include <iostream>
#include <functional>

template<typename T>
void foo()
{
    std::cout << typeid(T).name() << std::endl; // 템플릿 타입 인자 출력, 이 경우는 함수 타입을 출력하기 위함
}


int func(float) 
{
    return 1;
}

struct Func
{
    int operator()(float value) const
    {
        return 3;
    }

    static int func0(float value)
    {
        return 4;
    }

    int func1(float value) const
    {
        return 5;
    }
};

void funcnnn(int n1, int n2, int n3)
{
    std::cout << n1 << std::endl;
    std::cout << n2 << std::endl;
    std::cout << n3 << std::endl;
}


int main()
{
    foo<int(float)>(); // 함수 타입 출력

    std::function<int(float)> f = func;
    std::cout << f(5.1f) << std::endl;

    f = [](float value) { return 2; };
    std::cout << f(5.1f) << std::endl;

    f = Func();
    std::cout << f(5.1f) << std::endl;

    f = Func::func0;
    std::cout << f(5.1f) << std::endl;

    {
        // 멤버 함수

        // std::function 을 사용하지 않는 일반 함수 포인터로 멤버 함수를 가리킬 때
        int(Func:: * f0)(float) const = &Func::func1;
        std::cout << (Func().*f0)(2) << std::endl;

        // 멤버 함수는 첫번째 인자에 자기자신을 암시적으로 받는다
        std::function<int(const Func&, float)> f1 = &Func::func1;
        std::cout << f1(Func(), 5.1f) << std::endl;

        std::function<int(float)> f2 = std::bind(&Func::func1, Func(), std::placeholders::_1);
        std::cout << f2(5.1f) << std::endl;

        std::function<int(const Func&)> f3 = std::bind(&Func::func1, std::placeholders::_1, 5.1f);
        std::cout << f3(Func()) << std::endl;
    }

    {
        std::cout << std::endl;
        std::bind(funcnnn, std::placeholders::_3, std::placeholders::_1, std::placeholders::_2)
            (1, 2, 3);
    }
}