#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* My_strcat(char* dest, const char* src) {
	char* rst = dest;
	while (*dest) {
		dest++;
	}
	
	while (*dest++ = *src++) {
		;
	}
	return rst;
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "bit";
	My_strcat(arr1, arr2);
	printf("%s", arr1);
}
