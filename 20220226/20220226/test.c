#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
////�ṹ����ϰ
//struct students {
//	char name[20]; //��Ա����
//	int age;
//};
//int main()
//{
//	//�ṹ���Ա�ĳ�ʼ��
//	struct students stu1 = { "panghu",20 };
//	struct students stu2 = { "xiaofu",24 };
//	//���ʽṹ���Ա
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
//	struct school stu1 = { "��������ѧ",50 };
//	print(&stu1);
//}
// 
//�ṹ��������struct school������ʹ��typedef�ض���  typedef struct school school����ʱschoolΪ�ṹ������

////���������ʲô��
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


////�ݹ�ʵ��n�Ľ׳�
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

////ʵ�ִ��룺�� 1��+2��+3�� ...+ n! �������������
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
////�¶˴�������н����ʲô
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