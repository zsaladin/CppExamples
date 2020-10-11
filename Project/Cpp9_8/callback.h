#pragma once

#include <iostream>

using namespace std;

enum struct RequestType
{
    Login, Register, Update, Delete
};

bool onLogin(string id, string password)
{
    cout << "onLogin" << endl;
    cout << id << endl;
    cout << password << endl;
    return true;
}

bool onRegister(string id, string password)
{
    cout << "onRegister" << endl;
    cout << id << endl;
    cout << password << endl;
    return true;
}
bool onUpdate(string id, string password)
{
    cout << "onUpdate" << endl;
    cout << id << endl;
    cout << password << endl;
    return true;
}
bool onDelete(string id, string password)
{
    cout << "onDelete" << endl;
    cout << id << endl;
    cout << password << endl;
    return true;
}


void callback()
{
    bool (*callbacks[])(string, string) {
        onLogin, onRegister, onUpdate, onDelete
    };

    callbacks[(int)RequestType::Login]("daoid", "1234");
    callbacks[(int)RequestType::Register]("daoid", "1234");
    callbacks[(int)RequestType::Update]("daoid", "1234");
    callbacks[(int)RequestType::Delete]("daoid", "1234");
}
