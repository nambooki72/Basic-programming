#include <stdio.h>

int main(void)
{

	int a;
	float b;
	double c;

	printf("int 정수를 입력해주세요 :" );
	scanf("%d", &a);

	printf("float 실수를 입력해주세요 :");
	scanf("%f", &b);

	printf("double 실수를 입력해주세요 :");
	scanf("%lf", &c);
	printf("\n \n");


	printf("%%d를 통한 int 정수 출력 : %d \n", a);
	printf("%%f를 통한 float 실수 출력 : %f \n", b);
	printf("%%lf를 통한 double 실수 출력 : %lf \n", c);

	return 0;





}
