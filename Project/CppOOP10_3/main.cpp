#include <iostream>
#include <vector>
#include <numeric>
#include <range/v3/all.hpp>


int main()
{

    {
        // sort 비교
        std::vector<int> v{ 3, 2, 1 };

        std::sort(v.begin(), v.end());
        ranges::sort(v);

        for (int& i : v)
            std::cout << i << std::endl;
        std::cout << std::endl;
    }
    {
        // find 비교
        std::vector<int> v(10);
        std::iota(v.begin(), v.end(), 0);

        auto iter = ranges::find(v, 3);
        std::cout << *iter << std::endl;

        iter == std::find(v.begin(), v.end(), 3);
        std::cout << *iter << std::endl;
        std::cout << std::endl;
    }
    {
        // view, lazy evaluation
        // 0 ~ 9까지 출력
        for (int num : ranges::views::iota(0, 10))
            std::cout << num << std::endl;

        // 0부터 무한대
        //for (int num : ranges::views::iota(0))  // 실제로 무한대까지 숫자를 미리 만들어두지 않고 필요할 때 만든다
        //    std::cout << num << std::endl;
        std::cout << std::endl;
    }
    {
        // 합성, 파이프를 이용하여 합성
        auto r =
            ranges::views::iota(0, 10) |
            ranges::views::reverse |
            ranges::views::filter([](const int& num) {
            return num % 2 == 0;
                }) |
            ranges::views::cycle |
                    ranges::views::take(20);
        for (int num : r) {
            std::cout << num << std::endl;
        }
        std::cout << std::endl;
    }
    {
        // Action, 컨테이너에 영향을 줌
        auto v = ranges::views::iota(0, 20) | ranges::to<std::vector<int>>();
        v |= ranges::actions::reverse | ranges::actions::drop(2);

        std::cout << ranges::views::all(v);
    }
}
