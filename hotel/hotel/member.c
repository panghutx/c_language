#include"member.h"

//初始化
void InitMember(hotelMember* hm) {
	hm->size = 0;
	hm->capacity = 10; //默认能容纳10人
	//分配10人的空间
	hm->nums = (Consumer*)calloc(10, sizeof(Consumer));
	//开辟内存失败，打印错误信息
	if (hm->nums == NULL) {
		perror("InitMember::calloc");
	}
	
}

//动态扩容
void checkCapacity(hotelMember* hm) {
	if (hm->size == hm->capacity) {
		Consumer* tmp = (Consumer*) realloc( hm->nums, (hm->capacity + 5) * sizeof(Consumer));
		//扩容成功
		if (tmp != NULL) {
			hm->nums = tmp;
		}
		else {
			perror(realloc);
			return;
		}
		hm->capacity += 5;
		//printf("扩容成功");
	}
	
}
//增加住客信息
void AddMember(hotelMember* hm) {
	//检查是否需要扩容
	//checkCapacity(&hm);
	//录入信息
	printf("请输入姓名：\n");
	scanf("%s", hm->nums[hm->size].name);
	printf("请输入年龄：\n");
	scanf("%d", &(hm->nums[hm->size].age));
	printf("请输入性别：\n");
	scanf("%s", hm->nums[hm->size].sex);
	printf("请输入身份证号：\n");
	scanf("%s", hm->nums[hm->size].identify);
	printf("请输入电话：\n");
	scanf("%s", hm->nums[hm->size].phone);
	hm->size++;
	//录入成功
	printf("登记成功\n");
}

//打印住客信息
void PrintMember(const hotelMember* hm) {
	int i = 0;
	printf("%10s %5s %5s %20s %15s\n", "姓名", "年龄", "性别", "身份证号", "电话");
	for (i = 0; i < hm->size; i++) {
		printf("%10s ", hm->nums[i].name);
		printf("%5d", hm->nums[i].age);
		printf("%5s", hm->nums[i].sex);
		printf("%20s", hm->nums[i].identify);
		printf("%15s\n", hm->nums[i].phone);
	}
}

//删除住客信息
void DelMember(hotelMember* hm) {
	printf("请输入住客姓名：\n");
	int rst = search(*hm);
	if (rst == -1) {
		printf("住客不存在\n");
		return;
	}
	int j = 0;
	for (j = rst; j < hm->size - 1; j++) {
		hm->nums[j] = hm->nums[j + 1];
	}
	hm->size--;
	printf("退房成功\n");
}

//查找住户信息子模块
int search(hotelMember hm) {
	char name[20];
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < hm.size; i++) { //匹配字符串是否相等
		if (strcmp(hm.nums[i].name, name) == 0) {
			return i;
		}
	}
	return -1;
}
//查找住客信息
void FindMember(hotelMember hm) {
	printf("请输入住客姓名：\n");
	int rst = search(hm);
	if (rst == -1) {
		printf("住户不存在\n");
		return;
	}
	printf("%10s %5s %5s %20s %15s\n", "姓名", "年龄", "性别", "身份证号", "电话");
	printf("%10s %5d %5s %20s %15s ", 
		hm.nums[rst].name,hm.nums[rst].age,hm.nums[rst].sex,hm.nums[rst].identify,hm.nums[rst].phone);

}

//手动释放数据
void DestoryMember(hotelMember* hm) {
	free(hm->nums);
	hm->nums = NULL;
	hm->capacity = 0;
	hm->size = 0;
}