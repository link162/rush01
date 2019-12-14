#include "header.hpp"

System::System() { std::cout << "create System\n";}
System::~System() { std::cout << "delete System\n";}
System::System(const System &old)
{
	*this = old;
}
System &System::operator = (const System &old)
{
	*this = old;
	return *this;
}
void System::update()
{
	//get_curr_time();
}

