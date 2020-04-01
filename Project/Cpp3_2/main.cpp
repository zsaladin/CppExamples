#pragma warning(disable: 4996)
#include <cstdio>

int main()
{
    {
        // 정수 입력
        int num = 0;
        scanf("%d", &num); // num 앞에 & 를 넣어줘야 한다.
        printf("%d\n", num);
    }
    {
        // 문자 입력
        int num;
        char ch;
        int n = scanf("%d %c", &num, &ch); // 성공적으로 입력 받은 변수의 개수를 반환한다.
        printf("%d\n", n);
    }
    {
        // num 제대로 입력 받은 경우만 출력을 해준다.
        int num;
        if (scanf("%d", &num)) // 제대로 입력 받은 경우 1이 반환되고 1은 true 형변환이 된다.
            printf("%d\n", num);
    }
    {
        int num0, num1, num2;
        scanf("%d + %d = %d", &num0, &num1, &num2); // 형식에 맞춰서 입력을 해줘야 한다. ex) "1 + 1 = 2"
        printf("%d + %d = %d\n", num0, num1, num2);
    }
    {
        // 접미사(0x, 0)을 넣어 주면 16진수, 8진수로 입력을 받을 수 있음
        int num;
        scanf("%i", &num);
        printf("%i\n", num);
    }
    {
        // 문자형 입력
        char ch;
        scanf("%c", &ch);
        printf("%c\n", ch);
        printf("%d\n", ch);
    }
    {
        // 부동소수점 입력, scanf에서는 %f float, %lf double
        float f0;
        double d0, d1;
        scanf("%lf %lf %f", &d0, &d1, &f0);
        printf("%lf %lf %f", d0, d1, f0);
    }
    {
        // 8진수 입력
        int num;
        scanf("%o", &num);
        printf("%d\n", num);
    }
    {
        // scanf 오류 처리
        char ch;
        scanf("%c", &ch);
        printf("1, %c\n", ch);

        while (getchar() != '\n');

        scanf("%c", &ch);
        printf("2, %c\n", ch);
    }
    {
        // stdin 을 input.txt에 연결
        int num;
        freopen("input.txt", "r", stdin);
        scanf("%d", &num);
    }
}