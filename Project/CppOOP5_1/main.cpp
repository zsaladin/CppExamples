#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>

using std::cout;
using std::endl;


int divide(double d, double v, double& result)
{
    if (v == 0)
    {
        result = 0;
        return -1;
    }
    result = d / v;
    return 0;
}

int errorCode = 0;
double divide(double d, double v)
{
    if (v == 0)
    {
        errorCode = -1;
        return 0;
    }
    errorCode = 0;
    return d / v;
}

int main()
{
    {
        // 에러 발생 시 종료
        // 비정상 종료
        //std::abort();

        // 종료 코드를 넣은 종료
        //exit(123);
    }
    // 아래의 예외 처리 방법은 예외 처리가 강제 되지 않는다.
    // printf 가 실패했지만 실패한 것에 대한 예외 상황을 처리하지 않고 작성하더라도 눈치채지 못할 수 있다.
    // 따라서 실패 시 실패에 대한 처리를 강제하게 하는 메커니즘이 필요
    {
        freopen("input.txt", "r", stdout);
        // 읽기 전용으로 stdout의 파일을 열었으니 해당 파일(input.txt)로 쓰기(출력)을 할 수 없다
        int result = printf("%d\n", 10);  // 에러 발생 시 음수
        cout << result << endl;

        cout << cout.fail(); // 에러 발생 시 해당 객체에 저장
    }
    {
        double result;
        int errorCode = divide(10, 0, result); // 에러 발생 시 에러 코드
        if (errorCode > 0)
        {
            cout << result << endl;
        }
    }
    {
        double result = divide(10, 0);
        if (errorCode > 0) // 전역적으로 사용하는 변수, 멀티 쓰레드에서 문제 발생
        {

        }
    }


}