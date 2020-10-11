#include <iostream>
#include <vector>

using namespace std;

int main()
{
    {
        // 가변 배열
        // 기본 값(0)으로 초기화 되어 있음
        vector<int> vec(10);
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << vec[i] << endl;
        }
    }
    {
        vector<int> vec(5, 2);
        for (int num : vec)
            cout << num << endl;

        vec.resize(10, 20);
        for (int num : vec)
            cout << num << endl;
    }
    {
        vector<int> vec;
        cout << vec.size() << endl; // 0

        vec.push_back(10);
        cout << vec.size() << endl; // 1
        cout << vec[0] << endl; // 10
    }
    {
        vector<int> vec;
        for (int i = 0; i < 10; ++i)
        {
            vec.push_back(i);
            cout << vec.size() << endl;
            cout << vec.data() << endl; // 주소가 바뀐다(재할당이 발생)
        }
    }
    {
        vector<int> vec{ 1, 2, 3 };
        cout << vec.front() << endl; // 1
        cout << vec.back() << endl; // 2
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        vec0.swap(vec1);
        // vec0 : 3, 2, 1
        // vec1 : 1, 2, 3
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        vec0 = vec1;
        // vec0 : 3, 2, 1
        // vec1 : 3, 2, 1
    }
    {
        vector<int> vec0{ 1, 2, 3 };
        vector<int> vec1{ 3, 2, 1 };
        if (vec0 == vec1)
            cout << "==";
        if (vec0 > vec1)
            cout << ">";
        if (vec0 < vec1)
            cout << "<";
    }

}