#include <iostream>

using namespace std;

void swap0(int px, int py)
{
    // 주소 출력
    //cout << "px addr : " << &px << endl;
    //cout << "py addr : " << &py << endl;

    int temp = px;
    px = py;
    py = temp;
}

struct Weapon
{
    int price;
    int power;
};

void upgrade0(Weapon weapon)
{
    weapon.power += 10;
    weapon.price += 10;
}

Weapon upgrade1(Weapon weapon)
{
    weapon.power += 10;
    weapon.price += 10;
    return weapon;
}

int main()
{
    {
        // swap을 inline으로 수행
        int x = 10, y = 20;
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;

        int temp = x;
        x = y;
        y = temp;

        // 값이 바뀌지 않음
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }

    {
        int x = 10, y = 20;
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        swap0(x, y);// 값으로 전달했기 때문에 복사가 안 됨

        //cout << "x addr : " << &x << endl;
        //cout << "y addr : " << &y << endl;

        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
    {
        int x = 10, y = 20;
        cout << "x : " << x << endl;
        cout << "y : " << y << endl;

        // swap0 풀어쓰기
        int px = x;
        int py = y;

        int temp = px;
        px = py;
        py = temp;

        cout << "x : " << x << endl;
        cout << "y : " << y << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        upgrade0(weapon);

        // 실제로 업그레이드 되지 않음
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // upgrade(weapon); 풀어쓰기
        Weapon pWeapon = weapon;
        pWeapon.power += 10;
        pWeapon.price += 10;

        // 실제로 업그레이드 되지 않음
        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;

        // 값으로 전달하여 수정
        weapon = upgrade1(weapon);

        cout << "Price : " << weapon.price << endl;
        cout << "Power : " << weapon.power << endl;
    }
}