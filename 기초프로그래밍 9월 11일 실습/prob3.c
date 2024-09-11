#include <stdio.h>


int main(void)
{
	int a, b, c, d, e;

	printf("거리를 km단위로 입력하세요 : ");
	scanf("%d", &a);

	printf("거리는 입니다. %d \n", a*1000 );

	printf("시간을 시, 분, 초로 입력하세요 (예 : 1 30 45): ");
	scanf(" %d %d %d", &b, &c, &d );
	printf(" 전체 초 : %d ", 3600*b+60*c+d );


	return 0;

}
