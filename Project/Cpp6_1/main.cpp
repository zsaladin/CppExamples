#include <iostream>

using namespace std;

int main()
{
    {
        // bool이 31개 있는 배열
        bool attendanceBook[31];
        // bool, bool, bool ... bool (*31)

        attendanceBook[0];  // 배열의 맨 앞 값 (0)
        attendanceBook[30]; // 배열의 맨 뒤 값 (SIZE - 1)

        attendanceBook[-1]; // 정의 되지 않은 행동, 음수 (컴파일 됨)
        attendanceBook[31]; // 정의 되지 않은 행동, 사이즈 초과 (컴파일 됨)
    }
    {
        int arraySize;
        cin >> arraySize;

        // 변수로 배열 사이즈를 지정할 수 없다
        //  bool attedanceBook[arraySize]; 
    }
    {
        // 상수를 이용한 배열 사이즈
        const int arraySize = 31;
        bool attendanceBook[arraySize];

        // 상수는 바꿀 수 없다.
        //arraySize = 1;
    }
    {
        // 매크로를 이용한 배열 사이즈
#define ARRAY_SIZE 31
        bool attendanceBook[ARRAY_SIZE];
    }
    {
        int nums[3];
        cout << nums[0] << endl; // 초기화가 안 돼서 쓰레기 값이 나온다.
    }
    {
        // 배열의 값 설정
        int nums[3];
        nums[0] = 10;
        nums[1] = 10;
        nums[2] = 10;
    }
    {
        // 초기화 리스트
        int nums[3] = { 1, 2, 3 };
    }
    {
        int nums[3] = { 1 }; // 1 이후로는 0으로 채워진다.
    }
    {
        int nums[]{ 1, 2 }; // 사이즈 명시 하지 않으면 초기화 시 넣어준 원소의 개수 배열

        // 배열 자체의 사이즈
        cout << sizeof(nums) << endl;

        // 배열 원소의 개수
        cout << sizeof(nums) / sizeof(int) << endl;
    }
    {
        // 배열 순회
        int nums[]{ 1, 2, 3, 4 };
        int size = sizeof(nums) / sizeof(int);
        for (int i = 0; i < size; ++i)
        {
            cout << nums[i] << endl;
        }

        int i = 0;
        while (i < size)
        {
            cout << nums[i] << endl;
            i++;
        }
    }
    {
        // 배열 개 수 구하기 
        int nums[3];
        int nSize = size(nums);
        cout << nSize << endl;
    }
    {
        // 배열 복사
        int nums0[3] = { 0, 1, 2 };
        int nums1[3];

        // 대입 안 됨
        // nums1 = nums0;

        // 순회를 이용한 복사
        for (int i = 0; i < 3; ++i)
        {
            nums1[i] = nums0[i];
        }

        // 함수를 이용한 복사
        memcpy(nums1, nums0, sizeof(nums0));
        memcpy(&nums1, &nums0, sizeof(nums0));
        copy(nums0, nums0 + 3, nums1);
    }
    {
        // 홀수번 반복 되어 있는 한 개의 수 구하기
        int nums[] = { 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 1, 2, 3 };
        int result = 0;
        for (int i = 0; i < size(nums); ++i)
        {
            result ^= nums[i];
        }

        cout << result << endl; // 4
    }
    {
        int nums[]{ 5, 4, 3, 1, 7, 4, 3, 5, 6, 1, 2 };
        for (int i = 0; i < size(nums); ++i)
        {
            for (int j = 0; j < size(nums) - i - 1; ++j)
            {
                if (nums[j] > nums[j + 1])
                {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        for (int i = 0; i < size(nums); ++i)
        {
            cout << nums[i] << endl;
        }
    }
}