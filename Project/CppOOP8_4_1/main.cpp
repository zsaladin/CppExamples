#include <iostream>
#include <map>

using std::cout;
using std::endl;


int main()
{
    // Key, Value, 트리 기반, 삽입 삭제 O(log n)
    std::map<int, std::string> m;
    m[1] = "a";

    cout << m[1] << endl;
    cout << m[2] << endl; // 첨자 연산 조회 시 Value가 없는 경우 Value의 기본 값이 나오게 됨

    // map의 원소는 std::pair
    std::map<int, std::string> m0{
        {1, "1"},
        std::pair<int, std::string>(2, "2"),
        std::make_pair(3, "3")
    };

    // 항상 Key 값으로 정렬이 되어 있다
    for (const std::pair<int, std::string>& pair : m0)
    {
        cout << pair.first << ":" << pair.second << endl;
    }

    std::map<int, std::string> m1;
    // 사실 상 pair는 std::pair<int, std::string> 이 아니라 std::pair<const int, std::string>
    // Tree에서 Key는 바뀌면 안 되기 때문
    for (const std::pair<int, std::string>& pair : m1) // 실제로 pair의 타입이 다르기 때문에 형변환이 일어남
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const std::pair<const int, std::string>& pair : m1) // 실제로 const가 있는 pair가 맞는 표현
    {
        cout << pair.first << ":" << pair.second << endl;
    }
    for (const auto& pair : m1) // 실수를 방지 하기 위해 auto를 사용
    {
        cout << pair.first << ":" << pair.second << endl;
    }
}