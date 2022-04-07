#define _CRT_SECURE_NO_WARNINGS 1
//010
//011
//001
#include<stdio.h>
void Single(int arr[], int sz) {
	int single1 = 0;
	int single2 = 0;
	//所有数异或，得到两个只出现一次的数
	int i = 0; int rst = 0;
	for (i = 0; i < sz; i++) {
		rst ^= arr[i]; //2^3
	}
	//分组，按异或后位数为1
	for (i = 0; i < 32; i++) {
		if ((rst >> i & 1) == 1) {
			break;
		}
	}
	int pos = i; //记录下位数
	for (i = 0; i < sz; i++) {
		if ((arr[i] >> pos & 1) == 1) {
			single1 ^= arr[i];
		}
	}
	single2 = single1 ^ rst;
	printf("%d %d", single1, single2);
}
int main()
{
	int arr[] = { 0,1,2,4,4,3,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Single(arr, sz);
	//2^3
	//最低位为0： 0 0 2 4 4   异或后值为2
	//最低位为1： 1 1 3       异或后值为3
}
