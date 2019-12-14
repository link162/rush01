#ifndef TIME
#define TIME

#include "header.hpp"

class Time : public IMonitorModule
{
	private:
	std::string time;
	std::string data;
	public:
	Time();
	~Time();
	Time(const Time &old);
	Time &operator = (const Time &old);
	void update();
};

#endif
