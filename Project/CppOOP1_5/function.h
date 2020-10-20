#pragma once

#include <iostream>

using namespace std;


// 함수 선언, 정의가 포함되지 않은 선언
void func();

// 햠수 정의, 선언이지만 정의가 포함
void func()
{
    cout << "func" << endl;
}

// 한 번 더 정의 하게 되면 중복 정의(컴파일이 안 됨)
//void func()
//{
//    cout << "func" << endl;
//}
