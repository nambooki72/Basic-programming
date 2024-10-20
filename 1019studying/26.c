#include <stdio.h>
int check_prime(int);
int main(void)
{
 int i;
printf("1과 100 사이에서 소수를 찾습니다.\n");
for (i = 0; i < 100; i++) {
if (check_prime(i) == 1) printf("%d ", i);
}
 return 0;
}
int check_prime(int n) {
int is_prime = 1; // 일단 소수라고 가정한다. 
for (int i = 2; i < n; ++i) {
 if (n % i == 0) {
 is_prime = 0;
break;
}
}
 return is_prime;
}
