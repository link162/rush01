#include "header.hpp"

Ram::Ram() { std::cout << "create Ram\n";}
Ram::~Ram() { std::cout << "delete Ram\n";}
Ram::Ram(const Ram &old)
{
	*this = old;
}
Ram &Ram::operator = (const Ram &old)
{
	*this = old;
	return *this;
}
void Ram::update()
{
	//get_curr_time();
}

