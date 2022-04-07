#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//先排序
int* Bobble_sort(int* ps, int n) {
	int* start = ps;
	int sz = n - 1;
	int i = 0;
	int* tmp = ps;
	for (i = 0; i < sz; i++) {
		int j = 0;
		for (j = 0; j < sz - i; j++) {
			
		}
	}
	return start;
}
//再查找
int Only_one(int arr[], int n) {
	for (int i = 0; i < n-1; i++) {
		if (arr[i] == arr[i + 1]) {

		}
	}
}

int main()
{
	int arr[] = { 1,0,3,3,0,5,1 ,6,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	Bobble_sort(arr, len);
	//排序后打印
	//for (int i = 0; i < len; i++) {
	//	printf("%d", arr[i]);
	//}
	int rst = Only_one(arr, len);
	printf("%d", rst);
	
}
