int main(void) {
 float x, y;
 int points;
printf("다트의 x, y 좌표를 입력하시오: ");
 scanf("%f %f", &x, &y);
float distance = sqrt(x * x + y * y);
 if (distance > 10) {
 points = 0;
}
 else if (distance > 5) {
 points = 1;
}
 else if (distance > 1) {
 points = 5;
}
 else {
 points = 10;
}
 printf("획득한 점수: %d\n", points);
 return 0;
}
