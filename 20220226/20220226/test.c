#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////结构体练习
//struct students {
//	char name[20]; //成员属性
//	int age;
//};
//int main()
//{
//	//结构体成员的初始化
//	struct students stu1 = { "panghu",20 };
//	struct students stu2 = { "xiaofu",24 };
//	//访问结构体成员
//	printf("%s %d", stu1.name, stu1.age);
//
//}

//struct school {
//	char name[20];
//	int age;
//}stu1,stu2;
//
//void print(struct school *str) {
//	printf("%s %d",str->name ,str->age);
//}
//int main()
//{
//	struct school stu1 = { "华北理工大学",50 };
//	print(&stu1);
//}
// 
//结构体类型是struct school，可以使用typedef重定义  typedef struct school school，此时school为结构体类型

////程序输出是什么？
//struct stu
//{
//    int num;
//    char name[10];
//    int age;
//};
//
//
//void fun(struct stu* p)
//{
//    printf("%s\n", (*p).name);
//    return;
//}
//
//
//int main()
//{
//    struct stu students[3] = { {9801,"zhang",20},
//                              {9802,"wang",19},
//                              {9803,"zhao",18}
//    };
//    fun(students + 1);
//    return 0;
//}


////递归实现n的阶乘
//int  factor(int n) {
//	int rst = 0;
//	if (n == 1) {
//		return 1;
//	}
//	else {
//		rst = n * factor(n - 1);
//		return rst;
//	}
//	
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d", factor(n));
//}

////实现代码：求 1！+2！+3！ ...+ n! ；不考虑溢出。
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int sum = 0;
//	int rst = 1;
//	for (i = 1; i <= n; i++) {
//		rst = i * rst;
//		sum += rst;
//	}
//	printf("%d", sum);
//}
// 
// 
////下端代码的运行结果是什么
//int main()
//{
//	int i = 0;
//	int arr[10] = { 0 };
//	for (i = 0; i <= 12; i++)
//	{
//		arr[i] = 0;
//		printf("youngsay.cn\n");
//	}
//	return 0;
//}