#pragma once

#include "vectori.h"


class VectorF
{
private:
    float x;
    float y;
    float z;
    

public:
    VectorF(float x, float y, float z)
        : x(x), y(y), z(z)
    {

    }


    VectorF operator+(const VectorI v) const
    {
        return VectorF{ x + v.x , y + v.y, z + v.z };
    }
};
