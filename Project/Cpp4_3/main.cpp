#include <iostream>

using namespace std;

int main()
{
    {
        // AND 연산자(&&)
        // true && true == true
        // true && false == false
        // false && true == false
        // false && false == false
    }
    {
        int num0 = 10, num1(10);
        int num2 = 20, num3(30);
        if (num0 == num1 && num2 != num3) // == 연산자가 &&보다 우선 순위가 높다
            cout << "!!!!" << endl;
        if (num0 == num1 && num2 == num3)
            cout << "@@@@" << endl;
    }
    {
        // OR 연산자(||)
        // true && true == true
        // true && false == true
        // false && true == true
        // false && false == false
    }
    {
        int num0 = 10, num1(10);
        int num2 = 20, num3(30);
        if (num0 == num1 && num2 == num3)
            cout << "AND" << endl;
        if (num0 == num1 || num2 == num3)
            cout << "OR" << endl;
    }
    {
        // && 연산자가 || 연산자보다 우선순위가 높다.
        if (true || false && false)
            cout << "OK" << endl;
    }
    {
        // short-circuit evaluation
        int num0 = 10, num1(20);
        int num2 = 20, num3(20);
        
        // num0 == num1 이 false이기 때문에 num2 == num3은 평가할 필요가 없어서 평가되지 않는다.
        if (num0 == num1 && num2 == num3)
            cout << "AND" << endl;
        
        // num0 != num1 이 true이기 때문에 num2 == num3은 평가할 필요가 없어서 평가되지 않는다.
        if (num0 != num1 || num2 == num3)
            cout << "OR" << endl;

        // printf("") 의 반환값이 0이기 때문에 false로 평가돼서 우항의 printf("ABC")는 실행되지 않는다.
        printf("") && printf("ABC");
        cout << endl;

        // printf("a") 의 반환값이 1이기 때문에 true로 평가돼서 우항의 printf("ABC")는 실행된다.
        printf("a") && printf("ABC");
        cout << endl;

        // printf("a") 의 반환값이 1이기 때문에 true로 평가돼서 우항의 printf("ABC")는 실행되지 않는다.
        printf("a") || printf("ABC");
        cout << endl;

        // printf("") 의 반환값이 0이기 때문에 false로 평가돼서 우항의 printf("ABC")는 실행된다.
        printf("") || printf("ABC");
        cout << endl;
    }
    {
        // &&, || 연산자는 시퀀스 포인트
    }
    {
        // Not 연산자(!)
        bool r = true;
        r = !r;
        cout << r << endl;
    }
    {
        // 같은 의미의 if 문
        int num0 = 10, num1 = 20;
        if (num0 != num1)
        {
            cout << "num0 != num1" << endl;
        }
        if (!(num0 == num1))
        {
            cout << "!(num0 == num1)" << endl;
        }
    }
    {
        cout.setf(ios_base::boolalpha);
        
        // 10이 bool로 평가 될 떄 true 평가 되어서 false 출력
        cout << !10 << endl;

        // 좌항과 우항의 정수가 둘 다 0이 아니기 때문에 둘 다 true로 평가되어 true && true 가 된다.
        cout << (1 && 2) << endl;
    }

}