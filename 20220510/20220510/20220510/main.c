#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

menu() {
	printf("-----------------------------\n");
	printf("------1.add     2.del--------\n");
	printf("------3.modify  4.find-------\n");
	printf("------5.show   6.clear-------\n");
	printf("------7.order  0.exit--------\n");
	printf("-----------------------------\n");
}
int main()
{
	contact ps;
	int input = 0;
	Initcontact(&ps);
	do
	{
		menu();
		printf("输入你选择的序号；\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Addcontact(&ps);
			break;
		case 2:
			Delcontact(&ps);
			break;
		case 3:
			Modcontact(&ps);
			break;
		case 4:
			Findcontact(ps);
			break;
		case 5:
			Printcontact(ps);
			break;
		case 6:
			Clearcontact(&ps);
			break;
		case 7:
			Ordercontact(&ps);
			break;
		case 0:
			Savecontact(&ps);
			Destorycontact(&ps);
			
			printf("退出成功\n");
			break;
		default:
			printf("你输入的信息有误\n");
			break;
		}
	} while (input);
}