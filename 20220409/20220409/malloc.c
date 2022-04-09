#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int* p =(int*)malloc(10); //动态开辟10字节的空间
	if (p == NULL) { //判断是否开辟成功
		perror("malloc");
		return;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	free(p); //释放p空间
	return 0;
}