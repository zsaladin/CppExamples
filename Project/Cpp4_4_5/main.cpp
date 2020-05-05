#include <iostream>

using namespace std;

int main()
{
    {
        // Not 연산자(~)
        // 0 -> 1
        // 1 -> 0
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0)
        int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (-1)
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0000 (0)
        unsigned int num = 0;

        // 1111,1111,1111,1111,1111,1111,1111,1111 (2^32 - 1)
        cout << ~num << endl;
    }
    {
        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        unsigned int num = 1;

        // 1111,1111,1111,1111,1111,1111,1111,1110 (2^32 - 2)
        cout << ~num << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0001 (1)
        cout << ~~num << endl;
    }
    {
        // AND 연산자(&)
        // 1 & 1 == 1
        // 1 & 0 == 0
        // 0 & 1 == 0
        // 0 & 0 == 0
    }
    {
        int num0 = 5;
        int num1 = 10;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1010 == 10 == 8 + 2 == 2^3 + 2^1
        // 0000,0000 == 0
    }
    {
        int num0 = 5;
        int num1 = 11;

        int result = num0 & num1;
        cout << result << endl;

        // 0000,0101 == 5 == 4 + 1 == 2^2 + 2^0
        // 0000,1011 == 10 == 8 + 2 == 2^3 + 2^1 + 2^0
        // 0000,0001 == 1
    }
    {
        // AND 연산자를 이용하여 flag가 존재하는지 체크
        uint32_t attendanceBook = 5;

        if (attendanceBook & (int)pow(2, 0))
            cout << "1st" << endl;

        if (attendanceBook & (int)pow(2, 1))
            cout << "2nd" << endl;

        if (attendanceBook & (int)pow(2, 2))
            cout << "3th" << endl;

        if (attendanceBook & ((int)pow(2, 0) + (int)pow(2, 1)))
            cout << "1 or 2" << endl;

        int flag = (int)pow(2, 0) + (int)pow(2, 2);
        if ((attendanceBook & flag) == flag)
            cout << "1 and 3" << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5

        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 AND // 1일 체크
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 // 1일 출석

        // 0000,0000,0000,0000,0000,0000,0000,0010 = 1 AND // 2일 체크
        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0 // 2일 결석
    }
    {
        // OR 연산자(|)
        // 1 | 1 == 1
        // 1 | 0 == 1
        // 0 | 1 == 1
        // 0 | 0 == 0
    }
    {
        // OR 연산자를 이용하여 flag를 추가
        uint32_t attendanceBook = 0u;

        // 첫째 날 출석 처리
        attendanceBook |= (int)pow(2, 0);
        cout << attendanceBook << endl;

        // 중복해서 같은 날에 출석을 해도 문제가 없다.
        attendanceBook |= (int)pow(2, 0);
        cout << attendanceBook << endl;

        // 0000,0000,0000,0000,0000,0000,0000,0000 = 0
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1 OR // 1일 출석
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1
    }
    {
        uint32_t attendanceBook = 5u;

        // 셋째 날 결석 처리ㅅ세셋셋ㅉ째 ㄴ나날 ㄱ겨결겴결서석 ㅊ처철처리
        attendanceBook &= ~((int)pow(2, 2));

        // 0000,0000,0000,0000,0000,0000,0000,0101 = 5
        // 1111,1111,1111,1111,1111,1111,1111,1011 AND
        // 0000,0000,0000,0000,0000,0000,0000,0001 = 1
    }
    {
        // XOR
        // 1 ^ 1 == 0
        // 1 ^ 0 == 1
        // 0 ^ 1 == 1
        // 0 ^ 0 == 0
    }
    {
        int num0 = 5;
        int num1 = 10;

        cout << (num0 ^ num1) << endl;

        // 0000,0101 = 5
        // 0000,1010 = 10
        // 0000,1111 = 15
    }
    {
        // XOR 를 이용하여 출석/결석 토글
        uint32_t attendanceBook = 0u;

        attendanceBook ^= (int)pow(2, 0); // 0001
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0001 ^ 0001 == 0000
        cout << attendanceBook << endl;

        attendanceBook ^= (int)pow(2, 0); // 0000 ^ 0001 == 0001
        cout << attendanceBook << endl;
    }
    {
        // 홀수번 있는 단 한개의 수를 구하기
        int a = 1, b = 3, c = 2, d = 1, e = 2;
        cout << (a ^ b ^ c ^ d ^ e) << endl;
        cout << (a ^ d ^ c ^ e ^ b) << endl; // 교환 법칙
    }
    {
        // << 연산자
        // 0000,0001
        // 0000,1000
        cout << (1 << 3) << endl;


        // << 한 번 할 때 마다 2배
        cout << (1 << 0) << endl;
        cout << (1 << 1) << endl;
        cout << (1 << 2) << endl;
        cout << (1 << 3) << endl;

        // 값의 잘림(오버 플로우)
        int num = 2200000000;
        num <<= 2;

        cout << num << endl;

        // pow 연산을 사용하지 않고 출석 처리
        int attendanceBook = 0u;
        attendanceBook |= (1 << 2);
        cout << attendanceBook << endl;
    }
    {
        // >> 연산자
        // 값의 잘림(언더 플로우)
        cout << (1 >> 1) << endl;

        
        // >> 한 번 할 때 마다 절반
        cout << (16 >> 1) << endl;
        cout << (8 >> 1) << endl;
        cout << (4 >> 1) << endl;
        cout << (2 >> 1) << endl;
        cout << (1 >> 1) << endl;


        cout << (14 >> 1) << endl; // 7
        cout << (15 >> 1) << endl; // 7 잘려서 나머지 없어짐

        cout << (14 >> 2) << endl; // 3 잘려서 나머지 없어짐
        cout << (15 >> 2) << endl; // 3 잘려서 나머지 없어짐
    }
}