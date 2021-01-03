#include "swap.h"


template<typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}
