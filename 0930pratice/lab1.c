#include <stdio.h>



int main(void)
{


	int times = 0;
	double paperheight = 0.001;
	const double everest = 8800.0;

	for(paperheight = 0.001; paperheight < everest; paperheight *= 2)
	{
		times += 1;
	}	
	printf("종이 접는 횟수 = %d \n", times);






	return 0;
}
