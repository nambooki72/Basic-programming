
#include <stdio.h>



int main(void)
{

        int num, password;

        printf("회원가입을 진행합니다\n");
        printf("학번을 입력하세요");
        scanf("%d", &num);

        if (num >= 2019000000 && num <= 2024999999)
	{
                printf("비밀번호 (정수)를 입력하세요:");
                scanf("%d", &password);
                printf("회원가입이 완료되었습니다! \n");
                printf("학번 : %d, 비밀번호 : %d \n", num, password);
	}

        else
	{
                printf("유효하지 않은 학번입니다. 2019000000에서 2024999999 사이의 학번만 회원가입 가능합니다. \n");
	}

        return 0;
}
