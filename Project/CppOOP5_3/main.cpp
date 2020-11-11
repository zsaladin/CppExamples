#include <iostream>
#include <memory>


using std::cout;
using std::endl;


class RAII
{
public:
    int* i;
    RAII()
    {
        i = new int;
    }
    ~RAII()
    {
        cout << "~RAII" << endl;
        delete i;
    }
};

class Test
{
public:
    ~Test() { cout << "~Test" << endl; }
};

void func()
{
    throw "exception";
}

int main()
{
    try
    {
        int* i = new int; // *i 는 메모리 leak 발생
        func();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }

    try
    {
        RAII raii;
        func();
    } // 블럭을 벗어나면서 RAII의 소멸자가 호출되면서 내부에 할당한 동적 객체가 해제된다
    catch (const char* e)
    {
        cout << e << endl;
    }


    try
    {
        // unique_ptr을 이용해 동적할당에 대한 RAII를 사용할 수 있다
        std::unique_ptr<Test> test(new Test());
        func();
    }
    catch (const char* e)
    {
        cout << e << endl;
    }
}