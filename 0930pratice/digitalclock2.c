#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int main(void)
{
	int sec = 0;
 	while (sec<100) {
	system("clear"); // 화면을 지운다.
	printf("%02d \n", sec);
	sec++;
	sleep(1); // 1초 동안 프로그램을 재운다.
}

 return 0;

 
}

