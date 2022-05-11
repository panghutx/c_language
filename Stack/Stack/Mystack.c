#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include< ctype.h >
#include"Mystacl.h"
#define MAX 100
int main()
{
	char arr[MAX] = { 0 };
	printf("输入表达式:\n");
	gets(arr);
	for (int i = 0; i < strlen(arr); i++) {
		if (isdight((int)arr[i])) {

		}
	}

	
	
}
