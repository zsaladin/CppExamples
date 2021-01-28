#include <iostream>
#include <map>
#include <set>
#include <functional>

using std::cout;
using std::endl;


int main()
{
    {
        cout << std::boolalpha;

        std::map<int, std::string> m;
        std::pair<std::map<int, std::string>::iterator, bool> result = m.insert({ 3, "10" }); // 복잡하니까 auto 사용
        cout << result.second << endl; // 성공 여부
        cout << result.first->first << endl; // 해당 Key에 일치하는 map에 있는 iterator
        cout << result.first->second << endl;


        // C++17부터
        auto [iter, success] = m.insert({ 3, "20" });
        cout << success << endl;
        cout << iter->first << endl;
        cout << iter->second << endl;

        // C++17부터
        for (auto& [key, value] : m)
        {
            value = "abc";
        }

        // 이터레이터 찾기
        if (auto iter = m.find(3); iter != m.end())
        {
            cout << iter->second << endl; // 이터레이터로 지우기
            m.erase(iter);
        }
        m.erase(3); // 키로 지우기
        cout << endl;
    }
    {
        // 중복 key 허용
        std::multimap<int, std::string> mm{
            {2, "10"},
            {1, "10"},
            {1, "20"},
            {1, "30"},
        };

        for (const auto& [k, v] : mm)
        {
            cout << k << ":" << v << endl;
        }

        // 항상 성공
        mm.insert({ 1, "40" });
        
        // 경계
        auto lower = mm.lower_bound(1);
        auto upper = mm.upper_bound(1);
        //auto [lower, upper] = mm.equal_range(1); // 위와 같음
        for (auto iter = lower; iter != upper; ++iter)
        {
            cout << iter->second << endl;
        }
    }
    {
        // 트리 구조. Key만 있음, 정렬 되어 있음
        std::set<int> s{
            1, 2, 3, 4
        };

        if (auto [iter, success] = s.insert(10); success)
        {
            cout << *iter << endl;
        }
    }
    {
        // 트리 구조. Key만 있음, 정렬 되어 있음, 중복 허용
        std::multiset<int> ms{
            1, 1, 3, 10, 10, 3
        };
        for (const auto& num : ms)
        {
            cout << num << endl;
        }
    }
    {
        // std::less<int> 정렬을 어떻게 할지 결정하는 함수 객체
        std::set<int, std::less<int>> s;
        std::map<int, std::string, std::less<int>> m;

        std::set<int, std::less<int>> s0{ 3, 10, -1 };
        std::set<int, std::greater<int>> s1{ 3, 10, -1 };

        // 오름차순
        for (const auto& num : s0)
        {
            cout << num << endl;
        }

        // 내림차순
        for (const auto& num : s1)
        {
            cout << num << endl;
        }

    }
}