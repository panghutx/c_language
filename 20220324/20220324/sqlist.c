#define _CRT_SECURE_NO_WARNINGS 1
#include "sqlist.h"

//1.顺序表初始化
void InitList(SqList* list) {
	list->length = 0;
}
// 2、判断是否空
bool ListIsEmpty(SqList list) {
	if (list.length == 0) {
		return true;
	}
	else {
		return false;
	}
}
//3.元素个数
int ListLength(SqList list) {
	return list.length;
}
// 4、增——在表的第i个位置插入元素e
bool ListInsert(SqList* list, int i, ElemType e) {
	//判断合法性
	if (list->length >= MaxSize) {  //数组已满
		return false;
	}
	if (i<1 || i>list->length + 1) { //插入范围错误
		return false;
	}
	//插入元素，位置不在length+1处
	int j = list->length-1; //j是下标位
	for (j; j >=i-1; j--) { 
		list->data[j+1] = list->data[j];
	}
	list->data[i-1] = e;
	list->length++;
	return true;
}

// 5、删——删除表中位置i的元素，并存储在e中
bool ListDelet(SqList* list, int i, ElemType* e) {
	if (list->length == 0) {
		return false;
	}
	if (i<1 || i>list->length) {
		return false;
	}
	int j = list->length - 1;
	if (i < list->length) { //删除不是最后位置
		for (int j = i; j <= list->length;j++) {
			list->data[j-1] = list->data[j];
		}
	}
	
	*e = list->data[i - 1];
	list->length--;//包含了删除最后一个元素的情况
	return true;
}

// 6、改——将表中第i个元素改为e
bool ListChange(SqList* list, int i, ElemType e) {
	//判断i的合法性
	
	if (i<1 || i>list->length) {
		return false;
	}
	list->data[i - 1] = e;
	return true;
}

// 7、查——查询线性表中是否存在元素e，找到返回表中序号，否则返回0
int LocateElem(SqList list, ElemType e) {
	int i = 0;
	for (i = 0; i < list.length; i++) {
		if (list.data[i] == e) {
			return i + 1;
		}
	}
	return 0;
}
// 8、取——获取第i个位置的元素，并存储在e中
bool GetElem(SqList list, int i, ElemType* e) {
	if (i<1 || i>list.length) {
		return false;
	}
	*e = list.data[i - 1];
	return true;
}
//10.清空顺序表
void Clear(SqList* list) {
	list->length = 0;
}
// 11.合并两个线性表
void UnionL(SqList* La, SqList Lb) {
	int Lalength = ListLength(*La);
	int Lblength = ListLength(Lb);
	ElemType e;
	//取出Lb中的元素，判断是否在La中，若不在，加入
	for (int i = 1; i <= Lblength; i++) {
		GetElem(Lb, i, &e);
	}
	if (!LocateElem(*La, e)) {
		ListInsert(La, Lalength++, e);
	}
	
}

// 12.打印顺序表
void printSqList(SqList* list) {
	int i = 0;
	for (i = 0; i < list->length; i++) {
		printf("%d ", list->data[i]);
	}
}