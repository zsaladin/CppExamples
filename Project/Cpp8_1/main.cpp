#include <iostream>
#include <vector>

using namespace std;


int main()
{
    {
        int num0 = 10;
        int& num1 = num0;  // 참조
        int* num2 = &num0; // 포인터

        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        num0 = 20;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        num1 = 30;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;

        *num2 = 40;
        cout << num0 << endl;
        cout << num1 << endl;
        cout << *num2 << endl;
        cout << endl;
    }
    {
        int num0 = 10;
        // 초기화 할 때 가리키는 녀석이 고정 됨, 바꿀 수 없음
        int& num1 = num0;

        int num2 = 20;

        // num2의 값이 쓰여짐, num2를 가리키게 할 수 없음.
        num1 = num2;
    }
    {
        vector<int> vec0;
        vector<int>& vec1 = vec0;  // 가능
        vector<int>* vec2 = &vec0; // 가능
    }
    {
        int* num0 = new int(12);
        int& num1 = *num0;

        cout << num0 << endl;
        cout << num1 << endl;

        delete num0;

        // 해제된 레퍼런스 사용 시 위험
        //cout << num1 << endl;
    }
    {
        int num0 = 10;
        int& num1 = num0;
        int* const num2 = &num0; // 이렇게 하면 참조와 비슷해짐

        int num3 = 20;

        // 참조처럼 초기화 이후 가리키는 녀석을 바꿀 수 없게 된다
        //num2 = &num3;
    }

}