#include <stdio.h>

// 함수 원형 선언 - 포인터 표기법 사용
void add_matrix(int (*A)[10], int (*B)[10], int (*result)[10], int n);
int get_diagonal_sum(int (*matrix)[10], int n);
int is_sparse_matrix(int (*matrix)[10], int n);

int main(void) {
    	int N;
    	int check;
    
    	printf("[Input]\n");
    	//N 입력값 검증
    	while(1) {
        	check = scanf("%d", &N);
        		if(check != 1) {
            			printf("Invalid input. Please enter a number: ");
            			while(getchar() != '\n');
            			continue;
        		}

        		if(N >= 2 && N <= 10) {
           		break;
        		}
        	
			printf("N must be between 2 and 10. Please enter again: ");
    			}
    
    	int A[10][10] = {0}, B[10][10] = {0}, result[10][10] = {0};
    
    	// A 행렬 입력
    	for(int i = 0; i < N; i++) {
        	for(int j = 0; j < N; j++) {
            	while(1) {
                	check = scanf("%d", &A[i][j]);
                		if(check != 1) {
                    			printf("Invalid input. Please enter a number for A[%d][%d]: ", i, j);
                    			while(getchar() != '\n');
                    			continue;
                		}
                
				if(A[i][j] >= -100 && A[i][j] <= 100) {
                    			break;
                	}
                
				printf("Element must be between -100 and 100. Please enter again for A[%d][%d]: ", i, j);
            		}
        	}
    	}
    
    	// B 행렬 입력
    	for(int i = 0; i < N; i++) {
        	for(int j = 0; j < N; j++) {
            		while(1) {
                		check = scanf("%d", &B[i][j]);
                			if(check != 1) {
                    				printf("Invalid input. Please enter a number for B[%d][%d]: ", i, j);
                    				while(getchar() != '\n');
                    				continue;
                				}
                
					if(B[i][j] >= -100 && B[i][j] <= 100) {
                    				break;
                				}
                
					printf("Element must be between -100 and 100. Please enter again for B[%d][%d]: ", i, j);
            			}
        		}
    		}
    
    	// 행렬 덧셈, 대각합 계산, 희소행렬 판별
   	printf("[Output]\n");
    	add_matrix(A, B, result, N);
    
    
	// 결과 행렬 출력
    	for(int i = 0; i < N; i++) {
        	for(int j = 0; j < N; j++) {
            		printf("%d ", result[i][j]);
        	}
        	printf("\n");
    	}
    
    	printf("%d\n", get_diagonal_sum(result, N));
    
    	printf("A: %s, B: %s\n", 
           	is_sparse_matrix(A, N) ? "sparse matrix" : "not a sparse matrix",
           	is_sparse_matrix(B, N) ? "sparse matrix" : "not a sparse matrix");
    
    	return 0;
}

// 행렬 덧셈 함수
void add_matrix(int (*A)[10], int (*B)[10], int (*result)[10], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// 대각원소 합 계산 함수
int get_diagonal_sum(int (*matrix)[10], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// 희소행렬 판별 함수
int is_sparse_matrix(int (*matrix)[10], int n) {
    int zero_count = 0;
    int total_elements = n * n;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 0) {
                zero_count++;
            }
        }
    }
    
    return zero_count >= total_elements/2;
}
