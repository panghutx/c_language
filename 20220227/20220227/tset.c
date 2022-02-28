#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)// 注意，如果输入是多个测试用例，请通过while循环处理多个测试用例
//        printf("%d\n", a + b);
//    return 0;
//}

#include<stdio.h>
#include<string.h>

//求任意两个数的最大公约数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = b;
//	scanf("%d %d", &a, &b);
//	while (a % b != 0) {
//		c = a % b;
//		a = b;
//		b = c;
//	}
//	printf("%d", b);
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	//a中存储较大的那个数，b存储小数，当a<b时交换两数
//	if (a < b) {
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//从b到1遍历，找最大公约数
//	for (i = b; i > 1; i--) {
//		//同时整除两个数的那个数即为所求，找到后break结束遍历
//		if (a % i == 0 && b % i == 0) {
//			break;
//		}
//	}
//	printf("%d", i);
//	return 0;
//	
//}

//求任意两个数中的最小公倍数
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	//a存放两数中较大的那个，b存放小数
//	if (a < b) {
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//从最大数开始向上计数
//	for (i = a; i > 0; i++) {
//		//找出最小公倍数，退出循环
//		if (i % a == 0 && i % b == 0) {
//			break;
//		}
//	}
//	printf("%d", i);
//
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int i = 1;
//	scanf("%d %d", &a, &b);
//	while (a * i % b) {
//		i++;
//	}
//	printf("%d", a * i);
//	return 0;
//}

////字符串倒序
//void reverse(char* l,char* r)
//{
//
//	while (l < r) {
//		char* tmp = *l;
//		*l = *r;
//		*r = tmp;
//		l++;
//		r--;
//	}
//}
//int main()
//
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	//逆序整个字符串
//	char* left = arr;
//	char* right = arr + strlen(arr) - 1;	
//	reverse(left,right);
//	//逆序每个单词
//	char* cur = arr;
//	char* start = arr;
//	while (*cur!='\0')
//	{
//		while (*cur != ' '&& *cur!='\0') {
//			cur++;
//		}
//		reverse(start, cur - 1);
//		start = cur + 1;
//		cur++;
//	}
//	printf("%s", arr);
//
//}

////字符串倒序思路二
//void sort(char* left,char* right) {
//	while (left < right) {
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr[100] = { 0 };
//	gets(arr);
//	//倒置整个字符串
//	int len = strlen(arr);
//	sort(arr, arr+len-1);
//	//倒置每个单词
//	int i = 0;
//	char* start = arr;
//	for (i = 0; i <= len; i++) {
//		if (arr[i] == ' ' || arr[i] == '\0') {
//			sort(start, arr + i - 1);
//			start = arr + i + 1;
//		}
//	}
//	printf("%s", arr);
//}
// 
// 
//int My_strlen(char* arr) {
//	int count = 0;
//	while (*arr) {
//		count++;
//		arr++;
//	}
//	return count;
//}
////模拟实现库函数strlen
////strlen() 求字符串的长度
//int main()
//{
//	char arr[] = "panghu";
//	int sz = My_strlen(arr);
//	printf("%d", sz);
//}

////模拟实现库函数strcpy
//void My_strcpy(char* des,const char* ori) {
//	while (*ori) {
//		*des++ = *ori++;
//		
//	}
//}
//int main()
//{
//	const char arr1[] = "panghu";
//	char arr2[100] = { 0 };
//	My_strcpy(arr2, arr1);
//	printf("%s", arr2);
//}
//
