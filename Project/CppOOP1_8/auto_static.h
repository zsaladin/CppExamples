#pragma once
#include <iostream>


void autoStatic()
{
    using namespace std;

    for (int i = 0; i < 10; ++i)
    {
        int autoVar = 0; // 매번 할당
        autoVar++;
        cout << "auto : " << autoVar << endl;

        static int staticVar = 0; // 한 번 할당
        staticVar++;
        cout << "static : " << staticVar << endl;
    }
}
