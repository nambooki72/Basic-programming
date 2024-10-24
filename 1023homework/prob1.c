#include <stdio.h>

int main(void)
{
    int money, password, input, num;
    int newmoney, newaccount;

    printf("은행 잔고와 비밀번호 초기값을 입력하세요: ");
    scanf("%d %d", &money, &password);

    printf("비밀번호를 입력하세요: ");
    scanf("%d", &input);

    if (password == input)
    {
 
        while (1) //5번 종료 버튼이 따로 있으므로 1~4번에 대해서 메뉴 표시가 무한 루프일 것이라고 이해함
        {

            printf("\nATM\n"
                "1-5메뉴 중 하나를 선택하시오\n"
                "<1> 잔고 확인\n"
                "<2> 입금\n"
                "<3> 출금\n"
                "<4> 이체\n"
                "<5> 종료\n\n");


            printf("메뉴를 선택하시오(숫자로만): ");
            scanf("%d", &num);


            switch (num)
            {
            case 1:
                printf("현재 잔고는 %d원\n", money);
                break;

            case 2:
                printf("입금 금액을 입력하시오: ");
                scanf("%d", &newmoney);

                money += newmoney;
                printf("%d원이 입금되었습니다. 새로운 잔고는 %d원 입니다.\n", newmoney, money);
                break;

            case 3:
                printf("출금 금액을 입력하시오: ");
                scanf("%d", &newmoney);
                
                if (newmoney > money) {
                    printf("잔액 부족 다시 시도\n");
                }
                
                else {
                    money -= newmoney;
                    printf("%d원이 출금되었습니다. 새로운 잔고는 %d원 입니다.\n", newmoney, money);
                }
                break;

            case 4:
                printf("이체할 계좌번호 정수로 입력: ");
                scanf("%d", &newaccount);
                
                printf("이체할 금액 입력: ");
                scanf("%d", &newmoney);

                if (newmoney > money) {
                    printf("잔액 부족 이체할 수 없음\n");
                }
                else if (newmoney <= 0) {
                    printf("유효하지 않은 금액 다시 시도\n");
                }
                else {
                    money -= newmoney;
                    printf("%d원이 이체되었습니다. 새로운 잔고는 %d원 입니다.\n", newmoney, money);
                }
                break;

            case 5:
                printf("프로그램 종료\n");
                return 0;

            default:
                printf("다시 선택\n");
            }
        }
    }


    else //비번이 틀린 경우
    {
        for (int i = 1; i <= 2; i++)
        {
            printf("잘못된 비밀번호입니다. 다시 시도하세요.\n");
            printf("%d회 남았습니다.\n", 3 - i);
            printf("비밀번호를 입력하세요: ");
            scanf("%d", &input);

            if (input == password)
                break;

            if (i == 2)
            {
                printf("비밀번호 3회 실패. 프로그램을 종료합니다.\n");
                return 1;
            }

        }

        if (input == password)
            main(); // 올바른 비밀번호 입력 시 메인 함수 재호출
    }
    return 0;
}
