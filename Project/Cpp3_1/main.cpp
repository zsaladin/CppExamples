#pragma warning(disable: 4996)
#include <cstdio>

int main()
{
    {
        // signed int 10진수 출력
        printf("%d + %d = %i\n", 2, 3, 2 + 3);
    }
    {
        // unsigned int 10진수 출력
        printf("%u + %u = %u\n", 3, 2, 3 + 2);
    }
    {
        // unsigned int 10진수 출력 형식으로 음수 int 출력
        printf("%u\n", -1);
    }
    {
        // unsigned char 10진수 출력 형식으로 음수 int 출력
        printf("%hhu\n", -1);
    }
    {
        // char 출력
        char ch = 'b';
        printf("%c%c\n", 'a', ch);
    }
    {
        // 부동소수점 출력(%f, %lf 같음)
        printf("%f - %f = %lf\n", 2.0, 3.0f, -1.0f);
    }
    {
        // unsigned int 8, 16진수 출력
        printf("%o, %x, %X\n", 10, 10, 10);
    }
    {
        // unsigned char 16진수 출력
        printf("%hhx\n", 255);
    }
    {
        // unsigned char 16진수 출력(overflow)
        printf("%hhx\n", 256);
    }
    {
        // 앞에 0을 채워 총 10글자로 맞추기
        printf("%010d\n", 1);
        printf("%010d\n", -1);
        printf("%010f\n", 1.1);
        printf("%010f\n", -1.1);
    }
    {
        // 소수점 자리수 표현
        printf("%010.1f\n", 1.1);
        printf("%010.1f\n", -1.1);
    }
    {
        // 앞에 여백을 넣기
        printf("%10d\n", 1);
        printf("%10d\n", -1);
        printf("%10f\n", 1.1);
        printf("%10f\n", -1.1);
    }
    {
        // 뒤에 여백을 넣기
        printf("%-10d\n", 1);
        printf("%-10d\n", -1);
        printf("%-10f\n", 1.1);
        printf("%-10f\n", -1.1);
    }
    {
        // % 출력하기
        printf("%%\n");
    }
    {
        // stdout을 output.txt로 연결
        freopen("output.txt", "w", stdout);
        printf("Hello World!");
    }
}