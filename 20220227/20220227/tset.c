#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//int main() {
//    int a, b;
//    while (scanf("%d %d", &a, &b) != EOF)// ע�⣬��������Ƕ��������������ͨ��whileѭ����������������
//        printf("%d\n", a + b);
//    return 0;
//}

#include<stdio.h>
#include<string.h>

//�����������������Լ��
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
//	//a�д洢�ϴ���Ǹ�����b�洢С������a<bʱ��������
//	if (a < b) {
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//��b��1�����������Լ��
//	for (i = b; i > 1; i--) {
//		//ͬʱ�������������Ǹ�����Ϊ�����ҵ���break��������
//		if (a % i == 0 && b % i == 0) {
//			break;
//		}
//	}
//	printf("%d", i);
//	return 0;
//	
//}

//�������������е���С������
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int tmp = 0;
//	int i = 0;
//	scanf("%d %d", &a, &b);
//	//a��������нϴ���Ǹ���b���С��
//	if (a < b) {
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	//���������ʼ���ϼ���
//	for (i = a; i > 0; i++) {
//		//�ҳ���С���������˳�ѭ��
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

////�ַ�������
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
//	//���������ַ���
//	char* left = arr;
//	char* right = arr + strlen(arr) - 1;	
//	reverse(left,right);
//	//����ÿ������
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

////�ַ�������˼·��
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
//	//���������ַ���
//	int len = strlen(arr);
//	sort(arr, arr+len-1);
//	//����ÿ������
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
////ģ��ʵ�ֿ⺯��strlen
////strlen() ���ַ����ĳ���
//int main()
//{
//	char arr[] = "panghu";
//	int sz = My_strlen(arr);
//	printf("%d", sz);
//}

////ģ��ʵ�ֿ⺯��strcpy
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
