#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void* My_memmove(void* des, void* src, size_t count) {
	if (des < src) {
		//从前向后拷贝
		while (count--) {
			*(char*)des = *(char*)src;
			des = (char*)des + 1;
			src = (char*)src + 1;
		}

	}
	else {
		//从后向前拷贝
		des = (char*)des + count - 1;
		src = (char*)src + count - 1;
		while (count--) {
			*(char*)des = *(char*)src;
			des = (char*)des - 1;
			src = (char*)src - 1;
		}
	}
}


int main() 
{
	int arr[] = { 1,2,3,4,5,6,7,8 };
	My_memmove(arr + 3, arr, 16);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("%d", arr[i]);
	}
}

