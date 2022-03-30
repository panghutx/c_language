#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int My_strlen1(char* ps) {
	int count = 0;
	while (*ps) {
		count++;
		ps++;
	}
	return count;
}

int My_strlen2(char* ps) {
	char* start = ps;
	while (*ps) {
		ps++;
	}
	return ps - start;
}

int My_strlen3(char* ps) {
	if (*ps == '\0')
		return 0;
	else
		return 1+My_strlen3(ps+1);
}
int main()
{
	char arr[] = "abcdef";
	int rst = My_strlen3(arr);
	printf("%d", rst);
}
