#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

#define MaxNum 100
//������Ϣ
struct Person {
	char name[20];
	char sex[5];
	int age;
	char phone[12];
};
//ͨѶ¼�ṹ
typedef struct contact {
	struct Person* nums;
	int sz;
	int capacity;
}contact;

//��ʼ��
void Initcontact(contact* pcon);
//����
void Addcontact(contact* pcon);
//ɾ��
void Delcontact(contact* pcon);
//�޸�
void Modcontact(contact* pcon);
//����
void Findcontact(contact pcon);
//���
void Clearcontact(contact* pcon);
//����
void Ordercontact(contact* pcon);
//��ӡ
void Printcontact(contact pcon);
//free
void Destorycontact(contact* pcon);