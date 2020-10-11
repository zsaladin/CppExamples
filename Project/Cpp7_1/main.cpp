#include <iostream>
#include <numeric>

using namespace std;

union Union
{
    int i;
    float f;
    double d;
};

int main()
{
    {
        int num = 100;

        // 포인터 선언
        // 가리킬 타입에 *추가
        // &연산자를 사용하여 num의 주소값을 얻음
        int* pointer = &num;


        cout << num << endl; // num 값
        cout << &num << endl; // num의 주소값
        cout << pointer << endl; // num의 주소값을 pointer가 가지고 있다

        cout << *pointer << endl; // 역참조, dereference, num에 접근
        *pointer = 200;

        cout << num << endl;
        cout << *pointer << endl;
    }
    {
        int num = 123;
        int* pNum0 = &num;
        int* pNum1 = &num;
        int* pNum2 = pNum0;

        cout << &num << endl;
        cout << pNum0 << endl;
        cout << pNum1 << endl;
        cout << pNum2 << endl;
        cout << endl;
        
        cout << num << endl;    // 123
        cout << *pNum0 << endl; // 123
        cout << *pNum1 << endl; // 123
        cout << *pNum2 << endl; // 123
        cout << endl;
        
        num = 100;
        cout << num << endl;    // 100
        cout << *pNum0 << endl; // 100
        cout << *pNum1 << endl; // 100
        cout << *pNum2 << endl; // 100
        cout << endl;
    }
    {
        int* pNum = 0;
        cout << pNum << endl;
        //cout << *pNum << endl; // 정의 되지 않은 행동
    }
    {
        Union u;
        int* ip = (int*)&u;
        float* fp = (float*)&u;
        double* dp = (double*)&u;

        u.i = 1;

        cout << u.i << endl;
        cout << *ip << endl; // 메모리를 int로 해석

        cout << u.f << endl;
        cout << *fp << endl; // 메모리를 float로 해석

        cout << u.d << endl;
        cout << *dp << endl; // 메모리를 double로 해석
    }
    {
        // 포인터 선언 시 const가 가장 앞에 위치하는 경우
        int num0 = 10;
        const int* pNum = &num0;

        int num1 = 20;
        pNum = &num1; // 가능

        //*pNum = 30; // 불가능, 가리키는 녀석의 내용을 바꿀 수 없음
    }
    {
        // 포인터 선언 시 const가 변수명 바로 앞에 위치하는 경우
        int num0 = 10;
        int* const pNum = &num0;

        int num1 = 20;
        //pNum = &num1; // 불가능

        *pNum = 30; // 가능
    }
    {
        int num0 = 10;
        const int* const pNum = &num0;

        int num1 = 20;
        //pNum = &num1; // 불가능
        //*pNum = 30; // 불가능
    }
}