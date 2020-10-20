#pragma once
#include <iostream>

using namespace std;


class Player2
{
private:
    int _health;
    int _power;

public:
    Player2()
    {
        // 중복 제거를 위해 Player2(int, int)를 호출한 듯 보이지만 실제로는 Player2를 한 번 더 생성
        Player2(100, 50); 
    }
    Player2(int health, int power)
    {
        _health = health;
        _power = power;

        cout << "Player " << _health << ", " << _power << endl;
    }

    void print()
    {
        cout << _health << endl;
        cout << _power << endl;
    }
};

void player2()
{
    Player2 player;
    player.print();
}
