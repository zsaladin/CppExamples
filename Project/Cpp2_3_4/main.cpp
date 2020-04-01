#include <iostream>
#include <cfloat>

using namespace std;

int main()
{
    {
        // 부동소수점의 출력
        float num0 = 1.5;
        float num1 = num0 * 1.5;
        float num2 = num0 / 2;
        float num3 = num0 - 3;

        cout << "num0 " << num0 << endl; // 1.5
        cout << "num1 " << num1 << endl; // 2.25
        cout << "num2 " << num2 << endl; // 0.75
        cout << "num3 " << num3 << endl; // -1.5
    }
    
    {
        // 부동소수점 자료형들의 사이즈
        float fnum = 1.0;
        double dnum = 1.0;
        long double ldnum = 1.0;

        // float은 4바이트, double은 8바이트(대부분)
        // 환경에 따라 사이즈가 다를 수 있음(특히 long double)
        cout << "float : " << sizeof(fnum) << endl;  // 4
        cout << "double : " << sizeof(dnum) << endl;  // 8
        cout << "long double : " << sizeof(ldnum) << endl; // 8

        // 리터럴에 어떤 접미사를 붙이는 가에 따라 세부 자료형을 정할 수 있다 
        cout << "sizeof(1.0f) : " << sizeof(1.0f) << endl; // float
        cout << "sizeof(1.0) : " << sizeof(1.0) << endl;  // double
        cout << "sizeof(1.0L) : " << sizeof(1.0L) << endl; // long double
    }

    // 정밀도 변경
    cout.precision(64);

    {
        // 부동 소수점의 메모리 상의 표현
        unsigned int uintNum;
        float fnum = -118.625f;
        memcpy(&uintNum, &fnum, sizeof(fnum));

        cout << uintNum << endl; // 1100,0010,1110,1101,0100,0000,0000,0000 = 3270328320
        cout << fnum << endl;    // 1100,0010,1110,1101,0100,0000,0000,0000 = -118.625


        fnum = 0.231689453125f;
        memcpy(&uintNum, &fnum, sizeof(fnum));

        cout << uintNum << endl; // 0011,1110,0110,1101,0100,0000,0000,0000 = 1047347200
        cout << fnum << endl;    // 0011,1110,0110,1101,0100,0000,0000,0000 = 0.231689453125
    }
    
    {
        // 부동 소수점 비교 연산 시 문제점
        float num0 = 0.1f;
        float num1 = 0.02f * 5.0f;

        if (num0 == num1)
            cout << "Equal 1" << endl; // 실행이 안 된다.
        if (num0 == 0.1f)
            cout << "Equal 2" << endl; // 실행이 된다.
        if (num0 == 0.1)
            cout << "Equal 3" << endl; // 실행이 안 된다.
        if (num0 == 0.1L)
            cout << "Equal 4" << endl; // 실행이 안 된다.

        cout << num0 << endl; // 실제로 0.1 이 아니다.
        cout << num1 << endl; // 실제로 0.1 이 아니다.

        cout << "0.1f : " << 0.1f << endl;
        cout << "0.1  : " << 0.1 << endl;
        cout << "0.1L : " << 0.1L << endl;


        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 1000; i++)
            num1 = num1 + 0.001;
        if (num0 == num1)
            cout << "Equal 0" << endl;  // 안 됨
        if (fabsf(num0 - num1) <= FLT_EPSILON)
            cout << "Equal 1" << endl;  // 안 됨


        num0 = 1.0f;
        num1 = 0.0f;
        for (int i = 0; i < 10; i++)
            num1 = num1 + 0.1;
        if (num0 == num1)
            cout << "Equal 2" << endl;  // 안 됨
        if (fabsf(num0 - num1) <= FLT_EPSILON)
            cout << "Equal 3" << endl;  // 됨
    }
    
    {
        // Epsilon 유도
        unsigned int intNum0 = 0b00111111100000000000000000000000;
        float fNum0;
        memcpy(&fNum0, &intNum0, sizeof(intNum0));
        cout << fNum0 << endl; // 1.0f

        unsigned int intNum1 = 0b00111111100000000000000000000001;
        float fNum1;
        memcpy(&fNum1, &intNum1, sizeof(intNum1));
        cout << fNum1 << endl; // 1.00000011920928955078125f, float이 표현할 수 있는 1보다 큰, 가장 작은 수

        float epsilon = fNum1 - fNum0;
        cout << epsilon << endl;
        cout << FLT_EPSILON << endl;
    }

    {
        // 1.0f에서 더할 수 있는 가장 작은 수 구하기
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110100000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // Epsilon, 1.0(2) * 10^-23(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나옴
    }
    {
        // 1.0f에서 더할 수 있는 가장 작은 수보다 더 작은 수를 더 할 때
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b00110011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^-24(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나오지 않음
    }

    {
        // 1.0f를 더했을 때 문제가 없이 더해지는 수
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011000000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^23(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나옴
    }
    {
        // 1.0f를 더했을 때 더해지지 않는 수
        float fNum0 = 1.0f;
        float fNum1;
        unsigned int intNum1 = 0b01001011100000000000000000000000;
        memcpy(&fNum1, &intNum1, sizeof(intNum1)); // 1.0(2) * 10^24(2)

        cout << fNum0 << endl;
        cout << fNum1 << endl;
        cout << fNum0 + fNum1 << endl; // 더한 값이 나오지 않음
    }

    {
        // 최대값 구하기
        float fnum;
        unsigned int uintNum = 0b01111111011111111111111111111111;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_MAX << endl;
        cout << fnum << endl;
    }

    {
        // NaN 구하기
        float fnum;
        unsigned int uintNum = 0b01111111111111111111111111111111;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << fnum << endl;
    }

    {
        // 무한대 구하기
        float fnum;
        unsigned int uintNum = 0b01111111100000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << fnum << endl;
    }

    {
        // TRUE_MIN
        float fnum;
        unsigned int uintNum = 0b00000000000000000000000000000001;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_TRUE_MIN << endl;
        cout << fnum << endl;
    }

    {
        // MIN
        float fnum;
        unsigned int uintNum = 0b00000000100000000000000000000000;
        memcpy(&fnum, &uintNum, sizeof(uintNum));

        cout << FLT_MIN << endl;
        cout << fnum << endl;
    }
}