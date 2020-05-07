#pragma warning(disable: 4996)
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    {
        char str[] = "abc";
        cout << str << endl;
        cout << str[0] << endl;
        cout << str[1] << endl;
        cout << str[2] << endl;
        cout << str[3] << endl;
        cout << sizeof(str) << endl; // 길이가 3이 아니라 4

        cout << (int)str[0] << endl;
        cout << (int)str[1] << endl;
        cout << (int)str[2] << endl;
        cout << (int)str[3] << endl; // 문자열의 마지막은 항상 '\0'
        cout << strlen(str) << endl; // 문자열의 길이가 나온다.


        str[1] = '\0';
        cout << sizeof(str) << endl; // 4(배열의 길이, 변함 없음)
        cout << strlen(str) << endl; // 1('\0' 이전까지 길이)
    }
    {
        char str[100] = "hello";
        cout << (int)str[99] << endl; // "hello" 뒤는 전부 '\0'
    }
    {
        char str0[] = "hello";
        char str1[] = "hello";

        // 비교가 제대로 안 됨. 주소 값 비교임
        if (str0 == str1)
            cout << "true" << endl;

        // 같으면 0 다르면 -1 또는 1
        int result = strcmp(str0, str1);
        cout << result << endl;
    }
    {
        // 문자열 복사
        char str0[100];
        char str1[] = "hello";

        strcpy(str0, str1);
    }
    {
        // 문자열 붙이기
        char str0[100] = "hello";
        char str1[] = "world";

        strcat(str0, str1);
    }
    {
        // 문자열을 정수로 변경
        char str[] = "100";
        int num = atoi(str);
    }
    {
        // 문자열를 실수로 변경
        char str[] = "1.1";
        float num = atof(str);
    }
    {
        // 정수를 문자열로 변경
        int num = 100;
        char str[100];

        sprintf(str, "%d", num);
    }
    {
        char str[6];
        // 5개 이상의 문자열을 입력 받게 되면 문제
        // 공백이 있는 경우 공백 앞까지만 입력 받음(a b 라고 입력하면 a만 받음)
        // cin >> str;

        // 5개만 입력을 받고 개행 문자까지만 받음
        cin.getline(str, 6);
        cout << str << endl;
    }
}
