#define _CRT_SECURE_NO_WARNINGS 1
void buma()
{
	int n = 0;
	int arr[32] = { 0 };
	printf("请输入一个整型\n");
	scanf("%d", &n);
	int i = 0;
	int j = 31;
	for (i = 0; i <=31; i++) {
		arr[j] = (n >> i) & 1;
		if (j >= 0)
			j--;
	}
	for (i = 0; i <= 31; i++) {
		printf("%d", arr[i]);
	}
}
#include<stdio.h>
int main()
{
	buma();
}