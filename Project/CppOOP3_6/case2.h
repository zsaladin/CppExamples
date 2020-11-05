#pragma once

#include <iostream>


namespace case2
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

    class BaseA : public Base
    {
    public:
        BaseA() : Base(10)
        {
            std::cout << "BaseA" << std::endl;
        }
    };

    class BaseB : public Base
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
        {
            std::cout << "Derived" << std::endl;
        }
    };
}
