#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//��Ͱ��

//��͸�����Ϣ
typedef struct Consumer {
	char name[20]; //����
	int age;//����
	char sex[10];//�Ա�
	char phone[11];//�ֻ���
	char identify[18];//���֤

}Consumer;

//�ù������Ϣ
typedef struct hotelMember {
	Consumer* nums; //�ÿ���Ϣ
	int size;//�ÿ�����
	int capacity;//�õ�����

}hotelMember;

//�����õ���һЩ����

//��ʼ��
void InitMember(hotelMember* hm);
//����
void AddMember(hotelMember* hm);
//��ӡ
void PrintMember(const hotelMember* hm);
//ɾ��
void DelMember(hotelMember* hm);
//����
void FindMember(hotelMember hm);
//free
void DestoryMember(hotelMember* hm);