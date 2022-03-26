#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
int My_strcmp(const char* str1, const char* str2) {
	assert(str1 && str2);
	while (*str1 == *str2) {

		if (*str1 == '\0') {
			return 0;
		}
		str1++;
		str2++;
		
	}
	if (*str1 > *str2)
		return 1;
	else
		return -1;
}
int main()
{
	char arr1[] = "helloa";
	char arr2[] = "hellob";
	printf("%d",My_strcmp(arr1, arr2));
	//如果前者大于后者，返回1；等于返回0；小于返回-1
}