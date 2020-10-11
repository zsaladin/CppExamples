#include <iostream>

using namespace std;


void swap0(int& px, int& py)
{
    int temp = px;
    px = py;
    py = temp;
}


struct Weapon
{
    int price;
    int power;
};


void upgrade(Weapon& weapon)
{
    weapon.power += 10;
    weapon.price += 10;
}

void print(const Weapon& weapon) // const로 인해 내부에서 변경 되지 않는다
{
    cout << weapon.power << endl;
    cout << weapon.price << endl;
}

int squarev(int value)
{
    return value * value;
}

int squaref(const int& ref)
{
    return ref * ref;
}


int& func0()
{
    int num = 0;
    return num; // 위험하다. num은 삭제 됨
}


int& func1(Weapon& weapon)
{
    return weapon.power;
}

int main()
{
    {
        int x = 10, y = 20;
        swap0(x, y);

        cout << x << endl;
        cout << y << endl;
    }

    {
        int x = 10, y = 20;
        // swap0(x, y); 풀어쓰기

        int& px = x;
        int& py = y;

        int temp = px;
        px = y;
        py = temp;

        cout << x << endl;
        cout << y << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        upgrade(weapon);
        print(weapon);
    }
    {
        int num;
        cin >> num; // num을 레퍼런스로 넘겨주기 때문에 scanf처럼 num의 주소로 넘겨주지 않아도 된다
    }
    {
        int nums[] = { 1, 2, 3, 4 };
        for (int num : nums)
        {
            num = 0; // nums의 값이 안 바뀐다
        }

        for (int& num : nums)
        {
            num = 0; // nums의 값이 바뀐다
        }

        for (const int& num : nums)
        {
            // num = 0; // nums의 값을 바꿀 수 없다. 레퍼런스로 넘겼기 때문에 성능에 유리하다
        }
    }
    {
        int x = 10;
        cout << squarev(10.1) << endl;

        // 상수 참조는 호환이 되는 타입은 임시 객체를 생성해서 가리키게 한다.
        // 이 경우 10.1은 double 형이고 squaref의 ref는 const int& 이기 때문에
        // 10 임시 객체가 만들어진다.
        // 상수 참조 타입은 최대한 일반 값 타입과 호환이 되도록 하고 싶은 의도
        cout << squaref(10.1) << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        func1(weapon) = 30; // 이런 것도 된다
    }
}