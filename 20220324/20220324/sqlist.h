#define _CRT_SECURE_NO_WARNINGS 1
typedef int ElemType;
#define MaxSize 100
#include<stdio.h>
#include <stdbool.h>

// 线性表顺序存储结构

typedef struct SqList
{
	ElemType data[MaxSize];
	int length;
}SqList;

// 1、初始化
void InitList(SqList* list);
// 2、判断是否空
bool ListIsEmpty(SqList list);
//3.元素个数
int ListLength(SqList list);
// 4、增
bool ListInsert(SqList* list, int i, ElemType e);
// 5、删
bool ListDelet(SqList* list, int i, ElemType* e);
// 6、改
bool ListChange(SqList* list, int i, ElemType e);
// 7、查
int LocateElem(SqList list, ElemType e);
// 8、取
bool GetElem(SqList list, int i, ElemType* e);
// 10、清——清空线性表
void Clear(SqList* list);
// 11.合并两个线性表
void UnionL(SqList* La, SqList Lb);
// 12.打印顺序表
void printSqList(SqList* list);