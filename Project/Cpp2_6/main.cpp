#include <iostream>

using namespace std;

int main()
{
    {
        // bool 선언 및 출력
        bool b0 = 0 == 0;
        bool b1 = 0 < 1;
        bool b2 = 0 > 1;

        cout << "b0 : " << b0 << endl;
        cout << "b1 : " << b1 << endl;
        cout << "b2 : " << b2 << endl;
    }
    {
        // bool 출력을 true, false로 하도록 변경
        bool b0 = 0 == 0;
        bool b1 = 0 < 1;
        bool b2 = 0 > 1;

        cout.setf(ios_base::boolalpha);
        cout << "b0 : " << b0 << endl;
        cout << "b1 : " << b1 << endl;
        cout << "b2 : " << b2 << endl;
    }
    {
        // bool과 if
        bool b0 = 0 == 0;
        bool b1 = 0 < 1;
        bool b2 = 0 > 1;

        if (b0)
            cout << "b0" << endl;
        if (b1)
            cout << "b1" << endl;
        if (b2)
            cout << "b2" << endl;
    }
    {
        // bool 에서 정수로 형 변환
        int itrue = true;
        int ifalse = false;

        cout << itrue << endl;
        cout << ifalse << endl;


        // 정수에서 bool로 형 변환
        bool btrue = 100;
        bool bfalse = 0;

        cout << btrue << endl;
        cout << bfalse << endl;
    }
}
