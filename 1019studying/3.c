#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	long num;
	int count = 0;
	int digit;

	
	
	printf("정수를 입력하시오: ");
 	scanf("%ld", &num);
 
	
	while (num >0)
	{
	
	digit = num % 10;
	printf("%d", digit);
	num /= 10;

	}

 return 0;
}

