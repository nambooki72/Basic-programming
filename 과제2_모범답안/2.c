#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userInput, randomNumber, maxNumber;

    printf("랜덤 넘버의 최댓값을 입력하세요 > ");
    scanf("%d", &maxNumber);

    srand((unsigned int)time(NULL));

    randomNumber = rand() % maxNumber + 1;

    printf("랜덤 넘버 맞추기 게임을 시작합니다!\n");

    while (1) {
        printf("컴퓨터의 랜덤 넘버는? ");
        scanf("%d", &userInput);

        if (userInput > randomNumber) {
            printf("더 작은 수를 입력하세요\n");
        }
        else if (userInput < randomNumber) {
            printf("더 큰 수를 입력하세요\n");
        }
        else {
            printf("OK!!\n");
            break; 
        }
    }

    return 0;
}

