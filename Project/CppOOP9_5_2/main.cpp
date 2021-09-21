#include <iostream>
#include <vector>
#include "MoveString.h"


MoveString makeString(const char* str)
{
    return MoveString(str); // 이곳에 복사가 일어날 것으로 예상하여 std::move를 사용하지 말자. RVO 최적화
}

int main()
{
    std::vector<MoveString> s{ MoveString("abc") };
    std::cout << "resize" << std::endl;
    s.reserve(100); // MoveString의 이동 관련 함수들의 noexcept 를 삭제하는 경우 복사 발생


    makeString("abc");


    int num0 = 10;
    int& num1 = num0;
    int&& num2 = num0 + num1; // 임시 값을 받을 수 있다

    //int& num3 = 3; // 임시 값을 받을 수 없다
    //int&& num4 = num0; // 임시 값이 아니기 때문에 받을 수 없다
    //int&& num5 = num1; // 임시 값이 아니기 때문에 받을 수 없다

    int& num6 = num2; // r-value reference 는 l-value 이기 때문에 받을 수 있다
    //int&& num7 = num2; // r-value reference 는 l-value 이기 때문에 받을 수 없다
    int&& num8 = std::move(num0);

}