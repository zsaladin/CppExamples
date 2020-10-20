#pragma warning(disable:4996)
#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        // C++ 스타일
        string s0 = "hello";
        string s1 = "world";
        s0.append(s1); // 객체 s0의 함수 append 사용
        s0 += s1; // 객체 s0와 s1의 관계를 알 수 있음

        cout << s0 << endl;
    }
    {
        // C 스타일
        char s2[100] = "hello"; // 내부 구현이 드러남(배열)
        char s3[] = "world";

        strcat(s2, s3);
        cout << s2 << endl;
    }
}