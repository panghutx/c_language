#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
char* My_strcpy(char* des, char* src) {
	char* rst = des;
	while (*src) {
		*des = *src;
		des++;
		src++;
	}
	*des = *src;
	return rst;
}
char* My_strcpy1(char* des, char* src) {
	char* rst = des;
	while (*des++ = *src++) {
		;
	}
	return rst;
}
int main()
{
	char arr1[] = "abcdef";
	char arr2[20];
	printf("%s",My_strcpy(arr2, arr1));
}
