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
	//��ӡˮ�ɻ���
	
	int i = 0;
	for (i = 0; i <= 100000; i++)
	{
		//1.�ж�λ��
		int count = 0;
		int sum = 0;
		int tmp = i;
		while (tmp) {
			count++;
			tmp = tmp / 10;
		}
		//ˮ�ɻ�
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
	//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
	//���磺2 + 22 + 222 + 2222 + 22222
	int n = 0;
	scanf("%d", &n);
	printf("%d", sum(n));
}