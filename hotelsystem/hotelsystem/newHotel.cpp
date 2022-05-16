#include<iostream>
#include<fstream>
#include<string>
#include <sstream>
#include <iomanip>
#include <chrono>

using namespace std;
#include<list>
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
	string chuang_hao = "@";//ѡ��Ĵ��š�
	string in_time = "@";//��סʱ�䡣
	string out_time = "@";//���ʱ�䡣
	string free = "@";        //Ӧ�ý��ɵķ��á�

	void ji_ben_xin_xi() {               //�˿���Ҫ�Լ�����Ļ�����Ϣ��
		cout << "��������������:"; cin >> this->name;
		string temp_str;
		do
		{
			cout << "�����������Ա�:";
			cin >> temp_str;
			if (temp_str == "Ů" || temp_str == "��")
			{
				break;
			}
			else
			{
				cout << "����������" << endl;
			}
		} while (1);
		this->gender = temp_str;
		cout << "��������������:"; cin >> this->age;
		cout << "���������Ĺ�����λ:"; cin >> this->work_unit;
		cout << "����������ְ��:"; cin >> this->post;
		cout << "���������ĵ�ַ:"; cin >> this->address;
		cout << "����������ID:"; cin >> this->id;
	}
};
class Room   //���䡣
{
public:
	string fang_hao = "@";		//����š�
	string grade = "@";			//����ȼ���
	string gender = "@";		//�����Ա�
	string chuang_shu = "@";	//������
	string kong_chuang_shu = "@";//�մ�����
	string chuang_list;			//���б��硰010��,����1�Ŵ���3�Ŵ�Ϊ�մ�,2�Ŵ����ˡ�

	void jian_fang() {
		cout << "�����뷿���:"; cin >> this->fang_hao;
		cout << "�����뷿��ȼ�:"; cin >> this->grade;
		string temp_str;
		do
		{
			cout << "�����뷿���Ա�:";
			cin >> temp_str;
			if (temp_str == "Ů" || temp_str == "��")
			{
				break;
			}
			else
			{
				cout << "����������" << endl;
			}
		} while (1);
		this->gender = temp_str;
		cout << "�����봲������:"; cin >> this->chuang_shu;
		this->kong_chuang_shu = this->chuang_shu;
		for (size_t i = 0; i < atoi(this->chuang_shu.c_str()); i++)
		{
			this->chuang_list += "0";
		}
	}
};
class Function		//��������������������ĸ������ܡ�
{
public:
	void save_File(list<Customer*>& customer_list) {//���������ʱ�����������������������ı�����ݡ�
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

	void save_File(list<Room*>& room_list) {//����Ƿ����������ļ���Ż�û��ʵ�֡�
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

	void read_File(list<Customer*>& customer_list) {//����ʼ��ʱ��������������ļ���������ݶ����������档
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

	void read_File(list<Room*>& room_list) {//����Ƿ����ļ���¼�룬Ҳû��ʵ�֡�
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

	void jian_fang(list<Room*>& room_list, int num) {//�������䡣��1�����뷿�������2�����봴�����������
		for (size_t i = 0; i < num; i++)
		{
			Room* r = new Room();
			r->jian_fang();
			room_list.push_back(r);
		}
	}

	void zhu_dian(Customer* c, list<Room*> room_list) {							//ס�꺯����
		string grade;														//����û�ѡ��ĵȼ�
		cout << "���õ깲�������ȼ��ķ���:1.һ����2.������3.����\n";
		cout << "����ѡ�񷿼�ȼ�:";
		cin >> grade;

		Room* room = NULL;
		for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {//�ҷ���,����ȼ����ʣ��Ա���ʣ��пմ���
			room = *it;
			if (room->grade != grade || room->gender != c->gender || room->kong_chuang_shu == "0")
			{
				room = NULL;
				continue;
			}
			else
			{
				c->room_grade = room->grade;		//��ʼ���˿͵Ŀռ�ȼ���
				c->fang_hao = room->fang_hao;		//��ʼ���˿͵ķ���š�

				int kong_chuang_shu = atoi(((*it)->kong_chuang_shu).c_str());//��Ӧ����Ŀմ���-1
				(*it)->kong_chuang_shu = to_string(--kong_chuang_shu);
				break;
			}
		}

		if (room != NULL)//�ҵ�����,����һ���пմ���
		{
			int chuang_hao = 0;
			for (; chuang_hao < room->chuang_list.size(); chuang_hao++)//�Ҵ��š�
			{
				if (room->chuang_list[chuang_hao] == '0')
				{
					room->chuang_list[chuang_hao++] = '1';//��ʼ���˿͵Ĵ��š�
					c->chuang_hao = to_string(chuang_hao);
					cout << "�ɹ���ס��" << c->fang_hao << "�ŷ��� " << c->chuang_hao << "�Ŵ�";
					
					break;
				}
			}
		}
		else//û���ҵ�����
		{
			cout << "û���ҵ���Ӧ�ȼ��ķ��ӣ��Ƿ�Ҫ�����ȼ���\n" << endl;
			cout << "1.�� 2.��:";
			string temp;
			cin >> temp;
			if (temp == "1") {
				zhu_dian(c, room_list);
			}
			else
			{
				cout << "ס��������";
			}
		}
	}


	void bao_jian(Customer* c, list<Room*> room_list) {							//����������
		string grade; //����û�ѡ��ĵȼ�
		int num;//��ȡ�û�ס������
		cout << "���õ깲�������ȼ��ķ���:1.һ����2.������3.����\n";
		cout << "����ѡ�񷿼�ȼ�:";
		cin >> grade;
		cout << "����ѡ��ס������:";
		cin >> num;

		Room* room = NULL;
		for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {//�ҷ���,����ȼ����ʣ��Ա���ʣ��пմ���
			room = *it;
			//�մ����봲����һ�£�˵��������ס�����ܰ���
			if (room->grade != grade || room->kong_chuang_shu != room->chuang_shu) //���������ڿ����Ա�
			{
				room = NULL;
				continue;
			}
			else
			{
				c->room_grade = room->grade;		//��ʼ���˿͵Ŀռ�ȼ���
				c->fang_hao = room->fang_hao;		//��ʼ���˿͵ķ���š�

				int kong_chuang_shu = 0;//��Ӧ����Ŀմ�����Ϊ0
				(*it)->kong_chuang_shu = to_string(kong_chuang_shu); 
				cout << "�ɹ�������ס" << c->fang_hao << "�ŷ��� " << endl;
				//TODO
				break;
			}
		}

		if(room == NULL)//û���ҵ�����
		{
			cout << "û���ҵ���Ӧ�ȼ��ķ��ӣ��Ƿ�Ҫ�����ȼ���\n" << endl;
			cout << "1.�� 2.��:";
			string temp;
			cin >> temp;
			if (temp == "1") {
				bao_jian(c, room_list);
			}
			else
			{
				cout << "ס��������";
			}
		}
	}
	void yu_ding() {//Ԥ�����ܡ�

	}
	void tui_fang(Customer* c,list<Customer*> customer_list, list<Room*> room_list) {//�˷��书�ܡ�

		string name; //����
		string chuang_hao;//����
		string fang_hao;//����
		cout << "��������������" << endl;
		cin >> name;
		cout << "���������ķ���" << endl;
		cin >> fang_hao;
		cout << "���������Ĵ���" << endl;
		cin >> chuang_hao;
		
		int flg = 0; //�ж��Ƿ�鵽����Ϣ
		
		Room* room = NULL;
		Customer* customer = NULL;

		for (list<Customer*>::const_iterator it = customer_list.begin(); it != customer_list.end(); it++) {//����
			customer = *it;		
			if (customer->name==name && customer->fang_hao==fang_hao && customer->chuang_hao==chuang_hao) 
			{
				customer_list.remove(customer);
				
				//�ҵ�ƥ����
				for (list<Room*>::const_iterator it = room_list.begin(); it != room_list.end(); it++) {
					room = *it;
					if ((*it)->fang_hao == fang_hao) {

						int kong_chuang_shu = atoi(((*it)->kong_chuang_shu).c_str());//��Ӧ����Ŀմ���+1
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
			cout << "������Ϣ��������������" << endl;
			tui_fang(c,customer_list, room_list);
		}

		if (flg==1)//�ҵ����ţ��˷������մ�λ
		{
			int res = atoi(chuang_hao.c_str());
			int i = 0;
			for (; i < res-1; i++) {
				//
			}
			room->chuang_list[i] = '0';
			cout << "��Ϊ���˶�" << fang_hao << "�ŷ���" << chuang_hao << "�Ŵ�����ӭ�´ι���" << endl;
		} 
			

	}
	void qi_ta() {//�������ܵ����顣

	}
	void is_continue(int& select) {
		cout << "�Ƿ����ʹ�ã�\n";
		cout << "1.�� 2.��:";
		cin >> select;
		if (select == 1)
		{
			system("cls");
		}
		else
		{
			cout << "��ӭ��һ��ʹ��" << endl;
			select = 0;
		}
	}
};

int main() {
	Function* m = new Function();			//ʵ����Ӧ���ܵ���
	list<Customer*> customer_list;			//�˿���Ϣ����
	list<Room*> room_list;	//������Ϣ����
	m->read_File(customer_list);//�ļ���Ϣ����
	m->read_File(room_list);

	Customer* c = new Customer();//���Ǽ���Ϣ��
	//c->ji_ben_xin_xi();
	//m->jian_fang(room_list,1);

	int select = 1;
	while (select)
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
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select; //�����û�ѡ��

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
		case 0:  //�˳�ϵͳ
			cout << "��ӭ��һ��ʹ��" << endl;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("cls");
			break;
		}

	}

	m->save_File(room_list);			//�������ڵ�����д���ļ�
	m->save_File(customer_list);


}
