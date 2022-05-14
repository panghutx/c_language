// ConsoleApplication1.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//

#include <iostream>
#include <string.h>
#include <stdlib.h>
void enter();
void check_in();
void inquire();
void check_out();
void initial_room();
using namespace std;
int i = 0;
struct Room
{
    int number;
    int floor;
    int state;
};
class Customer
{
    char name[10], ID[19];
    int  room_number;
    int  change;
public:
    Customer()
    {
        cout << "��������˿͵�����\n";
        cin >> name;

        cout << "��������˿͵����֤����\n";
        cin >> ID;
        change = 0;
    }
    void set_name(char* _name) { strcpy_s(name, _name); }
    void set_ID(char* _ID) { strcpy_s(ID, _ID); }
    void set_room_number(int n) { room_number = n; }
    char* get_name() { return name; }
    char* get_ID() { return ID; }
    int  get_room_number() { return room_number; }
    ~Customer()
    {
        cout << "�ù˿��˷��ɹ�!" << endl;
    }
};
Room room[80];
Customer* customer[80];
int main()
{
    char choice = '1';
    initial_room();
    while (choice == '1')
    {
        enter();
        cout << endl;
        cout << "����ʹ�ñ�ϵͳ�밴\"1\",�˳��밴\"2\"!  ";
        cin >> choice;
        cout << endl;
    }
}
//ϵͳ���
void enter()
{
    int kind_of_service;
    while (1)
    {
        cout << "��ѡ��������:��������ס���˷����ǲ�ѯ? \n";
        cout << " 1->��ѯ  2->��ס  3->�˷�  4->�˳�:  ";
        cin >> kind_of_service;
        if ((kind_of_service <= 4) && (kind_of_service >= 1))
        {

            switch (kind_of_service)
            {
            case 1: inquire();
                break;
            case 2: check_in();
                break;
            case 3: check_out();
                break;
            case 4: exit(0);
                break;
            }
        }
        else
        {
            cout << "������������������!\n";
            continue;
        }
    }
}
//��ס�Ǽ�
void check_in()
{
    //char name1[10], id1[19];
    customer[i] = new Customer;
    int room_floor;
    cout << "����ѡ��Ԥ�������¥��:\n";
    cout << "1.һ¥\n2.��¥\n3.��¥\n4.��¥\n";
    cin >> room_floor;

    switch (room_floor)
    {
        int n;
    case 1:
        for (n = 0; n < 20; n++)
        {
            if (room[n].state == 0)
            {
                cout << "��ס�������Ϊ: " << room[n].number << endl;
                room[n].state = 1;
                customer[i]->set_room_number(room[n].number);
                break;
            }
        }
        break;
    case 2:
        for (n = 20; n < 40; n++)
        {
            if (room[n].state == 0)
            {
                cout << "��ס�������Ϊ: " << room[n].number << endl;
                room[n].state = 1;
                customer[i]->set_room_number(room[n].number);
                break;
            }
        }
        break;
    case 3:
        for (n = 40; n < 60; n++)
        {
            if (room[n].state == 0)
            {
                cout << "��ס�������Ϊ: " << room[n].number << endl;
                room[n].state = 1;
                customer[i]->set_room_number(room[n].number);
                break;
            }
        }
        break;
    case 4:
        for (n = 60; n < 80; n++)
        {
            if (room[n].state == 0)
            {
                cout << "��ס�������Ϊ: " << room[n].number << endl;
                room[n].state = 1;
                customer[i]->set_room_number(room[n].number);
                break;
            }
        }
        break;
    }
    i++;
}
//�˷�����
void check_out()
{
    char name2[10], id2[19];
    int room_number;
    cout << "������Ҫ�˷��Ĺ˿����������֤����:\n";
    cin >> name2 >> id2;
    for (int j = 0; j < i; j++)
    {
        if ((strcmp(customer[j]->get_name(), name2) == 0) && (strcmp(customer[j]->get_ID(), id2) == 0))
        {
            room_number = customer[j]->get_room_number();
        }
        cout << endl;
        cout << "�Ƿ�ȷ���˷�,�밴1: ";
        char account;
        cin >> account;
        if (account == '1')
        {
            for (int k = 0; k < 80; k++)
            {
                if (room[k].number == customer[j]->get_room_number())
                    room[k].state = 0;
            }
            i--;
            for (; j < i; j++)
            {
                customer[j] = customer[j + 1];
            }
            delete customer[i];
        }
    }
}
//��Ϣ��ѯ
void inquire()
{
    int j, k = 0;
    cout << endl;
    cout << "���з��仹û��Ԥ����Ҳû����ס��" << endl;
    for (j = 0; j < 80; j++)
    {
        if (room[j].state == 0)
        {
            if (k % 10 == 0) cout << endl;
            cout << room[j].number << '\t';
            k++;
        }
    }
    k = 0;
    cout << endl;
    cout << "���з���������ס��" << endl;
    for (j = 0; j < 80; j++)
    {
        if (room[j].state == 1)
        {
            if (k % 10 == 0) cout << endl;
            cout << room[j].number << '\t';
            k++;
        }
    }
    cout << endl;
}
//������Ϣ��ʼ��
void initial_room()
{
    int j, k = 101;
    for (j = 0; j < 20; j++)
    {
        room[j].number = k++;
        room[j].floor = 1;
        room[j].state = 0;
    }
    k = 201;
    for (j = 20; j < 40; j++)
    {
        room[j].number = k++;
        room[j].floor = 2;
        room[j].state = 0;
    }
    k = 301;
    for (j = 40; j < 60; j++)
    {
        room[j].number = k++;
        room[j].floor = 3;
        room[j].state = 0;
    }
    k = 401;
    for (j = 60; j < 80; j++)
    {
        room[j].number = k++;
        room[j].floor = 4;
        room[j].state = 0;
    }
}

// ���г���: Ctrl + F5 ����� >����ʼִ��(������)���˵�
// ���Գ���: F5 ����� >����ʼ���ԡ��˵�

// ����ʹ�ü���: 
//   1. ʹ�ý��������Դ�������������/�����ļ�
//   2. ʹ���Ŷ���Դ�������������ӵ�Դ�������
//   3. ʹ��������ڲ鿴���������������Ϣ
//   4. ʹ�ô����б��ڲ鿴����
//   5. ת������Ŀ��>���������Դ����µĴ����ļ�����ת������Ŀ��>�����������Խ����д����ļ���ӵ���Ŀ
//   6. ��������Ҫ�ٴδ򿪴���Ŀ����ת�����ļ���>���򿪡�>����Ŀ����ѡ�� .sln �ļ�