#include <stdio.h>
#include <limits.h>


int main(void)
{
	printf("int의 최소삾 : %d, 최댓값 : %d \n", INT_MIN, INT_MAX);

	unsigned int range = (unsigned int)(INT_MAX) - (unsigned int)(INT_MIN);
	printf("INT_MAX - INT_MIN의 값 : %u \n", range); //unsigned int니까 %u이다

	
	return 0;
	










}
