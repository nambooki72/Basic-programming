#include <stdio.h>


int main (void)
{


	int a, b, c = 0, d = 1;

	printf("a와 b값을 입력하세요 : ");
	scanf("%d %d", &a, &b);


	for(; c < b; c++)
	{
		d *= a;
	}

	printf("%d^%d = %d \n", a, b, d);





	return 0;
}
