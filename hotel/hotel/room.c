#include"room.h"
//�����ʼ��
//��ʼ��������Ϣ
void InitRoom(roomManager* rm){

	//rm->room[0] = { "A",2,"1001","δ����" };
	rm->capacity = 10;
	rm->size = 0;
	//rm->room[rm->size].level = "A";
	//rm->room[0].people = 2;
	//rm->room[0].roomNumber = "1001";
	//rm->room[0].status = "δ����";
	//rm->room[1].level = "A";
	//rm->room[1].people = 2;
	//rm->room[1].roomNumber = "1002";
	//rm->room[1].status = "δ����";
	

}

//����
void AddHotel(roomManager* rm) {
	while (rm->size < 10) {
		//¼����Ϣ
		printf("���룺");
		scanf("%s", rm->room[rm->size].level);
		printf("���룺");
		scanf("%d", &rm->room[rm->size].people);
		printf("���룺");
		scanf("%s", rm->room[rm->size].roomNumber);
		printf("���룺");
		scanf("%s", rm->room[rm->size].status);
		rm->size++;
	}

	//��ӳɹ�
	printf("��ӳɹ�\n");

}
//�����ݱ��浽�ļ�
void SaveHotel(roomManager* rm) {
	//���ļ�
	FILE* pfile = fopen("hotel.txt", "w+");
	if (pfile == NULL) {
		perror("Savacontact::fopen");
		return;
	}
	//д������

	for (int i = 0; i < rm->size; i++) {
		fwrite(rm->room + i, sizeof(Room), 1, pfile);
	}
	//�ر��ļ�
	fclose(pfile);
	pfile = NULL;


}

//��ʾ������Ϣ
void PrintRoom(roomManager rm) {
	printf("%5s %5s %5s %20s\n", "�ȼ�", "��λ", "����","״̬");
	for (int i = 0; i < 10; i++) {
		printf("%5s %5d %5s %5s\n", 
			rm.room[i].level, rm.room[i].people, rm.room[i].roomNumber,rm.room[i].status);
	}
}

