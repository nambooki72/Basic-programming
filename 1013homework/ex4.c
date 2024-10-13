#include <stdio.h>

int main(void)
{
    int num, password;
    int num1, password1;
    int login_success = 0;

    printf("회원가입을 진행합니다\n");
    printf("학번을 입력하세요: ");
    scanf("%d", &num);

    if (num >= 2019000000 && num <= 2024999999)
    {
        printf("비밀번호 (정수)를 입력하세요: ");
        scanf("%d", &password);
        printf("회원가입이 완료되었습니다!\n");
        printf("학번: %d, 비밀번호: %d\n\n", num, password);

        printf("로그인을 진행합니다.\n");

        while (!login_success) //로그인에 성공할때까지 반복하라
        {
            printf("아이디(학번)를 입력하세요: ");
            scanf("%d", &num1);
            printf("비밀번호를 입력하세요: ");
            scanf("%d", &password1);

            if (num != num1)
            {
                printf("존재하지 않는 아이디입니다.\n");
            }
            else if (password != password1)
            {
                printf("비밀번호가 틀립니다.\n");
            }
            else
            {
                printf("로그인에 성공했습니다!\n");
                login_success = 1;
            }

        }
    }
    else
    {
        printf("유효하지 않은 학번입니다. 2019000000에서 2024999999 사이의 학번만 회원가입 가능합니다.\n");
    }

    return 0;
}

