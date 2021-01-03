#pragma once
#include <iostream>

class Foo
{

};

template <typename T>
void swap(T& x, T& y)
{
    std::cout << "swap" << std::endl;
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
void swap(T* x, T* y) // 포인터에 대한 특수화
{
    std::cout << "swap pointer" << std::endl;
    T temp = *x;
    *x = *y;
    *y = temp;
}

template <>
void swap<Foo>(Foo& x, Foo& y) // 명시적 특수화, swap 뒤의 <> 를 지우면 암시적 특수화
{
    std::cout << "swap<Foo>" << std::endl;
}

