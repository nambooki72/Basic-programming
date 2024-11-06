#include<stdio.h>




int main(void)
{
	
	int i=0,j=0;
	int array[3][3];
	int hang =0, yul=0;

	printf("3x3 행렬의 요소를 입력하세요 : \n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		scanf("%d", &array[i][j]);
		}

	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
		hang += array[i][j];
		}
		printf("%d번쨰 행의 합 = %d \n", i+1, hang);
		hang = 0;

	}

	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
		yul += array[i][j];
		}
		printf("%d번째 열의 합 = %d \n", j+1, yul);
		yul = 0;

	}



	return 0;
}
