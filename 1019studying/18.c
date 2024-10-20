#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);
    
    // num1이 항상 더 크거나 같도록 보장
    if (num1 < num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    printf("%d와 %d의 최대공약수는 %d입니다.\n", num1, num2, gcd(num1, num2));
    
    return 0;
}
