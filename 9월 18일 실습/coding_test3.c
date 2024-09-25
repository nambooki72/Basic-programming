#include <stdio.h>



int main(void)
{


	
	int money, price, change;
	
	printf("투입한 돈: ");
	scanf("%d", &money);


	printf("물건값: ");
	scanf("%d", &price);

	change = money - price;
	printf("거스름돈: %d\n", change);

	int coin100s = change / 100; 
	change = change % 100; 

	int coin10s = change / 10; 
	change = change % 10; 

	printf("100원 동전의 개수: %d\n", coin100s);

	printf("10원 동전의 개수: %d\n", coin10s);

	printf("1원 동전의 개수: %d\n", change);
	
	
	return 0;
}
