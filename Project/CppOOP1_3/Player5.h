#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player5
{
private:
    // 인라인 초기화
    int _health = 100;
    int _power = 50;
    const string _name = "noname";

public:
    Player5() = default; // 컴파일러가 만든 생성자를 사용하겠다는 것을 명시
    //Player5() = delete; // 컴파일러가 생성자를 암시적으로 만들지 말 것을 명시
    Player5(int health, int power, string name)
        : _health(health), _power(power), _name(name)
    {

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _name << endl;
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player5()
{
    Player5 player;
    player.print();
}

