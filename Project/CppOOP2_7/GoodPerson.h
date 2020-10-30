#pragma once
#pragma warning(disable: 4996)
#include <iostream>


class GoodPerson
{
private:
    float _weight;
    float _height;
    char* _name;

public:
    GoodPerson() {}
    GoodPerson(float weight, float height, const char* name)
        : _weight(weight), _height(height), _name(new char[strlen(name) + 1])
    {
        strcpy(_name, name);
    }

    GoodPerson(const GoodPerson& person)
        : GoodPerson(person._weight, person._height, person._name)
    {

    }

    ~GoodPerson()
    {
        delete[] _name; // 복사된 녀석들이 중복 삭제 된다.
    }

    GoodPerson& operator=(const GoodPerson& person)
    {
        _weight = person._weight;
        _height = person._height;
        delete[] _name;

        _name = new char[strlen(person._name) + 1];
        strcpy(_name, person._name);
        return *this;
    }

    void print() const
    {
        using namespace std;
        cout << _name << endl;
        cout << _weight << endl;
        cout << _height << endl;
    }
};
