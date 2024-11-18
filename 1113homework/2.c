#include <stdio.h>




#define MAX_SIZE 10




// 함수 선언부
int inputImageSize();            // 이미지 크기 입력받는 함수
void inputImageData(char image[MAX_SIZE][MAX_SIZE], int size);             // 이미지 데이터 입력받는 함수
void printImage(char image[MAX_SIZE][MAX_SIZE], int size);                 // 일반 이미지 출력 함수
void printImage45(char image[2 * MAX_SIZE - 1][2 * MAX_SIZE - 1], int size); // 45도 회전된 이미지 출력 함수
void rotate90(char original[MAX_SIZE][MAX_SIZE], char rotated90[MAX_SIZE][MAX_SIZE], int size);   // 90도 회전 함수
void rotate270(char original[MAX_SIZE][MAX_SIZE], char rotated270[MAX_SIZE][MAX_SIZE], int size);  // 270도 회전 함수
void rotate45(char original[MAX_SIZE][MAX_SIZE], char rotated45[2 * MAX_SIZE - 1][2 * MAX_SIZE - 1], int size);  // 45도 회전 함수
void displayMenu();              // 메뉴 출력 함수




int main() {
    // 필요한 배열들 선언
    char image[MAX_SIZE][MAX_SIZE];                               // 원본 이미지 저장 배열
    char rotated90[MAX_SIZE][MAX_SIZE];                          // 90도 회전 이미지 저장 배열
    char rotated270[MAX_SIZE][MAX_SIZE];                         // 270도 회전 이미지 저장 배열
    char rotated45[2 * MAX_SIZE - 1][2 * MAX_SIZE - 1];         // 45도 회전 이미지 저장 배열
    int size = 0;   // 이미지 크기
    int choice;     // 메뉴 선택 변수

    do {
        displayMenu();
        printf("Select the desired operation: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                size = inputImageSize();  // 이미지 크기 입력받기
                inputImageData(image, size);
                printf("Original Image:\n");
                printImage(image, size);
                break;

            case 2:
                rotate90(image, rotated90, size);
                printf("90-Degree Rotated Image:\n");
                printImage(rotated90, size);
                break;

            case 3:
                rotate270(image, rotated270, size);
                printf("270-Degree (or Counterclockwise 90-Degree) Rotated Image:\n");
                printImage(rotated270, size);
                break;

            case 4:
                rotate45(image, rotated45, size);
                printf("45-Degree Rotated Image:\n");
                printImage45(rotated45, size);
                break;

            case 9:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid selection. Please try again.\n");
        }
    } while(choice != 9);

    return 0;
}




// 함수 정의부
void displayMenu() {
    printf("=========================================\n");
    printf("Image Rotation Program\n");
    printf("=========================================\n");
    printf("1. Enter Image Size\n");
    printf("2. Rotate 90 Degrees\n");
    printf("3. Rotate 270 Degrees (or Counterclockwise 90 Degrees)\n");
    printf("4. Rotate 45 Degrees\n");
    printf("9. Exit Program\n");
    printf("=========================================\n");
}




int inputImageSize() {
    int size;
    do {
        printf("Enter the size NxN of the image (Maximum: %d, Minimum: 2): ", MAX_SIZE);
        scanf("%d", &size);
        if(size < 2 || size > MAX_SIZE) {
            printf("Invalid input. Enter a value between 2 and %d.\n", MAX_SIZE);
        }
    } while(size < 2 || size > MAX_SIZE);
    return size;
}




void inputImageData(char image[MAX_SIZE][MAX_SIZE], int size) {
    printf("Enter the image data (%d x %d size, filled with characters):\n", size, size);
    char c;
    scanf("%c", &c); // 개행문자 처리
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            scanf("%c", &image[i][j]);
            if(image[i][j] == ' ' || image[i][j] == '\n') {
                j--;    // 공백이나 개행문자는 무시하고 다시 입력받기
                continue;
            }
        }
    }
}




void printImage(char image[MAX_SIZE][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }
}




void rotate90(char original[MAX_SIZE][MAX_SIZE], char rotated90[MAX_SIZE][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            rotated90[j][size-1-i] = original[i][j];
        }
    }
}




void rotate270(char original[MAX_SIZE][MAX_SIZE], char rotated270[MAX_SIZE][MAX_SIZE], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            rotated270[size-1-j][i] = original[i][j]; //270도 회전은 반대 방향으로 90도 회전과 동일하므로 90도 회전 알고리즘의 순서만 살짝 변형하면 된다 
        }
    }
}




void rotate45(char original[MAX_SIZE][MAX_SIZE], char rotated45[2 * MAX_SIZE - 1][2 * MAX_SIZE - 1], int size) {
    // 회전된 배열을 공백으로 초기화
    for(int i = 0; i < 2*size-1; i++) {
        for(int j = 0; j < 2*size-1; j++) {
            rotated45[i][j] = ' ';
        }
    }
    
    // 45도 회전
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            rotated45[i+j][size-1-i+j] = original[i][j]; //45도 회전은 해당 공식대로 위치한다는 것을 유념해두자 
        }
    }
}




void printImage45(char image[2 * MAX_SIZE - 1][2 * MAX_SIZE - 1], int size) {
    for(int i = 0; i < 2*size-1; i++) {
        for(int j = 0; j < 2*size-1; j++) {
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }
}




/*
문제에서는 회전과 출력을 따로 함수로 구현하였기에 간단하고 직관적으로 출력 순서를 바꾸어서 곧장 회전시키는 방법을 쓸 수 없었다
 만약 함수를 분리해야 한다는 조건이 없었다면


void rotate90(char image[MAX_SIZE][MAX_SIZE], int size) {
    // 90도 회전하여 출력: 열을 먼저 고정하고, 행을 거꾸로 읽기
    for(int j = 0; j < size; j++) {
        for(int i = size-1; i >= 0; i--) {
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }
}

void rotate270(char image[MAX_SIZE][MAX_SIZE], int size) {
    // 270도 회전하여 출력: 열을 거꾸로 고정하고, 행을 순서대로 읽기
    for(int j = size-1; j >= 0; j--) {
        for(int i = 0; i < size; i++) {
            printf("%c ", image[i][j]);
        }
        printf("\n");
    }
}

void rotate45(char image[MAX_SIZE][MAX_SIZE], int size) {
    // 45도 회전의 경우는 좀 더 복잡함
    // 각 대각선 방향으로 출력
    for(int sum = 0; sum < size*2-1; sum++) {
        for(int i = 0; i < size; i++) {
            int j = sum - i;
            if(j >= 0 && j < size) {
                printf("%c ", image[i][j]);
            }
        }
        printf("\n");
    }
}
들과 같이 더욱 간단하게 구현할 수 있다



혹은 이러한 접근도 가능하다
임시 버퍼를 생성하여 회전 출력값을 간단하게 임시 버퍼에 집어넣은 이후 새로 선언한 배열에 집어넣는 방식으로 할 수도 있다

void rotate90(char original[MAX_SIZE][MAX_SIZE], char rotated[MAX_SIZE][MAX_SIZE], int size) {
    // 임시 출력 버퍼
    char temp[MAX_SIZE][MAX_SIZE];

    // 회전된 형태로 읽어서 임시 버퍼에 저장
    for(int j = 0; j < size; j++) {
        for(int i = size-1; i >= 0; i--) {
            temp[j][size-1-i] = original[i][j];
        }
    }

    // 임시 버퍼의 값을 rotated 배열로 복사
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            rotated[i][j] = temp[i][j];
        }
    }
}




교수님 추가 공지사항

2번 문제 풀이 시 회전함수는 다음과 같이 작성하시면 됩니다.

- 회전함수(입력배열, 결과배열) => 결과배열에 회전된 배열이 기록된다.



또한, 45도 회전함수의 결과배열 크기는 2 * MAX_SIZE - 1 라는 것은 첨부파일의 예제를 참고하세요.



max_size를 입력받아서 행렬 선언하도록 하여도 컴파일 가능하니, 이대로 진행하시면 됩니다.

예) int max_size;  scanf("%d", &max_size); int arr[max_size]; 

위와 같이 하시면 됩니다.

혹은 애초에 max_size = 10으로 설정 후 사용자 크기에 따라 잘 조정하셔서 예시 입력에 맡게 생성되도록 하셔도 됩니다.



*/

