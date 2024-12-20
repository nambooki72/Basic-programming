#include<stdio.h>
int main(void)
{
        int i = 0, j = 0;
        int hang[3] = {0}, yul[3] = {0}, dae[2] = {0};  // 배열 초기화 추가
        int is_magic = 1;  // 마방진이면 1, 아니면 0
        int array[3][3];

        printf("1에서 9까지 서로 다른 숫자로 3x3 행렬의 요소를 입력하세요 : \n");
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        scanf("%d", &array[i][j]);
                        if(array[i][j] < 1 || array[i][j] > 9)  // arr를 array로 수정
                        {
                                printf("숫자가 1~9 범위를 벗어났습니다.\n");
                                return 1;
                        }
                }
        }

        // 행의 합
        for(i=0;i<3;i++)
        {
                for(j=0;j<3;j++)
                {
                        hang[i] += array[i][j];
                }
        }

        // 열의 합
        for(j=0;j<3;j++)
        {
                for(i=0;i<3;i++)
                {
                        yul[j] += array[i][j];
                }
        }

        // 주대각선 합
        for(i=0;i<3;i++)
        {
                dae[0] += array[i][i];
        }

        // 부대각선 합 (수정)
        for(i=0;i<3;i++)
        {
                dae[1] += array[i][2-i];
        }

        // 마방진 검사
        // 모든 행의 합이 같은지 검사
        for(i=1; i<3; i++)
        {
                if(hang[0] != hang[i])
                {
                        is_magic = 0;
                        break;
                }
        }

        // 모든 열의 합이 같은지 검사
        for(i=0; i<3; i++)
        {
                if(hang[0] != yul[i])  // 행의 합과 열의 합이 같은지 비교
                {
                        is_magic = 0;
                        break;
                }
        }

        // 대각선의 합이 같은지 검사
        if(hang[0] != dae[0] || hang[0] != dae[1])
        {
                is_magic = 0;
        }

        // 결과 출력
        if(is_magic)
                printf("마방진이다.\n");
        else
                printf("마방진이 아니다\n");

        return 0;
}
