#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* My_strncpy(char* dest, const char* src, size_t num) {
	char* rst = dest;
	while (num--) {
		*dest++ = *src++;
	}
	return rst;
}
int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "panghutx";
	printf("%s",My_strncpy(arr1, arr2,6));
}
