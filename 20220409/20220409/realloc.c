#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)malloc(40); //��̬����10�ֽڵĿռ�
	if (p == NULL) { //�ж��Ƿ񿪱ٳɹ�
		perror("malloc");
		return;
	}
	for (int i = 0; i < 10; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	//����
	int* tmp=(int*)realloc(p, 80);
	if (tmp != NULL) { //�ж��Ƿ����ݳɹ�
		p = tmp;
	}
	for (int i = 10; i < 20; i++) {
		*(p + i) = i;
		printf("%d ", *(p + i));
	}
	free(p);
	return 0;
}