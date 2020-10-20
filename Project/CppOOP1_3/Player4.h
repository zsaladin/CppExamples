#pragma once
#include <iostream>
#include <string>

using namespace std;


class Player4
{
private:
    int _health;
    int _power;
    const string _name;

public:
    Player4() : Player4(100, 50, "noname") 
    {
    }
    Player4(int health, int power, string name)
        : _health(health), _power(power), _name(name) // 멤버 초기화 리스트, 초기화 순서는 클래스에 선언된 순서
    {
        // 아래는 대입 연산들, 즉, 멤버 변수들은 초기화 (기본 생성자가 이미 호출 된 상태) 
        //_health = health;
        //_power = power;
        //_name = name; 상수가 이미 초기화가 되어 있어서 안 됨

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _name << endl;
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player4()
{
    Player4 player;
    player.print();
}

