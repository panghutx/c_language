#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//��ʼ��
void Initcontact(contact* pcon) {

	pcon->sz = 0;
	pcon->capacity = 3;
	pcon->nums = (struct Person*)calloc(3, sizeof(struct Person));
	if (pcon->nums == NULL) {
		perror(calloc);
	}
	/*memset(pcon->nums, 0, MaxNum);*/
	
}
//����
void Addcontact(contact* pcon) {
	//��������Ƿ�����
	//if (sizeof(pcon->nums) == MaxNum) {
	//	printf("�����������޷����");
	//	return;
	//}
	if (pcon->sz == pcon->capacity) {
		struct Person* tmp=(struct Person*)realloc(pcon->nums, (pcon->capacity+2) * sizeof(struct Person));
		if (tmp != NULL) {
			pcon->nums = tmp;
		}
		else {
			perror(realloc);
			return;
		}
		pcon->capacity += 2;
		printf("���ݳɹ�");
	}
	//¼����Ϣ
	printf("������������\n");
	scanf("%s", pcon->nums[pcon->sz].name);
	printf("�������Ա�\n");
	scanf("%s", pcon->nums[pcon->sz].sex);
	printf("���������䣺\n");
	scanf("%d", &pcon->nums[pcon->sz].age);
	printf("������绰��\n");
	scanf("%s", pcon->nums[pcon->sz].phone);
	pcon->sz++;
	//��ӳɹ�
	printf("��ӳɹ�\n");

}
//����
int search(contact pcon) {
	char name[20];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < pcon.sz; i++) {
		if (strcmp(pcon.nums[i].name,name)==0) {
			return i;
		}
	}
	return -1;
}

//ɾ��
void Delcontact(contact* pcon) {
	if (pcon->sz == 0) {
		printf("ͨѶ¼��Ϊ��\n");
	}
	printf("������Ҫɾ����������\n");
	int rst = search(*pcon);
	if (rst == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}
	int j = 0;
	for (j = rst; j < pcon->sz-1; j++) {
		pcon->nums[j] = pcon->nums[j + 1];
	}
	pcon->sz--;
	printf("ɾ���ɹ�\n");
}
//�޸�
void Modcontact(contact* pcon) {

	printf("������Ҫ�޸ĵ�������\n");
	int rst = search(*pcon);
	if (rst == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}
	int msg = 0;
	printf("������Ҫ�޸ĵ���Ϣ����1.���� 2.�Ա� 3.���� 4.�绰��\n");
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("����������\n");
		scanf("%s", pcon->nums[rst].name);
		break;
	case 2:
		printf("�������Ա�\n");
		scanf("%s", pcon->nums[rst].sex);
		break;
	case 3:
		printf("����������\n");
		scanf("%d", &pcon->nums[rst].age);
		break;
	case 4:
		printf("������绰\n");
		scanf("%s", pcon->nums[rst].phone);
		break;
	default:
		printf("�������");
		break;
	}
	
	printf("�޸ĳɹ�\n");
	
}

//����
void Findcontact(contact pcon) {
	printf("������Ҫ���ҵ�������\n");
	int rst = search(pcon);
	if (rst == -1) {
		printf("��ϵ�˲�����\n");
		return;
	}
	printf("%10s %5s %5s %12s\n", "����", "�Ա�", "����", "�绰");
	printf("%10s %5s %5d %12s\n", pcon.nums[rst].name, pcon.nums[rst].sex, pcon.nums[rst].age, pcon.nums[rst].phone);
}

//���
void Clearcontact(contact* pcon) {
	Initcontact(pcon);
	printf("��ճɹ�\n");
}

//����
void Ordercontact(contact* pcon) {
	int i = 0;
	int j = 0;
	struct Person tmp;
	for (i = 0; i < pcon->sz - 1; i++) {
		for (j = 0; j < pcon->sz - 1 - i; j++) {
			if (strcmp(pcon->nums[j].name, pcon->nums[j + 1].name) > 0) {
				tmp = pcon->nums[j];
				pcon->nums[j]= pcon->nums[j+1];
				pcon->nums[j + 1] = tmp;
				
			}
		}
	}
	Printcontact(*pcon);
}
//��ӡ
void Printcontact(contact pcon) {
	int i = 0;
	printf("%10s %5s %5s %12s\n", "����","�Ա�","����","�绰");
	for (i = 0; i < pcon.sz; i++) {
		printf("%10s ", pcon.nums[i].name);
		printf("%5s ", pcon.nums[i].sex);
		printf("%5d ", pcon.nums[i].age);
		printf("%12s \n", pcon.nums[i].phone);
	}
}

//�ݻ�
void Destorycontact(contact* pcon) {
	free(pcon->nums);
	pcon->nums = NULL;
	pcon->capacity = 0;
	pcon->sz = 0;
}