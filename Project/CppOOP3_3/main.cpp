#include <iostream>
#include "Animal.h"

using namespace std;


class A
{
public:
    int num;
};


class B : public A
{

};


A operator+(const A& x, const A& y)
{
    A a;
    a.num = x.num + y.num;
    return a;
}

B operator+(const B& x, const B& y)
{
    B b;
    b.num = x.num * y.num;
    return b;
}


void func(int x) // 컴파일 시 함수 이름이 변경 name mangling, 정적 결합
{
}

void func(int x, int y) // 컴파일 시 함수 이름이 변경 name mangling, 정적 결합
{
}


void foo(Animal* animal)
{
    animal->eat(); // 동적 결합, 오버라이딩, 실행 중일 때 animal의 실제 타입을 알 수 있고 그에 맞는 eat을 호출해준다
    animal->walk(); // 정적 결합, 컴파일 타임에 알 수 있는 'Animal' 만 보고 항상 뚜벅 
}



int main()
{
    // 정적 결합, static binding
    // 컴파일 시간에 결정
    // 예시) 오버로딩

    // 동적 결합, dynamic binding
    // 런타임에 결정
    // 예시) 오버라이딩
    
    B b0, b1;
    b0.num = 10;
    b1.num = 20;

    A& a0 = b0;
    A& a1 = b1;

    // 실제로는 a0, a1 둘 다 B class이지만 자료형이 A이기 때문에 A+A로 바인딩 된다. 오버로딩은 정적 결합
    // 실제 a0, a1이 가리키는 타입은 런타임에 알 수 있다.
    A a2 = a0 + a1; 
    cout << a2.num << endl; // 30

    Animal* animal = new Dog;
    foo(animal);


    class A { int a; };
    class B { int a; virtual ~B() {} };

    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl; // virtual 함수가 한 개라도 있으면 사이즈가 늘어난다. 가상함수 테이블을 가리키는 포인터 추가
    // 부모 자식 관계를 이용해 다형성을 이용하는 경우(Parent *p = new Child)
    // virtual 함수들은 가상 함수 테이블에 등록되고 실행 시 포인터 타입을 보고 함수를 실행하지 않고
    // 가상 함수 테이블에 있는 함수를 실행한다.
}