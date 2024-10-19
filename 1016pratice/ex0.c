#include <stdio.h>



long long power(int x, int n)
{
	if(n==0)
	{
		return 1;
	}

	long long half = power(x, n/2);

	if (n % 2 ==0)
	{
		return half * half;
	}
	else
	{
		return half * half * x;
	}

}

int main (void)
{

	int x, n;

	printf("밑수를 입력하세요 :");
	scanf("%d", &x);

	printf("지수를 입력하세요 :");
	scanf("%d", &n);


	printf("%d^%d = %lld \n", x, n, power(x,n));



	return 0;
}
