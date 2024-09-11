#include <stdio.h>

int main(void)

{
	int a;
	float b;

	printf("정수를 입력하세요 : ");
	scanf("%d", &a);

	printf("10 진수 : %d \n", a);
	printf("8 진수 : %o \n", a);
	printf("16 진수 : %x \n", a);
	printf("최소 폭이 3인 10진수 : %-3.3d \n", a);
	printf("\n");


	printf("float실수를 입력하세요 : ");
	scanf("%f", &b);

       	printf("고정 소수점 형식 : %3.2f \n ", b);
	printf("지수 형식 : %3.2e \n ", b  );
	printf("일반 형식 : %4.3f \n ", b  ); 	

 
	return 0;




}
