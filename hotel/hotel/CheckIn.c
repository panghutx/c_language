#include"member.h"
#include"room.h"
//住店服务页面菜单
checkInMenu() {
	printf("-----------住店服务菜单--------\n");
	printf("------本菜单提供如下服务-------\n");
	printf("----------1.房间查询-----------\n");
	printf("----------2.入住登记-----------\n");
	printf("----------3.其他服务-----------\n");
	printf("----------0.退出系统-----------\n");
	printf("-------------------------------\n");


}


void checkIn() {

	roomManager rm;
	hotelMember hm;
	
	InitMember(&hm); //房客初始化
	InitRoom(&rm); //房间初始化
	

	int input = 1;
	while (input)
	{
		printf("请选择您要咨询的业务\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("房间查询\n");
			//AddHotel(&rm);
			LoadHotel(&rm); //加载房间信息
			
			//ModifyHotel(1002, &rm);
			SaveHotel(&rm);
			
			PrintRoom(rm);//打印房间信息
			break;
		case 2:
			printf("入住登记\n");
			AddMember(&hm);
			break;
		case 3:
			printf("qita服务\n");
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
