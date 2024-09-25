#include <stdio.h>

int main(void) 
{
    int num, value, digit_sum = 0;
    
    printf("3자리 숫자를 입력하시오: ");
    scanf("%d", &num);
    
    value = num;
    
    // 각 자리수를 분리하여 합산
    digit_sum += num % 10; // 1의 자리
    num /= 10;
    digit_sum += num % 10; // 10의 자리
    num /= 10;
    digit_sum += num % 10; // 100의 자리
    
    printf("%d의 자릿수 합은 %d입니다.\n", value, digit_sum);
    
    return 0;
}
