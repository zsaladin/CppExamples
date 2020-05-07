#include <iostream>
#include <string>

using namespace std;

int main()
{
    {
        string str = "abcd";
        cout << str << endl;
        cout << str[0] << endl;
        cout << str[1] << endl;
        cout << str[2] << endl;
        cout << str[3] << endl;
    }
    {
        string str;
        cin >> str; // 길이 제한이 없음
    }
    {
        string str0("abc");
        string str1("abc");

        // 비교 가능
        if (str0 == str1)
            cout << "Compareable" << endl;

        // 붙이기
        str0 += str1;

        // 사이즈 구하기
        str0.size();
        str1.length();
    }
    {
        string str0("abc");
        string str1("abc");

        // C 스타일 문자열 사용
        strcmp(str0.c_str(), str0.c_str());
    }
    {
        // 다른 타입을 문자열로 변환
        string str0 = to_string(123);
        string str1 = to_string(123.3);
    }
    {
        // 문자열을 다른 타입으로 변환
        int i = stoi("1");
        float f = stof("1.1");
    }
    {
        // 개행 문자까지 입력 받기
        // "a b"와 같이 중간에 공백이 있어도 "a b"를 다 받음
        string str;
        getline(cin, str);
    }


}