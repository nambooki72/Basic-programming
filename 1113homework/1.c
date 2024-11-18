#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>




#define ROWS 10
#define COLS 5
#define MAX_NUMBER 101 //난수를 0부터 100까지 생성하기 위하여 101로 설정한다




// 각종 함수들을 선언한다
void initializeArray(int arr[ROWS][COLS]);//a
void printArray(int arr[ROWS][COLS]);//b
int isPrime(int n);//c
int isDuplicate(int arr[ROWS][COLS], int value);//d
void multiplyByIndex(int arrROWS[][COLS], int result[ROWS][COLS]);//e
void doublePrimes(int arr[ROWS][COLS], int result[ROWS][COLS]);//f
void displayMenu(void);//g




int main() {
    int array[ROWS][COLS];
    int result[ROWS][COLS];
    int choice;
    
    srand(time(NULL));
    
    do {
        displayMenu();
        printf("Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                initializeArray(array);
                printf("Initialized array:\n");
                printArray(array);
                break;
                
            case 2:
                multiplyByIndex(array, result);
                printf("New array (elements multiplied by index):\n");
                printArray(result);
                break;
                
            case 3:
                doublePrimes(array, result);
                printf("New array (prime elements doubled):\n");
                printArray(result);
                break;
                
            case 9:
                printf("Exiting the program.\n");
                break;
                
            default://1239 외에 다른 수 입력할 경우 오류 출력
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 9);
    
    return 0;
}



void displayMenu(void) {
    printf("======================================================================\n");
    printf("Select a menu option:\n");
    printf("1. Initialize array - initialize the array with unique random numbers.\n");
    printf("2. Multiply by index - create a new array by multiplying each element by its index.\n");
    printf("3. Double prime values - double the values of prime numbers in the array.\n");
    printf("9. Exit - terminate the program.\n");
    printf("======================================================================\n");
}




void initializeArray(int arr[ROWS][COLS]) 
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int num;
            do {
                num = rand() % (MAX_NUMBER); //max number를 100이 아니라 101로 설정하여 0도 출력하게 만든다 
            } while(isDuplicate(arr, num));
            arr[i][j] = num;
        }
    }
}




void printArray(int arr[ROWS][COLS]) 
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%5d ", arr[i][j]); //적당히 오른쪽 정렬
        }
        printf("\n");
    }
    printf("\n");
}




int isPrime(int n) 
{
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    
    for(int i = 3; i <= n; i += 2) { //i가 홀수일 때만 확인하고 최대 n까지만 확인한다
        if(n % i == 0) return 0;
    }
    return 1;
}



int isDuplicate(int arr[ROWS][COLS], int value) 
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(arr[i][j] == value) return 1;
        }
    }
    return 0;
}




void multiplyByIndex(int arr[ROWS][COLS], int result[ROWS][COLS]) 
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            result[i][j] = arr[i][j] * (i * COLS + j);//2차원 배열에서 선형 인덱스는 행번호 x 열번호 + 열번호 임을 이용한다 실제 배열은 0부터 시작한다는 점에 주의하여 번호를 계산한다
        }
    }
}




void doublePrimes(int arr[ROWS][COLS], int result[ROWS][COLS]) 
{
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(isPrime(arr[i][j])) {
                result[i][j] = arr[i][j] * 2;
            } else {
                result[i][j] = arr[i][j];
            }
        }
    }
}
