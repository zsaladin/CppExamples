#include <iostream>

using namespace std;

enum Color
{
    // 값을 지정해주지 않으면 첫 번쨰는 0이 되고 이후로 1씩 증가
    Red, Green, Blue, SIZE
};

struct ColorStruct
{
    int red;
    int green;
    int blue;
};

enum TextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum CircleAttribute
{
    //Bold = 1 // Unscoped Enum 의 경우 TextAttribute::Bold 와 이름이 겹쳐서 사용할 수 없다.
};


enum struct ScopedTextAttribute
{
    Bold = 1,
    Underline = 2,
    Italic = 4,
    Strikethrough = 8
};

enum class ScopedCircleAttribute
{
    Bold = 1 // ScopedEnum은 이름이 겹쳐도 가능
};

enum Overflow
{
    Value0 = 100000000000
};

enum NotOverflow : uint64_t
{
    Value1 = 100000000000
};

int main()
{
    {
        // 주석으로 RGB Index를 표현
        // 0 : Red, 1 : Green, 2 :Blue
        int colors[3] = { 255, 128, 64 };

        cout << "Red : " << colors[0] << endl;
        cout << "Green : " << colors[1] << endl;
        cout << "Blue : " << colors[2] << endl;

        // 상수로 RGB Index를 표현
        const int red = 0;
        const int green = 1;
        const int blue = 2;

        cout << "Red : " << colors[red] << endl;
        cout << "Green : " << colors[green] << endl;
        cout << "Blue : " << colors[blue] << endl;

        // Unscoped enum 을 이용하여 RGB Index를 표현
        cout << "Red : " << colors[Red] << endl;
        cout << "Green : " << colors[Green] << endl;
        cout << "Blue : " << colors[Blue] << endl;
    }

    {
        int colors[SIZE] = { 255, 128, 64 };
        // Unscoped enum 을 이용하여 RGB 값의 평균
        int total = 0;
        for (int i = 0; i < SIZE; ++i)
        {
            total += colors[i];
        }

        int avg0 = total / SIZE;
        cout << avg0 << endl;

        // Struct를 이용하여 RGB 값의 평균
        ColorStruct cs = { 255, 128, 64 };
        int avg1 = (cs.red + cs.green + cs.blue);
        cout << avg1 << endl;
    }
    {
        // BitFlag 사용
        int textAttrs = 0;
        textAttrs |= Bold;
        textAttrs |= Underline;

        cout << textAttrs << endl;
        if (textAttrs & Underline)
            cout << "Underline" << endl;
    }
    {
        Bold;
        TextAttribute::Bold; // 범위 지정해서 사용 가능
        ScopedTextAttribute::Bold; // 범위 지정을 반드시 해야 한다.

        cout << Bold << endl;
        cout << TextAttribute::Bold << endl;
        cout << (int)ScopedTextAttribute::Bold << endl; // 강타입, 암시적으로 정수형으로 변환되지 않는다
        // Unscoped enumeration 보다 Scoped enumeration 사용이 권장 된다
    }
    {
        cout << Overflow::Value0 << endl;
        cout << NotOverflow::Value1 << endl;
    }
    {
        Color color = Color::Red; // 변수로 사용
        if (color == Color::Red) // 비교문
        {
            cout << "Red" << endl;
        }
    }
    {
        Color color = (Color)0; // 정수를 enum으로 변환
        if (color == Color::Red) 
        {
            cout << "Red" << endl;
        }
    }
}
