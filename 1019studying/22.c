#include <stdio.h>
int get_integer()
{
int value;
printf("정수를 입력하시오 : ");
scanf("%d", &value);
return value;
}
int get_max(int x, int y)
{
if (x > y) return(x);
else return(y);
}
int main(void)
{
int a = get_integer(); // 함수 호출
int b = get_integer(); // 함수 호출
printf("두수 중에서 큰 수는 %d입니다.\n", get_max(a, b)); // 함수 호출
return 0;
}
