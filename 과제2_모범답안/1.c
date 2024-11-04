#include <stdio.h>

int main() {
    int balance = 100000;  // 초기 잔고
    int password = 1234;   // 초기 비밀번호
    int inputPassword;
    int attempt = 0;       // 비밀번호 시도 횟수
    int choice;
    int amount;

    // 비밀번호 확인 단계
    while (attempt < 3) {
        printf("계좌 비밀번호를 입력하세요: ");
        scanf("%d", &inputPassword);
        
        if (inputPassword == password) {
            printf("비밀번호가 확인되었습니다.\n");
            break;
        } else {
            attempt++;
            if (attempt < 3) {
                printf("잘못된 비밀번호입니다. 다시 시도하세요.\n");
            } else {
                printf("비밀번호 3회 실패. 프로그램을 종료합니다.\n");
                return 0;  // 프로그램 종료
            }
        }
    }

    // 메뉴 선택 반복
    while (1) {
        printf("\nATM 메뉴:\n");
        printf("< 1 > 잔고 확인\n");
        printf("< 2 > 입금\n");
        printf("< 3 > 출금\n");
        printf("< 4 > 이체\n");
        printf("< 5 > 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // 잔고 확인
                printf("현재 잔고는 %d원 입니다.\n", balance);
                break;

            case 2:
                // 입금
                printf("입금 금액을 입력하세요: ");
                scanf("%d", &amount);
                if (amount <= 0) {
                    printf("유효하지 않은 금액입니다. 다시 시도하세요.\n");
                } else {
                    balance += amount;
                    printf("%d원이 입금되었습니다. 새로운 잔고는 %d원 입니다.\n", amount, balance);
                }
                break;

            case 3:
                // 출금
                printf("출금 금액을 입력하세요: ");
                scanf("%d", &amount);
                if (amount <= 0) {
                    printf("유효하지 않은 금액입니다. 다시 시도하세요.\n");
                } else if (amount > balance) {
                    printf("잔액 부족. 다시 시도하세요.\n");
                } else {
                    balance -= amount;
                    printf("%d원이 출금되었습니다. 새로운 잔고는 %d원 입니다.\n", amount, balance);
                }
                break;

            case 4:
                // 이체
                printf("이체할 금액을 입력하세요: ");
                scanf("%d", &amount);
                if (amount <= 0) {
                    printf("유효하지 않은 금액입니다. 다시 시도하세요.\n");
                } else if (amount > balance) {
                    printf("잔액 부족. 이체할 수 없습니다.\n");
                } else {
                    balance -= amount;
                    printf("%d원이 이체되었습니다. 새로운 잔고는 %d원 입니다.\n", amount, balance);
                }
                break;

            case 5:
                // 종료
                printf("프로그램을 종료합니다.\n");
                return 0;

            default:
                printf("유효하지 않은 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}

