#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
void* My_mommove(char* dest, char* src, size_t count) {

}
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	
	memmove(arr + 3, arr, 20);
}
