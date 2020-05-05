#include <iostream>

using namespace std;

int main()
{
    {
        // for (초기화; 조건; 갱신)
        //   반복할 구문
        //
        // 1. 초기화
        // 2. 조건(true -> 3, false -> 종료)
        // 3. 반복할 구문 수행
        // 4. 갱신
        // 5. 2번으로 돌아감
    }
    {
        // for의 기본
        // 0 ~ 9 출력
        int i;
        for (i = 0; i < 10; ++i)
            cout << i << endl;
    }
    {
        int i;
        // i가 0이기 때문에 false로 평가 되어 아무 것도 실행 되지 않음
        for (i = 0; i; ++i)
            cout << i << endl;
    }
    {
        int i;
        // 10 ~ 1 출력
        for (i = 10; i; --i)
            cout << i << endl;
    }
    {
        // 무한 루프
        // for (;;)
        // 주석을 풀고 사용

        //int i;
        //for (i = 0;; ++i)
        //    cout << i << endl;

    }
    {
        // 선언을 for에 포함 시킬 수 있다
        for (int i = 0; i < 10; i += 2)
            cout << i << endl;
    }
    {
        // 두 개 이상의 변수 사용 가능
        for (int i = 0, j = 0; i < 10 && j < 10; i += 1, j += 2)
        {
            cout << i << endl;
            cout << j << endl;
        }
    }
    {
        // break의 사용
        for (int i = 0; i < 10; ++i)
        {
            if (i % 3 == 0)
                break;
            if (i % 5 == 0)
                break;

            cout << i << endl;
        }
    }
    {

        // continue의 사용
        for (int i = 0; i < 10; ++i)
        {
            if (i % 3 == 0)
                continue;

            cout << i << endl;
        }
    }
    {
        int i;
        for (i = 0; i < 10; ++i)
        {
            cout << i << endl;
            if (i == 9)
                break;
        }
        cout << " " << i << endl; // 9, break는 i 갱신을 하지 않고 바로 종료

        for (i = 0; i < 10; ++i)
        {
            cout << i << endl;
        }
        cout << " " << i << endl; // 10
    }
    {
        // switch 안의 break는 for를 break하지 못 한다.
        for (;;)
        {
            cout << "Food" << endl;
            cout << "1) Kimch" << endl;
            cout << "2) BBQ" << endl;
            cout << "3) Chicken" << endl;
            int num;
            cin >> num;

            bool needToBreak = false;

            switch (num)
            {
            case 1:
                cout << "Kimch" << endl;
                needToBreak = true;
                break;
            case 2:
                cout << "BBQ" << endl;
                needToBreak = true;
                break;
            case 3:
                cout << "Chicken" << endl;
                needToBreak = true;
                break;
            }

            if (needToBreak)
                break;
        }
    }
    {
        // switch 안의 continue는 for를 continue 한다.
        for (;;)
        {
            cout << "Food" << endl;
            cout << "1) Kimch" << endl;
            cout << "2) BBQ" << endl;
            cout << "3) Chicken" << endl;
            int num;
            cin >> num;

            switch (num)
            {
            case 1:
                cout << "Kimch" << endl;
                break;
            case 2:
                cout << "BBQ" << endl;
                break;
            case 3:
                cout << "Chicken" << endl;
                break;
            default:
                continue;
            }
            break;
        }
    }
    {
        // 팩토리얼 구하기
        int num;
        cin >> num;

        int total = 1;
        for (; num; num--)
        {
            total *= num;
        }
        cout << total << endl;
    }
    {
        // 알파벳 출력
        for (char ch = 'a'; ch <= 'z'; ++ch)
        {
            cout << ch << endl;
        }
    }
    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 1) + a(n - 2)
        
        int num;
        cin >> num;

        if (num < 2)
        {
            cout << num << endl;
        }
        else
        {
            int prevValue = 0;
            int currValue = 1;
            for (int i = 0; i < num - 1; ++i)
            {
                int nextValue = prevValue + currValue;
                prevValue = currValue;
                currValue = nextValue;
            }
            cout << currValue << endl;
        }
    }
}