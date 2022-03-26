#define _CRT_SECURE_NO_WARNINGS 1
#include "sqlist.h"

//1.˳����ʼ��
void InitList(SqList* list) {
	list->length = 0;
}
// 2���ж��Ƿ��
bool ListIsEmpty(SqList list) {
	if (list.length == 0) {
		return true;
	}
	else {
		return false;
	}
}
//3.Ԫ�ظ���
int ListLength(SqList list) {
	return list.length;
}
// 4���������ڱ�ĵ�i��λ�ò���Ԫ��e
bool ListInsert(SqList* list, int i, ElemType e) {
	//�жϺϷ���
	if (list->length >= MaxSize) {  //��������
		return false;
	}
	if (i<1 || i>list->length + 1) { //���뷶Χ����
		return false;
	}
	//����Ԫ�أ�λ�ò���length+1��
	int j = list->length-1; //j���±�λ
	for (j; j >=i-1; j--) { 
		list->data[j+1] = list->data[j];
	}
	list->data[i-1] = e;
	list->length++;
	return true;
}

// 5��ɾ����ɾ������λ��i��Ԫ�أ����洢��e��
bool ListDelet(SqList* list, int i, ElemType* e) {
	if (list->length == 0) {
		return false;
	}
	if (i<1 || i>list->length) {
		return false;
	}
	int j = list->length - 1;
	if (i < list->length) { //ɾ���������λ��
		for (int j = i; j <= list->length;j++) {
			list->data[j-1] = list->data[j];
		}
	}
	
	*e = list->data[i - 1];
	list->length--;//������ɾ�����һ��Ԫ�ص����
	return true;
}

// 6���ġ��������е�i��Ԫ�ظ�Ϊe
bool ListChange(SqList* list, int i, ElemType e) {
	//�ж�i�ĺϷ���
	
	if (i<1 || i>list->length) {
		return false;
	}
	list->data[i - 1] = e;
	return true;
}

// 7���顪����ѯ���Ա����Ƿ����Ԫ��e���ҵ����ر�����ţ����򷵻�0
int LocateElem(SqList list, ElemType e) {
	int i = 0;
	for (i = 0; i < list.length; i++) {
		if (list.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
// 8��ȡ������ȡ��i��λ�õ�Ԫ�أ����洢��e��
bool GetElem(SqList list, int i, ElemType* e) {
	if (i<1 || i>list.length) {
		return false;
	}
	*e = list.data[i - 1];
	return true;
}
//10.���˳���
void Clear(SqList* list) {
	list->length = 0;
}
// 11.�ϲ��������Ա�
void UnionL(SqList* La, SqList Lb) {
	int Lalength = ListLength(*La);
	int Lblength = ListLength(Lb);
	ElemType e;
	//ȡ��Lb�е�Ԫ�أ��ж��Ƿ���La�У������ڣ�����
	for (int i = 1; i <= Lblength; i++) {
		GetElem(Lb, i, &e);
	}
	if (!LocateElem(*La, e)) {
		ListInsert(La, Lalength++, e);
	}
	
}

// 12.��ӡ˳���
void printSqList(SqList* list) {
	int i = 0;
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
}