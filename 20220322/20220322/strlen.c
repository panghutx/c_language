#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//模拟实现strlen函数
//方法1
int My_strlen(char* str) {
	int count = 0;
	while (*str) {
		count++;
		str++;
	}
	return count;
}
//方法2 指针相减
int My_strlen2(char* str) {
	char* end = str;
	while (*end) {
		end++;
	}
	return end - str;
}
//方法3：递归
int My_strlen3(char* str) {
	if (*str == '\0') {
		return 0;
	}else {
	return 1 + My_strlen3(str + 1);
	}
}

int main()
{
	char arr[] = "abcdefg";
	int len = My_strlen3(arr);
	printf("%d", len);
}
