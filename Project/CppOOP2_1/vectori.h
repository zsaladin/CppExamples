#pragma once

#include "vectorf.h"


class VectorI
{
    friend class VectorF;

private:
    int x;
    int y;
    int z;

public:
    VectorI(int x, int y, int z)
        : x(x), y(y), z(z)
    {

    }
};
