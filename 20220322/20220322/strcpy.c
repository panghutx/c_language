#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
//ģ��ʵ��strcpy
//����һ
char* My_strcpy1(char* des, const char* src) {
	char* rst = des;
	while (*src) {
		*des = *src;
		des++;
		src++;
	}
	*des = *src;
	return rst;
	
}
//�Ľ�
char* My_strcpy(char* des, const char* src) {
	assert(des && src);
	char* str = des;
	while (*des++=*src++) {
		;
	}
	return str;

}
int main()
{
	char arr1[20] = { 0 };
	char arr2[] = "panghu";
	printf("%s",My_strcpy(arr1, arr2));
	

}
