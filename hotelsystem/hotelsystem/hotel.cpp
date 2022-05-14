#include<iostream>
#include<fstream>
using namespace std;
#include<list>
#include<vector>

class Customer      //ס��˿͵���
{
	
public:
	//����Ϊ�˿͵����г�Ա����
	string name = "@";
	string gender = "@";
	string age = "@";
	string work_unit = "@";    //������λ��
	string post = "@";        //������ְ��
	string address = "@";     //��ͥ��ַ��
	string id = "@";          //���֤�š�
	string room_grade = "@";//��ѡ��ķ��ݵȼ���
	string fang_hao = "@";//ѡ��ķ���š�
	string zhuang_hao = "@";//ѡ��Ĵ��š�
	string in_time = "@";//��סʱ�䡣
	string out_time = "@";//���ʱ�䡣
	string free = "@";        //Ӧ�ý��ɵķ��á�
	void ji_ben_xin_xi() {               //�˿���Ҫ�Լ�����Ļ�����Ϣ��
		cout << "��������������:"; cin >> this->name;
		cout << "�����������Ա�:"; cin >> this->gender;
		cout << "��������������:"; cin >> this->age;
		cout << "���������Ĺ�����λ:"; cin >> this->work_unit;
		cout << "����������ְ��:"; cin >> this->post;
		cout << "���������ĵ�ַ:"; cin >> this->address;
		cout << "����������ID:"; cin >> this->id;
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

class MyClass		//��������������������ĸ������ܡ�
{
	Customer* customer[20];
	vector<Customer>vCus; //ס������
	Room room[20];
	
public:
	void save_File(list<Customer*>& cl) {//���������ʱ�����������������������ı�����ݡ�
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
	//��ʼ������
	void init_Room() {
		int j, k = 101;
		//��ʼ��3���ķ��䣬����Ϊ101-106��6�䣬����Ϊ3
		for (j = 0; j < 6; j++) {
			room[j].chuang_shu = 3;
			room[j].kong_chuang_shu = 3;
			room[j].fang_hao = k++;
			room[j].grade = 3;
			room[j].gender = 0;//0Ϊ�գ�1ΪŮ�ͣ�2Ϊ�п�
		}
		//��ʼ��2���ķ��䣬����201-206������2
		k = 201;
		for (j = 6; j < 12; j++) {
			room[j].chuang_shu = 2;
			room[j].kong_chuang_shu = 2;
			room[j].fang_hao = k++;
			room[j].grade = 2;
			room[j].gender = 0;//0Ϊ�գ�1ΪŮ�ͣ�2Ϊ�п�
		}
		//��ʼ��1���ķ��䣬����301-308������2
		k = 301;
		for (j = 12; j < 20; j++) {
			room[j].chuang_shu = 2;
			room[j].kong_chuang_shu = 2;
			room[j].fang_hao = k++;
			room[j].grade = 1;
			room[j].gender = 0;//0Ϊ�գ�1ΪŮ�ͣ�2Ϊ�п�
		}
	}
	void show_Room()
	{
		cout << "����" << '\t';
		cout << "�Ա�" << '\t';
		cout << "�ȼ�" << '\t';
		cout << "����" << '\t';
		cout << "�մ���" << endl;
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
	void save_File() {//����Ƿ����������ļ���Ż�û��ʵ�֡�

		
	}
	void read_File(list<Customer*>& cl) {//����ʼ��ʱ��������������ļ���������ݶ����������档
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
	void read_File(list<Room*>& cl) {//����Ƿ����ļ���¼�룬Ҳû��ʵ�֡�
		//TODO
		////���ļ��ж�ȡ������
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
	void zhu_dian() {//ס�꺯����
		int room_grade;
		cout << "����ѡ�񷿼�ȼ�:\n";
		cout << "1.һ��\n2.����\n3.����\n";
		cin >> room_grade;
		cout << "Ϊ���ҵ����·���" << endl;
		cout << "����" << '\t';
		cout << "�Ա�" << '\t';
		cout << "�ȼ�" << '\t';
		cout << "����" << '\t';
		cout << "�մ���" << endl;
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
			cout << "��ѡ����Ҫ��ס�ķ����" << endl;
			cin >> room_num;

			for (j = 0; j < 20; j++)
			{
				if (room[j].fang_hao == room_num) {
					
					room[j].status = 1;
					room[j].kong_chuang_shu--;
				}
			}
			
			cout << "��ס�ɹ�" << endl;
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
	void bao_jian() {//���书��

	}
	void yu_ding() {//Ԥ�����ܡ�

	}
	void tui_fang() {//�˷��书�ܡ�

	}
	void qi_ta() {//�������ܵ����顣

	}

	//��ʼ���ÿ�����
	void initVector()
	{
		//ȷ���������״̬
		
		//vCus.clear();

		//��ȡ��Ϣ   
		ifstream ifs;
		ifs.open("Customer.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ȡʧ��" << endl;
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

		//	cout << "��ǰ�˿�����Ϊ�� " << vCus.size() << endl;
		ifs.close();

	}

	//���ÿ������򷿺Ų�ѯ�ÿ���Ϣ��
	void search_Consumer()
	{
		cout << "������Ҫ���ҵ������򷿺�:" << endl;
		string input;
		cin >> input;
		
		
			//����ÿ�
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
					cout << "δ��ѯ�������Ϣ" << endl;
				}
			}
		}
		
	



	void jie_mian() {		//������ʾ����������ܼ򵥣����ö��ˡ�
		int select = 0;

		while (true)
		{
			cout << endl << "ѡ����Ӧ����" << endl;
			cout << "\t\t -------------------------------\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          1.ס�����           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          2.�������           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          3.Ԥ������           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          4.��    ��           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          5.��    ��           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t|          6.��    ��           |\n";
			cout << "\t\t|                               |\n";
			cout << "\t\t -------------------------------\n";
			cout << "��������ѡ��: ";

			cin >> select; //�����û�ѡ��

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
			case 6:  //�˳�ϵͳ
				cout << "��ӭ��һ��ʹ��" << endl;
				system("pause");

				break;
			default:
				cout << "��������������ѡ��" << endl;
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

	list<Customer*> cl;			//����һ�����������������ŵ��ǹ˿�������ָ�롣
	
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