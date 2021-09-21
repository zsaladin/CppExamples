#include <iostream>
#include "MoveString.h"
#include "NotMoveString.h"


template<typename T>
void swapCopy(T& x, T& y)
{
    T temp = x; // 임시 객체에 복사하는 비용
    x = y;
    y = temp;
}


template<typename T>
void swapMove(T& x, T& y)
{
    T temp = std::move(x); // 강제로 이동,
    x = std::move(y);
    y = std::move(temp);
}

int main()
{
    NotMoveString nms0("abc");
    nms0 = NotMoveString("def"); // 복사 비용 발생


    MoveString  ms0("abc");
    ms0 = MoveString("def"); // 복사 비용 발생 하지 않음, 이동
    MoveString ms1("def");
    ms0 = ms1;  // 이동하지 않고 복사, ms1 이 이후에 사용될 수 있기 때문

    swapCopy(ms0, ms1);
    swapMove(ms0, ms1);
}