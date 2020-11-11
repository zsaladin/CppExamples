#include <iostream>


using namespace std;


void func(float f)
{

}


int main()
{
    // double이 float으로 형 변환
    float f = 1;

    // double이 float으로 형 변환
    func(1);

    char ch0 = 'a';
    int num0 = ch0; // promotion, widening conversion, 확대 변환, 손실이 일어나지 않음

    int num1 = 1000;
    char ch1 = num1; // demotion, narrowing conversion, 축소 변환, 손실이 일어남

    // Uniform initailization
    // { } 를 이용하여 초기화를 하면 축소 변환의 경우 컴파일 타임 에러가 발생한다
    //char ch = { num1 };
    
    const int num2 = 10;
    char ch2{ num2 }; // num2는 int 지만 상수이기 때문에 컴파일 타임에 축소되지 않는다는 것을 알 수 있다

    unsigned short s0 = 40000;
    cout << s0 + s0 << endl; // int로 promotion 됨, int 보다 작은 사이즈는 int로 변환 됨
    cout << typeid(s0 + s0).name() << endl;

    unsigned int i0 = 4100000000;
    cout << i0 + i0 << endl; // 다른 타입으로 변하지 않고 오버플로
    cout << typeid(i0 + i0).name() << endl;

    unsigned int i1 = 10;
    int i2 = -110;
    cout << i0 + i2 << endl; // 언더플로우, 같은 타입의 연산 중 unsigned 가 한 개라도 붙어있으면 결과는 unsigned
    cout << typeid(i0 + i1).name() << endl;

    long long l0 = 10;
    cout << l0 + i1 << endl; // 큰 타입으로 변환된다
    cout << typeid(l0 + i1).name() << endl;

    // 정수, 실수의 연산 -> 실수
    // 실수, 실수의 연산 -> 더 큰 타입의 실수

    // if, while, for, &&, ||, !, :? 안의 bool이 필요한 경우
    // 변환 연산자, 변환 생성자를 explicit 로 정의하더라도 해당 자리에서는 암시적으로 변환 됨

    // type -> const type 으로는 암시적 변환

    // 자식 포인터(참조)-> 부모 포인터(참조) 타입으로 암시적 변환
}