#include <stdio.h>


int main(void)
{
	float km = 0;
	int h = 0;
	int m = 0;
	int s = 0;

	printf("거리를 킬로미터 단위로 입력하세요: ");
	scanf("%f", &km);
	printf("입력한 거리 : %.2f km\n ", km);

	printf("시간을 시간 단위로 입력하세요 :  ");
	scanf("%d", &h);
	printf("입력한 시간 : %d 시간 \n", h);

	printf("분을 분 단위로 입력하세요 :");
	scanf("%d", &m);
	printf("입력한 분 : %d 분\n", m);

	printf("초를 초 단위로 입력하세요 :");
	scanf("%d", &s);
	printf("입력한 초 : %d 초 \n", s);

	printf("속력 : %.2f km/h ", (km/(h + m/60 + s/3600)));



	return 0;
}
