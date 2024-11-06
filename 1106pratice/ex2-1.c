#include <stdio.h>




int main(void)
{

	int i=0, j=0;
	int array[3][3];
	int value = 1;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		array[i][j] = value;
		value++;

		}

	}



	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("%d", array[i][j]);
		}
		printf("\n");

	}



	return 0;
}
