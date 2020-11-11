#include <iostream>

using std::cout;
using std::endl;


class Parent
{
public:
    virtual ~Parent() {}
};


class Child : public Parent
{
public:
    void func()
    {
        cout << "func" << endl;
    }
};


void func0(Parent* p)
{
    // 상속 관계에 대한 변환 지원, virtual 함수가 한 개라도 있어야 dynamic_cast가 사용 가능
    // p가 실제로 Parent이면 정의되지 않은 행동
    //Child* child = dynamic_cast<Child*>(p); 
    //child->func();

    Child* child = dynamic_cast<Child*>(p);  // downcasting
    if (child != nullptr)
    {
        child->func();
    }

    // if 내 선언 활용
    if (Child* child = dynamic_cast<Child*>(p)) // downcasting
        child->func();
}


void func1(Parent* p)
{
    // p가 Child가 아닌 경우 예외가 발생, 추후 try catch 활용
    Child& child = dynamic_cast<Child&>(*p); //downcasting
    child.func(); 
}

int main()
{
    Parent* p = new Parent;
    func0(p);
    func1(p);

    // upcasting, 자식으로 부모로 변환 (암시적)
    // downcasting, 부모를 자식으로 변환 (명시적, 위험할 수 있음)
}