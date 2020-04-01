#pragma warning(disable: 4996)
#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    {
        cout << 1 << endl;
        cout.operator<<(1).operator<<(endl); // 위와 동일(연산자 오버로딩, 추후 배움)

        cout << '1' << endl;
        operator<<(cout, '1').operator<<(endl); // 위와 동일(연산자 오버로딩, 추후 배움)
    }
    {
        cout << 'a' << 'b' << endl;
        cout.put('a').put('b').put('\n');
        cout.write("ab\n", 3);
    }
    {
        // 10칸 여백
        cout.width(10);
        cout << 1 << endl;
    }
    {
        // 10칸을 여백
        cout.width(10);
        // 여백에 공백 문자 대신 '#'을 넣어준다.
        cout.fill('#');
        cout << 1 << endl;
        // '#'이 었던 것을 원상 복구
        cout.fill(' ');
    }

    {
        float num = 0.1234567;

        // 정밀도 조절 없이 출력
        cout << num << endl;

        // 정밀도 조절
        cout.precision(2);
        cout << num << endl;

        // 정밀도 조절
        cout.precision(64);
        cout << num << endl;
    }
    {
        // 양수에 + 기호를 표시하게 한다.
        cout.setf(ios_base::showpos);
        cout << 1 << endl;
        cout << 2 << endl;

        // 양수에 + 기호 표시를 하지 않게 한다.
        cout.unsetf(ios_base::showpos);
        cout << 1 << endl;
        cout << 2 << endl;
    }
    {
        // bool 값을 true/false로 출력하게 한다.
        cout.setf(ios_base::boolalpha);
        cout << true << endl;
        cout << false << endl;

        // bool 값을 1/0으로 출력하게 한다.
        cout.unsetf(ios_base::boolalpha);
        cout << true << endl;
        cout << false << endl;
    }
    {
        // 부호와 숫자를 양 끝에 배치한다.
        cout.setf(ios_base::internal, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;

        // 왼쪽 정렬한다.
        cout.setf(ios_base::left, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;

        // 오른쪽 정렬한다.
        cout.setf(ios_base::right, ios_base::adjustfield);
        cout.width(10);
        cout << -10 << 20 << endl;
    }
    {
        // 8진수로 출력한다.
        cout.setf(ios_base::oct, ios_base::basefield);
        cout << 16 << endl;

        // 16진수로 출력한다.
        cout.setf(ios_base::hex, ios_base::basefield);
        cout << 16 << endl;

        // 10진수로 출력한다.
        cout.setf(ios_base::dec, ios_base::basefield);
        cout << 16 << endl;
    }
    {
        // 16진수, 8진수, 10진수 출력을 다른 방식으로 표현
        cout << hex << 16 << endl;
        cout << oct << 8 << endl;
        cout << dec << 10 << endl;

        // hex는 함수이다.
        hex(cout);
        cout << 16 << endl;

        // oct는 함수이다.
        oct(cout);
        cout << 8 << endl;

        // dec는 함수이다.
        dec(cout);
        cout << 10 << endl;
    }
    {
        // << 을 이용하여 기존에 사용했던 것들을 표현
        cout << setw(10) << setfill('#') << setprecision(2) << showpos << 1.1f;
    }
    {
        // stdout를 output.txt 파일로 출력
        freopen("output.txt", "w", stdout);
        cout << "Hello World" << endl;
    }
}
