#include <stdio.h>
#define GROWTH_RATE 0.01 // 연간 인구 증가율
int main(void) 
{
 double population = 7.9e9; // 현재 세계 인구
 int year = 2024; // 현재 연도
 while (population < 10e9) {
 population *= (1.0 + GROWTH_RATE);
 year++;
}
printf("세계 인구가 100억 명을 돌파하는 연도는 %d년입니다.\n", year);
 return 0;
}
