#include <stdio.h>


int main(void)
{

	char a;
	char b;


	printf("대문자를 입력하세요 :");
	scanf(" %c", &a); //입력버퍼? 어떻게 해야 asci랑 a변수에 둘 다 넣을
	//a에 32를 더해야 한다 그래야 소문자로 바뀐다
	printf("입력한 문자 : %c\n", a );
	
	a += 32;

	printf("소문자로 입니다. %c \n\n", a);

	
	printf("소문자를 입력하세요 :");
	scanf(" %c", &b);
	printf("입력한 문자 : %c\n", b );

	b -= 32;

	printf("대문자로 %c입니다.", b);







	return 0;

}
