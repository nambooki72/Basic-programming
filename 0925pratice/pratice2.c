#include <stdio.h>


int main(void)
{
	int a = 0;
	int b = 0;
	int result1 =0;


	printf("첫 번째 16진수 값을 입력하세요. :"); //ctrl c 누루면 빠져나올 수 있음
	scanf(" %x", &a);

	printf("두 번째 16진수 값을 입력하세요. :");
	scanf(" %x", &b);

	result1 = a & b;
	printf(" 비트AND 연산 결과 : %x\n", result1);

	result1 = a | b;
	printf(" 비트OR 연산 결과 : %x\n", result1);

	result1 = a ^ b;
        printf(" 비트XOR 연산 결과 : %x\n", result1);
	// 앞에 확장된 숫자 출력은 # 이었고, 대문자로 나타내려면 x를 대문자로 입력해야함
	result1 =  ~ b; // 둘 중 하나 맞는 값 찾아야함 아래 3개 모두

        printf(" 비트NOT 연산 결과 : %x\n", result1);

	result1 = a << 2;
        printf(" 비트LEFT_SHIFT 연산 결과(2칸 이동) :%x\n", result1);

	result1 = a << 3;
        printf(" 비트RIGHT_SHIFT 연산 결과(3칸 이동) : %x\n", result1);






	return 0;
}
