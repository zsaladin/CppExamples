#pragma once

#include <vector>

//#include "person.h" // 헤더 파일 include는 최소화 하자


class Person; // 전반 선언
class Villiage
{
private:
    // 전방 선언을 위해서는 포인터나 레퍼런스 형이어야 함.
    // 포인터나 레퍼런스는 사이즈가 알려져있기 떄문
    std::vector<Person*> persons;
public:
    void add(Person* person);
};

