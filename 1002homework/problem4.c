#include <stdio.h>



int main (void)
{

   	unsigned char num; // 0부터 256미만의 양의 정수를 받는다는 조건에 주의한다 
	int quotient, remain, multiple;

	printf("Enter a positive integer: ");
   	scanf("%hu", &num); // 형식지정자에 주의한다. 교안에서는 %hu로 나와있어서 이걸 썼으나 %hhu로 warning이 뜸. 교안에 충실하여 %hu를 사용함


   	quotient = num >> 2;  // 4로 나누는 것과 같은 효과이다


   	remain = num & 3;  // 4로 나눈 나머지와 같다. 3은 2진수로 11이므로, AND 연산자를 통하여 3이하의 자릿수만 출력하게 된다


   	multiple = (num << 2) + num;  //5를 곱한다는 것은 4배를 한 이후 1배를 더하는 것과 같다. 따라서 원래 num에 4배를 해주고, num을 한번 더 더하면 5곱하기와 같은 효과이다 



   	printf("After divided by 4, the quotient is %d and the remainder is %d\n", quotient, remain);
   	printf("After multiplied by 5, it is %d\n", multiple);




	return 0;
}
