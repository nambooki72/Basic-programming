#include <stdio.h>


int main(void)
{
	

	int number;

	printf("5이하 숫자를 입력하세요");
	scanf("%d", &number);

	switch (number){
		case 5:
			printf("5\n");
		case 4:
			printf("4\n");
		case 3:
			printf("3\n");
		case 2:
			printf("2\n");
		case 1:
			printf("1\n"); //switch 문에 case를 입력하는 중 break를 입력하지 않아서 쭉 내려가게끔 만듦
		case 0:
			printf(" 카운트 종료\n");
			break;
		default:
			printf("유효하지 않은 입력입니다. 0에서 5 사이의 숫자만 입력 가능합니다. \n"); //그 외의 숫자 입력 시에는 오류가 뜨게끔 만듦
		}


	

	
	

	return 0;

}
