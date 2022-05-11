#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//租客板块

//租客个人信息
typedef struct Consumer {
	char name[20]; //姓名
	int age;//年龄
	char sex[10];//性别
	char phone[11];//手机号
	char identify[18];//身份证

}Consumer;

//旅馆租客信息
typedef struct hotelMember {
	Consumer* nums; //旅客信息
	int size;//旅客人数
	int capacity;//旅店容量

}hotelMember;

//此类用到的一些方法

//初始化
void InitMember(hotelMember* hm);
//增加
void AddMember(hotelMember* hm);
//打印
void PrintMember(const hotelMember* hm);
//删除
void DelMember(hotelMember* hm);
//查找
void FindMember(hotelMember hm);
//free
void DestoryMember(hotelMember* hm);