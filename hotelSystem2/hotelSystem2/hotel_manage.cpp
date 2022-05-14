#include "hotel_manage.h"
#include "room.h"

using namespace std;

HotelManage::HotelManage(void)
{
	hotel = new Hotel;
}
HotelManage::~HotelManage(void)
{
	delete hotel;
}
void HotelManage::run(void)
{
	//hotel->show();
    while(1)
    {
        cout << "1.开房" << endl;
        cout << "2.退房" << endl;
        cout << "3.显示房间人数" << endl;
        cout << "4.查询空房" << endl;
        cout << "请选择" << endl;
        int num;
        cin >> num;
        switch (num)
        {
            case 1: in();break;
            case 2: out();break;
            case 3: show();break;
            case 4: query();break;
            case 0: return;
        }
    }
}
void HotelManage::in(void)
{
    cout << "请选择房间类型" << endl;
    cout << "Type1.普通单间" << endl;
    cout << "Type2.双人间" << endl;
    cout << "Type3.3人套间" << endl;
    cout << "Type4.豪华套房" << endl;
    int type;
    cin >> type;
    hotel->find_type(type);
    cout << "请输入人数" << endl;
    int num;
    cin >> num;
    if(type >= num)
    {
    	Guest* guest = new Guest[num];
    	cout << "请选择房间号:" << endl;
		int id,x=0,y=0;
		cin >> id;
		x = (id-100)/100;
		y = (id-100)%100;
		for(int i=0;i<num;i++)
		{
			string name;
			int id;
            cout << "请输入姓名" << endl;
			cin >> name;
			cout << "请输入身份证" << endl;
			cin >> id;
			Guest guest1(name,id);
			guest[i] = guest1;
		}
		hotel->Pcheck_in(num,guest,x,y);
	}
	else
	{
		cout << "人数过多，房间不够大" << endl;
		return;
	}
}
void HotelManage::out(void)
{
    cout << "2" << endl;
    cout << "请选择房间号:" << endl;
	int id,x=0,y=0;
	cin >> id;
	x = (id-100)/100;
	y = (id-100)%100;
	hotel->Pcheck_out(x,y);
}
void HotelManage::show(void)
{
	cout << "3" << endl;
	hotel->show_room();
}
void HotelManage::query(void)
{
    cout << "4" << endl;
    hotel->show_emroom();
}

