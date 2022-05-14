
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>


//房间板块

//房间信息
typedef struct Room {
	char level[10]; //房间等级
	int people;//容纳人数
	char roomNumber[10];//房号
	char status[10]; //出租与否

}Room;




//旅馆各房间租用信息
typedef struct roomManager {
	Room* room;
	int size;//使用数量
	int capacity;//房间总数量

}roomManager;

//此类用到的一些方法

//初始化

//显示房间信息
void InitRoom(roomManager* rm);
void PrintRoom(roomManager rm);
void AddHotel(roomManager* rm);
void SaveHotel(roomManager* rm);
void LoadHotel(roomManager* rm);
//int HotelNum(); //获取房间号
void ModifyHotel(roomManager* rm); //修改房间状态



