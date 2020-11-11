#include <iostream>

using namespace std;


class ClassA {};
class ClassB {};

enum class TypeA
{
    A, B, C
};


enum class TypeB
{
    A, B, C
};


class Test
{
public:
    Test(int num) {}
    explicit Test(int num0, int num1) {}

    operator bool() const
    {
        return true;
    }

    explicit operator double() const
    {
        return 1.2;
    }
};


class Parent {};
class Child : public Parent {};


int main()
{
    // static_cast
    // 컴파일 타임 변환
    // 컴파일 타임에 호환 되지 않는 변환은 에러를 냄

    float f = 1.1f;
    int* i0 = (int*)&f; // 일반 C 스타일 캐스트는 된다
    //int* i1 = static_cast<int*>(&f); // 안 된다.

    ClassA a;
    ClassB* b = (ClassB*)&a; // 일반 C 스타일 캐스트는 된다.
    //ClassB* b = static_cast<ClassB*>(&a);  // 안 된다. 컴파일 타임에 오류를 잡아준다

    TypeA type0 = static_cast<TypeA>(0); // enum과 정수형은 호환이 되기 때문에 static_cast가 된다
    TypeB type1 = static_cast<TypeB>(type0); // enum 끼리 변환이 가능

    Test t0 = static_cast<Test>(1); // 변환 생성자
    Test t1 = static_cast<Test>(1, 2); // 변환 생성자

    bool b0 = static_cast<bool>(t0);
    double d0 = static_cast<double>(t1);


    Child c;
    Parent& p0 = c;
    Child& c0 = static_cast<Child&>(p0); // Downcasting -> 부모를 자식으로 변환
    // 그렇지만 부모를 자식으로 캐스팅하는 것은 위험할 수 있음

    Parent p1;
    Child& c1 = static_cast<Child&>(p1); // 이 경우는 정의되지 않은 동작, Pointer를 통해 dynamic_cast 활용


}