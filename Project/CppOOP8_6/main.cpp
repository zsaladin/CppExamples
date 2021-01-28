#include <iostream>
#include <vector>
#include <list>
#include "Ranges.h"

using std::cout;
using std::endl;


template<typename TIterator, typename T>
bool has(TIterator begin,TIterator end, T value)
{
    for (auto iter = begin; iter != end; ++iter)
    {
        if (*iter == value)
            return true;
    }
    return false;
}

int main()
{
    {
        std::vector<int> v{ 1, 2, 3 };

        for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter)
        {
            *iter *= 2;
        }

        for (std::vector<int>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter)
        {
            //*iter = 10; // const_iterator 이기 떄문에 변경 불가능
            cout << *iter << endl;
        }
    }
    {
        std::vector<int> nums0{ 1, 2, 3 };
        std::list<int> nums1{ 1, 2, 3 };

        std::cout << std::boolalpha;
        // 이터레이터를 통해 이종의 컨테이너에 대해 같은 코드를 사용
        std::cout << has(nums0.begin(), nums0.end(), 1) << endl;
        std::cout << has(nums1.begin(), nums1.end(), 4) << endl;
        std::cout << std::endl;
    }
    {
        // Range based for loop 역시 이터레이터 인터페이스를 이용한다
        for (int num : Ranges(0, 3))
        {
            std::cout << num << endl;
        }
    }
}

