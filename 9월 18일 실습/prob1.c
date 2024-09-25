#include <stdio.h>


int main(void)
{
	
	int a, b;

	printf("정수형 int의 크기는 %zu입니다.\n", sizeof(int));
	printf("정수형 long의 크기는 %zu입니다.\n", sizeof(long));
	printf("정수형 long long의 크기는 %zu입니다.\n\n\n\n", sizeof(long long));


	printf("정수를 입력하시오(10진수):  \n");
	scanf("%d", &a);
	printf("%d은 10진수로%d , 8진수로 %#o, 16진수로 %#x입니다.\n\n\n", a, a, a, a);


	printf("정수를 입력하시오(16진수): \n");
	scanf("%x", &b);
	printf("%d은 10진수로%d, 8진수로 %#o, 16진수로 %#x입니다.\n", b, b, b, b);






	return 0;
}
