#include <stdio.h>


int get_length(char *str);
int is_alpha(char c);
char to_lower(char c);
int check_palindrome_array(char str[]);
int check_palindrome_pointer(char *str);




int main(void)
{


    	char str[100];//문자열 길이 최대 100으로 설정한다
    	printf("Input: ");

	int i = 0;
	char c;
	while ((c = getchar()) != '\n' && i < 99) { //getchar를 활용하여 c에 문자를 일일이 저장하고, str[] 배열에 넣어준다
    	str[i++] = c;
	}
	str[i] = '\0';
    

    	if(check_palindrome_array(str))
        	printf("Answer(array) : \"%s\" is a palindrome.\n", str);
    	else
        	printf("Answer(array) : \"%s\" is not a palindrome.\n", str);
    
    	if(check_palindrome_pointer(str))
        	printf("Answer(pointer) : \"%s\" is a palindrome.\n", str);
    	else
        	printf("Answer(pointer) : \"%s\" is not a palindrome.\n", str);
    



	return 0;
}



int get_length(char *str) { //문자열 길이를 측정하는 함수 널 문자가 올때까지 센다
    	int len = 0;
    	
	while (str[len] != '\0') {
        	len++;
    	}
    
	return len;
}


// 알파벳인지 확인하는 함수 a부터 z까지와, A부터 Z까지
int is_alpha(char c) {
    	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}



// 대문자를 소문자로 변환하는 함수
char to_lower(char c) {
    	if (c >= 'A' && c <= 'Z') {
        	return c + ('a' - 'A'); // 97 - 65 = 32
    	}
    
	return c;
}



// 배열을 사용한 팰린드롬 검사
int check_palindrome_array(char str[]) {
    	int len = get_length(str);
    	char cleaned[100];
    	int j = 0;

    	// 알파벳만 추출하여 소문자로 저장. 위에서 문자열 길이를 측정하는 함수가 있으나, 여기서는 문자열 중에서 알파벳만 선택적으로 개수를 센다
    	for(int i = 0; i < len; i++) {
        	if(is_alpha(str[i])) {
            	cleaned[j] = to_lower(str[i]);
            	j++;
        	}
    	}
    	cleaned[j] = '\0'; //다 끝나면 끝에 null문자를 넣어서 마무리를 짓는다


    	// 팰린드롬 검사
    	for(int i = 0; i < j/2; i++) {
        	if(cleaned[i] != cleaned[j-1-i]) {
            	return 0; //중간에 불일치를 발견할 경우 함수를 즉시 종료
        	}
    	}
    	return 1;//위의 조건을 만족할 경우 팰린드롬이라고 판정
}



// 포인터를 사용한 팰린드롬 검사
	int check_palindrome_pointer(char *str) {
    	int len = get_length(str);
    	char cleaned[100];
    	char *ptr = cleaned;

    	// 알파벳만 추출하여 소문자로 저장
    	while (*str != '\0') {
        	if(is_alpha(*str)) {
            	*ptr = to_lower(*str);
            	ptr++;
        	}
        	str++;
    	}
    	*ptr = '\0';


    	// 팰린드롬 검사
    	char *start = cleaned;
    	char *end = ptr - 1;

    	while(start < end) {
        	if(*start != *end) {
            	return 0; //마찬가지로 다를 경우 즉시 종료
        	}
        	start++;
        	end--;
    	}
    	return 1; //위의 조건에서 살아남으면 팰린드롬 판정
}


