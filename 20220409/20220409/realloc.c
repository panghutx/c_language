#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)malloc(40); //动态开辟10字节的空间
	if (p == NULL) { //判断是否开辟成功
		perror("malloc");
		return;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	//扩容
	int* tmp=(int*)realloc(p, 80);
	if (tmp != NULL) { //判断是否扩容成功
		p = tmp;
	}
	for (int i = 10; i < 20; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	free(p);
	return 0;
}