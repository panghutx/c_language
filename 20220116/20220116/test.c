#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	//随机数实验
	
	printf("%d\n",rand());
	printf("%d\n", rand());
	printf("%d\n", rand());
	
}
void game()
{
	int guest = 0;
	int rst = rand()%100+1;
	while (1) {
		printf("请输入一个数字\n");
		scanf("%d", &guest);
		if (guest==rst) {
			printf("猜对了\n");
			break;
		}
		else if (guest<rst) {
			printf("猜小了\n");
		}
		else {
			printf("猜大了\n");
		}
	}
}
void menu()
{
	printf("----------------\n");
	printf("---1.开始游戏---\n");
	printf("---2.结束游戏---\n");
	printf("----------------\n");
}
int main4()
{
	//猜数字游戏
	srand((unsigned int)time(NULL));
	menu();
	int num = 0;
	printf("请输入选项：1.开始游戏 2.结束游戏\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		game();
		break;
	case 2:
		break;
	default:
		printf("输入错误，请重新输入\n");
		menu();
		break;
	}
	
}
int main3()
{
	//二分查找
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 7;
	int left = arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int mid = (left + right) >> 1;
	while (left <= right) { //千万不要忽略=
		mid = (left + right) >> 1;
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			printf("%d", mid);
			break;
		}
	}
	if(left>right)
		printf("找不到");
}
int factor(int n) {
	if (n == 1) {
		return 1;
	}
	return n* factor(n - 1);
}
int main2()
{
	//计算1!=2!+……+5!
	int rst = 0;
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	
	for (n; n >0; n--) {
		rst = factor(n);
		sum += rst;
	}
	
	printf("%d\n", sum);
}
int main66()
{
	//非递归求5的阶乘
	int i = 1;
	int sum = 0;
	int rst = 1;
	for (i = 1; i <= 5; i++) {
		rst = rst * i;
	}
	printf("%d", rst);
}
int main666()
{
	//求1!+2!+……+5的！
	int i = 1;
	int sum = 0;
	int rst = 1;
	for (i = 1; i <= 5; i++) {
		rst = rst * i;
		sum += rst;
	}
	printf("%d", sum);
}
int main1()
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		k++;
	return 0;
}