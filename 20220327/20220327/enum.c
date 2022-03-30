#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

enum Color {
	Green,
	RED,
	YELLOW
}color;

union MyUnion
{
	char a;
	int b;
};
int main()
{
	union MyUnion un;
	
	//printf("%d", Green);
	//enum Coloe color = RED;
	//color = 3;
	//printf("%d", color);
	un.b = 0x11223344;
	un.a = 0x55;
	printf("%x\n",un.b);
	printf("%p\n", &(un.b));
}
