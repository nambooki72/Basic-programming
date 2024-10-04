#include <stdio.h>


int main (void)
{

	unsigned char num; //4번과 마찬가지로 256 미만의 정수를 입력받아야한다
	int count1 = 0; //각 자리에 1이 존재하는지 확인하는 변수이다



   	printf("Enter a hexadecimal number: ");
    	scanf("%hx", &num); //형식지정자에 유의. 처음에는 교안에 있는 %hx를 썼으나 컴파일 중 %hhx를 써야한다고 경고가 뜸. warning이기에 무시하고 교안을 따름


    	printf("The number is %d in decimal representation and %o in octal representation.\n", num, num);


	// 힌트에 따라, 8자리의 이진수 11111111(255) 과 AND 비트연산을 활용하여 1만 건져내는 과정을 거친다
	count1 += (num & 1) !=0; // 이진수 1, 10, 100, 1000, 10000 등과 AND 연산자를 이용하여 정확히 1개씩 count1에 더하도록 한다
	count1 += (num & 2) !=0; // !=0을 사용하지 않을 경우, count1에는 우리가 원하는 1의 개수가 아니라, 실제 이진수 정수가 더해지는 심각한 문제가 발생한다
	count1 += (num & 4) !=0;
	count1 += (num & 8) !=0;
	count1 += (num & 16) !=0;
	count1 += (num & 32) !=0;
	count1 += (num & 64) !=0;
	count1 += (num & 128) !=0;




    	printf("The number of 1's in the binary representation is %d\n", count1);






	return 0;
}
