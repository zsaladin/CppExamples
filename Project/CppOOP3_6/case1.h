#pragma once

#include <iostream>


namespace case1
{
    class BaseA
    {
    public:
        int m = 0;
        void foo()
        {
            std::cout << "BaseA" << std::endl;
        }
    };

    class BaseB
    {
    public:
        int m = 0;
        void foo()
        {
            std::cout << "BaseB" << std::endl;
        }
    };


    class Derived : public BaseA, public BaseB 
    {
    };
}
