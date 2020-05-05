#pragma warning(disable : 4996)
#include <iostream>

using namespace std;

int main()
{
    {
        cout << "What's your favorite food?" << endl;
        cout << "1) Kimch" << endl;
        cout << "2) Korean BBQ" << endl;
        cout << "3) Chicken" << endl;

        int num;
        cin >> num;

        switch (num)
        {
        case 1:
            cout << "You selected Kimch" << endl;
            break;
        case 2:
            cout << "You selected Korean BBQ" << endl;
            break;
        case 3:
            cout << "You selected Chicken" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    }
    {
        cout << "What's your favorite food?" << endl;
        cout << "a) Kimch" << endl;
        cout << "b) Korean BBQ" << endl;
        cout << "c) Chicken" << endl;

        char ch;
        cin >> ch;

        switch (ch)
        {
        case 'a':
        case 'A':
            cout << "You selected Kimch" << endl;
            break;
        case 'b':
        case 'B':
            cout << "You selected Korean BBQ" << endl;
            break;
        case 'c':
        case 'C':
            cout << "You selected Chicken" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    }
    {
        char ch;
        cin >> ch;

        switch (ch)
        {
        case 'A':
            cout << "Converted to a" << endl;
            [[fallthrough]]; // 명시적으로 break 를 사용하지 않음을 알림, C++17 이상
        case 'a':
            cout << "You selected Kimch" << endl;
            break;
        case 'B':
            cout << "Converted to b" << endl;
            [[fallthrough]]; // 명시적으로 break 를 사용하지 않음을 알림, C++17 이상
        case 'b':
            cout << "You selected Korean BBQ" << endl;
            break;
        case 'C':
            cout << "Converted to c" << endl;
            [[fallthrough]]; // 명시적으로 break 를 사용하지 않음을 알림, C++17 이상
        case 'c':
            cout << "You selected Chicken" << endl;
            break;
        default:
            cout << "Invalid Input" << endl;
        }
    }
    {
        // 정수형과 호환되는 녀석들만 switch를 할 수 있음
        // 문자열은 안 됨 -> 이런 경우 if 문
        bool b = true;
        switch (b)
        {
        case true:
            cout << "true" << endl;
            break;
        default:
            cout << "false" << endl;
        }
    }
    {
        // if 문과의 비교
        // if 문의 개수만큼 비교 연산 실행
        int selection = 0;
        if (selection == 0)
            cout << 0 << endl;
        else if (selection == 1)
            cout << 1 << endl;
        else if (selection == 2)
            cout << 2 << endl;
        else if (selection == 3)
            cout << 3 << endl;

        // 한 번만 비교 실행
        switch (selection)
        {
        case 0:
            cout << 0 << endl;
            break;
        case 1:
            cout << 1 << endl;
            break;
        case 2:
            cout << 2 << endl;
            break;
        case 3:
            cout << 3 << endl;
            break;
        }
    }
    {
        // switch 안에서 변수 선언
        int num0, num1;
        switch (int count = scanf("%d %d", &num0, &num1))
        {
        case 1:
            cout << num0 << endl;
            break;
        case 2:
            cout << num0 << endl;
            cout << num1 << endl;
            break;
        }
    }
    {
        // switch 안에서 변수 선언 2
        // C++17 이상
        switch (int num0, num1;int count = scanf("%d %d", &num0, &num1))
        {
        case 1:
            cout << num0 << endl;
            break;
        case 2:
            cout << num0 << endl;
            cout << num1 << endl;
            break;
        }
    }
}