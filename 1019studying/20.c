#include <stdio.h>
int get_integer();

int main(void)
{
	int a, b, sum;

	a=get_integer();
	b=get_integer();

	sum = a+b;
	printf("두 수의 합 = %d \n", a+b);

	return 0;
}



int get_integer()
{
	int value;
	printf("정수를 입력하시오 :");
	scanf("%d", &value);
	return value;


}
