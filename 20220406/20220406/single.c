#define _CRT_SECURE_NO_WARNINGS 1
//010
//011
//001
#include<stdio.h>
void Single(int arr[], int sz) {
	int single1 = 0;
	int single2 = 0;
	//��������򣬵õ�����ֻ����һ�ε���
	int i = 0; int rst = 0;
	for (i = 0; i < sz; i++) {
		rst ^= arr[i]; //2^3
	}
	//���飬������λ��Ϊ1
	for (i = 0; i < 32; i++) {
		if ((rst >> i & 1) == 1) {
			break;
		}
	}
	int pos = i; //��¼��λ��
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
	//���λΪ0�� 0 0 2 4 4   ����ֵΪ2
	//���λΪ1�� 1 1 3       ����ֵΪ3
}
