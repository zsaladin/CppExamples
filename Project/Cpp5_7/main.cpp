#include <iostream>

using namespace std;

int main()
{
    {
        // 무한 루프
    //go:
    //    cout << 1 << endl;
    //    goto go;
    }
    {
        int num = 5;
        if (num % 3 == 0)
            goto go;
        if (num % 5 == 0)
            goto go;
        cout << "can't divide 3 and 5" << endl;

    go:
        cout << "wow" << endl;
    }
    {
        // 팩토리얼
        int num;
        cin >> num;

        int total = 1;
    multiply:
        total *= num;
        if (--num >= 1)
            goto multiply;

        cout << total << endl;
    }
    {
        // 알파벳 출력
        char ch = 'a';
    alpha:
        cout << ch << endl;
        if (++ch <= 'z')
            goto alpha;
    }
    {
        // 피보나치 수열
        // 0, 1, 1, 2, 3, 5, 8, 13, 21
        // a(0) = 0, a(1) = 1
        // a(n) = a(n - 2) + a(n - 1)

        int num;
        cin >> num;

        if (num <= 1)
            cout << num << endl;
        else
        {
            int prevValue = 0;
            int currValue = 1;

        add:
            int nextValue = prevValue + currValue;
            prevValue = currValue;
            currValue = nextValue;
            if (--num - 1)
                goto add;
            cout << currValue << endl;
        }
    }
}