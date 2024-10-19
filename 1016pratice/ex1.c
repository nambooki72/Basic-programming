#include <stdio.h>

int gcd(int a, int b)
{
    int c1 = (a > b) ? a : b;
    int c2 = (a > b) ? b : a;
    
    if (c2 == 0)
        return c1;
    else
        return gcd(c2, c1 % c2);
}

int main(void)
{
    int a, b;
    printf("첫 번째 숫자를 입력하세요 :");
    scanf("%d", &a);
    printf("두 번째 숫자를 입력하세요 :");
    scanf("%d", &b);
    printf("%d와 %d의 최대공약수는 %d입니다", a, b, gcd(a,b));
    return 0;
}
