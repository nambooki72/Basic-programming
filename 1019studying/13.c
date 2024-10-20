#include <stdio.h>
int main(void)
{
int start_h, start_m; // 시작 시간을 저장할 변수
 int free_time; // 자유 시간을 저장할 변수
int end_h, end_m; // 귀환 시간을 저장할 변수
 printf("현재 시각을 입력하세요(시 분): "); // 시작 시각과 자유 시간을
입력받음
 scanf("%d %d", &start_h, &start_m);
printf("자유 시간을 입력하세요(분): ");
 scanf("%d", &free_time);
 end_h = start_h; // 자유 시간이 끝나는 시각을 계산함
 end_m = start_m + free_time;
 if (end_m >= 60) {
end_h += end_m / 60;
end_m = end_m % 60;
}
// 결과를 출력함
 printf("귀환 시각은 %02d %02d입니다.", end_h, end_m);
 return 0;
}
