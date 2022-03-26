#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#define ListSize 10
typedef int ElemType;
typedef struct 
{
	ElemType elem[ListSize];
	int length;
}Sqlist;

void sq_dele(Sqlist* L, ElemType k1, ElemType k2) {
	int i, count = 0;
	if (L->length == 0 || k1 >= k2) 
		return; //判断合法性，若线性表为空或左值不小于右值，退出
	for (i = 0; i < L->length; i++) { //遍历线性表元素
		if (L->elem[i] >= k1 && L->elem[i] <= k2)
			count++;  //计算k1，k2之间的元素个数：如果元素满足k1<=elem[i]<=k2,count++;
		else
			L->elem[i - count] = L->elem[i]; //如果不满足条件，让i下标的元素向前移动count步
	}
	L->length -= count; //最后让线性表长度等于原长度减去删除元素个数
}
void sq_dele1(Sqlist* L, ElemType k1, ElemType k2) {
	if (L->length == 0 || k1 >= k2)
		return; //判断合法性，若线性表为空或左值不小于右值，退出
	int i = 0;
	for(i=0;i<L->length;i++){
		if (L->elem[i] >= k1 && L->elem[i] <= k2) {
			break;
		}
		//找到首个要删除元素的位置
	}
	int j = 0;
	for (j = i; j < L->length; j++) {
		if (L->elem[j] >= k2) {
			break;
		}
		//找到最后一个要删除元素的位置
	}
	int count = j - i + 1; //得到要删除元素个数
	int k = 0;
	for (k = j+1; k < L->length; k++)//遍历k2后面的元素
		L->elem[k - count] = L->elem[k]; //当前元素前移count个位置
	L->length -= count; //原长度减去删除元素个数
}
void print(Sqlist* L) {
	int i = 0;
	for (i = 0; i < L->length; i++) {
		printf("%d ", L->elem[i]);
	}
}
int main()
{
	Sqlist arr = { {1,2,3,4,5,6,7,8,9,10},10 };
	sq_dele1(arr.elem, 5, 8);
	print(arr.elem);
}
