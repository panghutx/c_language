#include "room.h"

using namespace std;

uint16_t Room::get_id(void)
{
    return id;
}
float Room::get_price(void)
{
    return price;
}
RoomType Room::get_type(void)
{
	return type;
}
void Room::set_id(uint16_t id)
{
    this->id = id;
}
void Room::set_price(float price)
{
    this->price = price;
}
void Room::set_type(RoomType type)
{
    this->type = type;
}
void Room::Member_in(int num,Guest* guest)
{
	cnt = num;
	guests = guest;
}
void Room::Member_out(void)
{
	cnt = 0;
	delete[] guests;
}
void Room::show_people(void)
{
	int z = cnt;
	while(z--)
	{
		cout<<guests[z].get_id()<<endl;
		cout << guests[z].get_name() << endl;
	}
}
