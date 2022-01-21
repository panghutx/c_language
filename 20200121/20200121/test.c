#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//交换数组中的内容
void swap(int arr1[], int arr2[],int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++) {
		int tmp = arr1[i];
		arr1[i] = arr2[i];
		arr2[i] = tmp;
	}
}
int main()
{
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 6,7,8,9,10 };
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	swap(arr1, arr2, sz);
	int i = 0;
	//arr1
	for ( i = 0; i < sz; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");
	//arr2
	int j = 0;
	for (j = 0; j < sz; j++)
	{
		printf("%d ", arr2[j]);
	}
	return 0;
}




//创建一个整形数组，完成对数组的操作
//实现函数init() 初始化数组为全0
//实现print()  打印数组的每个元素
//实现reverse()  函数完成数组元素的逆置。

void init(int* p,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++) {
		*(p+i) = 0;
	}
}
void print(int* p, int sz)
{
	int i = 0;
	for ( i = 0; i < sz; i++)
	{
		printf("%d ", *(p+i));
	}
}
void reverse(int arr[], int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left <= right) {
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
}
int main2()
{
	int arr[] = { 1,2,3,4,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//init(arr,sz);
	reverse(arr, sz);
	print(arr,sz);
	
	return 0;
}
//数组实现冒泡排序
void bobber_Sort(int arr[],int sz)
{
	int i = 0;
	for (i = 0; i < sz-1; i++) {
		int flg = 1;
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flg = 0;
			}
		}
		if (flg == 1) {
			break;
		}
	}
}
int main1()
{
	int arr[] = { 1,2,3,4,5,6,7 };
	
	int sz = sizeof(arr) / sizeof(arr[0]);

	bobber_Sort(arr,sz);

	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}