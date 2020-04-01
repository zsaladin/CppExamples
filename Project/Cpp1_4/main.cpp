// 해당 프로젝트 실행 시 솔루션 탐색기에서 해당 프로젝트에 우클릭을 한 후
// "시작 프로젝트로 설정" 선택

// 컴파일(Compile) 이전에 전처리(Preprocess) 과정 중 iostream에 있는 내용을 현재 파일에 복사 붙여넣기를 함
// iostream을 include 하는 이유는 std::cout 을 사용하기 위함
#include <iostream>

int main()
{
    // std::cout 이 "Hello World" 를 출력
    std::cout << "Hello World";
    
    // main() 함수의 반환값. Exit code
    // 해당 프로그램이 종료 될 때 이 프로그램을 실행한 부모 프로그램에게 알려주는 값
    // 0으로 종료 코드를 넘겨주게 되면 정상 종료라고 알려줌
    return 0;
}