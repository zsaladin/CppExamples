#pragma once

#include <iostream>

using namespace std;

struct Character
{
    int health;
    void (*dieCallback)();
};


void damaged(Character& character)
{
    character.health -= 100;
    if (character.health <= 0)
    {
        cout << "died" << endl;
        if (character.dieCallback)
            character.dieCallback();
    }
}


void gameOver()
{
    cout << "gameOver" << endl;
}

void playCharacter()
{
    Character character0{ 200, nullptr };
    Character character1{ 200, gameOver };


    damaged(character0);
    damaged(character0);

    damaged(character1);
    damaged(character1);
}
