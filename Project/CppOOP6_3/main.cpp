#include <iostream>
#include <vector>
#include "swap.h"

using std::cout;
using std::endl;


// 템플릿 특수화
template<typename T, typename S>
class Test
{
public:
    T num0;
    S num1;
};


// 완전 특수화
template<>
class Test<int, float>
{

};


// 부분 특수화
template<typename T>
class Test<T, T>
{

};



int main()
{
    Foo f0, f1;
    swap(f0, f1);

    int x = 10, y = 20;
    int* px = &x, * py = &y;
    swap(px, py);

    cout << x << endl;
    cout << y << endl;


    Test<int, int> t0;
    Test<int, float> t1;
    Test<float, int> t2;

    // bool을 그대로 사용하면 효율이 떨어지기 때문에 vector에서 특수화를 사용한다
    std::vector<bool> vb;
}