#include <stdio.h>

double F_to_C(double temp_F);

int main(void)
{
	
	double c,f;
	printf("화씨온도 :");
	scanf("%lf", &f);
	printf("섭씨온도 : %lf \n\n", F_to_C(f));


	return 0;
}


double F_to_C(double temp_F)
{
	
	double temp_C;
	temp_C = (5.0 * (temp_F - 32.0)) / 9.0;
	return temp_C;	

}
