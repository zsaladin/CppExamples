#pragma once
#include <iostream>

using namespace std;


int sum(int x, int y)
{
    return x + y;
}


void functionPointer()
{
    // int sum(int x, int y) 을 가리킬 수 있는 함수 포인터
    int (*f0)(int, int) = &sum; // 함수의 주소
    int (*f1)(int, int) = sum;  // 함수의 이름이지만 주소로 평가 되는 것을 허용


    cout << (*f0)(1, 2) << endl;
    cout << f0(1, 2) << endl;  // 역참조 생략 허용

    int(&f2)(int, int) = sum; // 함수 참조
    //int (&f3)(int, int) = &sum; // 안 됨

    cout << f2(1, 2) << endl;
    cout << (*f2)(1, 2) << endl; // 허용
    cout << (*sum)(1, 2) << endl; // 허용, 함수 주소가 필요한 곳에서는 암시적으로 함수 주소로 변경
}

