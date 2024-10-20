#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
printf("동전 던지기 게임을 시작합니다.\n");
srand(time(NULL)); // 현재 시간을 난수의 씨앗값으로 한다. 
int coin = rand() % 2;
if (coin == 0)
printf("앞면입니다.\n");
else
printf("뒷면입니다.\n");
return 0;
}

