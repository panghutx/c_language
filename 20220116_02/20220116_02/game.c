#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	char arr[20] = {0};
	system("shutdown -s -t 60");
	printf("��ĵ��Խ���60s��ػ������롰������ȡ���ػ�\n");
	scanf("%s", arr);
	while (1)
	{
		if (strcmp(arr, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
		else {
			printf("�����������������\n");
			scanf("%s", arr);
		}
	}
	system("pause");
}