#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int sec = 0;
    printf("초를 입력하세요: ");
    scanf("%d", &sec);

    for (; sec > 0; sec -= 1)
    {
        system("clear");  // 화면을 지웁니다
        printf("%d 초 남음\n", sec);
        fflush(stdout);  // 출력 버퍼를 즉시 비웁니다
        sleep(1);  // 1초 동안 대기합니다
    }

    system("clear");
    printf("시간 종료!\n");
    return 0;
}
