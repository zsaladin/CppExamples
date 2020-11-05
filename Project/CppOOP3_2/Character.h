#pragma once

#include <iostream>

class Character
{
private:
    int _health;
    int _power;

public:
    Character(int headth, int power)
        : _health(headth), _power(power)
    {

    }

    virtual ~Character() // virtual이 없다면 자식 소멸자를 호출하지 않을 수 있다
    {
        std::cout << "~Character" << std::endl;
    }

    virtual void damaged(int power)
    {
        _health -= power;
    }

    void attack(Character& target) const
    {
        target.damaged(_power);
    }
};


class Player : public Character
{
public:
    using Character::Character;
    virtual void damaged(int power) override
    {
        Character::damaged(power);
        std::cout << "으악" << std::endl;
    }

    virtual ~Player()
    {
        std::cout << "~Player" << std::endl;
    }
};

class Monster : public Character
{
public:
    using Character::Character;
    virtual void damaged(int power) override
    {
        Character::damaged(power);
        std::cout << "꿰엑" << std::endl;
    }
};
