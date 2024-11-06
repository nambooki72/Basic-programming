#include<stdio.h>



int main(void)
{

	int i, j;
	int array[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		printf("array[%d][%d] : %d \n", i, j, array[i][j]);
		}
	}




	return 0;
}
