#pragma warning(disable: 4996)
#include <iostream>

using namespace std;

void swap0(int *px, int *py)
{
    int temp = *px;
    *px = *py;
    *py = temp;
}

void scan(int* n)
{
    *n = 10;
}

struct Weapon
{
    int price;
    int power;
};

void upgrade(Weapon* pWeapon)
{
    (*pWeapon).price += 10;
    pWeapon->power += 10;
}


void print(const Weapon *weapon)
{
    cout << weapon->price << endl;
    cout << weapon->power << endl;
}

void func0(int nums[4]) // 실제로 포인터이다. 배열이 아님
{
    cout << typeid(nums).name() << endl;

    for (int i = 0; i < 4; ++i)
    {
        int num = nums[i];
        cout << num << endl;
    }
}

void func1(int argc, char** argv)
{

}

void func2(int argc, char(*argv)[5])
{

}

int main(int argc, char* argv[])
{
    {
        // 포인터 복습
        int x = 10;
        int* px = &x;

        cout << x << endl;
        cout << *px << endl;

        x = 20;
        cout << x << endl;
        cout << *px << endl;

        *px = 30;
        cout << x << endl;
        cout << *px << endl;
    }
    {
        int x = 10, y = 20;
        cout << x << endl;
        cout << y << endl;

        // 포인터로 하니 변환된다
        swap0(&x, &y);

        cout << x << endl;
        cout << y << endl;
    }
    {
        int x = 10, y = 20;
        cout << x << endl;
        cout << y << endl;

        //swap0(&x, &y); 풀어 쓰기
        // 주소 값이 복사 된다
        int* px = &x;
        int* py = &y;

        int temp = *px;
        *px = *py;
        *py = temp;

        cout << x << endl;
        cout << y << endl;
    }
    {
        int i;
        scanf("%d", &i);  // 주소값으로 넘겨줬던 이유, i를 함수 내부에서 변경하기 위해
    }
    {
        int n = 0;
        scan(&n);
        cout << n << endl; // 변경된다. 값으로 넘기면 변경 안 됨
    }
    {
        Weapon weapon{ 10, 20 };
        upgrade(&weapon);

        cout << weapon.price << endl;
        cout << weapon.power << endl;
    }
    {
        Weapon weapon{ 10, 20 };
        // 내부적으로 const 포인터로 받았기 때문에
        // 호출하는 입장에서는 바뀌지 않았을 거라고 생각할 수 있다.
        print(&weapon);
    }
    {
        int nums[4] = { 1, 2, 3, 4 };
        func0(nums);
    }
    {
        // 실제로 argv는 char** 이다. 배열이 아니다
        cout << typeid(argv).name() << endl; 
    }
    {
        func1(argc, argv);

        char strs[][5] = { "abcd", "efgh" };
        //func1(2, strs);
        func2(2, strs);
    }
}

// 메모리 모양
// char**
// |주소|주소|주소|주소|
//   |
//   -> "cpp9_4.ext"

// chat[2][5]
// |"abcd\0"|"efgh\0"|