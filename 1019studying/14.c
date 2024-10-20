#include <stdio.h>

int sum(int x, int y)
{
	int result;
	result = x + y;
	return result;

}



int main(void)
{
	int answer =0;
	answer = sum(3,4);
	printf("%d \n", answer);

	return 0;
}
