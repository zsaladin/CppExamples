#include <iostream>
#include <array>

using namespace std;

struct Person
{
    float weight;
    float height;
};

int main()
{
    {
        // C스타일 배열, 기존 출력 방법
        int nums[5] = { 1, 2, 3, 4, 5 };
        for (int i = 0; i < 5; ++i)
        {
            cout << nums[i] << endl;
        }

        // Range based for
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
    {
        // C++ 스타일 배열, 기존 출력 방법
        array<int, 5> nums = { 1, 2, 3, 4, 5 };
        for (int i = 0; i < 5; ++i)
        {
            cout << nums[i] << endl;
        }

        // Range based for
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경
        for (int i = 0; i < 2; ++i)
        {
            persons[i].weight = 0.f;
        }

        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경
        for (Person person : persons)
        {
            person.weight = 0.f;
        }

        // 변경 되지 않음
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        // 순회하면서 변경, 참조(레퍼런스)
        for (Person& person : persons)
        {
            person.weight = 0.f;
        }

        // 변경 됨
        for (Person person : persons)
        {
            cout << person.weight << " " << person.height << endl;
        }
    }
    {
        Person persons[]{
            Person{70.f, 181.f},
            Person{56.2f, 167.3f}
        };

        for (int i = 0; i < 2; ++i)
        {
            cout << &persons[i] << endl;
        }

        cout << endl;
        for (Person person : persons)
        {
            cout << &person << endl; // 주소 값이 다르다
        }

        cout << endl;
        for (Person& person : persons)
        {
            cout << &person << endl;
        }
    }
    {
        int nums[3] = { 1, 2, 3 };
        for (int num : nums)
        {
            num = 0; // 안 바뀜
        }
        for (int num : nums)
        {
            cout << num << endl;
        }

        for (int& num : nums) // 참조(레퍼런스)
        {
            num = 0; // 바뀜
        }
        for (int num : nums)
        {
            cout << num << endl;
        }
    }
}