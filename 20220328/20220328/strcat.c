#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
char* My_strcat(char* des, char* src) {
	char* ret = des;
	//�ҵ�des��'\0'
	while (*des) {
		des++;
	}
	//�ַ�������
	while (*des++ = *src++) {
		;
	}
	return ret;
}
int main()
{
	char arr1[20] = "hello ";
	char arr2[] = "panghu";
	printf("%s",My_strcat(arr1, arr2));
}