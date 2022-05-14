#include<iostream>
#include<fstream>

using namespace std;
int i = 0;
class Consumer      //ס��˿͵���
{

public:
	//����Ϊ�˿͵����г�Ա����
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
		cout << "��������������\n";
		cin >> name;

		cout << "�������������֤����\n";
		cin >> ID;

		cout << "�����������Ա�(1����Ů����2��������)\n";
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


void zhu_dian() {//ס�꺯����
	
	consumer[i] = new Consumer;
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

				room[j].kong_chuang_shu--;
				room[j].gender = consumer[i]->get_sex();
				consumer[i]->set_room_number(room[j].fang_hao);
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

		cout << "��ѡ����Ҫ��ס�ķ����" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu--;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "��ס�ɹ�" << endl;
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

		cout << "��ѡ����Ҫ��ס�ķ����" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu--;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "��ס�ɹ�" << endl;
		break;
	}
	i++;

}

//չʾ����
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

void bao_jian() {//���书��
	int i = 0;
	consumer[i] = new Consumer;
	int room_grade;
	int room_number; //��ס����
	int room_num;//�����
	cout << "��ӭѡ��������" << endl;
	cout << "����ѡ�񷿼�ȼ�:\n";
	cout << "1.һ��\n2.����\n3.����\n";
	cin >> room_grade;
	cout << "��ѡ����ס����" << endl;
	cin >> room_number;
	cout << "��������ѡ��Ϊ��ƥ�䵽���·���" << endl;
	cout << "����" << '\t';
	cout << "�Ա�" << '\t';
	cout << "�ȼ�" << '\t';
	cout << "����" << '\t';
	cout << "�մ���" << endl;


	int j = 0;
	

	switch (room_grade)
	{

		//
	case 1:

		
		for (j = 0; j < 20; j++)
		{
			//����������������ȣ�����û��ס�ˣ��������ڵ���Ҫ��ס����
			if (room[j].grade == 1 && room[j].gender==0 && room[j].kong_chuang_shu>=room_number) {
				cout << room[j].fang_hao << '\t';
				cout << room[j].gender << '\t';
				cout << room[j].grade << '\t';
				cout << room[j].chuang_shu << '\t';
				cout << room[j].kong_chuang_shu << endl;
			}
		}
		cout << "��ѡ����Ҫ�ķ����" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].kong_chuang_shu==0;
				room[j].gender = consumer[i]->get_sex();
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "��ס�ɹ�" << endl;


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

		cout << "��ѡ����Ҫ��ס�ķ����" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu=0;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "��ס�ɹ�" << endl;
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

		cout << "��ѡ����Ҫ��ס�ķ����" << endl;
		cin >> room_num;

		for (j = 0; j < 20; j++)
		{
			if (room[j].fang_hao == room_num) {

				room[j].gender = consumer[i]->get_sex();
				room[j].kong_chuang_shu=0;
				consumer[i]->set_room_number(room[j].fang_hao);
			}
		}

		cout << "��ס�ɹ�" << endl;
		break;
	}
	i++;

}

void yu_ding() {//Ԥ�����ܡ�

}


void tui_fang() {//�˷��书�ܡ�

	char name2[10], id2[19];
	int room_number;
	cout << "������Ҫ�˷��Ĺ˿����������֤����:\n";
	cin >> name2 >> id2;
	for (int j = 0; j < i; j++)
	{
		if ((strcmp(consumer[j]->get_name(), name2) == 0) && (strcmp(consumer[j]->get_ID(), id2) == 0))
		{
			room_number = consumer[j]->get_room_number();
		}
		cout << endl;
		cout << "�Ƿ�ȷ���˷�,�밴1: ";
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


int main()
{
	menu();
}