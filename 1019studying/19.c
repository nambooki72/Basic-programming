#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fact(int n);
int main(void)
{
int result = fact(5);
printf("5!은 %d입니다.\n", result);
return 0;
}
int fact(int n)
{
printf("fact(%d)\n", n);
if (n <= 1) return 1; // 종료 조건
else return n * fact(n - 1); // 자기 자신을 호출
}

