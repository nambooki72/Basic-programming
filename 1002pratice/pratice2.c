
#include <stdio.h>

int main(void)
{


    float h;
    int i, j;


    printf("피라미드의 높이를 입력하세요: ");
    scanf("%f", &h);



    if (h <= 0) {
        printf("프로그램을 종료합니다.\n");
    } 
    
    else {
        
		for (i = 0; i < h; i++) {
			for (j = 0; j < h - i; j++) {
                	printf("*");
            }
            printf("\n");
        }
    }

    return 0;
}
