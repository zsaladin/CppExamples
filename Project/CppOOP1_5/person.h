#pragma once

// #pragma once -> 헤더파일은 한 번만 include 하도록 함, 비표준
// #ifndef #define #endif -> 헤더파일을 한 번만 include 하도록 함, 표준
#include <iostream>
#include <string>


// Person 클래스의 선언 분리
class Person
{
private:
    float _weight;
    float _height;
    const std::string _name;

public:
    Person(float weight, float height, const std::string& name);
    void print();
};


// 함수의 선언
void foo();
