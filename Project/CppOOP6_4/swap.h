#pragma once


template<typename T>
void swap(T& x, T& y);



// 명시적 구체화
// 선언, 정의를 header, cpp 분리하는 경우 매 타입마다 명시적 구체화를 해야한다
// 매 사용하려는 타입마다 헤더파일에 명시하기 어려우니 템플릿은 선언/정의의 분리를 하지 않고 정의를 전부 헤더에 둔다
template
void swap<int>(int&, int&);
