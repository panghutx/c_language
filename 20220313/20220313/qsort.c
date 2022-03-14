#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//ѧϰ�⺯��qsort
//1.��int���͵������������
//2.�Խṹ�����ͽ�������
struct stu {
	char name[20];
	int age;
	double score;
};
int cmp_int(const void* e1,const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_struct_age(const void* e1, const void* e2) {
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int cmp_struct_name(const void* e1, const void* e2) {
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
void print(int arr[],int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}
void test1() {  //��������
	int arr1[] = { 9,6,10,8,7,3,4,5,2,1 };
	int num = sizeof(arr1) / sizeof(arr1[0]);
	qsort(arr1, num, sizeof(arr1[0]), cmp_int);
	print(arr1, num);
}

void test2() //�ṹ������  
{
	struct stu arr2[] = { {"panghu",20,99.5},{"daxiong",16,60.5},{"jingxiang",14,100.0}};
	int num = sizeof(arr2) / sizeof(arr2[0]);
	//qsort(arr2, num, sizeof(arr2[0]), cmp_struct_age); //����������
	qsort(arr2, num, sizeof(arr2[0]), cmp_struct_name); //����������
}

int main()
{
	test1();
	test2();

}



