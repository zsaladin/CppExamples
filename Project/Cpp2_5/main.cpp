#include <iostream>

using namespace std;
int main()
{
    {
        // "Hello World", 문자열
        cout << "Hello World" << endl;
    }
    {
        // 'h', 문자
        cout << 'h' << endl;
    }
    {
        // 문자와 정수의 관계
        char ch = 'a';
        cout << ch << endl;

        char ch0 = 'a';
        char ch1 = 97;

        cout << "ch0 : " << ch0 << endl; // a
        cout << "ch1 : " << ch1 << endl; // a

        cout << "ch0 : " << (int)ch0 << endl; // 97
        cout << "ch1 : " << int(ch1) << endl; // 97

        // 같은 값이지만 어떤 타입으로 넘기는 지에 따라 다르게 출력
        cout << (char)97 << endl; // a
        cout << 97 << endl; // 97
    }
    {
        // 문자의 사이즈
        cout << "sizeof(char) : " << sizeof(char) << endl;
    }
    {
        // Escape Sequence
        cout << "New Line" << endl;
        cout << "Hello World";
        cout << '\n';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Tab" << endl;
        cout << "Hello World";
        cout << '\t';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Backspace" << endl;
        cout << "Hello World";
        cout << '\b';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Audio" << endl;
        cout << "Hello World";
        cout << '\a';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Single Quotation Mark" << endl;
        cout << "Hello World";
        cout << '\'';
        cout << "Hello World";
        cout << endl << endl;

        cout << "Double Quotation Mark" << endl;
        cout << "\"Hello World\"";
        cout << "Hello World";
        cout << endl << endl;

        cout << "Hex" << endl;
        cout << '\x61';
        cout << endl << endl;

        cout << "Oct" << endl;
        cout << '\141';
        cout << endl << endl;
    }
    {
        // MultiCharacter Literal - 사용 주의, 표준이 아님
        char ch = 'ab';
        int num = 'ab';

        cout << ch << endl;
        cout << num << endl;
    }
}