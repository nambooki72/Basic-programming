#include <stdio.h>

int main(void)
{
    int i = 0;
    do
    {
        printf("1---파일열기\n");
        printf("2---파일저장하기\n");
        printf("3---종료\n");
        printf("하나를 선택하시오: ");
        scanf("%d", &i);
    } while(i < 1 || i > 3);
    
    printf("선택된 메뉴=%d\n", i);
    
    // 선택된 메뉴에 따라 추가 설명 출력
    switch(i)
    {
        case 1:
            printf("선택하신 작업은 1---파일열기 입니다.\n");
            break;
        case 2:
            printf("선택하신 작업은 2---파일저장하기 입니다.\n");
            break;
        case 3:
            printf("선택하신 작업은 3---종료 입니다.\n");
            break;
    }
    
    return 0;
}
