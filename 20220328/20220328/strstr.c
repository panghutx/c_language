#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

const char* My_strstr(const char* str1, const char* str2) {
	const char* ps1 = str1;
	const char* ps2 = str2;
	const char* cur = str1;
	while (*ps1) {
		
		while (*ps1 == *ps2 && *ps1 && *ps2) {
			ps1++;
			ps2++;
		}
		if (*ps2 == '\0') {
			return cur;
		}
		cur++;
		ps1 = cur;
		ps2 = str2;
		
	}
	return NULL;
}
int main()
{
	char arr1[] = "abcdeqabcdef";
	char arr2[] = "def";
	printf("%s", My_strstr(arr1, arr2));
}
