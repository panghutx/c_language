#include "guest.h"

string& Guest::get_name(void)
{
	return name;
}
uint32_t Guest::get_id(void)
{
	return id;
}
Guest& Guest::operator=(Guest guest)
{
	this->id = guest.id;
	this->name = guest.name;
    return *this;
}
