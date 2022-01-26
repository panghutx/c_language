#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include<string.h>
int My_strlen2(char* str)
{
	//指针相减求字符串长度
	char* tmp = str;
	while (*str)
		str++;
	return str - tmp;
}
int My_strlen1(char* str)
{
	//递归求字符串长度
	if (*str != '\0')
		return 1 + My_strlen1(str + 1);
	else
		return 0;
}
int My_strlen(char* str)
{
	int count = 0;
	while (*str!='\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	//自定义函数求字符串长度
	char str[100];
	gets(str);
	//计数器
	int len =My_strlen(str);
	//递归
	int len1 = My_strlen1(str);
	//指针相减
	int len2 = My_strlen2(str);
	printf("%d %d %d", len,len1,len2);
}
void my_reverse(char* str)
{
	int sz = strlen(str);
	char* left = str;
	char* right = str + strlen(str) - 1;
	char tmp = *left;
	*left = *right;
	*right = '\0';
	if (strlen(str+1) > 1)
		my_reverse(str + 1);

	*right = tmp;
}
int main5()
{
	//递归求字符串的逆序
	char str[100];
	gets(str);
	my_reverse(str);
	printf("%s", str);
}
void reverse(char* str)
{
	char* left = str;
	char* right = str + strlen(str) - 1;
	while (left < right)
	{
		int tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main4()
{
	//字符串的逆序
	char str[100];
	gets(str);
	reverse(str);
	printf("%s", str);
	
}

void print(int* ps,int sz)
{
	
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(ps + i));
	}
}
int main3()
{
	//使用指针打印数组内容
	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr,sz);
}
void swap(int* x,int* y)
{
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;

}
int main2()
{
	//交换两个变量（不创建临时变量）
	int a = 12;
	int b = 10;
	swap(&a, &b);
	printf("%d %d",a,b);

}
void Printbit(int num)
{
	for (int i = 31; i >= 1; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");

	for (int i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (num >> i) & 1);
	}
	printf("\n");
}
int main1()
{
	//打印整数二进制的奇数位和偶数位
	Printbit(6);
}
//全局变量初始化为0
//int i;
//int main()
//{
//    i--;
//    if (i > sizeof(i))
//    {
//        printf(">\n");
//    }
//    else
//    {
//        printf("<\n");
//    }
//    return 0;
//}