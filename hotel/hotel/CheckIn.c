#include"member.h"
#include"room.h"
//ס�����ҳ��˵�
checkInMenu() {
	printf("-----------ס�����˵�--------\n");
	printf("------���˵��ṩ���·���-------\n");
	printf("----------1.�����ѯ-----------\n");
	printf("----------2.��ס�Ǽ�-----------\n");
	printf("----------3.��������-----------\n");
	printf("----------0.�˳�ϵͳ-----------\n");
	printf("-------------------------------\n");


}


void checkIn() {

	roomManager rm;
	hotelMember hm;
	
	InitMember(&hm); //���ͳ�ʼ��
	InitRoom(&rm); //�����ʼ��
	

	int input = 1;
	while (input)
	{
		printf("��ѡ����Ҫ��ѯ��ҵ��\n");
		scanf("%d", &input);
		switch (input) {
		case 1:
			printf("�����ѯ\n");
			//AddHotel(&rm);
			LoadHotel(&rm); //���ط�����Ϣ
			
			//ModifyHotel(1002, &rm);
			SaveHotel(&rm);
			
			PrintRoom(rm);//��ӡ������Ϣ
			break;
		case 2:
			printf("��ס�Ǽ�\n");
			AddMember(&hm);
			break;
		case 3:
			printf("qita����\n");
			break;
		case 0:
			printf("�˳��ɹ�����л���ķ���");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}
}
