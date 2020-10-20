#include <iostream>
#include "Person.h"

using namespace std;

// 클래스 멤버 변수 초기화
int Person::num0 = 0;
int Person::num1 = 0;
const int Person::num2 = 0; // const 초기화


Person::Person()
{
    num0++;
}


void Person::print()
{
    cout << num0 << endl;
}

void Person::staticPrint()
{
    cout << num0 << endl;
    //print(); // 비 정적 멤버 접근 불가, 즉 this가 없다
}

void personFunc()
{
    Person p0;
    Person p1;

    p0.print();
    p1.print();


    // public static 멤버 접근
    cout << Person::num1 << endl;

    Person::staticPrint();
    p0.staticPrint();
}
