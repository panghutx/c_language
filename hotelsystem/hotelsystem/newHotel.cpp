#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;
#include<list>
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
	string chuang_hao = "@";//选择的床号。
	string in_time = "@";//入住时间。
	string out_time = "@";//离店时间。
	string free = "@";        //应该交纳的费用。

	void ji_ben_xin_xi() {               //顾客需要自己填入的基本信息。
		cout << "请输入您的姓名:"; cin >> this->name;
		string temp_str;
		do
		{
			cout << "请输入您的性别:";
			cin >> temp_str;
			if (temp_str == "女" || temp_str == "男")
			{
				break;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		} while (1);
		this->gender = temp_str;
		cout << "请输入您的年龄:"; cin >> this->age;
		cout << "请输入您的工作单位:"; cin >> this->work_unit;
		cout << "请输入您的职务:"; cin >> this->post;
		cout << "请输入您的地址:"; cin >> this->address;
		cout << "请输入您的ID:"; cin >> this->id;
	}
};
class Room   //房间。
{
public:
	string fang_hao = "@";		//房间号。
	string grade = "@";			//房间等级。
	string gender = "@";		//房间性别。
	string chuang_shu = "@";	//床数。
	string kong_chuang_shu = "@";//空床数。
	string chuang_list;			//床列表。如“010”,代表1号床和3号床为空床,2号床有人。

	void jian_fang() {
		cout << "请输入房间号:"; cin >> this->fang_hao;
		cout << "请输入房间等级:"; cin >> this->grade;
		string temp_str;
		do
		{
			cout << "请输入房间性别:";
			cin >> temp_str;
			if (temp_str == "女" || temp_str == "男")
			{
				break;
			}
			else
			{
				cout << "请重新输入" << endl;
			}
		} while (1);
		this->gender = temp_str;
		cout << "请输入床的总数:"; cin >> this->chuang_shu;
		this->kong_chuang_shu = this->chuang_shu;
		for (size_t i = 0; i < atoi(this->chuang_shu.c_str()); i++)
		{
			this->chuang_list += "0";
		}
	}
};
class Function		//在这个类里面存放这个程序的各个功能。
{
public:
	void save_File(list<Customer*>& customer_list) {//程序结束的时候，用这个方法保存容器里面改变的数据。
		ofstream ofs;
		ofs.open("Customer.txt", ios::out);
		for (list<Customer*>::const_iterator it = customer_list.begin(); it != customer_list.end(); it++)
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
				<< c->chuang_hao << " "
				<< c->in_time << " "
				<< c->out_time << " "
				<< c->free << endl;
		}
	}

	void save_File(list<Room*>& room_list) {//这个是房间容器的文件存放还没有实现。
		ofstream ofs;
		ofs.open("Room.txt", ios::out);
		for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {
			Room* r = *it;
			ofs << r->fang_hao << " "
				<< r->grade << " "
				<< r->gender << " "
				<< r->chuang_shu << " "
				<< r->kong_chuang_shu << " "
				<< r->chuang_list << endl;
		}
	}

	void read_File(list<Customer*>& customer_list) {//程序开始的时候，用这个方法将文件里面的数据读到容器里面。
		ifstream ifs;
		ifs.open("Customer.txt", ios::in);
		while (1)
		{
			Customer* c = new Customer();
			ifs >> c->name&& ifs >> c->gender&&
				ifs >> c->age&& ifs >> c->work_unit&&
				ifs >> c->post&& ifs >> c->address&&
				ifs >> c->id&& ifs >> c->room_grade&&
				ifs >> c->fang_hao&& ifs >> c->chuang_hao&&
				ifs >> c->in_time&& ifs >> c->out_time&&
				ifs >> c->free;
			if (c->name == "@")
			{
				break;
			}
			customer_list.push_back(c);
		}
	}

	void read_File(list<Room*>& room_list) {//这个是房间文件的录入，也没有实现。
		ifstream ifs;
		ifs.open("Room.txt", ios::in);
		while (1)
		{
			Room* r = new Room();
			ifs >> r->fang_hao&&
				ifs >> r->grade&&
				ifs >> r->gender&&
				ifs >> r->chuang_shu&&
				ifs >> r->kong_chuang_shu&&
				ifs >> r->chuang_list;
			if (r->fang_hao == "@")
			{
				break;
			}
			room_list.push_back(r);
		}
	}

	void jian_fang(list<Room*>& room_list, int num) {//创建房间。第1个传入房间链表第2个传入创建房间个数。
		for (size_t i = 0; i < num; i++)
		{
			Room* r = new Room();
			r->jian_fang();
			room_list.push_back(r);
		}
	}

	void zhu_dian(Customer* c, list<Room*> room_list) {							//住店函数。
		string grade;														//获得用户选择的等级
		cout << "本旅店共有三个等级的房间:1.一级、2.二级、3.三级\n";
		cout << "请您选择房间等级:";
		cin >> grade;

		Room* room = NULL;
		for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {//找房子,房间等级合适，性别合适，有空床。
			room = *it;
			if (room->grade != grade || room->gender != c->gender || room->kong_chuang_shu == "0")
			{
				room = NULL;
				continue;
			}
			else
			{
				c->room_grade = room->grade;		//初始化顾客的空间等级。
				c->fang_hao = room->fang_hao;		//初始化顾客的房间号。

				int kong_chuang_shu = atoi(((*it)->kong_chuang_shu).c_str());//对应房间的空床数-1
				(*it)->kong_chuang_shu = to_string(--kong_chuang_shu);
				break;
			}
		}

		if (room != NULL)//找到房子,并且一定有空床。
		{
			int chuang_hao = 0;
			for (; chuang_hao < room->chuang_list.size(); chuang_hao++)//找床号。
			{
				if (room->chuang_list[chuang_hao] == '0')
				{
					room->chuang_list[chuang_hao++] = '1';//初始化顾客的床号。
					c->chuang_hao = to_string(chuang_hao);
					cout << "成功入住到" << c->fang_hao << "号房间 " << c->chuang_hao << "号床";
					
					break;
				}
			}
		}
		else//没有找到房子
		{
			cout << "没有找到相应等级的房子，是否要更换等级？\n" << endl;
			cout << "1.是 2.否:";
			string temp;
			cin >> temp;
			if (temp == "1") {
				zhu_dian(c, room_list);
			}
			else
			{
				cout << "住店服务结束";
			}
		}
	}


	void bao_jian(Customer* c, list<Room*> room_list) {							//包房函数。
		string grade; //获得用户选择的等级
		int num;//获取用户住店人数
		cout << "本旅店共有三个等级的房间:1.一级、2.二级、3.三级\n";
		cout << "请您选择房间等级:";
		cin >> grade;
		cout << "请您选择住店人数:";
		cin >> num;

		Room* room = NULL;
		for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {//找房子,房间等级合适，性别合适，有空床。
			room = *it;
			//空床数与床数不一致，说明有人入住，不能包房
			if (room->grade != grade || room->kong_chuang_shu != room->chuang_shu) //包房，不在考虑性别
			{
				room = NULL;
				continue;
			}
			else
			{
				c->room_grade = room->grade;		//初始化顾客的空间等级。
				c->fang_hao = room->fang_hao;		//初始化顾客的房间号。

				int kong_chuang_shu = 0;//对应房间的空床数置为0
				(*it)->kong_chuang_shu = to_string(kong_chuang_shu); 
				cout << "成功包间入住" << c->fang_hao << "号房间 " << endl;
				//TODO
				break;
			}
		}

		if(room == NULL)//没有找到房子
		{
			cout << "没有找到相应等级的房子，是否要更换等级？\n" << endl;
			cout << "1.是 2.否:";
			string temp;
			cin >> temp;
			if (temp == "1") {
				bao_jian(c, room_list);
			}
			else
			{
				cout << "住店服务结束";
			}
		}
	}
	void yu_ding() {//预定功能。

	}
	void tui_fang(Customer* c,list<Customer*> customer_list, list<Room*> room_list) {//退房间功能。

		string name; //姓名
		string chuang_hao;//床号
		string fang_hao;//房号
		cout << "请输入您的姓名" << endl;
		cin >> name;
		cout << "请输入您的房号" << endl;
		cin >> fang_hao;
		cout << "请输入您的床号" << endl;
		cin >> chuang_hao;
		
		int flg = 0; //判断是否查到房信息
		
		Room* room = NULL;
		Customer* customer = NULL;

		for (list<Customer*>::const_iterator it = customer_list.begin(); it != customer_list.end(); it++) {//找人
			customer = *it;		
			if (customer->name==name && customer->fang_hao==fang_hao && customer->chuang_hao==chuang_hao) 
			{
				customer_list.remove(customer);
				
				//找到匹配项
				for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {
					room = *it;
					if ((*it)->fang_hao == fang_hao) {

						int kong_chuang_shu = atoi(((*it)->kong_chuang_shu).c_str());//对应房间的空床数+1
						(*it)->kong_chuang_shu = to_string(++kong_chuang_shu);
						flg = 1;
						break;
					}
				}

			}
			if (flg == 1) {
				break;
			}
			
			
		}
		
		if (flg == 0) {
			cout << "您的信息有误，请重新输入" << endl;
			tui_fang(c,customer_list, room_list);
		}

		if (flg==1)//找到房号，退房，回收床位
		{
			int res = atoi(chuang_hao.c_str());
			int i = 0;
			for (; i < res-1; i++) {
				//
			}
			room->chuang_list[i] = '0';
			cout << "已为您退订" << fang_hao << "号房间" << chuang_hao << "号床，欢迎下次光临" << endl;
		} 
			

	}
	void qi_ta() {//其他功能的事情。

	}
	void is_continue(int& select) {
		cout << "是否继续使用？\n";
		cout << "1.是 2.否:";
		cin >> select;
		if (select == 1)
		{
			system("cls");
		}
		else
		{
			cout << "欢迎下一次使用" << endl;
			select = 0;
		}
	}
};

int main() {
	Function* m = new Function();			//实现相应功能的类
	list<Customer*> customer_list;			//顾客信息链表
	list<Room*> room_list;	//房间信息链表
	m->read_File(customer_list);//文件信息读入
	m->read_File(room_list);

	Customer* c = new Customer();//入店登记信息。
	//c->ji_ben_xin_xi();
	//m->jian_fang(room_list,1);

	int select = 1;
	while (select)
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
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select; //接受用户选择

		switch (select)
		{
		case 1:
			
			m->zhu_dian(c, room_list);
			customer_list.push_back(c);
			m->is_continue(select);
			break;
		case 2:
			
			m->bao_jian(c, room_list);
			customer_list.push_back(c);
			m->is_continue(select);
			break;
		case 3:
			m->is_continue(select);
			break;
		case 4:
			m->tui_fang(c,customer_list, room_list);
			m->is_continue(select);
			break;
		case 5:
			m->is_continue(select);
			break;
		case 0:  //退出系统
			cout << "欢迎下一次使用" << endl;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("cls");
			break;
		}

	}

	m->save_File(room_list);			//当程序内的数据写入文件
	m->save_File(customer_list);


}
