#include"room.h"
#include"member.h"
#include<string.h>

//�����ʼ��
//��ʼ��������Ϣ
void InitRoom(roomManager* rm){
	rm->capacity = 10;
	rm->size = 0;
	//����10�˵Ŀռ�
	rm->room = (Room*)calloc(10, sizeof(Room));
	//�����ڴ�ʧ�ܣ���ӡ������Ϣ
	if (rm->room == NULL) {
		perror("Init::calloc");
	}

}

//�����ļ����ݵ�����̨
void LoadHotel(roomManager* rm)
{
	//���ļ�
	FILE* pf = fopen("hotel.txt", "r");
	if (pf == NULL)
	{
		perror("LoadContact::fopen");
		return;
	}
	//���ļ�
	struct Room tmp = { 0 };
	while (fread(&tmp, sizeof(Room), 1, pf))
	{
		rm->room[rm->size] = tmp;
		rm->size++;
	}

	//�ر��ļ�
	fclose(pf);
	pf = NULL;
}

//����
void AddHotel(roomManager* rm) {
	while (rm->size < 10) {
		//¼����Ϣ
		printf("����ȼ���");
		scanf("%s", rm->room[rm->size].level);
		printf("���뷿��������");
		scanf("%d", &rm->room[rm->size].people);
		printf("�������ƺţ�");
		scanf("%s", rm->room[rm->size].roomNumber);
		printf("����״̬��");
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




////�ļ������޸�
////void ModifyHotel(roomManager* rm) {
////	
////	int rst[10] = hotelNum(&hm);
////	rstת����string
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
////				strcpy(rm->room[z].status, "�ѳ���");
////			}
////		}
////		
////	}
////}

//��ʾ������Ϣ
void PrintRoom(roomManager rm) {
	printf("%5s %5s %5s %5s\n", "�ȼ�", "��λ", "����","״̬");
	for (int i = 0; i < 10; i++) {
		printf("%5s %5d %5s %5s\n", 
			rm.room[i].level, rm.room[i].people, rm.room[i].roomNumber,rm.room[i].status);
	}
}



