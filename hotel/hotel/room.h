#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//������

//������Ϣ
typedef struct Room {
	char level[10]; //����ȼ�
	int people;//��������
	char roomNumber[10];//����
	char status[10]; //�������

}Room;




//�ùݸ�����������Ϣ
typedef struct roomManager {
	Room* room;
	int size;//ʹ������
	int capacity;//����������

}roomManager;

//�����õ���һЩ����

//��ʼ��

//��ʾ������Ϣ
void InitRoom(roomManager* rm);
void PrintRoom(roomManager rm);
void AddHotel(roomManager* rm);
void SaveHotel(roomManager* rm);

////��ӡ
//void PrintMember(const hotelMember* hm);
////ɾ��
//void DelMember(hotelMember* hm);
////����
//void FindMember(hotelMember hm);
////free
//void DestoryMember(hotelMember* hm);