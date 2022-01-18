#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//乘法口诀
void multiplication(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%d ", j, i, i * j);
		}
		printf("\n");
	}
}
int main()
{
	multiplication(12);
}
//交换两个整数
void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int main4()
{
	int x = 2;
	int y = 3;
	swap(&x,&y);
	printf("%d %d", x, y);
	return 0;
}
//判断闰年
int is_runyear(int year)
{
	if ((year % 4 == 0) && (year % 100 != 0) || year % 400 == 0)
		return 1;
	else
		return 0;
}
int main3()
{
	int a = 0;
	scanf("%d", &a);
	if (is_runyear == 1) {
		printf("是闰年");
	}
	else {
		printf("不是闰年");
	}
	return 0;
}
//判断素数
void is_prime(int n)
{
	int i = 0;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			break;
		}
	}
	if (i > sqrt(n)) {
		printf("%d ", n);
	}
}
int main2()
{
	int j = 0;
	for (j = 100; j <= 200; j++) {
		is_prime(j);
	}
	return 0;
}

int main1()
{
	/*char a = '\8';
	printf("%d\n", a);
	int y[5 + 3] = { 0, 1, 3, 5, 7, 9 };
	printf("%d", y);*/
	int b;
	char c[10];
	scanf("%d%s", &b, c);
	printf("%d,%s", b, c);
	return 0;
}