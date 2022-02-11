#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <math.h>
int main()
{
	//char a = "*";
	//int i = 0;
	//for (i = 0; i < 7; i++)
	//{
	//	int j = 0;
	//	for (j = 0; j < 13; j += 2)
	//	{
	//		printf("%s", a * j);
	//	}
	//}
	char arr1[] = "***********";
	char arr2[] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', };
	
}
int main2()
{
	//打印水仙花数
	
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//1.判断位数
		int count = 0;
		int sum = 0;
		int tmp = i;
		while (tmp) {
			count++;
			tmp = tmp / 10;
		}
		//水仙花
		tmp = i;
		while (tmp) {
			sum += pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		if (sum == i) {
			printf("%d\n", i);
		}
		
	}
}
int sum(int n)
{
	int sum = 0;
	int i = 0;
	int rst = 0;
	for (i = 0; i < 5; i++)
	{
		rst = rst+ (n * pow(10,i));
		sum += rst;
	}
	return sum;
}
int main1()
{
	//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
	//例如：2 + 22 + 222 + 2222 + 22222
	int n = 0;
	scanf("%d", &n);
	printf("%d", sum(n));
}