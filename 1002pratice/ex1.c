#include <stdio.h>



int main (void)
{

	int i, j;


	for(int i =1, j =1; i<=9; i++)
	{
		for(; j<=9; j++)
		{
			printf("%d X %d = %d \n", i, j, i * j);

		}
		j = 1;
		printf("\n");
	}





	return 0;
}
