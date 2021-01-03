#include <iostream>
#include <typeinfo>


using std::cout;
using std::endl;

class Parent
{
public:
    virtual ~Parent() {}
};

class Child : public Parent
{

};


int main()
{
    Parent* p = new Child;

    // 런타임 형식 정보 사용(RTTI) 하지 않는 경우 아래의 코드가 실행이 되지 않는다
    // 런타임에 실제 타입을 알아야하는 경우
    cout << typeid(*p).name() << endl; // p의 타입은 런타임에 알 수 있다
    dynamic_cast<Child*>(p); // p의 캐스팅 여부는 런타임에 알 수 있다.(다운 캐스팅)

    // RTTI 는 가상함수 테이블에 정보가 있다.
    // typeid, dynamic_cast 는 virtual 함수가 없는 경우 제대로 동작하지 않을 수 있다.
}