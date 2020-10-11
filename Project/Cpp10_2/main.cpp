#include <iostream>

using namespace std;


int x = 10;
int getX();

static int y = 10;
int getY();


enum struct RequestType
{
    Login, Register, Update, Delete
};


namespace CompanyA
{
    int num;
}

namespace CompanyB
{
    int num;
}

int main()
{
    {
        // Block scope 
        int a = 0;
        cout << a << endl;
        cout << &a << endl;
        cout << endl;
        {
            static int a = 10; // 블록에 a가 선언되어 상단에서 선언된 a가 가렸음
            cout << a << endl;
            cout << &a << endl;
            cout << endl;
        }

        cout << a << endl;
        cout << &a << endl;  // 최초로 선언 된 a, 블록 내부의 a가 static이기 때문에 해제가 된 것은 아님
        cout << endl;


        if (int num = 1)
        {
            cout << num << endl;
        }

        //num = 1;  접근할 수 없음

        if (int num = 0)
        {
            cout << num << endl;
        }
        else
        {
            cout << num << endl; // else에서는 접근할 수 있음
        }


        for (int i = 0; i < 10; ++i)
        {

        }
        // i = 1; // 접근할 수 없음
    }
    {
        // Global scope
        cout << getX() << endl;
        x = 20;
        cout << getX() << endl;
    }
    {
        // File scope
        cout << getY() << endl;
        y = 20;
        cout << getY() << endl; // 변하지 않음. 10 출력
    }
    {
        // Enumeration scope
        RequestType::Login;
        RequestType::Update;
        RequestType::Register;
        RequestType::Delete;
    }
    {
        // Namespace scope
        // 이름 중복을 피하기 위해 사용.
        // 예를 들어 전역 변수명의 중복을 피할 수 있다
        CompanyA::num;
        CompanyB::num;

        // using namespace 를 사용하여 해당 namespace를 가져올 수 있음
        // using std::cout, cout 만 현재 namespace로 가져옴 
    }

}