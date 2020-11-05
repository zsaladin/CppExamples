#pragma once

#include <iostream>


namespace case3
{
    class Base
    {
    public:
        int m = 10;
        Base(int m) : m(m)
        {
            std::cout << "Base(" << m << ")" << std::endl;
        }
    };

    class BaseA : virtual public Base // virtual을 써서 Base를 한 개만 만든다
    {
    public:
        BaseA() : Base(10)
        {
            std::cout << "BaseA" << std::endl;
        }
    };

    class BaseB : virtual public Base // virtual을 써서 Base를 한 개만 만든다
    {
    public:
        BaseB() : Base(20)
        {
            std::cout << "BaseB" << std::endl;
        }
    };


    class Derived : public BaseA, public BaseB
    {
    public:
        Derived()
            : Base(30) // Base를 virtual 상속을 한다면 Base의 어떤 생성자를 호출할지 지정해줘야 한다
        {
            std::cout << "Derived" << std::endl;
        }
    };
}
