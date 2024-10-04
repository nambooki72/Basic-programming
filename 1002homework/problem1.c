#include <stdio.h>


int main (void)
{

	int year, studentID; //입학연도와 학번을 정수형으로 입력받는다
	float score; //학점은 소수점 한 자리 까지만 받으므로 일단 float형으로 입력을 받는다


	printf("When did you enter the university?");
	scanf("%d", &year);

	printf("What is your student ID (without years)?");
	scanf("%d", &studentID);

	printf("What is your score?");
	scanf("%f", &score);



	printf("Your student number is %d-%d and your score is %.1f \n", year, studentID, score); //.1f를 붙여서 학점은 소수점 한 자리 까지만 반올림하여 표현한다








	return 0;
}
