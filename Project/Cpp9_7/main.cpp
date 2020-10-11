#include <iostream>
#include <string>

using namespace std;

int countDigit(int num)
{
    if (num == 0)
        return 1;

    int count = 0;
    while (num)
    {
        num /= 10;
        ++count;
    }
    return count;
}


int countDigit(string num)
{
    return countDigit(stoi(num));
}


//string countDigit(int num)  반환형식으로는 함수 오버로딩이 안 됨
//{
//
//}


// 컴파일 시 함수 이름을 바꾼다. name decoration, name mangling
// 컴파일 시 어떤 함수가 호출 되는지 결정이 된다. 정적 바인딩
void func(int, int); // func#int-int
void func(char); // func#char

int main()
{
    cout << countDigit(12345) << endl;
    cout << countDigit("12345") << endl;


    // operator<< 라는 함수가 매개변수에 따라(char 또는 int) 오버로딩이 되어있다.
    cout << 'a' << endl;
    cout << (int)'a' << endl;
}