/*
#include <stdio.h>

int main (void)
{
	const int salary = 60; // 분명 왕복 출퇴근 거리가 60km라고 했지 편도가 60km이라고
	//문제에서 주어지지 않았습니다. 하루에 60km를 이동한다고 생각하여 풀었습니다
	const int distance = 383000;


	int d = distance/salary + 1;
	int y = d/365;
	int m = (d%y)/30;
	int final_d = (d%y)%30;
	
	
	printf("왕복 출퇴근 거리 : %d \n", salary);
	printf("달까지의 거리 : %d \n", distance);

	printf("%d년 %d월 %d일 후 출퇴근 거리가 달까지의 거리가 됩니다.\n", y, m, final_d);




	return 0;
}


#include <stdio.h>

int main (void)
{
	const int daily_commute = 60; // 하루 출퇴근 거리 (km)
	const int distance_to_moon = 383000; // 달까지의 거리 (km)
	int days = ((double)distance_to_moon / daily_commute + 1);
	int years =((double) days / 365);
	int months = ((double) (days % 365) / 30);
	int remaining_days = ((double)(days % 365) % 30);

	printf("하루 출퇴근 거리: %d km\n", daily_commute);
	printf("달까지의 거리: %d km\n", distance_to_moon);
	printf("%d년 %d월 %d일 후 출퇴근 거리가 달까지의 거리가 됩니다.\n", years, months, remaining_days);

    return 0;


}
*/


#include <stdio.h>


int main(void)
{
    const int daily_commute = 60; // 하루 출퇴근 거리 (km)
    const int distance_to_moon = 383000; // 달까지의 거리 (km)
    int days = distance_to_moon/daily_commute +1;
    int years = days / 365;
    int months = (days % 365) / 30;
    int remaining_days =   (days % 365) % 30;

    printf("%d는 days\n", days);
    printf("%d는 years\n", years);
    printf("%d는 months\n", months);
    printf("%d는 remaining_days\n", remaining_days);


    printf("하루 출퇴근 거리: %d km\n", daily_commute);
    printf("달까지의 거리: %d km\n", distance_to_moon);
    printf("%d년 %d월 %d일 후 출퇴근 거리가 달까지의 거리가 됩니다.\n", years, months, remaining_days);

    return 0;
}

