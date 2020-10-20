#pragma once
#include <iostream>

using namespace std;

class Player
{
private:
    int _num;

public:
    Player(int num) : _num(num)
    {
        cout << "Constroctor : " << _num << endl;
    }

    ~Player() // 파괴자(소멸자), 항상 파라메터가 없음, 명시하지 않아도 컴파일러가 만들어줌
    {
        cout << "Destructor : " << _num << endl;
    }
};

Player player0(0);
Player* player1 = new Player(1); // player1은 해제 되지만 *player1은 해제가 되지 않음


void func()
{
    static Player player2(2);
}


void player()
{
    // 생성과 삭제를 확인해보자
    Player player3(3);
    Player* player4 = new Player(4);
    {
        Player player5(5);
        Player* player6 = new Player(6); // delete를 수동으로 안 해줬기 떄문에 해제 되지 않는다. *player6은 해제되지 않음
    }
    delete player4;
    func();
    func(); // static은 한 번만 생성 되기 때문에 두 번째 호출 시에도 생성되지 않는다
}
