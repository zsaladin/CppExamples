#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>


using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vector;
        vector.push_back(10);
        vector.push_back(20);
        vector.push_back(-1);

        // 넣어주는 순서대로 출력, Sequence Container
        cout << "vector" << endl;
        for (int num : vector)
            cout << num << endl;


        std::set<int> set;
        set.insert(10);
        set.insert(20);
        set.insert(-1);

        // 정렬된 순서대로 출력, Ordered Associative Container
        cout << "set" << endl;
        for (int num : set)
            cout << num << endl;


        std::unordered_set<int> uset;
        uset.insert(10);
        uset.insert(20);
        uset.insert(-1);

        // 순서보장이 안됨, Unordered Associative Container
        cout << "unordered set" << endl;
        for (int num : uset)
            cout << num << endl;

    }
    {
        std::vector<int> nums{ 1, 2, 3, 4 };
        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << endl;
        }
        cout << endl;

        for (int num : nums)
        {
            cout << num << endl;
        }
        cout << endl;

        // 이터레이터는 포인터 사용법과 호환이 됨
        for (std::vector<int>::iterator iter = nums.begin(); iter != nums.end(); ++iter) // [begin, end)
        {
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums{ 10, 1, 2, 3, 4 };

        // 알고리즘을 사용하여 정렬
        std::sort(nums.begin(), nums.end());

        for (int num : nums)
            cout << num << endl;
    }
}