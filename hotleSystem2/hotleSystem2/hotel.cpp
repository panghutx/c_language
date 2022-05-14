// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
        cout << "请您输入顾客的姓名\n";
        cin >> name;

        cout << "请您输入顾客的身份证号码\n";
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
        cout << "该顾客退房成功!" << endl;
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
        cout << "继续使用本系统请按\"1\",退出请按\"2\"!  ";
        cin >> choice;
        cout << endl;
    }
}
//系统入口
void enter()
{
    int kind_of_service;
    while (1)
    {
        cout << "请选择服务类别:订房、入住、退房还是查询? \n";
        cout << " 1->查询  2->入住  3->退房  4->退出:  ";
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
            cout << "您的输入有误，请重试!\n";
            continue;
        }
    }
}
//入住登记
void check_in()
{
    //char name1[10], id1[19];
    customer[i] = new Customer;
    int room_floor;
    cout << "请您选择预定房间的楼层:\n";
    cout << "1.一楼\n2.二楼\n3.三楼\n4.四楼\n";
    cin >> room_floor;

    switch (room_floor)
    {
        int n;
    case 1:
        for (n = 0; n < 20; n++)
        {
            if (room[n].state == 0)
            {
                cout << "入住房间号码为: " << room[n].number << endl;
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
                cout << "入住房间号码为: " << room[n].number << endl;
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
                cout << "入住房间号码为: " << room[n].number << endl;
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
                cout << "入住房间号码为: " << room[n].number << endl;
                room[n].state = 1;
                customer[i]->set_room_number(room[n].number);
                break;
            }
        }
        break;
    }
    i++;
}
//退房结算
void check_out()
{
    char name2[10], id2[19];
    int room_number;
    cout << "请输入要退房的顾客姓名和身份证号码:\n";
    cin >> name2 >> id2;
    for (int j = 0; j < i; j++)
    {
        if ((strcmp(customer[j]->get_name(), name2) == 0) && (strcmp(customer[j]->get_ID(), id2) == 0))
        {
            room_number = customer[j]->get_room_number();
        }
        cout << endl;
        cout << "是否确定退房,请按1: ";
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
//信息查询
void inquire()
{
    int j, k = 0;
    cout << endl;
    cout << "下列房间还没人预订，也没人入住：" << endl;
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
    cout << "下列房间有人入住：" << endl;
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
//房间信息初始化
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

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件