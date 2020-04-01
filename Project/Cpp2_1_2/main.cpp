#include <iostream>
#include <numeric> // 최대값, 최소값을 보기 위해 포함

// std 네임 스페이스를 명시하지 않아도 사용할 수 있도록 하기 위함
using namespace std;

int main()
{
    {
        // x는 정수형의 변수라고 선언
        int x;
        x = 0;

        // std::endl 은 개행을 의미한다.
        cout << x << endl;
    }
    {
        // 선언과 동시에 초기화
        // C 스타일 초기화
        int y = 1;
        cout << y;

        // C++ 스타일 초기화
        int z(2);
        cout << z << endl;
        // 개행(std::endl)이 없어 y,z 값이 연달아서 출력 됨
    }
    {
        // 정수형의 소수점 버림
        int num0 = 1;
        int num1 = num0 * 1.5;
        int num2 = num0 / 2;
        int num3 = 2.5;

        cout << "num0 " << num0 << endl; // 1
        cout << "num1 " << num1 << endl; // 1, 1.5이지만 소수점은 버림
        cout << "num2 " << num2 << endl; // 0, 0.5이지만 소수점은 버림
        cout << "num3 " << num3 << endl; // 2, 2.5이지만 소수점은 버림
    }

    {
        // 정수형 리터럴
        int num0 = 11;   // 일반 정수 리터럴
        int num1 = 011;  // 8진수 정수 리터럴
        int num2 = 0b11; // 2진수 정수 리터럴
        int num3 = 0x11; // 16진수 정수 리터럴

        cout << "num0 " << num0 << endl; // 11
        cout << "num1 " << num1 << endl; // 8 + 1 = 9
        cout << "num2 " << num2 << endl; // 2 + 1 = 3
        cout << "num3 " << num3 << endl; // 16 + 1 = 17
    }
    
    {
        // 자료형의 사이즈 출력
        // Windows x86(32bit)의 경우 4/4/4
        // Windows x64(64bit)의 경우 4/4/8
        // Unix and Unix-like 환경은 다른 결과 출력
        int intNum = 0;
        long longNum = 0;
        int* intPointer = &intNum;

        cout << sizeof(intNum) << endl;
        cout << sizeof(longNum) << endl;
        cout << sizeof(intPointer) << endl;
    }
    {
        // 고정폭 정수형
        // 어느 환경에서도 고정된 길이를 보장한다.
        int8_t num00 = 0;
        int16_t num11 = 0;
        int32_t num22 = 0;

        cout << sizeof(num00) << endl; // 1
        cout << sizeof(num11) << endl; // 2
        cout << sizeof(num22) << endl; // 4
    }
    {
        // 리터럴 접미사를 이용하여 정수형의 세부 타입을 표현
        int intNum_ = 11;
        unsigned int uintNum = 11u;
        long int longNum_ = 0L;
        long long longLongNum = 0LL;
        unsigned long long ulongLongNum = 0uLL;
    }
    {
        // unsigned의 최대값
        // char 형이기 때문에 cout이 숫자로 출력을 하지 않아 (int)로 형변환
        cout << (int)numeric_limits<uint8_t>::max() << endl;
        cout << numeric_limits<uint16_t>::max() << endl;
        cout << numeric_limits<uint32_t>::max() << endl;
        cout << numeric_limits<uint64_t>::max() << endl;
    }
    {
        // signed의 최대값
        cout << (int)numeric_limits<int8_t>::max() << endl;
        cout << numeric_limits<int16_t>::max() << endl;
        cout << numeric_limits<int32_t>::max() << endl;
        cout << numeric_limits<int64_t>::max() << endl;
    }
    {
        // signed의 최소값
        cout << (int)numeric_limits<int8_t>::min() << endl;
        cout << numeric_limits<int16_t>::min() << endl;
        cout << numeric_limits<int32_t>::min() << endl;
        cout << numeric_limits<int64_t>::min() << endl;
    }
    {
        // unsigned overflow
        uint32_t unum32 = numeric_limits<uint32_t>::max();
        uint32_t unum32_ = unum32 + 1; // Overflow

        cout << unum32 << endl;  // 4294967295
        cout << unum32_ << endl; // 0, Overflow
    }
    {
        // signed overflow
        int32_t num32 = numeric_limits<int32_t>::max();
        int32_t num32_ = num32 + 1; // Overflow

        cout << num32 << endl;  // 2147483647
        cout << num32_ << endl; // -2147483648, Overflow
    }
    {
        // unsigned underflow
        uint32_t unum32 = numeric_limits<uint32_t>::min();
        uint32_t unum32_ = unum32 - 1; // Underflow

        cout << unum32 << endl;  // 0
        cout << unum32_ << endl; // 4294967295, Underflow 
    }
    {
        // signed underflow
        int32_t num32 = numeric_limits<int32_t>::min();
        int32_t num32_ = num32 - 1; // Underflow

        cout << num32 << endl;  // -2147483648
        cout << num32_ << endl; // 2147483647, Underflow
    }
}