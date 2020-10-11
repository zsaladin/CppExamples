#include <iostream>

using namespace std;

// 함수 호출 비용을 줄여줌
// 실행 파일 사이즈가 커질 수 있음
// 항상 컴파일러가 인라인화 해주지는 않음
inline int square(int x)
{
    return x * x;
}


// 전처리를 이용한 인라인.
// 오류가 발생할 수 있으니 C++의 inline 문법을 사용
#define SQUARE(X) X*X


int main()
{
    int x = square(10);
    cout << x << endl;

    int y = 10;
    cout << SQUARE(++y) << endl; // 의도치 않은 결과 발생
}