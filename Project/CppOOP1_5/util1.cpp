#pragma once

#include "person.h" // 중복 정의 실수 방지를 위해 header 파일을 만들어서 include 한다


void foo1()
{
    Person p(50.f, 171.f, "david");
    p.print();
}