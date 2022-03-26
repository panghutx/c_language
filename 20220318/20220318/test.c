#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
//水仙花数  153 = 1^3+5^3+3^3
int main1()
{
	
	int i = 0;
	for (i = 1; i < 1000000; i++) {
		//1.判断位数
		int tmp = i;
		int count = 0;
		while (tmp) {
			count++;
			tmp = tmp / 10;
		}
		//2.求各幂次之和
		tmp = i;
		int sum = 0;
		while (tmp) {
			sum += (int)pow(tmp % 10, count);
			tmp = tmp / 10;
		}
		//3.判断是否相等
		if (sum == i) {
			printf("%d ", i);
		}
		
	}

}

int main2()
{
	//输入一个字符，判断是否为字母
	char n = 0;
	scanf("%c", &n);
	if (n >= 'a' && n <= 'z' || n>='A' && n <= 'Z') {
		printf("Yes");
	}
	else {
		printf("No");
	}
}

int main4()
{
	//左旋字符串
	//1.一次一次移动
	//2.三次翻转
	char arr[] = "abcdef";
	int len = strlen(arr);
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		char tmp = arr[0];
		for (j = 0; j < len-1; j++) {
			arr[j] = arr[j + 1];
		}
		arr[j] = tmp;
		
	}
	printf("%s", arr);

}
//多次反转--》左旋字符串
//abcdef   3
//cba
//fed
//defabc
void reverse(char* left,char* right) {
	
	while (left < right) {
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}

}
int main5()
{
	char arr[] = "abcdefg";
	int n = 0;
	scanf("%d", &n);
	int len = strlen(arr);
	reverse(arr,arr+n-1);
	reverse(arr + n, arr + len - 1);
	reverse(arr, arr + len - 1);
	printf("%s", arr);

}
//升序数组合并
//#include<stdio.h>
//int main()
//{
//	int m, n = 0;
//	scanf("%d %d", &n, &m);
//	int i = 0;
//	int arr1[n];
//	int arr2[m];
//	int arr3[m + n];
//	for (i = 0; i < n; i++) {
//		scanf("%d", &arr1[i]);
//	}
//	for (i = 0; i < m; i++) {
//		scanf("%d", &arr2[i]);
//	}
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	while (a < n && b < m) {
//		if (arr1[a] < arr2[b]) {
//			arr3[c++] = arr1[a++];
//		}
//		else {
//			arr3[c++] = arr2[b++];
//		}
//	}
//	while (a < n) {
//		arr3[c++] = arr1[a++];
//	}
//	while (b < m) {
//		arr3[c++] = arr2[b++];
//	}
//	for (i = 0; i < m + n; i++) {
//		printf("%d ", arr3[i]);
//	}
//
//}
void search(int arr[3][3], int r, int c,int k) {
	//从右上角开始找
	int x = 0;
	int y = c - 1;
	while (x<r&&y>=0)
	{

		if (arr[x][y] > k) {
			y--;
		}
		else if (arr[x][y] < k) {
			x++;
		}
		else {
			printf("找到了，下标是%d %d", x, y);
			return;
		}
	}
	printf("没找到");
}
int main7()
{
	//杨氏矩阵，查找某个数字是否存在
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	search(arr, 3, 3, 7);
}

//原地删除数组中的元素
int main()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 0; i < len; i++) {
		if (arr[i] == n) {
			break;
		}
	}
	while (i < len - 1) {
		int* j = &arr[i + 1];
		*(arr + i) = *j;
		i++;
		j++;
	}
	i = 0;
	for (i = 0; i < len-1; i++) {
		printf("%d ", arr[i]);
	}

}