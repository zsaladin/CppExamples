#include <iostream>
#include <array>

using namespace std;

int main()
{
    {
        // int가 5개 있는 C++ 스타일 배열 선언
        // 내부적으로 정적 배열을 가지고 있다
        // 초기화가 안 되어 있으면 쓰레기 값
        array<int, 5> arr0;

        // 기본값으로 초기화(int의 경우 기본값은 0)
        array<int, 5> arr1{};

        // arr2[0], arr2[1]의 값만 세팅 되고 나머지 값들은 기본값으로 초기화(int의 경우 기본값은 0)
        array<int, 5> arr2{ 0, 1 };
    }
    {
        array<int, 5> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        //cout << arr[-1] << endl; // release 빌드 시 예외 발생 안 할 수 있음(정의 되지 않은 행동)
        //cout << arr.at(-1) << endl; // 범위 벗어날 떄 예외 보장 (std::out_of_range)
    }
    {
        // 배열 사이즈 구하기
        int arr0[] = { 1, 2, 3 };
        cout << sizeof(arr0) / sizeof(int) << endl;
        cout << sizeof(arr0) / sizeof(arr0[0]) << endl;

        array<int, 3> arr1 = { 1, 2, 3 };
        cout << arr1.size() << endl;
    }
    {
        // 배열의 가장 앞, 가장 뒤 원소 구하기
        array<int, 3> arr{ 1, 2, 3 };
        cout << arr[0] << endl;
        cout << arr.front() << endl;

        cout << arr[arr.size() - 1] << endl;
        cout << arr.back() << endl;
    }
    {
        array<int, 5> arr0{ 1, 2, 3, 4, 5 };
        array<int, 5> arr1{ 5, 4, 3, 2, 1 };

        // 교환
        arr0.swap(arr1);

        // 대입 가능
        arr0 = arr1;

        // 비교 연산들 가능
        if (arr0 == arr1)
        {

        }
        if (arr0 > arr1)
        {

        }
        if (arr0 < arr1)
        {

        }
    }
    {
        array<int, 5> arr{ 1, 2, 3, 4, 5 };
        cout << arr.data()[0] << endl; // 내부 정적 배열에 접근
    }
}