#pragma once
#pragma warning(disable: 4996)
#include <iostream>


class BadPerson
{
private:
    float _weight;
    float _height;
    char* _name;

public:
    BadPerson() {}
    BadPerson(float weight, float height, const char* name)
        : _weight(weight), _height(height), _name(new char[strlen(name) + 1])
    {
        strcpy(_name, name);
    }

    ~BadPerson()
    {
        delete[] _name; // 복사된 녀석들이 중복 삭제 된다. 주소값만 복사 됐기 때문
    }

    void print() const
    {
        using namespace std;
        cout << _name << endl;
        cout << _weight << endl;
        cout << _height << endl;
    }
};
