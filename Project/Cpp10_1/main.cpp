#include <iostream>
#include <string>

#define SQUARE(X) X*X

using namespace std;


int sum(int, int);
int main(int argc, char* argv[])
{
    SQUARE(1);

    int total = 0;
    for (int i = 0; i < argc; ++i)
    {
        string arg(argv[i]);
        int num = stoi(arg);
        total = sum(total, num);
    }
    cout << total << endl;
}


// 1. 시작
// 2. Developer 입력
// 3. Developer Command Prompt for VS 2019 선택
// 4. cd 를 이용하여 main.cpp 파일의 경로로 이동


// 컴파일 후 실행
// 1. cl main.cpp util.cpp
// 2. main.exe 10 20 30
// 3. del *.obj
// 4. del main.exe


// 1. cl main.cpp
// 안 됨, sum 함수를 찾을 수 없음, obj 파일은 생성 됨

// 1. cl util.cpp
// 안 됨, main 함수를 찾을 수 없음, obj 파일은 생성 됨


// 1. cl main.cpp util.cpp /c
// main.obj, util.obj 파일이 생성 되어있음. /c는 컴파일만 하겠다는 의미
// 2. link main.obj util.obj
// main.exe 생성

// obj가 생성되었다는 것은 컴파일이 되었다는 것을 의미
// 컴파일 후 링킹 과정이 있는데 main.cpp, util.cpp를 각각 별도로 컴파일 하면 링킹에서 실패

// 1. link main.obj 
// sum 함수를 찾을 수 없음



// 1. cl main.cpp /P
// main.i 생성, 전처리만 함
// iostream 파일들이 main.cpp 에 붙여넣은 결과가 생성
// SQUARE와 같이 전처리 매크로도 대체가 됨
