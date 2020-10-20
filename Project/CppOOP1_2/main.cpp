#include <iostream>

using namespace std;

class Player0
{
    int health;
    int power;
};

class Player1
{
public: // 접근 지정자
    int headlth;
    int power;
};


class Player2
{
public:
    int health;
private:
    int power;
};


class Player3
{
public:
    int _health;
    int _power;
    string _name;

public:
    void attack(Player3& target)
    {
        cout << "Attack " << _name << "->" << target._name << endl;
        target.damaged(_power);
    }

    void damaged(int power)
    {
        _health -= power;
        if (_health <= 0)
            cout << "Died" << _name << endl;
    }
};


class Player4
{
private:
    int _health;
    int _power;
    string _name;

public:
    Player4(int health, int power, string name)
    {
        _health = health;
        _power = power;
        _name = name;
    }

    void attack(Player4& target)
    {
        cout << "Attack " << _name << "->" << target._name << endl;
        target.damaged(_power);
    }

    void damaged(int power)
    {
        _health -= power;
        if (_health <= 0)
            cout << "Died" << _name << endl;
    }
};

int main()
{
    {
        // 기본적으로 private
        //Player0 player0{ 100, 200 }; // 안 됨

        //Player0 player0;
        //player0.health = 100; // 안 됨
    }
    {
        // public으로 만들어줘야 가능
        Player1 player1{ 100, 200 };
        player1.headlth = 200;
    }
    {
        Player2 player2;
        //player2.power = 300; // 안 됨, private
    }
    {
        Player3 david{ 200, 100, "David" };
        Player3 daniel{ 200, 100, "Daniel" };
        
        daniel._health -= 300;
        // daniel의 health가 0 이하가 됐음에도 죽었다는 메시지가 발생하지 않음
        // 멤버 변수를 노출하게 되면 이렇게 객체의 무결성이 깨지는 상태가 발생할 가능서잉 높아짐
    }
    {
        Player4 david{ 200, 100, "David" };
        Player4 daniel{ 200, 100, "Daniel" };
        
        //daniel._health -= 300; // 불가능하다
        david.attack(daniel);
        david.attack(daniel);
    }
}