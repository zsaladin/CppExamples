#include <iostream>
#include <cfloat>

using std::cout;
using std::endl;

union ID
{
    char chars[10];
    int integer;
};


int main()
{
    ID id;
    id.integer = 10;

    // 해당 비트 배열을 int로 인식하겠다는 의미
    // 사용에 주의
    int* p = reinterpret_cast<int*>(&id);
    cout << *p << endl;


    // 특수한 경우 메모리의 특정 주소에 있는 값을 Device로 다루는 경우가 있을 수 있음
    //Device* p0 = reinterpret_cast<Device*>(0xabcd);

    
    // 0000,0000,0000,0000,0000,0000,0000,0001
    // int, 1의 비트 배열을 flaot 형태로 해석하면 float의 최소 값이 나옴
    int i = 1;
    float* a = reinterpret_cast<float*>(&i);
    cout << *a << endl;
    cout << FLT_TRUE_MIN << endl;

    // 일반 형변환은 단순히 1이 나온다
    float b = i;
    cout << b << endl;

}