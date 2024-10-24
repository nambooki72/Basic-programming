#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int max, correct, guess, num;
    
    printf("랜덤 넘버의 최댓값을 입력하세요 > ");
    scanf("%d", &max);

    srand((unsigned)time(NULL)); // 랜덤 함수의 seed값을 초기화
    num = rand() % max + 1; // 1에서 max 사이의 난수 생성

    correct = 0; // correct 변수를 0으로 초기화
    while (!correct) // 맞출 때까지 반복
    {
        printf("컴퓨터의 랜덤 넘버는? ");
        scanf("%d", &guess);
        
        if (guess == num)
        {
            printf("OK!!\n");
            correct = 1; // 맞췄으므로 루프를 종료
        }

        else if (guess < num)
        {
            printf("더 큰 수를 입력하세요\n");
        }

        else
        {
            printf("더 작은 수를 입력하세요\n");
        }
    }

    return 0;
}
