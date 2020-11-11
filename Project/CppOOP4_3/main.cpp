#include <iostream>
#include "String.h"


using std::cout;
using std::endl;


int volotileFunc()
{
    // volatile 컴파일 타임 최적화를 하지 않겠다.
    // 매번 메모리에서 읽어서 사용하겠다.
    volatile int i = 0;
    i++;
    i++;
    i++;
    return i;
}

void func(const int& i)
{
    int& j = const_cast<int&>(i); // 상수성을 제거해준다.
    j = 10;
}

int main()
{
    int i = 0;
    func(i);

    cout << i << endl;


    const int j = 0; // 원본인 const인 경우 문제가 될 수 있다
    func(j); // 정의되지 않은 행동

    cout << j << endl;


    stringFunc();
}