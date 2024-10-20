#include <stdio.h>
#include <stdlib.h>
#include <time.h> // time 함수를 사용하기 위한 헤더 파일
int main(void)
{
 int dice;
srand((unsigned int)time(NULL)); // 현재 시간을 시드값으로 초기화
dice = rand() % 6 + 1; // 1부터 6까지의 값을 무작위로 반환
printf("%d 값이 나왔습니다!\n", dice); // 결과 출력
 return 0;
}

