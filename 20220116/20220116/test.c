#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	//�����ʵ��
	
	printf("%d\n",rand());
	printf("%d\n", rand());
	printf("%d\n", rand());
	
}
void game()
{
	int guest = 0;
	int rst = rand()%100+1;
	while (1) {
		printf("������һ������\n");
		scanf("%d", &guest);
		if (guest==rst) {
			printf("�¶���\n");
			break;
		}
		else if (guest<rst) {
			printf("��С��\n");
		}
		else {
			printf("�´���\n");
		}
	}
}
void menu()
{
	printf("----------------\n");
	printf("---1.��ʼ��Ϸ---\n");
	printf("---2.������Ϸ---\n");
	printf("----------------\n");
}
int main4()
{
	//��������Ϸ
	srand((unsigned int)time(NULL));
	menu();
	int num = 0;
	printf("������ѡ�1.��ʼ��Ϸ 2.������Ϸ\n");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		game();
		break;
	case 2:
		break;
	default:
		printf("�����������������\n");
		menu();
		break;
	}
	
}
int main3()
{
	//���ֲ���
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int key = 7;
	int left = arr[0];
	int sz = sizeof(arr) / sizeof(arr[0]);
	int right = sz - 1;
	int mid = (left + right) >> 1;
	while (left <= right) { //ǧ��Ҫ����=
		mid = (left + right) >> 1;
		if (arr[mid] < key) {
			left = mid + 1;
		}
		else if (arr[mid] > key) {
			right = mid - 1;
		}
		else {
			printf("%d", mid);
			break;
		}
	}
	if(left>right)
		printf("�Ҳ���");
}
int factor(int n) {
	if (n == 1) {
		return 1;
	}
	return n* factor(n - 1);
}
int main2()
{
	//����1!=2!+����+5!
	int rst = 0;
	int n = 0;
	int sum = 0;
	scanf("%d", &n);
	
	for (n; n >0; n--) {
		rst = factor(n);
		sum += rst;
	}
	
	printf("%d\n", sum);
}
int main66()
{
	//�ǵݹ���5�Ľ׳�
	int i = 1;
	int sum = 0;
	int rst = 1;
	for (i = 1; i <= 5; i++) {
		rst = rst * i;
	}
	printf("%d", rst);
}
int main666()
{
	//��1!+2!+����+5�ģ�
	int i = 1;
	int sum = 0;
	int rst = 1;
	for (i = 1; i <= 5; i++) {
		rst = rst * i;
		sum += rst;
	}
	printf("%d", sum);
}
int main1()
{
	int i = 0;
	int k = 0;
	for (i = 0, k = 0; k = 0; i++, k++)
		k++;
	return 0;
}