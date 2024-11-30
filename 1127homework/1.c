#include <stdio.h>


double eval(double p[], double x, int n);
double add(double f[], double g[], double h[], int n);


int main(void) {
 
	int n;
    	printf("다항식의 차수 n: ");
    	scanf("%d", &n);
    	double p[101];  // 최대 100차까지 가능하도록
    

    	printf("x값: ");
    	double x;
    	scanf("%lf", &x);
    
    
	printf("a0 ~ a%d 입력: ", n);
    	for (int i = 0; i <= n; i++) {
        	scanf("%lf", &p[i]);
    	}
    

    	double result = eval(p, x, n);
    	printf("p(%.0f) = %.0f\n", x, result);
    
	
    
	printf("----------------------\n");
    
    // 두 다항식의 덧셈 테스트
    	printf("다항식의 차수 n: ");
    	scanf("%d", &n);
    
    
	double g[101], h[101], f[101];
    

    	printf("g(x) a0 ~ a%d 입력: ", n);
    	for (int i = 0; i <= n; i++) {
        	scanf("%lf", &g[i]);
    	}
    

    	printf("h(x) b0 ~ b%d 입력: ", n);
    	for (int i = 0; i <= n; i++) {
        	scanf("%lf", &h[i]);
    	}
    

    	add(f, g, h, n);
    
    	// 결과 출력
    	printf("g(x) = %.0f", g[0]); //소수점 아래를 깔끔하게 제거하기 위해 %.0f를 사용한다
    	for (int i = 1; i <= n; i++) {
        	printf(" + %.0fx^%d", g[i], i);
    	}
    	printf("\n");
    

    	printf("h(x) = %.0f", h[0]);
    	for (int i = 1; i <= n; i++) {
        	printf(" + %.0fx^%d", h[i], i);
    	}
    	printf("\n");
    
    	printf("f(x) = %.0f", f[0]);
    	for (int i = 1; i <= n; i++) {
        	printf(" + %.0fx^%d", f[i], i);
    	}
    	printf("\n");
    
    	return 0;
}




double eval(double p[], double x, int n) 
{
    double result = p[0]; // 초기값은 a0로 준다 이는 상수항이다
    double temp = x; //임시 변수 temp에는 일단 x를 넣어둔다
    for (int i = 1; i <= n; i++) {
        result += p[i] * temp; //i=1일때 우선 a0x부터 시작하여, i가 증가함에 따라 x의 차수도 하나씩 증가하게 만든다
        temp *= x; // temp에 x^i 값을 누적
    }
    return result;
}


double add(double f[], double g[], double h[], int n) 
{
    for (int i = 0; i <= n; i++) {
        f[i] = g[i] + h[i];
    }
    return f[n];
}
