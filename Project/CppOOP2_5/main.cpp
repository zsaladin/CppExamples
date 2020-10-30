#include <iostream>
#include <string>

using namespace std;


class Vector
{
private:
    int x;
    int y;
    int z;

public:
    Vector()
    {

    }

    Vector(int x, int y, int z)
        :x(x), y(y), z(z)
    {

    }

    friend ostream& operator<<(ostream& os, const Vector& v)
    {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }

    friend istream& operator>>(istream& is, Vector& v)
    {
        string temp;
        is >> temp;
        v.x = stoi(temp);

        is >> temp;
        v.y = stoi(temp);

        is >> temp;
        v.z = stoi(temp);

        return is;
    }

    Vector operator~() const
    {
        return Vector(~x, ~y, ~z);
    }

    Vector operator&(const Vector& v) const
    {
        return Vector(x & v.x, y & v.y, z & v.z);
    }

    Vector operator|(const Vector& v) const
    {
        return Vector(x | v.x, y | v.y, z | v.z);
    }

    Vector operator^(const Vector& v) const
    {
        return Vector(x ^ v.x, y ^ v.y, z & v.z);
    }

    Vector operator<<(int v) const
    {
        return Vector(x << v, y << v, z << v);
    }

    Vector operator>>(int v) const
    {
        return Vector(x >> v, y >> v, z >> v);
    }
};


int main()
{
    Vector v{ 1, 2, 3 };
    cout << v << endl; // operator<<(cout, v);
    operator<<(cout, v).operator<<(endl);

    cin >> v; // operator>>(cin, v)
    cout << v << endl;


    Vector v0{ 0, 0, 0 };
    cout << ~v0 << endl;

    Vector v1{ 1, 2, 3 };
    cout << (v0 & v1) << endl;
    cout << (v0 | v1) << endl;
    cout << (v1 ^ v1) << endl;

    Vector v2{ 2, 4, 8 };
    cout << (v2 << 2) << endl;
    cout << (v2 >> 2) << endl;
}