#pragma once
class Person
{
private:
    static int num0;
public:
    static int num1;
    static const int num2;

    Person();
    void print();
    static void staticPrint();
};

void personFunc();
