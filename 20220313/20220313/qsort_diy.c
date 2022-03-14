#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现一个qsort
#include<stdio.h>
struct stu {
	char name[20];
	int age;
	double score;
};
int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
int cmp_struct_name(const void* e1, const void* e2) {
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}
void Swap(char* e1, char* e2,int width) {
	int i = 0;
	for (i = 0; i < width; i++) {
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
	
}
void qsort_diy(int arr[],int num,int width,int (*cmp_int)(const void* e1,const void* e2)) {
	int i = 0;
	for (i = 0; i < num-1; i++) {
		int j = 0;
		for (j = 0; j < num - 1 - i; j++) {
			if (cmp_int((char*)arr+j*width,(char*)arr+(j+1)*width)>0) {
				Swap((char*)arr + j * width, (char*)arr + (j + 1) * width,width);
			}
		}
	}
}
void print(int arr[], int sz) {
	int i = 0;
	for (i = 0; i < sz; i++) {
		printf("%d ", arr[i]);
	}
}
test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1 };
	int num = sizeof(arr) / sizeof(arr[0]);

	qsort_diy(arr, num, sizeof(arr[0]), cmp_int);
	print(arr,num);

}
test2()
{
	struct stu arr2[] = { {"panghu",20,99.5},{"daxiong",16,60.5},{"jingxiang",14,100.0} };
	int num = sizeof(arr2) / sizeof(arr2[0]);
	//qsort(arr2, num, sizeof(arr2[0]), cmp_struct_age); //按年龄排序
	qsort(arr2, num, sizeof(arr2[0]), cmp_struct_name); //按姓名排序
}
int main()
{
	//test1();
	test2();
}