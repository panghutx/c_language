#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
struct Stu {  //类型
	//属性
	char name[20];
	int age;
	char sex[10];
}; //变量
struct {
    int a;
    char b;
    double c;
} a;
struct s1{
    char a;
    int b;
    char c;
}s1;

struct A
{
    int _a : 2;
    int _b : 5;
    int _c : 10;
    int _d : 30;
};
struct S
{
    char a : 3;
    char b : 4;
    char c : 5;
    char d : 4;
};

int main()
{
    /*printf("%d", sizeof(struct s1));
    printf("%d", sizeof(struct A));*/

    struct S s = { 0 };
    s.a = 10;
    s.b = 12;
    s.c = 3;
    s.d = 4;
}