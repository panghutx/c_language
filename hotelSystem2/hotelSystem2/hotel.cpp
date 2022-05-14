#include <cstdio>
#include <cstring>
#include <fstream>
#include "hotel.h"
#include "tools.h"

using namespace std;

Hotel::Hotel(void)
{
	fstream fs("hotel.txt",ios::in);
	if(!fs.good())
	{
		cout << "请输入酒店层数:";
		cin >> floor;
		room_cnt = new uint16_t[floor];
		
		for(int i=0;i<floor;i++)
		{
			cout << "输入第" << i + 1 << "层房间数量" << endl;cin >> room_cnt[i];
		}
	}
	else
	{
		fs >> floor;
		room_cnt = new uint16_t[floor];
		for(int i=0;i<floor;i++)
		{
			fs >> room_cnt[i];
		}
	}
	
	rooms = new Room*[floor];
	for(int i=0;i<floor;i++)
	{
		    rooms[i] = new Room[room_cnt[i]];
		    for(int j=0;j<room_cnt[i];j++)
		    {
		    	if(i<4)
		        {   
		        	rooms[i][j].set_id((i+1)*100+j);
		            rooms[i][j].set_type(Type1);
		            rooms[i][j].set_price(333);
		        }
		        else if(i<7)
		        {
		        	rooms[i][j].set_id((i+1)*100+j);
		            rooms[i][j].set_type(Type2);
		            rooms[i][j].set_price(555);
		        }
		        else if(i<9)
		        {
		            rooms[i][j].set_id((i+1)*100+j);
		            rooms[i][j].set_type(Type3);
		            rooms[i][j].set_price(888);
		        }
		        else
		        {
		            rooms[i][j].set_id((i+1)*100+j);
		            rooms[i][j].set_type(Type4);
		            rooms[i][j].set_price(1222);
    	        }
    	        
			} 
		}
}
Hotel::~Hotel(void)
{
	fstream fs("hotel.txt",ios::out|ios::trunc);
	fs << floor << endl;
	for(int i=0;i<floor;i++)
    {
    	fs << room_cnt[i] << endl;    
    }
}
void Hotel::show(void)
{
    for(int i=0;i<floor;i++)
    {
        for(int j=0;j<room_cnt[i];j++)
        {
            cout << "房间号" << rooms[i][j].get_id() << "-类型" << rooms[i][j].get_type() << " ";
        }
        cout << endl;
     }
}

void Hotel::find_type(int type)
{
	for(int i=0;i<floor;i++)
    {
        for(int j=0;j<room_cnt[i];j++)
        {
        	if((RoomType)type == rooms[i][j].get_type())
            cout << "房间号" << rooms[i][j].get_id() << "-类型" << rooms[i][j].get_type() << " ";
        }
        cout << endl;
     }
}
void Hotel::show_room(void)
{
	for(int i=0;i<floor;i++)
    {
        for(int j=0;j<room_cnt[i];j++)
       	{
       		if(0 != rooms[i][j].cnt)
            {
            	fflush(stdin);
        	   	cout << "房间号" << rooms[i][j].get_id() << " 人数" << rooms[i][j].cnt << " ";
            	//printf("%d\n",rooms[i][j].cnt);
            }
       	}
    }
    cout << endl;
}

void Hotel::show_emroom(void)
{
	for(int i=0;i<floor;i++)
    {
        for(int j=0;j<room_cnt[i];j++)
       	{
       		if(0 == rooms[i][j].cnt)
            {
            	fflush(stdin);
        	   	cout << "房间号" << rooms[i][j].get_id() << " ";
            	//printf("%d\n",rooms[i][j].cnt);
            }
       	}
    }
    cout << endl;
}
void Hotel::Pcheck_in(int num,Guest* guest,int x,int y)
{
	rooms[x][y].Member_in(num,guest);
}
void Hotel::Pcheck_out(int x,int y)
{
	rooms[x][y].Member_out();
}
