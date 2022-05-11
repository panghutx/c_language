#include"room.h"
//房间初始化
//初始化房间信息
void InitRoom(roomManager* rm){

	//rm->room[0] = { "A",2,"1001","未出租" };
	rm->capacity = 10;
	rm->size = 0;
	//rm->room[rm->size].level = "A";
	//rm->room[0].people = 2;
	//rm->room[0].roomNumber = "1001";
	//rm->room[0].status = "未出租";
	//rm->room[1].level = "A";
	//rm->room[1].people = 2;
	//rm->room[1].roomNumber = "1002";
	//rm->room[1].status = "未出租";
	

}

//增加
void AddHotel(roomManager* rm) {
	while (rm->size < 10) {
		//录入信息
		printf("输入：");
		scanf("%s", rm->room[rm->size].level);
		printf("输入：");
		scanf("%d", &rm->room[rm->size].people);
		printf("输入：");
		scanf("%s", rm->room[rm->size].roomNumber);
		printf("输入：");
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

//显示房间信息
void PrintRoom(roomManager rm) {
	printf("%5s %5s %5s %20s\n", "等级", "床位", "房号","状态");
	for (int i = 0; i < 10; i++) {
		printf("%5s %5d %5s %5s\n", 
			rm.room[i].level, rm.room[i].people, rm.room[i].roomNumber,rm.room[i].status);
	}
}

