#pragma once

#include <iostream>

class Animal
{
public:
    virtual void eat() const
    {
        std::cout << "³È" << std::endl;
    }

    void walk() const
    {
        std::cout << "¶Ñ¹÷" << std::endl;
    }
};


class Cat : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "³É" << std::endl;
    }

    void walk() const
    {
        std::cout << "»ç»Ó" << std::endl;
    }
};

class Dog : public Animal
{
public:
    virtual void eat() const override
    {
        std::cout << "ÅÍ¹÷" << std::endl;
    }

    void walk() const
    {
        std::cout << "¶Ñ¹÷" << std::endl;
    }
};
