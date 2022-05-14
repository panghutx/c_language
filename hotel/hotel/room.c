#include"room.h"
#include"member.h"
#include<string.h>

//房间初始化
//初始化房间信息
void InitRoom(roomManager* rm){
	rm->capacity = 10;
	rm->size = 0;
	//分配10人的空间
	rm->room = (Room*)calloc(10, sizeof(Room));
	//开辟内存失败，打印错误信息
	if (rm->room == NULL) {
		perror("Init::calloc");
	}

}

//加载文件数据到控制台
void LoadHotel(roomManager* rm)
{
	//打开文件
	FILE* pf = fopen("hotel.txt", "r");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//读文件
	struct Room tmp = { 0 };
	while (fread(&tmp, sizeof(Room), 1, pf))
	{
		rm->room[rm->size] = tmp;
		rm->size++;
	}

	//关闭文件
	fclose(pf);
	pf = NULL;
}

//增加
void AddHotel(roomManager* rm) {
	while (rm->size < 10) {
		//录入信息
		printf("输入等级：");
		scanf("%s", rm->room[rm->size].level);
		printf("输入房间人数：");
		scanf("%d", &rm->room[rm->size].people);
		printf("输入门牌号：");
		scanf("%s", rm->room[rm->size].roomNumber);
		printf("输入状态：");
		scanf("%s", rm->room[rm->size].status);
		rm->size++;
	}

	//添加成功
	printf("添加成功\n");

}



//将数据保存到文件
void SaveHotel(roomManager* rm) {
	//打开文件
	FILE* pfile = fopen("hotel.txt", "w+");
	if (pfile == NULL) {
		perror("Savacontact::fopen");
		return;
	}
	//写入数据

	for (int i = 0; i < rm->size; i++) {
		fwrite(rm->room + i, sizeof(Room), 1, pfile);
	}
	//关闭文件
	fclose(pfile);
	pfile = NULL;


}




////文件内容修改
////void ModifyHotel(roomManager* rm) {
////	
////	int rst[10] = hotelNum(&hm);
////	rst转换成string
////	char* strDst[256] = { 0 };
////	for (int j = 0; j < 10; j++) {
////		sprintf_s(strDst[j], 10, "%d", rst[j]);
////	}
////	
////
////	int i = 0;
////	for (i = 0; i < 10; i++) {
////		for (int z = 0; z < 10; z++) {
////			if (strcmp(rm->room[z].roomNumber, strDst[z]) == 0) {
////				strcpy(rm->room[z].status, "已出租");
////			}
////		}
////		
////	}
////}

//显示房间信息
void PrintRoom(roomManager rm) {
	printf("%5s %5s %5s %5s\n", "等级", "床位", "房号","状态");
	for (int i = 0; i < 10; i++) {
		printf("%5s %5d %5s %5s\n", 
			rm.room[i].level, rm.room[i].people, rm.room[i].roomNumber,rm.room[i].status);
	}
}



