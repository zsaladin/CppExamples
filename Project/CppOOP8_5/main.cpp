#include <iostream>
#include <unordered_map>

using std::cout;
using std::endl;


struct BadHashFunction
{
    std::size_t operator()(const int& key) const
    {
        return 1;
    }
};

int main()
{
    {
        // 해시 테이블 기반, 삽입, 삭제 O(1)
        std::unordered_map<int, std::string> um{
            {1, "10"},
            {2, "20"},
            {3, "30"},
            {4, "40"},
        };

        // 순서가 보장 안 됨
        for (const auto& [key, value] : um)
        {
            cout << key << ":" << value << endl;
        }
    }
    {
        std::unordered_map<int, std::string, BadHashFunction> um;
        for (int i = 0; i < 100; ++i)
        {
            um[i] = i;
        }
        cout << um.bucket_count() << endl;
        cout << um.bucket_size(0) << endl;
        cout << um.bucket_size(1) << endl; // 한 개의 버켓에 모든 원소가 들어가게 됨. 항상 충돌 O(n)
    }
}
