#include <iostream>
#include <cstdarg>


using std::cout;
using std::endl;


// C 스타일 가변인자
int sum0(int count, ...)
{
    int result = 0;
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; ++i)
    {
        result += va_arg(args, int);
    }
    va_end(args);
    return result;
}


template<typename T>
T sum1(T value) // unpack에 마지막 인자가 남았을 때
{
    return value;
}

// C++ 스타일 가변인자
template<typename T, typename... Args>
T sum1(T value, Args... args)
{
    return value + sum1(args...); // unpack
}




int main()
{
    cout << sum0(4, 10, 20, 30, 40) << endl;
    cout << sum1(10, 20, 30, 40) << endl;
}