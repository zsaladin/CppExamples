#pragma warning(disable: 4996)

#include <iostream>
#include <limits>

using namespace std;
int main()
{
    {
        // 정수 입력
        int num;
        cin >> num;
        cout << num << endl;
    }
    {
        // 입력이 성공했을 때만 출력
        // 10 입력 성공
        // a  입력 실패
        int num;
        if (cin >> num)
            cout << num << endl;
    }
    {
        // 입력 실패 처리
        int num;
        cin >> num;
        cout << num << endl;

        // 입력이 실패했을 경우 초기화 시켜준다.
        if (cin.fail())
            cin.clear();

        // 버퍼에 남은 문자 한 개를 무시
        // cin.ignore();

        // 개행 문자가 나올 때까지 무시한다.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cin >> num;
        cout << num << endl;
        cout << num << endl;
    }
    {
        // bool 입력을 1/0로 받기
        bool b;
        cin >> b;
        cout << b << endl;

        // bool 입력을 true/false로 받기
        cin.setf(ios_base::boolalpha);
        cin >> b;
        cout << b << endl;
    }
    {
        // 16 진수로 입력 받기
        int num;
        cin.setf(ios_base::hex, ios_base::basefield);
        cin >> num;
        cout << num << endl;

        cin >> hex >> num;
        cout << num << endl;
    }
    {
        freopen("input.txt", "r", stdin);

        int num;
        cin >> num;
        cout << num << endl;
    }
}