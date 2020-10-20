#include <iostream>
#include <string>

using namespace std;


// Person의 중복 정의 가능, 그렇지만 똑같이 정의 해야함
//class Person
//{
//private:
//    float _weight;
//    float _height;
//    const string _name;
//
//public:
//    Person(float weight, float height, const string& name)
//        : _weight(_weight), _height(height), _name(name)
//    {
//
//    }
//
//    void print()
//    {
//        cout << _name << endl;
//    }
//};
//
//void foo0()
//{
//    Person p(50.f, 171.f, "daniel");
//    p.print();
//}