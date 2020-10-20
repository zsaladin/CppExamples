#pragma once
#include <iostream>

using namespace std;


class Person
{
private:
    float weight;
    float height;
    string name;

public:
    Person(float weight, float height, const string& NAME)
        : weight(weight), height(height), name(NAME)
    {
        // 이름이 같은 경우 this로 구분 가능
        weight; // 파라메터 weight
        this->weight; // 멤버 변수 weight


        // 이름이 같지 않기 때문에 this 생략 가능
        name; // 멤버 변수 name 
        this->name; // 멤버 변수 name
    }

    void loseWeight(float weight)
    {
        // 아래의 둘은 같다
        this->height;
        height;

        this->height -= weight;
        if (this->weight < 0)
            this->weight = 0;
    }

    float getBMI()
    {
        return weight / (height * 100 * height * 100);
    }


    Person& complete(Person& person)
    {
        if (this->getBMI() < person.getBMI())
            return *this; // this의 반환
        else
            return person;
    }


    void doCeremony()
    {
        cout << name << " win!!" << endl;
    }
};


void personFunc()
{
    Person david(67.3f, 172.3f, "david");
    Person daniel(58.3f, 167.3f, "daniel");

    daniel.complete(david).doCeremony();
}
