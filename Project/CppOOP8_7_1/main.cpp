#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using std::cout;
using std::endl;


// 함수 객체
struct Func
{
    int operator()(int value) const
    {
        return value;
    }
};

int main()
{
    {
        Func func;
        cout << func(10) << endl;

        // lambda 객체
        auto func0 = []()
        {
            return 10;
        };
        cout << func0() << endl;

        int num = 1;
        auto func1 = [num](int value) // num이 캡쳐 됨
        {
            return num + value;
        };
        cout << func1(10) << endl;
    }
    {
        // algorithm의 find 사용
        std::vector<int> v{ 1, 2, 3, 4 };
        if (auto iter = std::find(v.begin(), v.end(), 4); iter != v.end())
        {
            cout << *iter << endl;
        }

        // 멤버 함수의 find 사용
        std::set<int> s{ 1, 2, 3, 4};
        if (auto iter = s.find(4); iter != s.end())
        {
            cout << *iter << endl;
        }

        // 멤버 함수가 있는 경우는 멤버 함수를 사용하자


        // find_if 는 set에도 멤버 함수가 없다. 
        std::find_if(s.begin(), s.end(), [](const int& value) {
            return (value % 2 == 0);
            });
    }
}