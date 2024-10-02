#include <stdio.h>

int main() 
{

    int n, i;
    long long int first = 0, second = 1, next;



    printf("몇 번째 피보나치 수를 계산할까요? (3 이상의 수를 입력하세요): ");
    scanf("%d", &n);



    for (i = 3; i <= n; i++) {
        next = first + second;
        first = second;
        second = next;
    }



    printf("%d번째 피보나치 수는 %lld입니다.\n", n, next);

    return 0;
}

