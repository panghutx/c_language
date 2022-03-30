#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

//初始化
void Initcontact(contact* pcon) {

	pcon->sz = 0;
	pcon->capacity = 3;
	pcon->nums = (struct Person*)calloc(3, sizeof(struct Person));
	if (pcon->nums == NULL) {
		perror(calloc);
	}
	/*memset(pcon->nums, 0, MaxNum);*/
	
}
//增加
void Addcontact(contact* pcon) {
	//检查数组是否满了
	//if (sizeof(pcon->nums) == MaxNum) {
	//	printf("数组已满，无法添加");
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
		printf("增容成功");
	}
	//录入信息
	printf("请输入姓名：\n");
	scanf("%s", pcon->nums[pcon->sz].name);
	printf("请输入性别：\n");
	scanf("%s", pcon->nums[pcon->sz].sex);
	printf("请输入年龄：\n");
	scanf("%d", &pcon->nums[pcon->sz].age);
	printf("请输入电话：\n");
	scanf("%s", pcon->nums[pcon->sz].phone);
	pcon->sz++;
	//添加成功
	printf("添加成功\n");

}
//查找
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

//删除
void Delcontact(contact* pcon) {
	if (pcon->sz == 0) {
		printf("通讯录已为空\n");
	}
	printf("请输入要删除的姓名：\n");
	int rst = search(*pcon);
	if (rst == -1) {
		printf("联系人不存在\n");
		return;
	}
	int j = 0;
	for (j = rst; j < pcon->sz-1; j++) {
		pcon->nums[j] = pcon->nums[j + 1];
	}
	pcon->sz--;
	printf("删除成功\n");
}
//修改
void Modcontact(contact* pcon) {

	printf("请输入要修改的姓名：\n");
	int rst = search(*pcon);
	if (rst == -1) {
		printf("联系人不存在\n");
		return;
	}
	int msg = 0;
	printf("请输入要修改的信息：（1.姓名 2.性别 3.年龄 4.电话）\n");
	scanf("%d", &msg);
	switch (msg)
	{
	case 1:
		printf("请输入姓名\n");
		scanf("%s", pcon->nums[rst].name);
		break;
	case 2:
		printf("请输入性别\n");
		scanf("%s", pcon->nums[rst].sex);
		break;
	case 3:
		printf("请输入年龄\n");
		scanf("%d", &pcon->nums[rst].age);
		break;
	case 4:
		printf("请输入电话\n");
		scanf("%s", pcon->nums[rst].phone);
		break;
	default:
		printf("输入错误");
		break;
	}
	
	printf("修改成功\n");
	
}

//查找
void Findcontact(contact pcon) {
	printf("请输入要查找的姓名：\n");
	int rst = search(pcon);
	if (rst == -1) {
		printf("联系人不存在\n");
		return;
	}
	printf("%10s %5s %5s %12s\n", "姓名", "性别", "年龄", "电话");
	printf("%10s %5s %5d %12s\n", pcon.nums[rst].name, pcon.nums[rst].sex, pcon.nums[rst].age, pcon.nums[rst].phone);
}

//清空
void Clearcontact(contact* pcon) {
	Initcontact(pcon);
	printf("清空成功\n");
}

//排序
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
//打印
void Printcontact(contact pcon) {
	int i = 0;
	printf("%10s %5s %5s %12s\n", "姓名","性别","年龄","电话");
	for (i = 0; i < pcon.sz; i++) {
		printf("%10s ", pcon.nums[i].name);
		printf("%5s ", pcon.nums[i].sex);
		printf("%5d ", pcon.nums[i].age);
		printf("%12s \n", pcon.nums[i].phone);
	}
}

//摧毁
void Destorycontact(contact* pcon) {
	free(pcon->nums);
	pcon->nums = NULL;
	pcon->capacity = 0;
	pcon->sz = 0;
}