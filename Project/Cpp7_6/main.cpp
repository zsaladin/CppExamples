#include <iostream>

using namespace std;

int main()
{
    {
        // 값의 형태로 선언할 수 없음
        //void p;
    }
    {
        int num = 10;
        int* p = &num;

        // void* 는 다른 데이터형을 가리킬 수 있음
        void* vp = p;

        // 포인터를 어떤 형태로 다루어야 하는지 알 수 없어서 불가능
        //cout << *vp << endl;
        
        // 다른 형으로 변환 가능
        p = (int*)vp;
    }
    {
        int nums[] = { 1, 2, 3 };
        void* vp = nums;

        // 안 된다
        //*(vp + 1);
    }
    {
        // 사용 되는 곳
        // malloc은 메모리를 매개변수의 크기만큼한 할당한다. 이 경우 sizeof(int) * 3 만큼
        // malloc 함수 안에서는 타입을 알 수 없고 크기만 알기 때문에 void*로 반환 함
        int* p = (int*)malloc(sizeof(int) * 3);

        // 모둔 타입의 동적할당 된 변수가 해제 되어야 하니 void*로 매개 변수를 받는다.
        free(p);
    }
}