#include<stdio.h>




int main(void)
{
	
	int i = 0, j = 0;

	int array[3][3];

	printf("3x3 행렬의 요소를 입력하세요 : \n");

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d", &array[i][j]);
		}
		
	}




	printf("90도 회전된 배열 : \n");

	i = 0;
	j = 0;


	for(j=0;j<3;j++)
	{
		for(i=2;i>=0;i--)
		{
			printf("%d", array[i][j]);

		}
		printf("\n");

	}


	return 0;
}


/*
     // 90도 시계방향 회전
    // 회전 시 원래 배열의 i번째 행이 회전된 배열의 (2-i)번째 열이 됨
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            rotated[j][2-i] = arr[i][j];
        }
    }
 */
