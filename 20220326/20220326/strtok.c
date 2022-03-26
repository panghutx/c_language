#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

int main1()
{
	char arr[] = "https://youngsay.cn";
	char arr2[100] = { 0 };
	strcpy(arr2, arr);
	printf("%s\n", strtok(arr2, ":/."));
	printf("%s\n", strtok(NULL, ":/."));
	printf("%s\n", strtok(NULL, ":/."));
	printf("%s", arr);
}

int main()
{
	char arr[] = "https://youngsay.cn";
	char arr2[100] = { 0 };
	const char* sep = "://.";
	strcpy(arr2, arr);
	for (char* str = strtok(arr2, sep); str != NULL; str = strtok(NULL, sep)) {
		printf("%s ", str);
	}
}