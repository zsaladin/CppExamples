#pragma once

#include <iostream>


class Vector
{
private:
    float x;
    float y;
    float z;

public:
    Vector(float x, float y, float z)
        : x(x), y(y), z(z)
    {

    }

    Vector operator+() const
    {
        return *this;
    }

    Vector operator-() const
    {
        return Vector{ -x, -y, -z };
    }

    Vector operator+(const Vector& v) const
    {
        return Vector{ x + v.x, y + v.y, z + v.z };
    }

    Vector operator-(const Vector& v) const
    {
        return Vector{ x - v.x, y - v.y, z - v.z };
    }

    float operator*(const Vector& v) const
    {
        return x * v.x + y * v.y + z - v.z;
    }

    Vector operator*(float v) const
    {
        return Vector{ x * v, y * v, z * v };
    }

    Vector operator/(float v) const
    {
        return Vector{ x / v, y / v, z / v };
    }

    Vector& operator++()
    {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    Vector& operator--()
    {
        --x;
        --y;
        --z;
        return *this;
    }

    Vector operator++(int)
    {
        Vector temp = *this;
        ++(*this);
        return temp;
    }

    Vector operator--(int)
    {
        Vector temp = *this;
        --(*this);
        return temp;
    }

    friend Vector operator*(float v0, const Vector& v1); // 해당 함수에서 멤버 변수에 접근하기 위함

    void print() const
    {
        std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
    }
};

Vector operator*(float v0, const Vector& v1)
{
    return Vector{ v0 * v1.x, v0 * v1.y, v0 * v1.z };
}

