#include <stdio.h>




#define NUM_STUDENTS 5
#define NUM_SUBJECTS 3
#define NAME_LENGTH 20





void calcTotalAvg(int scores[NUM_STUDENTS][NUM_SUBJECTS], 
                 double totals[NUM_STUDENTS], 
                 double avgs[NUM_STUDENTS], 
                 int maxs[NUM_STUDENTS], 
                 int mins[NUM_STUDENTS]);
void calcSubAvgMax(int scores[NUM_STUDENTS][NUM_SUBJECTS], 
                  double subAvgs[NUM_SUBJECTS], 
                  int subMaxs[NUM_SUBJECTS]);
void assignGrade(double avgs[NUM_STUDENTS], 
                char grades[NUM_STUDENTS]);
void calcRank(double avgs[NUM_STUDENTS], 
             int ranks[NUM_STUDENTS]);
void printScore(char names[NUM_STUDENTS][NAME_LENGTH], 
               char subjects[NUM_SUBJECTS][NAME_LENGTH], 
               int scores[NUM_STUDENTS][NUM_SUBJECTS], 
               double totals[NUM_STUDENTS], 
               double avgs[NUM_STUDENTS], 
               char grades[NUM_STUDENTS], 
               int ranks[NUM_STUDENTS]);
void printSubAvgMax(char subjects[NUM_SUBJECTS][NAME_LENGTH], 
                   double subAvgs[NUM_SUBJECTS], 
                   int subMaxs[NUM_SUBJECTS]);
void printHist(char names[NUM_STUDENTS][NAME_LENGTH], 
              char subjects[NUM_SUBJECTS][NAME_LENGTH], 
              int scores[NUM_STUDENTS][NUM_SUBJECTS]);




int main() {
    // 2차원 배열로 학생과 성적 선언 각 열에 알파벳과 공백 문자를 저장
    char names[NUM_STUDENTS][NAME_LENGTH] = {
        "Dongguk Kim", "Goryeo Park", "Yonsei Lee", "Seoul Yoon", "Ihwa Hong"
    };
    char subjects[NUM_SUBJECTS][NAME_LENGTH] = {
        "Algorithm", "Python", "C Language"
    };
    
    
    
    int scores[NUM_STUDENTS][NUM_SUBJECTS];
    double totals[NUM_STUDENTS] = {0};
    double avgs[NUM_STUDENTS] = {0};
    int maxs[NUM_STUDENTS];
    int mins[NUM_STUDENTS];//최대와 최소 함수에서 어차피 실행 전에 각각 숫자로 초기화를 하므로 여기서는 배열 선언만 하고 넘어간다
    char grades[NUM_STUDENTS];
    int ranks[NUM_STUDENTS];
    double subAvgs[NUM_SUBJECTS] = {0};
    int subMaxs[NUM_SUBJECTS] = {0};



    // 성적 입력
    for(int i = 0; i < NUM_STUDENTS; i++) {
        printf("Enter the scores for student %s (Student %d):\n", names[i], i+1); //문자들이 입력된 행 하나를 전체 출력할 때 문자열 %s를 써야한다
        for(int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%s: ", subjects[j]);
            scanf("%d", &scores[i][j]);
        }
	printf("\n");

    }
    
    /*
    printf("Enter the scores for student ");
    
    for(int j = 0; j < NAME_LENGTH; j++) 
    {
      if(names[i][j] == '\0') break;  // null 문자 만나면 종료
      printf("%c", names[i][j]);
    }
    printf(" (Student %d):\n", i+1); //배열은 항상 0부터 시작한다는 점을 주의하도록 하자
    
    위와 같은 방식으로 문자열을 한번에 출력하는 것이 아니라 for문을 사용하여 각 행의 열을 차례로 출력하고, null문자에서 멈추도록 할 수도 있다
    
    */
    
    

    // 모든 계산 수행
    calcTotalAvg(scores, totals, avgs, maxs, mins);
    calcSubAvgMax(scores, subAvgs, subMaxs);
    assignGrade(avgs, grades);
    calcRank(avgs, ranks);



    // 결과 출력
    printf("\nScore Report for Each Student:\n");
    printScore(names, subjects, scores, totals, avgs, grades, ranks);
    
    printf("\nAverage and Highest Scores for Each Subject:\n");
    printSubAvgMax(subjects, subAvgs, subMaxs);
    
    printf("\nScore Histograms for Each Student:\n");
    printHist(names, subjects, scores);



    return 0;
}



// 함수 정의부
void calcTotalAvg(int scores[NUM_STUDENTS][NUM_SUBJECTS], 
                 double totals[NUM_STUDENTS], 
                 double avgs[NUM_STUDENTS], 
                 int maxs[NUM_STUDENTS], 
                 int mins[NUM_STUDENTS]) {
    for(int i = 0; i < NUM_STUDENTS; i++) {
        totals[i] = 0;
        maxs[i] = 0;
        mins[i] = 100;
        
        for(int j = 0; j < NUM_SUBJECTS; j++) {
            totals[i] += scores[i][j]; //총점 합하기 
            if(scores[i][j] > maxs[i]) maxs[i] = scores[i][j]; //각각 최대 최소 확인하며 교체하기
            if(scores[i][j] < mins[i]) mins[i] = scores[i][j];
        }
        
        avgs[i] = totals[i] / NUM_SUBJECTS;
    }
}




void calcSubAvgMax(int scores[NUM_STUDENTS][NUM_SUBJECTS], 
                  double subAvgs[NUM_SUBJECTS], 
                  int subMaxs[NUM_SUBJECTS]) {
    for(int j = 0; j < NUM_SUBJECTS; j++) {
        subAvgs[j] = 0;
        subMaxs[j] = 0;
        
        for(int i = 0; i < NUM_STUDENTS; i++) {
            subAvgs[j] += scores[i][j]; //평균을 구하기 전에 총점을 합쳐주
            if(scores[i][j] > subMaxs[j]) subMaxs[j] = scores[i][j]; //각 기과목 최대값 찾기
        }
        
        subAvgs[j] /= NUM_STUDENTS; //일반적으로 이중 for문으로 배열을 입력하거나 출력하는데, 각 학생의 과목 점수를 계산하므로 j 열을 우선 돌리는 것에 주의한다
    }
}




void assignGrade(double avgs[NUM_STUDENTS], 
                char grades[NUM_STUDENTS]) {
    for(int i = 0; i < NUM_STUDENTS; i++) {
        if(avgs[i] >= 90) grades[i] = 'A';
        else if(avgs[i] >= 80) grades[i] = 'B';
        else if(avgs[i] >= 70) grades[i] = 'C';
        else if(avgs[i] >= 60) grades[i] = 'D';
        else grades[i] = 'F';
    }
}




void calcRank(double avgs[NUM_STUDENTS], 
             int ranks[NUM_STUDENTS]) {
    for(int i = 0; i < NUM_STUDENTS; i++) {
        ranks[i] = 1;
        for(int j = 0; j < NUM_STUDENTS; j++) {
            if(avgs[j] > avgs[i]) ranks[i]++; //자신보다 높은 점수의 학생이 존재하면 나의 순위는 1씩 증가(순위가 내려감)
        }
    }
}




void printScore(char names[NUM_STUDENTS][NAME_LENGTH], 
               char subjects[NUM_SUBJECTS][NAME_LENGTH], 
               int scores[NUM_STUDENTS][NUM_SUBJECTS], 
               double totals[NUM_STUDENTS], 
               double avgs[NUM_STUDENTS], 
               char grades[NUM_STUDENTS], 
               int ranks[NUM_STUDENTS]) {
    printf("======================================================================\n");
    printf("Name         Algorithm Python C Language Total Average Grade Rank\n"); 
    printf("======================================================================\n");
    
    for(int i = 0; i < NUM_STUDENTS; i++) {
        printf("%-12s %9d %6d %10d %5.0f %7.2f %5c %4d\n", //이름의 왼쪽 정렬, 이후 과목 이름의 글자수를 고려하여 각 점수 출력에 공백 크기 할당
               names[i], scores[i][0], scores[i][1], scores[i][2],
               totals[i], avgs[i], grades[i], ranks[i]);
    }
    printf("======================================================================\n");
}





void printSubAvgMax(char subjects[NUM_SUBJECTS][NAME_LENGTH], 
                   double subAvgs[NUM_SUBJECTS], 
                   int subMaxs[NUM_SUBJECTS]) {
    printf("---------------------------------------------------------------------------------------\n");
    for(int i = 0; i < NUM_SUBJECTS; i++) {
        printf("%s Average: %.2f, Highest Score: %d\n", 
               subjects[i], subAvgs[i], subMaxs[i]);
    }
    printf("---------------------------------------------------------------------------------------\n");
}





void printHist(char names[NUM_STUDENTS][NAME_LENGTH], 
              char subjects[NUM_SUBJECTS][NAME_LENGTH], 
              int scores[NUM_STUDENTS][NUM_SUBJECTS]) {
    for(int i = 0; i < NUM_STUDENTS; i++) {
        printf("\nGrade Histogram of Student %d:\n", i+1);
        for(int j = 0; j < NUM_SUBJECTS; j++) {
            printf("%s : ", subjects[j]);
            for(int k = 0; k < scores[i][j]/10; k++) {
                printf("*"); //점수를 10으로 나눈 이후 그만큼이 비례하여 별을 반복해서 출력해준다
            }
            printf(" (%d)\n", scores[i][j]);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    }
}
