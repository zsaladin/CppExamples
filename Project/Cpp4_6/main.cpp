#include <iostream>

using namespace std;

int main()
{
    {
        // 삼항 연산자
        // (A) ? (B) : (C)
        // A가 true면 B 실행 후 리턴
        // A가 false면 C 실행 후 리턴

        // 절대값 구하기
        int num = -10;
        int abs = num < 0 ? -num : num;


        num = 0;
        (num == 0 ? (cout << "num == 0") : (cout << "num != 0")) << endl;
        cout << (num == 0 ? "num == 0" : "num != 0") << endl;

        // 1과 "num != 0"이 호환이 안 되는 타입이라 삼항 연산자를 사용할 수 없음
        // num == 0 ? 1 : "num != 0";
    }
    {
        // sizeof 연산자
        int num = 0;
        cout << sizeof(num) << endl;
        cout << sizeof num << endl;
        cout << sizeof(int) << endl;
    }
    {
        // 범위 지정 연산자 (::)
        std::cout << 1 << std::endl;
        std::ios_base::floatfield;
    }
    {
        // 암시적 형변환
        unsigned int uintNum = 1;
        int intNum = 1u;
        float fNum = 1.1f;

        uintNum = intNum;
        intNum = uintNum;
        fNum = intNum;

        short sNum = numeric_limits<int>::max();
        cout << sNum << endl; // 암시적 형변환의 위험, 오버 플로우

        // 형변환 연산자
        cout << 'a' << endl;
        cout << (int)'a' << endl; // C스타일 형변환
        cout << int('a') << endl; // C++ 스타일 형변환

        // C++ 스타일의 형변환 연산자들 (추후 배울 예정)
        // static_cast
        // const_cast
        // dynamic_cast
        // reinterpret_cast
    }
}