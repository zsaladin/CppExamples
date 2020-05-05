#include <iostream>

using namespace std;

int main()
{
    {
        // 아래 for 문과 동일한 while 문
        int i = 0;
        while (i < 10)
        {
            cout << i << endl;
            ++i;
        }

        // 한 변수(i)를 가지고 초기화, 조건체크, 갱신을 해야하는 경우 for 문을 사용하자 
        for (int i = 0; i < 10; ++i)
        {
            cout << i << endl;
        }
    }
    {
        int i = 0;
        //while (i < 10)
        //{
        //    if (i % 3 == 0)
        //        continue; // for와 다르게 ++i가 호출이 되지 않는다. 무한 루프

        //    cout << i << endl;
        //    ++i;
        //}

        for (int i = 0; i < 10; ++i)
        {
            if (i % 3 == 0)
                continue; // ++i가 호출 된다
            cout << i << endl;
        }
    }
    {
        // while 문 내에서 switch 를 사용할 때 break, continue 는 for 문과 동일하게 동작
    }
    {
        // 팩토리얼
        int num;
        cin >> num;

        int total = 1;
        while (num)
        {
            total *= num--;
        }
        cout << total << endl;
    }
    {
        // 알파벳 출력
        char ch = 'a';
        while (ch <= 'z')
        {
            cout << ch++ << endl;
        }
    }
    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21 ...
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 2) + a(n - 1)

        int num;
        cin >> num;
        
        if (0 == num)
            cout << 0 << endl;
        else
        {
            int prevValue = 0;
            int currValue = 1;
            while (--num)
            {
                int nextValue = prevValue + currValue;
                prevValue = currValue;
                currValue = nextValue;
            }
            cout << currValue << endl;
        }
    }
}