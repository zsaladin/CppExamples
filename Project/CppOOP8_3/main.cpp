#include <iostream>
#include <list>
#include <forward_list>
#include <algorithm>

using std::cout;
using std::endl;


bool condition(const int& value)
{
    return value % 2 == 0;
}

int main()
{
    {
        // 양방향 연결 리스트
        std::list<int> list0{ 1, 2, 3 };
        // list0[2]; 안 됨, Indexing 자체가 O(n)이 걸리기 때문에 지원하지 않음
        // stl은 느리면(적합하지 않으면) 연산을 지원하지 않는다.
        // Head <-> Node0 <-> Node1 <-> Tail

        std::list<int>::iterator iter = list0.begin();
        std::advance(iter, 2); // 이렇게 두 번 전진할 수는 있음
        cout << *iter << endl;
        
        list0.sort(); // sort 를 따로 지원
        //std::sort(list0.begin(), list0.end()); 랜덤 액세스 이터레이터를 지원하는 컨테이너만 가능


        // list는 중간 삽입, 삭제가 빠름
        list0.remove(2);
        list0.remove_if(condition); // 조건에 맞으면 지움
        cout << endl;

        
        std::list<int> list1{ 1, 1, 2, 3 };
        std::list<int> list2{ 1, 2, 3, 4 };

        // 정렬 되어 있는 두 리스트를 연결하여 정렬
        list1.merge(list2);
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;

        // 중복 제거
        list1.unique();
        for (int num : list1)
        {
            cout << num << endl;
        }
        cout << endl;
    }
    {
        // 단방향 연결 리스트
        std::forward_list<int> list0{ 1, 2, 3, 4 };

        // 거의 사용하지 않는다. 제약이 많음
    }
}

