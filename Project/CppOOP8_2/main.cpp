#include <iostream>
#include <vector>
#include <deque>

using std::cout;
using std::endl;


int main()
{
    {
        std::vector<int> vec{ 1, 2, 3 };
        std::vector<int>::iterator iter = vec.begin();
        int* num = &vec[0];

        // vector의 사이즈가 크고 얼만큼 커질 지 알 수 있다면 reserve를 미리 해주자
        vec.reserve(vec.capacity() + 1);

        // 둘의 주소가 다르다.
        cout << num << endl;
        cout << &vec[0] << endl;

        // 대체로 시간 복잡도 O(1), 재할당 될 때가 있으니 주의
        vec.push_back(10);

        // 시간 복잡도 O(1)
        vec.pop_back();

        // 가장 앞에 삽입했기 때문에 O(n), 뒤로 다 밀림
        vec.insert(vec.begin(), 10);

        // [1, 2, 3, ?] 
        // size = 3
        // capacity = 4

        // push_back(4)
        // [1, 2, 3, 4]
        // size = 4
        // capacity = 4

        // push_back(5)
        // [1, 2, 3, 4, 5, ?, ?, ?] // 배열의 재할당
        // size = 4
        // capacity = 8
    }
    {
        std::deque<int> nums;

        // 대체로 O(1)
        nums.push_front(1);

        // 대체로 O(1)
        nums.push_back(2);

        // push_back
        // [0]

        // push_front
        // [1] [0]
        // push_front 도 빠르게 만들기 위해서 배열을 더 만든다.
    }
}
