#define _CRT_SECURE_NO_WARNINGS 1
typedef int ElemType;
#define MaxSize 100
#include<stdio.h>
#include <stdbool.h>

// ���Ա�˳��洢�ṹ

typedef struct SqList
{
	ElemType data[MaxSize];
	int length;
}SqList;

// 1����ʼ��
void InitList(SqList* list);
// 2���ж��Ƿ��
bool ListIsEmpty(SqList list);
//3.Ԫ�ظ���
int ListLength(SqList list);
// 4����
bool ListInsert(SqList* list, int i, ElemType e);
// 5��ɾ
bool ListDelet(SqList* list, int i, ElemType* e);
// 6����
bool ListChange(SqList* list, int i, ElemType e);
// 7����
int LocateElem(SqList list, ElemType e);
// 8��ȡ
bool GetElem(SqList list, int i, ElemType* e);
// 10���塪��������Ա�
void Clear(SqList* list);
// 11.�ϲ��������Ա�
void UnionL(SqList* La, SqList Lb);
// 12.��ӡ˳���
void printSqList(SqList* list);