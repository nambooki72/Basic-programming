#include <stdio.h>

int get_max(int x, int y);

int main(void)
{
    int num1, num2, result;
    
    printf("서로 다른 두 정수를 입력하시오 : ");
    scanf("%d %d", &num1, &num2);
    
    result = get_max(num1, num2);
    
    printf("두 수 중 큰 값은 %d입니다.\n", result);
    
    return 0;
}

int get_max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
