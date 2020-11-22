#include <iostream>

using std::cout;
using std::endl;

// 함수 템플릿
// 실제로는 함수가 아니다. 함수에 대한 템플릿, 템플릿을 기반으로 실제 함수 코드가 만들어진다
// 템플릿 파라메터로 타입을 받는다
template<typename T>
void swap(T& x, T& y)
{
    int temp = x;
    x = y;
    y = temp;
}


// 템플릿의 파라메터로 int 값을 받는다
template<int N>
int func(int (&nums)[N])
{
    return N;
}


// 타입 파라메터와 값 파라메터를 같이 받는 템플릿
template<int N, typename T>
int getSize(T(&nums)[N])
{
    return N;
}

int main()
{
    {
        int x = 10, y = 20;
        swap<int>(x, y); // 타입 명시
        cout << x << endl;
        cout << y << endl;

        swap(x, y); // 명시하지 않아도 타입이 추론된다.(여기서는 int로 추론된다)
    }


    {
        int nums[] = { 1, 2, 3 };
        cout << func<3>(nums) << endl; // 값 명시
        cout << func(nums) << endl;  // 3을 추론한다. 즉 배열의 사이즈를 추론을 통해서 구할 수 있다
    }
    {
        int nums[] = { 1, 2, 3 };
        cout << getSize(nums) << endl;

        char chars[] = {'a'};
        cout << getSize(chars);
    }
}