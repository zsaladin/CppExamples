#include <iostream>

using namespace std;


class Person
{
private:
    const string _name = "david"; // const 멤버 변수는 인라인으로 초기화 가능
    float _weight;
    float _height;

public:
    Person(const string& name, float weight, float height)
        : _name(name), _weight(weight), _height(height) // const 멤버 변수는 멤버 초기화 리스트에서 초기화 가능
    {

    }

    float getWeight(/* const Person* this */) const
    {

        // const가 붙은 멤버 함수에서의 this 포인터의 타입
        // const Person*

        return _weight;
    }

    float getHeight(/* Person* this */)
    {
        // this 포인터의 타입
        // Person*

        return _height;
    }
};
int main()
{
    const Person person("David", 75.f, 181.f);
    cout << person.getWeight() << endl; // getWeight에 const Person*가 넘어간다.
    //cout << person.getHeight() << endl; // getHeight에 const Person*을 넘길 수 없다.


    Person *person0 = new Person("Daniel", 57.f, 175.f);
    const Person* person1 = person0; // 변환 가능
    //Person* person2 = person1; // 변환 불가능
}