#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

char* My_strncat(char* dest, const char* src, size_t n) {
	//�ҵ�dest��0
	char* rst = dest;
	while (*dest) {
		dest++;
	}
	//�ҵ���
	while (n!=0) {
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	return rst;
}
int main()
{
	char arr1[20] = "hello";
	char arr2[] = "panghu";
	
	printf("%s", My_strncat(arr1, arr2, 3));
}
