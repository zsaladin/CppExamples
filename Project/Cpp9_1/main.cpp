#include <iostream>

using namespace std;

// 험수의 프로토타입 선언
int csum(int x, int y);
int cabs0(int x);
int cabs1(int x);


int abssum(int x, int y)
{
    // cabs0, cabs1, csum에 대한 선언이 필요하다.
    // abssum 입장에서는 cabs0, cabs1, csum
    int ax = cabs0(x);
    int ay = cabs1(y);
    return csum(ax, ay);
}

int csum(int x, int y)
{
    return x + y;
}

int cabs0(int x)
{
    return x >= 0 ? x : -x;
}

int cabs1(int x)
{
    if (x >= 0)
        return x;
    else
        return -x;
}

void print0(int x, int y)
{
    cout << x << endl;
    if (y < 0)
        return; // 함수 종료 시 return을 사용할 수 있다

    cout << y << endl;
}

void print1(void) // 인자가 없는 경우 void를 생략할 수 있다
{
    cout << "Hello World" << endl;
}

int main(int argc, char* arvc[])
{
    {
        // main 함수의 반환
        // 0 : 정상 종료
        // 0아 아님 : 비정상 종료
        //return 0;
    }
    {
        // 실행 시 넘겨진 인자 출력
        // 0번에는 실행한 파일명 출력
        for (int i = 0; i < argc; ++i)
        {
            cout << arvc[i] << endl;
        }
    }
    {
        // 사용자 정의 함수 사용
        cout << csum(5, 10) << endl;
        cout << cabs0(10) << endl;
        cout << cabs1(-10) << endl;
    }
}
