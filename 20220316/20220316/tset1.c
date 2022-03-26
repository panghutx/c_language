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
		return; //�жϺϷ��ԣ������Ա�Ϊ�ջ���ֵ��С����ֵ���˳�
	for (i = 0; i < L->length; i++) { //�������Ա�Ԫ��
		if (L->elem[i] >= k1 && L->elem[i] <= k2)
			count++;  //����k1��k2֮���Ԫ�ظ��������Ԫ������k1<=elem[i]<=k2,count++;
		else
			L->elem[i - count] = L->elem[i]; //�����������������i�±��Ԫ����ǰ�ƶ�count��
	}
	L->length -= count; //��������Ա��ȵ���ԭ���ȼ�ȥɾ��Ԫ�ظ���
}
void sq_dele1(Sqlist* L, ElemType k1, ElemType k2) {
	if (L->length == 0 || k1 >= k2)
		return; //�жϺϷ��ԣ������Ա�Ϊ�ջ���ֵ��С����ֵ���˳�
	int i = 0;
	for(i=0;i<L->length;i++){
		if (L->elem[i] >= k1 && L->elem[i] <= k2) {
			break;
		}
		//�ҵ��׸�Ҫɾ��Ԫ�ص�λ��
	}
	int j = 0;
	for (j = i; j < L->length; j++) {
		if (L->elem[j] >= k2) {
			break;
		}
		//�ҵ����һ��Ҫɾ��Ԫ�ص�λ��
	}
	int count = j - i + 1; //�õ�Ҫɾ��Ԫ�ظ���
	int k = 0;
	for (k = j+1; k < L->length; k++)//����k2�����Ԫ��
		L->elem[k - count] = L->elem[k]; //��ǰԪ��ǰ��count��λ��
	L->length -= count; //ԭ���ȼ�ȥɾ��Ԫ�ظ���
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
