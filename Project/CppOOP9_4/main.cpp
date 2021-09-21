#include <iostream>


constexpr int fib(int num)
{
    return num <= 1 ? num : fib(num - 2) + fib(num - 1);
}


template<int N>
void print()
{
    std::cout << N << std::endl;
}


struct Item
{
    int power;
    constexpr Item(int power) : power(power)  // constexpr 생성자
    {

    }

    constexpr Item operator+(const Item& other) const
    {
        return Item(power + other.power);
    }
};


template<typename T>
auto getValue(T t)
{
    if constexpr (std::is_pointer<T>()) // 컴파일 시간에 평가 됨
        return *t;
    else
        return t;
}

int main()
{
    constexpr int value = fib(10); // fib가 상수 시간에 연산이 되지 않는다면 컴파일 에러 발생.
    std::cout << value << std::endl;

    // 배열 선언에 value가 사용된 것으로 보아 컴파일 시간에 평가 되었다
    int nums[value];

    // 템플릿의 non type 파라메터에 value가 사용된 것으로 보아 컴파일 시간에 평가 되었다.
    print<value>();


    // 상수시간에 평가 됨
    constexpr Item item0(10);
    constexpr Item item1(20);
    constexpr Item newItem = item0 + item1;

    // 상수시간에 평가 됐기 때문에 배열 생성 가능
    int nums1[newItem.power];


    int num = 10;
    int *pNum = &num;

    std::cout << getValue(num) << std::endl;
    std::cout << getValue(pNum) << std::endl;


    auto func = [](int y) { // C++17부터 람다에 암시적으로 constexpr이 붙어 있음
        return y;
    };

    int nums0[func(10)]; // 람다가 상수시간에 평가 됨
}