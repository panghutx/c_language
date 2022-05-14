#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"member.h"
#include"room.h"
//总菜单页面
menu() {
	printf("------欢迎访问旅馆管理系统-----\n");
	printf("------本系统提供如下服务-------\n");
	printf("----------1.住店服务-----------\n");
	printf("----------2.退房服务-----------\n");
	printf("----------3.其他服务-----------\n");
	printf("----------0.退出系统-----------\n");
	printf("-------------------------------\n");

}


int main() 
{
	menu();

	int input = 1;
	while (input)
	{
		printf("请选择您要咨询的业务\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("住店服务\n");
			checkInMenu();
			checkIn();
			//InitRoom(&rm);
			//LoadHotel(&rm);
			//PrintRoom(rm);
			break;
		case 2:
			printf("退房服务\n");

			break;
		case 3:
			printf("其他服务\n");
			break;
		case 0:
			printf("退出成功，感谢您的访问");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	}

}