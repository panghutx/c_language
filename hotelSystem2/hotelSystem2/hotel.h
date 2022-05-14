#ifndef HOTEL_H
#define HOTEL_H

#include "room.h"
#include <cstdio>

class Hotel
{
	int floor;
	uint16_t* room_cnt;
	Room** rooms;
public:
	Hotel(void);
	~Hotel(void);
	void show(void);
	//查看该类型的房间
	void find_type(int type);
	void Pcheck_in(int num,Guest* guest,int x,int y);
	void Pcheck_out(int x,int y);
	void show_room(void);
	void show_emroom(void);
};

#endif//HOTEL_H

