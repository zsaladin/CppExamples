#pragma once

#include <iostream>
#include <functional>

using namespace std;


void func(int num)
{
    cout << num << endl;
}

typedef float real32_0;  // float의 별칭 real32
typedef double real64_0; // double의 별칭 real64

typedef void (*FuncType_0)(int);


using real32_1 = float;  // float의 별칭 real32
using real64_1 = double; // double의 별칭 real64

using FuncType_1 = void (*)(int);


void type()
{
    // 길거나 복잡한 타입에 대해 간략하게 표현할 수 있다.
    auto f0 = func;
    f0(1);

    auto& f1 = func;
    f1(2);

    function<void(int)> f2 = func;
    f2(3);

    FuncType_0 f3 = func;
    f3(4);

    FuncType_1 f4 = func;
    f4(5);
}
