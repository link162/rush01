#include "header.hpp"

Time::Time() { std::cout << "create Time\n";}
Time::~Time() { std::cout << "delete Time\n";}
Time::Time(const Time &old)
{
	*this = old;
}
Time &Time::operator = (const Time &old)
{
	*this = old;
	return *this;
}
void Time::update()
{
	//get_curr_time();
}

