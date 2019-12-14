#include "header.hpp"

Time::Time() {
	std::cout << "create Time\n";
}
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
	time_t now = time(0);
	curr = localtime(&now);
}
void Time::introduce() const
{
	char str[STD_BUFF];
	strftime(str, 100, "%Y %B %d  %H:%M:%S", curr);
	PRINT(str);
}
