#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <string.h>
#include<stdlib.h>

#define MaxNum 100
//个人信息
struct Person {
	char name[20];
	char sex[5];
	int age;
	char phone[12];
};
//通讯录结构
typedef struct contact {
	struct Person* nums;
	int sz;
	int capacity;
}contact;

//初始化
void Initcontact(contact* pcon);
//增加
void Addcontact(contact* pcon);
//删除
void Delcontact(contact* pcon);
//修改
void Modcontact(contact* pcon);
//查找
void Findcontact(contact pcon);
//清空
void Clearcontact(contact* pcon);
//排序
void Ordercontact(contact* pcon);
//打印
void Printcontact(contact pcon);
//free
void Destorycontact(contact* pcon);