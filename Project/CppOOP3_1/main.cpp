#include <iostream>

using namespace std;

class Base
{
public:
    Base()
    {
        cout << "Base" << endl;
    }

    Base(int num) : num(num)
    {
        cout << "Base(" << num << ")" << endl;
    }

    virtual ~Base() // 부모 클래스가 될 가능성이 있는 녀석들의 소멸자는 virtual을 추가해준다
    {
        cout << "~Base" << endl;
    }

    int num;

    void func()
    {
        cout << num << endl;
    }

private:
    int priNum;

protected:
    int proNum;
};


class Derived : public Base
{
public:
    // 생성자를 상속하고 싶은 경우 using을 이용한다.
    //using Base::Base;

    Derived() // 부모 생성자를 지정하지 않으면 부모의 디폴트 생성자를 실행해준다.
    {
        cout << "Derived" << endl;
    }

    Derived(int num) : Base(num) // 자식 생성자에서 어떤 부모 생성자를 호출할지 결정해준다
    {
        cout << "Derived(" << num << ")" << endl;
    }

    ~Derived()
    {
        cout << "~Derieved" << endl;
    }

    void foo()
    {
        // 부모의 멤버에 접근
        func();
        this->func();

        num += 20;
        func();

        //this->priNum = 20; private 으로 부모에서 선언 됐기 때문에 접근 불가, 메모리에는 존재
        this->proNum = 30; // protected는 자식에게 공개 됨
    }

    void func1()
    {

    }
};


void func(Base& b)
{

}


int main()
{
    Base b;
    b.num = 10;
    b.func();

    Derived d; // 부모의 생성자가 먼저 호출 된다. 
    d.num = 20;  // 부모의 num
    d.func(); // 부모의 func
    d.foo();

    //d.priNum = 20; // private으로 부모에서 선언 되어서 사용할 수 없다
    //d.proNum = 30; // protected로 부모에서 선언 되어서 사용할 수 없다

    // 부모 클래스는 자식 클래스를 가리킬 수 있다
    Base* base = new Derived;

    // 자식 파괴자가 먼저 호출된다.
    delete base;

    // 부모가 자식을 가리킬 수 있기 때문에 부모 클래스를 타입으로 가지는 파라메터에 자식 객체를 넘겨줄 수 있다
    func(d);

    

}