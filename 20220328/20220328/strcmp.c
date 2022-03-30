#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int My_strcmp(const char* str1, const char* str2) {
	while (*str1 == *str2) {
		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
	}
	if (*str1 > *str2) {
		return 1;
	}
	else{
		return -1;
	}
}
int main()
{
	char arr1[] = "hello";
	char arr2[] = "hello";
	printf("%d", My_strcmp(arr1, arr2));
}
