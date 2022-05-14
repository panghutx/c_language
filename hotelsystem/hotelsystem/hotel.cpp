#include<iostream>
#include<fstream>
using namespace std;
#include<list>
#include<vector>

class Customer      //住店顾客的类
{
	
public:
	//以下为顾客的所有成员属性
	string name = "@";
	string gender = "@";
	string age = "@";
	string work_unit = "@";    //工作单位。
	string post = "@";        //工作的职务。
	string address = "@";     //家庭地址。
	string id = "@";          //身份证号。
	string room_grade = "@";//所选择的房屋等级。
	string fang_hao = "@";//选择的房间号。
	string zhuang_hao = "@";//选择的床号。
	string in_time = "@";//入住时间。
	string out_time = "@";//离店时间。
	string free = "@";        //应该交纳的费用。
	void ji_ben_xin_xi() {               //顾客需要自己填入的基本信息。
		cout << "请输入您的姓名:"; cin >> this->name;
		cout << "请输入您的性别:"; cin >> this->gender;
		cout << "请输入您的年龄:"; cin >> this->age;
		cout << "请输入您的工作单位:"; cin >> this->work_unit;
		cout << "请输入您的职务:"; cin >> this->post;
		cout << "请输入您的地址:"; cin >> this->address;
		cout << "请输入您的ID:"; cin >> this->id;
	}
};

struct Room {
	int fang_hao;
	int grade;
	int gender;
	int chuang_shu;
	int kong_chuang_shu;
	int status;
};

class MyClass		//在这个类里面存放这个程序的各个功能。
{
	Customer* customer[20];
	vector<Customer>vCus; //住客容器
	Room room[20];
	
public:
	void save_File(list<Customer*>& cl) {//程序结束的时候，用这个方法保存容器里面改变的数据。
		ofstream ofs;
		ofs.open("Customer.txt", ios::out);
		for (list<Customer*>::const_iterator it = cl.begin(); it != cl.end(); it++)
		{
			Customer* c = *it;
			ofs << c->name << " "
				<< c->gender << " "
				<< c->age << " "
				<< c->work_unit << " "
				<< c->post << " "
				<< c->address << " "
				<< c->id << " "
				<< c->room_grade << " "
				<< c->fang_hao << " "
				<< c->zhuang_hao << " "
				<< c->in_time << " "
				<< c->out_time << " "
				<< c->free << endl;
		}
	}
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
	void save_File() {//这个是房间容器的文件存放还没有实现。

		
	}
	void read_File(list<Customer*>& cl) {//程序开始的时候，用这个方法将文件里面的数据读到容器里面。
		ifstream ifs;
		ifs.open("Customer.txt", ios::in);
		while (1)
		{
			Customer* c = new Customer();
			ifs >> c->name&& ifs >> c->gender&&
				ifs >> c->age&& ifs >> c->work_unit&&
				ifs >> c->post&& ifs >> c->address&&
				ifs >> c->id&& ifs >> c->room_grade&&
				ifs >> c->fang_hao&& ifs >> c->zhuang_hao&&
				ifs >> c->in_time&& ifs >> c->out_time&&
				ifs >> c->free;
			if (c->name == "@")
			{
				break;
			}
			cl.push_back(c);
		}
	}
	void read_File(list<Room*>& cl) {//这个是房间文件的录入，也没有实现。
		//TODO
		////从文件中读取的内容
		//string f_fang_hao;
		//int f_grade;
		//string f_gender;
		//int f_chuang_shu;
		//int f_kong_chuang_shu;

		//ifstream ifs;
		//ifs.open("Room.txt", ios::in);
		//	
		//while (ifs >> f_fang_hao && ifs >> f_grade && ifs >> f_gender && ifs >> f_chuang_shu && ifs >> f_kong_chuang_shu)
		//{
		//	cout << f_fang_hao<<" ";
		//	cout << f_grade;
		//	cout << f_gender;
		//	cout << f_chuang_shu;
		//	cout << f_kong_chuang_shu;
		//	cout << endl;

		//}

	}
	void zhu_dian() {//住店函数。
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
		int n;
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
					
					room[j].status = 1;
					room[j].kong_chuang_shu--;
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
			break;
		}

	}
	void bao_jian() {//包间功能

	}
	void yu_ding() {//预定功能。

	}
	void tui_fang() {//退房间功能。

	}
	void qi_ta() {//其他功能的事情。

	}

	//初始化旅客容器
	void initVector()
	{
		//确保容器清空状态
		
		//vCus.clear();

		//读取信息   
		ifstream ifs;
		ifs.open("Customer.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "文件读取失败" << endl;
			return;
		}

		Customer c;
		while (ifs >> c.name&& ifs >> c.gender&&
			ifs >> c.age&& ifs >> c.work_unit&&
			ifs >> c.post&& ifs >> c.address&&
			ifs >> c.id&& ifs >> c.room_grade&&
			ifs >> c.fang_hao&& ifs >> c.zhuang_hao&&
			ifs >> c.in_time&& ifs >> c.out_time&&
			ifs >> c.free)
		{
			vCus.push_back(c);
		}

		//	cout << "当前顾客数量为： " << vCus.size() << endl;
		ifs.close();

	}

	//按旅客姓名或房号查询旅客信息。
	void search_Consumer()
	{
		cout << "请输入要查找的姓名或房号:" << endl;
		string input;
		cin >> input;
		
		
			//检测旅客
			for (vector<Customer>::iterator it = vCus.begin(); it != vCus.end(); it++)
			{
				if (input.compare(it->name) == 0 || input.compare(it->fang_hao) == 0) {
					cout << it->name << " "
						<< it->gender << " "
						<< it->age << " "
						<< it->work_unit << " "
						<< it->post << " "
						<< it->address << " "
						<< it->id << " "
						<< it->room_grade << " "
						<< it->fang_hao << " "
						<< it->zhuang_hao << " "
						<< it->in_time << " "
						<< it->out_time << " "
						<< it->free << endl;
				}
				else {
					cout << "未查询到相关信息" << endl;
				}
			}
		}
		
	



	void jie_mian() {		//界面显示方法。这个很简单，不用动了。
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
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
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
};

int main() {
	MyClass* m = new MyClass();

	list<Customer*> cl;			//这是一个链表容器，里面存放的是顾客这个类的指针。
	
	for (size_t i = 0; i < 1; i++)
	{
		Customer* c = new Customer();
		c->ji_ben_xin_xi();
		cl.push_back(c);
	}
	m->init_Room();
	m->zhu_dian();
	m->save_File(cl);
	//m->initVector();
	//m->search_Consumer();

	
	

	//list<Room*> cl;
	//m->read_File(cl);


}