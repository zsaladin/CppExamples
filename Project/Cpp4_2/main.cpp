#include <iostream>
#include <compare>

using namespace std;
int main()
{
    {
        // Equal 연산자
        int num0 = 10, num1(10);
        if (num0 == num1)
            cout << "num0 == num1" << endl;
        
        // 아래의 실수들에 유의 한다.
        num0 = 10, num1 = 11;
        // if 문 내부가 11로 평가되고 11은 true로 평가되기 때문에 num0과 num1이 달라도 무조건 실행이 된다.
        if (num0 = num1)
            cout << "num0(10) = num1(11)" << endl;

        num0 = 0, num1 = 0;
        // if 문 내부가 0으로 평가되고 0은 false로 평가되기 때문에 num0과 num1이 같아도 실행이 안 된다.
        if (num0 = num1)
            cout << "num0(0) = num1(0)" << endl;
    }
    {
        // Not Equal 연산자
        int num0 = 0, num1(0);
        if (num0 != num1)
            cout << "num0(0) != num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 != num1)
            cout << "num0(0) != num1(1)" << endl;
    }
    {
        // > 연산자
        int num0 = 0, num1(0);
        if (num0 > num1)
            cout << "num0(0) > num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 > num1)
            cout << "num0(1) > num1(0)" << endl;
    }
    {
        // >= 연산자
        int num0 = 0, num1(0);
        if (num0 >= num1)
            cout << "num0(0) >= num1(0)" << endl;

        num0 = 1, num1 = 0;
        if (num0 >= num1)
            cout << "num0(1) >= num1(0)" << endl;
    }
    {
        // < 연산자
        int num0 = 0, num1(0);
        if (num0 < num1)
            cout << "num0(0) < num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 < num1)
            cout << "num0(0) < num1(1)" << endl;
    }
    {
        // <= 연산자
        int num0 = 0, num1(0);
        if (num0 <= num1)
            cout << "num0(0) <= num1(0)" << endl;

        num0 = 0, num1 = 1;
        if (num0 <= num1)
            cout << "num0(1) <= num1(0)" << endl;
    }
    {
        // SpaceShip 연산자
        // C++2x 에서 지원. 프로젝트 속성에서 C++ 언어 표준 변경
        cout.setf(ios_base::boolalpha);

        // <=> 의 결과를 0과 비교할 수 있다.
        // 0과 비교해서 0과 같으면 <=>의 좌항, 우항이 같다.
        // 0과 비교해서 0보다 크면 좌항이 우항보다 크다.
        // 0과 비교해서 0보다 작으면 좌항이 우항보다 작다.
        cout << ((1 <=> 1) == 0) << endl;
        cout << ((2 <=> 1) > 0) << endl;
        cout << ((1 <=> 2) < 0) << endl;

        cout << is_eq(1 <=> 1) << endl;
        cout << is_gt(2 <=> 1) << endl;
        cout << is_lt(1 <=> 2) << endl;
        cout << is_gteq(2 <=> 1) << endl;
        cout << is_lteq(1 <=> 2) << endl;

        cout << typeid(1 <=> 1).name() << endl;
        cout << typeid(1 <=> 1.0).name() << endl;
    }
}