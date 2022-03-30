#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

void* My_memcpy(void* des, void* src, size_t count) {
	void* ret = des;
	while (count--) {
		*(char*)des = *(char*)src;
		des = (char*)des + 1;
		src = (char*)src + 1;
	}
	return ret;
}

int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8 };
	int arr2[20] = {0};
	My_memcpy(arr2, arr1, 32);
	//for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
	//	printf("%d", arr2[i]);
	//}
}
