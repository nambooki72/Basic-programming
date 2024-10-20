#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void disp_car(int car_number, int distance)
{
int i;
printf("CAR #%d:", car_number);
for( i = 0; i < distance/10; i++ ) 
printf("*");
printf("\n");
}

int main(void)
{
int i;
int car1_dist=0, car2_dist=0;
srand( (unsigned)time( NULL ) );
for( i = 0; i < 20; i++ ) {
system("clear");
car1_dist += rand() % 100;
car2_dist += rand() % 100;
disp_car(1, car1_dist);
disp_car(2, car2_dist);
char tmp; scanf(“%c”, &tmp);
}
return 0;


}


/*
네, 이 코드는 두 대의 자동차 경주를 시뮬레이션하는 프로그램입니다. 각 부분을 자세히 설명해드리겠습니다:

헤더 파일:

<stdlib.h>: rand() 함수 사용을 위해
<stdio.h>: 입출력 함수 사용을 위해
<time.h>: time() 함수 사용을 위해


disp_car 함수:

자동차의 번호와 이동 거리를 받아 시각적으로 표시합니다.
거리를 10으로 나눈 만큼 "*"를 출력하여 자동차의 위치를 나타냅니다.


main 함수:

두 자동차의 거리를 저장할 변수 초기화: car1_dist, car2_dist
srand((unsigned)time(NULL)): 랜덤 숫자 생성기 초기화


주요 루프:

20번 반복합니다 (i < 20).
각 반복마다:
a. system("clear"): 화면을 지웁니다 (Windows에서는 "cls" 사용).
b. 각 자동차의 거리를 0~99 사이의 랜덤 값만큼 증가시킵니다.
c. disp_car 함수를 호출하여 각 자동차의 현재 위치를 표시합니다.
d. scanf("%c", &tmp): 사용자 입력을 기다립니다 (엔터키 입력을 위해).


시뮬레이션 특징:

각 단계마다 자동차들의 위치가 업데이트됩니다.
사용자가 엔터키를 누를 때마다 다음 단계로 진행됩니다.
20단계 후 프로그램이 종료됩니다.



이 프로그램은 간단한 텍스트 기반 레이싱 게임을 시뮬레이션합니다. 각 라운드마다 자동차들의 위치가 랜덤하게 변하며, 사용자는 엔터키를 눌러 게임을 진행할 수 있습니다. 화면이 계속 지워지고 다시 그려지므로, 자동차들이 움직이는 것처럼 보이게 됩니다.
*/
