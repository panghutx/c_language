#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[20] = {0};
	system("shutdown -s -t 60");
	printf("你的电脑将在60s后关机，输入“我是猪”取消关机\n");
	scanf("%s", arr);
	while (1)
	{
		if (strcmp(arr, "我是猪") == 0)
		{
			system("shutdown -a");
			break;
		}
		else {
			printf("输入错误，请重新输入\n");
			scanf("%s", arr);
		}
	}
	system("pause");
}