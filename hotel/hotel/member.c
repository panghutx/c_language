#include"member.h"

//��ʼ��
void InitMember(hotelMember* hm) {
	hm->size = 0;
	hm->capacity = 10; //Ĭ��������10��
	//����10�˵Ŀռ�
	hm->nums = (Consumer*)calloc(10, sizeof(Consumer));
	//�����ڴ�ʧ�ܣ���ӡ������Ϣ
	if (hm->nums == NULL) {
		perror("InitMember::calloc");
	}
	
}

//��̬����
void checkCapacity(hotelMember* hm) {
	if (hm->size == hm->capacity) {
		Consumer* tmp = (Consumer*) realloc( hm->nums, (hm->capacity + 5) * sizeof(Consumer));
		//���ݳɹ�
		if (tmp != NULL) {
			hm->nums = tmp;
		}
		else {
			perror(realloc);
			return;
		}
		hm->capacity += 5;
		//printf("���ݳɹ�");
	}
	
}
//����ס����Ϣ
void AddMember(hotelMember* hm) {
	//����Ƿ���Ҫ����
	//checkCapacity(&hm);
	//¼����Ϣ
	printf("������������\n");
	scanf("%s", hm->nums[hm->size].name);
	printf("���������䣺\n");
	scanf("%d", &(hm->nums[hm->size].age));
	printf("�������Ա�\n");
	scanf("%s", hm->nums[hm->size].sex);
	printf("���������֤�ţ�\n");
	scanf("%s", hm->nums[hm->size].identify);
	printf("������绰��\n");
	scanf("%s", hm->nums[hm->size].phone);
	hm->size++;
	//¼��ɹ�
	printf("�Ǽǳɹ�\n");
}

//��ӡס����Ϣ
void PrintMember(const hotelMember* hm) {
	int i = 0;
	printf("%10s %5s %5s %20s %15s\n", "����", "����", "�Ա�", "���֤��", "�绰");
	for (i = 0; i < hm->size; i++) {
		printf("%10s ", hm->nums[i].name);
		printf("%5d", hm->nums[i].age);
		printf("%5s", hm->nums[i].sex);
		printf("%20s", hm->nums[i].identify);
		printf("%15s\n", hm->nums[i].phone);
	}
}

//ɾ��ס����Ϣ
void DelMember(hotelMember* hm) {
	printf("������ס��������\n");
	int rst = search(*hm);
	if (rst == -1) {
		printf("ס�Ͳ�����\n");
		return;
	}
	int j = 0;
	for (j = rst; j < hm->size - 1; j++) {
		hm->nums[j] = hm->nums[j + 1];
	}
	hm->size--;
	printf("�˷��ɹ�\n");
}

//����ס����Ϣ��ģ��
int search(hotelMember hm) {
	char name[20];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < hm.size; i++) { //ƥ���ַ����Ƿ����
		if (strcmp(hm.nums[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}
//����ס����Ϣ
void FindMember(hotelMember hm) {
	printf("������ס��������\n");
	int rst = search(hm);
	if (rst == -1) {
		printf("ס��������\n");
		return;
	}
	printf("%10s %5s %5s %20s %15s\n", "����", "����", "�Ա�", "���֤��", "�绰");
	printf("%10s %5d %5s %20s %15s ", 
		hm.nums[rst].name,hm.nums[rst].age,hm.nums[rst].sex,hm.nums[rst].identify,hm.nums[rst].phone);

}

//�ֶ��ͷ�����
void DestoryMember(hotelMember* hm) {
	free(hm->nums);
	hm->nums = NULL;
	hm->capacity = 0;
	hm->size = 0;
}