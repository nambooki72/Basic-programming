#include <stdio.h>

int main()
{
 
     


	int priceA, gramA, priceB, gramB; // 가격과 무게를 모두 정수형으로 입력받는다
	double pricePergramA, pricePergramB; // 계산의 정확성을 위해 double 변수를 사용한다
   	int result;




    	printf("Enter the price and weight of A mart: ");
    	scanf("%d %d", &priceA, &gramA);


    	printf("Enter the price and weight of B mart: ");
    	scanf("%d %d", &priceB, &gramB);



    	// g당 가격을 계산하고 소수점 둘째자리까지 반올림한다
	// 소수점 둘째짜리까지 반올림하기 위해 0.5를 더하고 int에 집어넣는 테크닉을 사용한다
    	pricePergramA = (double)priceA / gramA * 100;
    	pricePergramA = (int)(pricePergramA + 0.5) / 100.0;



    	pricePergramB = (double)priceB / gramB * 100;
    	pricePergramB = (int)(pricePergramB + 0.5) / 100.0;



    	// 가격 비교
    	result = (pricePergramA > pricePergramB) - (pricePergramA < pricePergramB);
	
    	printf("The result of comparison [-1: A is cheaper, 0: the same, 1: B is cheaper]: %d\n", result);
    	
	
	
	
	return 0;
}

