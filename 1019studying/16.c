#include <stdio.h>
void count(void); 
int main(void)
{
 count( ); 
 count( ); 
 count( ); 
 return 0;
}
void count(void) 
{
 static int x=0; // 정적 변수, 초기화를 한 번만 수행
 int y=0; // 지역 변수, 초기화를 매 번 수행
 x=x+1;
 y=y+1;
 printf("x 값: %d, y 값: %d \n", x, y);
}

