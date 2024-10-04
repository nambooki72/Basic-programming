#include <stdio.h>



int main(void)
{


	float length;
	int meter, centimeter; //거리와 미터, 센티미터를 각각 알맞는 변수로 선언한다



	printf("Enter the length in km :");
	scanf("%f", &length);


	meter = (int)(length * 1000); // 힌트에 따라 형변환을 이용하여 소수점 이하 숫자를 없에버린다
        centimeter = (int)((length * 100000) - (meter * 100) + 0.5); //반올림을 해야한다는 조건에 주의한다



	printf("%gkm is approximately %dm %dcm \n", length, meter, centimeter);









	return 0;

}
