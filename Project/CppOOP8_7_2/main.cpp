#include <iostream>
#include <vector>
#include <list>
#include <set>

using std::cout;
using std::endl;


int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 3, 2, 1 };
    // 실제로 지우지 않고 지워야 하는 원소들만큼 앞으로 당긴다, 사이즈는 그대로
    // 1, 3, 4, 3, ?, ?
    auto iter = std::remove(v.begin(), v.end(), 2);

    // erase 를 해야 지워진다
    v.erase(iter, v.end());

    for (auto num : v)
    {
        cout << num << endl;
    }

    // remove 가 범용적이어야 하기 때문에 array 등에도 사용해야한다
    // array 경우 정적 배열이기 때문에 사이즈를 조절할 수 없음


    std::list<int> l{ 1, 2, 3, 4, 3, 2, 1 };
    l.remove(2); // list는 멤버 변수로 가지고 있고 erase 까지 한다. 

    for (auto num : l)
    {
        cout << num << endl;
    }
    
    std::set<int> s{ 1, 2, 3, 4, 3, 2, 1 };
    //std::remove(s.begin(), s.end(), 2);  // 안 됨
}