#include <stdio.h>


int main(void){

	int a, b, answer;
	char c;

	printf("첫 번째 정수를 입력하세요 :");
	scanf("%d", &a);

	printf("두 번째 정수를 입력하세요 :");
	scanf("%d", &b);

	printf("연산자를 입력하세요 ( +, -, *, /, %%) :");
	scanf(" %c", &c);


	switch (b) {
		case 0:
			
			switch (c) {
				case '/':
				case '%':
					printf("오류 : 0으로 나머지 연산을 할 수 없습니다\n");
					break;

				default:
					switch (c) {
						case '+':
						answer = a+b;
						printf("%d %c %d = %d \n", a, c, b, answer);
						break;

						case '-':
						answer = a-b;
						printf("%d %c %d = %d \n", a, c, b, answer);
						break;

						case '*':
						answer = a*b;
						printf("%d %c %d = %d \n", a, c, b, answer);
						break;

						default :
						printf("유효하지 않은 연산자입니다. 프로그램을 종료합니다\n");
					}
			}


		default:
			switch (c) {
				case '+':
                                answer = a+b;
                                printf("%d %c %d = %d \n", a, c, b, answer);
                                break;

                                case '-':
                                answer = a-b;
                                printf("%d %c %d = %d \n", a, c, b, answer);
                                break;

                                case '*':
                                answer = a*b;
                                printf("%d %c %d = %d \n", a, c, b, answer);
                                break;

				case '/':
				answer = a/b;
				printf("%d %c %d = %d \n", a, c, b, answer);
				break;

				case '%':
				answer = a%b;
				printf("%d %c %d = %d \n", a, c, b, answer);
				break;

                                default :
                                printf("유효하지 않은 연산자입니다. 프로그램을 종료합니다\n");


			}
	}


	return 0;
}
/*
#include <stdio.h>

int main(void) {
    int a, b, answer;
    char c;

    printf("첫 번째 정수를 입력하세요: ");
    scanf("%d", &a);
    printf("두 번째 정수를 입력하세요: ");
    scanf("%d", &b);
    printf("연산자를 입력하세요 ( +, -, *, /, %% ): ");
    scanf(" %c", &c);

    switch (c) {
        case '+':
            answer = a + b;
            printf("%d %c %d = %d\n", a, c, b, answer);
            break;
        case '-':
            answer = a - b;
            printf("%d %c %d = %d\n", a, c, b, answer);
            break;
        case '*':
            answer = a * b;
            printf("%d %c %d = %d\n", a, c, b, answer);
            break;
        case '/':
            if (b != 0) {
                answer = a / b;
                printf("%d %c %d = %d\n", a, c, b, answer);
            } else {
                printf("오류: 0으로 나눌 수 없습니다.\n");
            }
            break;
        case '%':
            if (b != 0) {
                answer = a % b;
                printf("%d %c %d = %d\n", a, c, b, answer);
            } else {
                printf("오류: 0으로 나머지 연산을 할 수 없습니다.\n");
            }
            break;
        default:
            printf("유효하지 않은 연산자입니다. 프로그램을 종료합니다.\n");
    }

    return 0;
*/


