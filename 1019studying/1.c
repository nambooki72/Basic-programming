#include <stdio.h>


int main(void) 
{

	double pheight = 0.001; // 단위 미터

	const double everest = 8800.0; // 단위 미터

	int count = 0;

	
	while (pheight < everest) 
	{
	pheight *= 2.0;
	count++;
	}


	printf("종이 접는 횟수=%d \n\n", count);
	return 0;
}

