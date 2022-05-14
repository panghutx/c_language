#ifndef GUEST_H
#define GUEST_H
#include <iostream>
#include <stdint.h>
using namespace std;

class Guest
{
	string name;
	uint32_t id;
public:
	Guest()
	{}
	Guest(string name,uint32_t id):name(name),id(id) {}
	string& get_name(void);
	uint32_t get_id(void);
	Guest& operator=(Guest guest);
};

#endif//GUEST_H

