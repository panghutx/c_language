#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int* p =(int*)malloc(10); //��̬����10�ֽڵĿռ�
	if (p == NULL) { //�ж��Ƿ񿪱ٳɹ�
		perror("malloc");
		return;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	free(p); //�ͷ�p�ռ�
	return 0;
}