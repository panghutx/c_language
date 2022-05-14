#include<iostream>
#include<fstream>

using namespace std;
int i = 0;
class Consumer      //住店顾客的类
{

public:
	//以下为顾客的所有成员属性
	char name[10];
	char ID[19];
	int sex;
	char work_unit[20];
	char post[20];
	char address[20];
	char room_grade[10];
	char fang_hao[10];
	char  in_time[10];
	char out_time[20];
	char free[10];

	int  room_number;
	

	Consumer()
	{
		cout << "请输入您的姓名\n";
		cin >> name;

		cout << "请输入您的身份证号码\n";
		cin >> ID;

		cout << "请输入您的性别(1代表女生，2代表男生)\n";
		cin >> sex;


	}
	void set_name(char* _name) 
	{ 
		strcpy_s(name, _name); 
	}
	void set_ID(char* _ID) 
	{ 
		strcpy_s(ID, _ID); 
	}
	void set_sex(int n)
	{
		sex = n;
	}
	void set_room_number(int n)
	{
		room_number = n;
	}
	char* get_name() 
	{ 
		return name;
	}
	char* get_ID()
	{ 
		return ID; 
	}
	int  get_room_number() 
	{ 
		return room_number;
	}
	int  get_sex()
	{
		return sex;
	}
};

struct Room {
	int fang_hao;
	int grade;
	int gender;
	int chuang_shu;
	int kong_chuang_shu;
};
Room room[20];
Consumer* consumer[20];



//初始化房间
void init_Room() {
	int j, k = 101;
	//初始化3级的房间，房号为101-106，6间，床数为3
	for (j = 0; j < 6; j++) {
		room[j].chuang_shu = 3;
		room[j].kong_chuang_shu = 3;
		room[j].fang_hao = k++;
		room[j].grade = 3;
		room[j].gender = 0;//0为空，1为女客，2为男客
	}
	//初始化2级的房间，房号201-206，床数2
	k = 201;
	for (j = 6; j < 12; j++) {
		room[j].chuang_shu = 2;
		room[j].kong_chuang_shu = 2;
		room[j].fang_hao = k++;
		room[j].grade = 2;
		room[j].gender = 0;//0为空，1为女客，2为男客
	}
	//初始化1级的房间，房号301-308，床数2
	k = 301;
	for (j = 12; j < 20; j++) {
		room[j].chuang_shu = 2;
		room[j].kong_chuang_shu = 2;
		room[j].fang_hao = k++;
		room[j].grade = 1;
		room[j].gender = 0;//0为空，1为女客，2为男客
	}
}


void zhu_dian() {//住店函数。
	
	consumer[i] = new Consumer;
	int room_grade;

	cout << "请您选择房间等级:\n";
	cout << "1.一级\n2.二级\n3.三级\n";
	cin >> room_grade;
	cout << "为您找到以下房间" << endl;
	cout << "房号" << '\t';
	cout << "性别" << '\t';
	cout << "等级" << '\t';
	cout << "床数" << '\t';
	cout << "空床数" << endl;


	int j = 0;
	int room_num;

	switch (room_grade)
	{

		//
	case 1:


		for (j = 0; j < 20; j++)
		{
			if (room[j].grade == 1) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}
		cout << "请选择你要入住的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].kong_chuang_shu--;
				room[j].gender = consumer[i]->get_sex();
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;


		break;
	case 2:
		j = 0;
		for (j = 0; j < 20; j++)
		{
			if (room[j].grade == 2) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}

		cout << "请选择你要入住的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu--;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;
		break;
	case 3:

		for (j = 0; j < 20; j++)
		{
			if (room[j].grade == 3) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}

		cout << "请选择你要入住的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu--;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;
		break;
	}
	i++;

}

//展示房间
void show_Room()
{
	cout << "房号" << '\t';
	cout << "性别" << '\t';
	cout << "等级" << '\t';
	cout << "床数" << '\t';
	cout << "空床数" << endl;
	int j = 0;
	for (j = 0; j < 20; j++)
	{
		cout << room[j].fang_hao << '\t';
		cout << room[j].gender << '\t';
		cout << room[j].grade << '\t';
		cout << room[j].chuang_shu << '\t';
		cout << room[j].kong_chuang_shu << endl;


	}
}

void bao_jian() {//包间功能
	int i = 0;
	consumer[i] = new Consumer;
	int room_grade;
	int room_number; //入住人数
	int room_num;//房间号
	cout << "欢迎选择包间服务" << endl;
	cout << "请您选择房间等级:\n";
	cout << "1.一级\n2.二级\n3.三级\n";
	cin >> room_grade;
	cout << "请选择入住人数" << endl;
	cin >> room_number;
	cout << "根据您的选择为您匹配到以下房间" << endl;
	cout << "房号" << '\t';
	cout << "性别" << '\t';
	cout << "等级" << '\t';
	cout << "床数" << '\t';
	cout << "空床数" << endl;


	int j = 0;
	

	switch (room_grade)
	{

		//
	case 1:

		
		for (j = 0; j < 20; j++)
		{
			//满足条件：级数相等，房间没有住人，床数大于等于要入住人数
			if (room[j].grade == 1 && room[j].gender==0 && room[j].kong_chuang_shu>=room_number) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}
		cout << "请选择你要的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].kong_chuang_shu==0;
				room[j].gender = consumer[i]->get_sex();
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;


		break;
	case 2:
		j = 0;
		for (j = 0; j < 20; j++)
		{
			if (room[j].grade == 2 && room[j].gender == 0 && room[j].kong_chuang_shu >= room_number) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}

		cout << "请选择你要入住的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu=0;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;
		break;
	case 3:

		for (j = 0; j < 20; j++)
		{
			if (room[j].grade == 3 && room[j].gender == 0 && room[j].kong_chuang_shu >= room_number) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}

		cout << "请选择你要入住的房间号" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu=0;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "入住成功" << endl;
		break;
	}
	i++;

}

void yu_ding() {//预定功能。

}


void tui_fang() {//退房间功能。

	char name2[10], id2[19];
	int room_number;
	cout << "请输入要退房的顾客姓名和身份证号码:\n";
	cin >> name2 >> id2;
	for (int j = 0; j < i; j++)
	{
		if ((strcmp(consumer[j]->get_name(), name2) == 0) && (strcmp(consumer[j]->get_ID(), id2) == 0))
		{
			room_number = consumer[j]->get_room_number();
		}
		cout << endl;
		cout << "是否确定退房,请按1: ";
		char account;
		cin >> account;
		if (account == '1')
		{
			for (int k = 0; k < 20; k++)
			{
				if (room[k].fang_hao == consumer[j]->get_room_number()) {
					room[k].gender = 0;
					room[k].kong_chuang_shu++;
				}
					
			}
			i--;
			for (; j < i; j++)
			{
				consumer[j] = consumer[j + 1];
			}
			delete consumer[i];
		}
	}
}


void menu() {
	init_Room();
	int select = 0;

	while (true)
	{
		cout << endl << "选择相应服务" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.住店服务           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.包间服务           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.预定房间           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          4.退    房           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          5.其    他           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          6.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";

		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:
			
			zhu_dian();
			show_Room();
			break;
		case 2:
			bao_jian();
			break;
		case 3:
			break;
		case 4:
			tui_fang();
			break;
		case 5:
			break;
		case 6:  //退出系统
			cout << "欢迎下一次使用" << endl;
			system("pause");

			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}

	}
	system("pause");

}


int main()
{
	menu();
}