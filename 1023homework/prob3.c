#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() 
{

    	int repetitions, operand_range, num1, num2, result, user_answer;
    	char operators[] = {'+', '-', '*', '/'};
    	char current_operator;
    

    	srand(time(NULL));  // 랜덤 시드 초기화
    
    	printf("몇 개의 문제를 풀겠습니까? ");
    	scanf("%d", &repetitions);
    

    	printf("사용할 숫자의 최대값을 입력하세요 (1 이상): ");
    	scanf("%d", &operand_range);
    

    	for (int i = 0; i < repetitions; i++) 
	{
        	num1 = rand() % (operand_range + 1);  // 0부터 operand_range까지의 랜덤 숫자
        	num2 = rand() % (operand_range + 1);
        	current_operator = operators[rand() % 4];  // 랜덤 연산자 선택
        

        	switch(current_operator) 
		{
            	case '+':
                result = num1 + num2;
                break;

            	case '-':
                result = num1 - num2;
                break;

            	case '*':
                result = num1 * num2;
                break;

            	case '/':
                result = (num2 != 0) ? num1 / num2 : 0;  // 0으로 나누기 방지
                break;
        	}
        
        	printf("%d %c %d = ", num1, current_operator, num2);
        	scanf("%d", &user_answer);
        
        	if (user_answer == result) 
		{
            	printf("맞았습니다.\n");
        	} 
		else 
		{
            	printf("틀렸습니다.\n");
        	}
    	}
    
    return 0;
}
