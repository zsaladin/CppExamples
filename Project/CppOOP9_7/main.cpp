#include <iostream>
#include <memory>


struct Test
{
    int num;

    Test(int num) : num(num)
    {
        std::cout << "Construct : " << num << std::endl;
    }

    ~Test()
    {
        std::cout << "Destruct : " << num << std::endl;
    }
};

void foo0(std::unique_ptr<Test> p)
{

}

void foo1(const std::unique_ptr<Test>& p)
{

}

void foo2(Test* p)
{

}

struct B;
struct A
{
    A() { std::cout << "Construct A" << std::endl; }
    ~A() { std::cout << "Destruct A" << std::endl; }
    std::shared_ptr<B> b;
};

struct B
{
    B() { std::cout << "Construct B" << std::endl; }
    ~B() { std::cout << "Destruct B" << std::endl; }
 
    //std::shared_ptr<A> a; // 상호 참조 시 문제 발생
    std::weak_ptr<A> a; // 상호 참조 시 weak ptr 를 사용해야 해제가 된다.
};

struct Deleter
{
    void operator()(Test* test) const
    {
        std::cout << "custom delete : " << test->num << std::endl;
        delete test;
    } 
};
int main()
{
    {
        // Raw Pointer 
        int* num0 = new int(10);
        int* num1 = num0;

        delete num0;
        //delete num1; // 사용하기 어려움
    }


    // 스마트 포인터 종류
    // unique_ptr, shared_ptr, weak_ptr

    {
        // unique_ptr - 독점 소유

        std::unique_ptr<Test> p0(new Test(1)); // 자동 지역 변수 p가 삭제 될 떄 Test를 해제해준다
        auto p1 = std::make_unique<Test>(2);  // 예외 상황의 경우 make_unique가 유리하니 make_unique를 사용하자, C++14

        //std::unique_ptr<Test> p2 = p0;  // 안 됨, 독점 소유권
        std::unique_ptr<Test> p2 = std::move(p0);  // 소유권의 이동, p0은 비워짐

        foo0(std::move(p2)); // 소유권을 넘겨줌
        foo1(p1); // 참조로 받음
        foo2(p1.get()); // raw pointer로 받음

        Test* test = p1.release();  // 소유권 포기
        delete test;


        std::unique_ptr<Test, Deleter> p3(new Test(0)); // custom deleter 
    }

    {
        // shared_ptr - 공동 소유
        std::shared_ptr<Test> s0(new Test(0));  // 공동 소유, 레퍼런스 카운트를 이용하여 해제 시점 결정
        std::shared_ptr<Test> s1 = s0;

        std::cout << s0.use_count() << std::endl; // 2, s0, s1이 소유하고 있으므로
        std::cout << s1.use_count() << std::endl; // 2

    }
    {
        // weak_ptr

        // 상호 참조
        auto a = std::make_shared<A>();
        auto b = std::make_shared<B>();
        a->b = b;
        b->a = a;  // 멤버 변수 a를 weok_ptr로 사용하여 참조 카운팅을 증가시키지 않아 상호 참조 해결

        auto p = std::make_shared<Test>(0);
        std::weak_ptr<Test> w = p;

        std::cout << p.use_count() << std::endl; // 1
        auto shared = w.lock();
        std::cout << p.use_count() << std::endl; // 2

        if (shared) // p가 먼저 삭제됐다면 if 문을 통과할 수 없다
        {
            std::cout << shared->num << std::endl;
        }
    }
}