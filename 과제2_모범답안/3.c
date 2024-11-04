#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_questions = 5; 
    int operand1, operand2, correct_answer, user_input;
    char operator;

    
    srand((unsigned int)time(NULL));

    for (int i = 0; i < num_questions; i++) {
        
        operand1 = rand() % 10; 
        operand2 = rand() % 10; 
        int operator_choice = rand() % 4; 

        
        switch (operator_choice) {
        case 0:
            operator = '+';
            correct_answer = operand1 + operand2;
            break;
        case 1:
            operator = '-';
            correct_answer = operand1 - operand2;
            break;
        case 2:
            operator = '*';
            correct_answer = operand1 * operand2;
            break;
        case 3:
            // 나누기는 0으로 나누는 것을 방지
            if (operand2 == 0) {
                operand2 = 1; // operand2가 0일 경우 1로 대체
            }
            operator = '/';
            correct_answer = operand1 / operand2;
            break;
        }

        
        printf("%d %c %d = ", operand1, operator, operand2);
        scanf("%d", &user_input);

    
        if (user_input == correct_answer) {
            printf("맞았습니다.\n");
        }
        else {
            printf("틀렸습니다.\n");
        }
    }

    return 0;
}

