#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"member.h"
#include"room.h"
//�˵�ҳ��
menu() {
	printf("------��ӭ�����ùݹ���ϵͳ-----\n");
	printf("------��ϵͳ�ṩ���·���-------\n");
	printf("----------1.ס�����-----------\n");
	printf("----------2.�˷�����-----------\n");
	printf("----------3.��������-----------\n");
	printf("----------0.�˳�ϵͳ-----------\n");
	printf("-------------------------------\n");

}

int main() 
{
	menu();
	hotelMember hm;
	roomManager rm;
	//��ʼ���ù�ס����Ϣ
	InitMember(&hm);
	int input = 1;
	while (input)
	{
		printf("��ѡ����Ҫ��ѯ��ҵ��\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("ס�����\n");
			InitRoom(&rm);
			AddHotel(&rm);
			SaveHotel(&rm);
			PrintRoom(rm);
			//AddMember(&hm);
			//PrintMember(&hm);
			break;
		case 2:
			printf("�˷�����\n");
			DelMember(&hm);
			PrintMember(&hm);
			break;
		case 3:
			printf("qita����\n");
			break;
		case 0:
			printf("�˳��ɹ�����л���ķ���");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}

}