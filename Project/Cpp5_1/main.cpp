#pragma warning(disable: 4996)
#include <iostream>

using namespace std;
int main()
{
    {
        // if 문의 기본
        int num = 0;
        if (num == 0)
            cout << "Executed 0" << endl;
        
        if (num != 0)
            cout << "Executed 1" << endl;
    }
    {
        // if 문
        //if (condition)
        //    statement

        // expression
        // 1 + 2

        // statement
        // 1 + 2;

        int num = 0;
        if (num == 0)
            cout << 0 << endl; // statement

        // if 문에 묶인 statement는 null statement가 되어 아래 있는 statement는 if문에 영향을 받지 않게 된다.
        if (num != 0); 
            cout << "wow" << endl;
    }
    {
        int num = 0;
        // num = 0 표현식의 결과는 0이다.
        // 0은 false로 평가가 되기 때문에 아래에 있는 statement가 항상 실행되지 않는다.
        if (num = 0)
            cout << "wow" << endl;

        // num = 0 같은 것을 방지하기 위함
        if (0 == num)
            cout << "wow" << endl;
    }
    {
        // 복합문
        // { } 는 여러 statement를 묶어줄 수 있다.
        int num = 0;
        if (num != 0)
        {
            cout << "wow" << endl;
            cout << "wow1" << endl;
        }
    }
    {
        int num0 = 0;
        int num1 = 1;

        // if 문 중첩
        if (num0 == 0)
            if (num1 == 1)
                cout << "wow" << endl;

        if (num0 == 0)
        {
            if (num1 == 1)
            {
                cout << "wow" << endl;
            }
        }

        if (num0 == 0 && num1 == 1)
            cout << "wow" << endl;
    }
    {
        int num0 = 0;
        // &&가 시퀀스 포인트이기 때문에 같은 라인에서 num0이 두 번 이상 변경되었어도 정의되지 않은 행동이 아님
        if (num0++ == 0 && num0++ == 1)
        {
            cout << num0 << endl;
        }

        num0 = 0;
        // 정의되지 않은 행동
        if (num0++ + num0++ == 1)
        {
            cout << num0 << endl;
        }
    }
    {
        // if - else
        int num0 = 0;
        if (num0 == 0)
            cout << "num0 == 0" << endl;
        else
            cout << "!(num0 == 0)" << endl;

        // 위와 같은 삼항 연산자
        cout << (num0 == 0 ? "num0 == 0" : "!(num0 == 0)") << endl;
    }
    {
        // if - else if - else
        int num0 = 1;
        if (num0 == 0)
        {
            cout << "num0 == 0" << endl;
        }
        else if (num0 == 1)
        {
            cout << "num0 == 1" << endl;
        }

        int score;
        cin >> score;
        char grade;
        if (score == 100)
            grade = 'A';
        else if (90 <= score && score < 100)
            grade = 'B';
        else if (80 <= score && score < 90)
            grade = 'C';
        else
            grade = 'D';
        cout << grade << endl;
        // 90 <= score < 100 이 안 되는 이유
        // score가 80이라면
        // (90 <= 80) < 100
        // false < 100
        // 0 < 100
        // 따라서 score가 80임에도 true로 평가 됨
    }
    {
        // 드모르간의 법칙
        int score0 = 90;
        int score1 = 80;

        if (score0 >= 90 && score1 >= 90)
            ;
        else
            cout << "fail0" << endl;

        if (!(score0 >= 90 && score1 >= 90))
            cout << "fail1" << endl;
        if (!(score0 >= 90) || !(score1 >= 90))
            cout << "fail2" << endl;
        if (score0 < 90 || score1 < 90)
            cout << "fail3" << endl;
    }
    {
        // if 문 안에서 변수 선언
        int num0, num1;
        if (int count = scanf("%d %d", &num0, &num1))
            printf("count : %d\n", count);
        else
            printf("fail count : %d\n", count);

        // count 에 접근 할 수 없다
        // count += 1;

        // num0, num1 선언도 안에 넣을 수 있다(C++17 이상)
        if (int num0, num1; int count = scanf("%d %d", &num0, &num1))
            printf("count : %d\n", count);
        else
            printf("fail count : %d\n", count);
    }
}