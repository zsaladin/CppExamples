#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

class Max
{
public:
    int operator()(int x, int y)
    {
        return max(x, y);
    }
};


class AccMax
{
private:
    // 일반 함수와는 다르게 상태를 저장할 수 있다
    int _max = numeric_limits<int>::min();

public:
    int operator()(int x)
    {
        return _max = max(x, _max);
    }
};


struct Average
{
private:
    double _total = 0;
    int _times = 0;

public:
    double operator()(double value)
    {
        _times += 1;
        _total += value;
        return _total / _times;
    }
};


struct Print
{
public:
    void operator()(int v) const
    {
        cout << v << endl;
    }
};

int main()
{
    Max mx;
    cout << mx(1, 2) << endl;
    cout << mx(2, 3) << endl;
    cout << mx(3, 4) << endl;
    cout << mx(5, 6) << endl;


    AccMax amx;
    cout << amx(1) << endl;
    cout << amx(3) << endl;
    cout << amx(5) << endl;
    cout << amx(2) << endl;
    cout << amx(4) << endl;
    cout << amx(6) << endl;


    Average avg;
    cout << avg(100) << endl;
    cout << avg(200) << endl;
    cout << avg(300) << endl;


    Print print;
    int nums[] = { 1, 2, 3, 4, 5 };
    std::for_each(nums, nums + size(nums), print);

    function<void(int)> func = print;
    func(1);

    plus<int> p; // 함수 객체
    cout << p(1, 2) << endl;

    negate<int> n; // 함수 객체
    cout << n(1) << endl;

    equal_to<int> et; // 함수 객체
    cout << et(1, 1) << endl;
}