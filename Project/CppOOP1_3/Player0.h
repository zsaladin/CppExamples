#pragma once
#include <iostream>

using namespace std;


class Player0
{
private:
    int _health;
    int _power;

public:
    Player0()
    {
        // 디폴트 생성자(파라메터가 한 개도 없는 생성자)
        // 한 개의 생성자도 주어지지 않는다면 컴파일러가 암시적으로 만들어준다
        _health = 100;
        _power = 50;
        cout << "Player " << _health << ", " << _power << endl;
    }
    Player0(int health, int power)
    {
        _health = health;
        _power = power;

        cout << "Player " << _health << ", " << _power << endl;
    }
};

void player0()
{
    Player0 player0(100, 50);
    Player0 player1 = Player0(300, 150);
    Player0* player2 = new Player0(400, 250);


    Player0 player3;
    Player0 player4 = Player0();
    Player0* player5 = new Player0();
}
