#include <iostream>

using namespace std;

int main()
{
    {
        int nums[] = { 1, 2, 3 };
        cout << nums << endl; // 주소 출력

        int* pNums = nums; // 배열이 포인터로 decay(변환의 일종)

        cout << sizeof(nums) << endl;
        cout << sizeof(pNums) << endl; // 길이 속성을 잃음

        // 다 같은 주소 값
        cout << nums << endl;       // int*, decay 되었다.
        cout << &nums << endl;      // int (*)[3], 이 녀석만 타입이 다름
        cout << &nums[0] << endl;   // int*
        cout << endl;

        cout << typeid(1).name() << endl;       // int
        cout << typeid(nums).name() << endl;    // int [3], typeid를 사용하면 decay되지 않은 제대로 된 타입이 나옴
        cout << typeid(&nums).name() << endl;   // int (*)[3]
        cout << typeid(&nums[0]).name() << endl;// int*
    }
    {
        int nums[] = { 1, 2, 3 };
        int* pNums = nums;

        cout << pNums[0] << endl;   // 1
        cout << pNums[1] << endl;   // 2
        cout << pNums[2] << endl;   // 3

        cout << pNums << endl;      // base address + sizeof(int) * 0
        cout << pNums + 1 << endl;  // base address + sizeof(int) * 1
        cout << pNums + 2 << endl;  // base address + sizeof(int) * 2

        cout << *pNums << endl;
        cout << *(pNums + 1) << endl;
        cout << *(pNums + 2) << endl;
    }
    {
        int nums[] = { 1, 2, 3 };
        int* pNums = nums;

        cout << *pNums << endl; // nums[0]
        pNums++;
        cout << *pNums << endl; // nums[1]
    }
}