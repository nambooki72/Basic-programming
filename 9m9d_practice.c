#include <stdio.h>

int main(void)
{
	int n1, n2, n3, n4, n5, sum;

	

	printf("식별 번호를 입력하세요 :");
	scanf("%d %d %d %d %d", &n1, &n2, &n3, &n4, &n5);
	sum = n1 + n2 + n3 + n4 + n5;

	printf("체크 디지트는 %d입니다.", sum % 10 );

	return 0;

}
