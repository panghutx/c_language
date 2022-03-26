#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
char* My_strstr(char* s1, char* s2) {
	char* ss1 = s1;
	char* ss2 = s2;
	char* cur = s1;
	while (*ss1) {
		
		ss1 = cur;
		while(*ss1==*ss2 && *ss2 &&*ss1 ){
			
			ss1++;
			ss2++;
		}
		if (*ss2 == '\0') {
			return cur;
		}
		cur++;
		ss2 = s2;
	}
	return NULL;
	
	
}
int main()
{
	char arr1[] = "cdefbcdef";
	char arr2[] = "cdef";
	//返回子串在主串位置的首地址
	printf("%s", My_strstr(arr1, arr2));
}
