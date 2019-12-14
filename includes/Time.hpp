#ifndef TIME
#define TIME

#include "header.hpp"

class Time : public IMonitorModule
{
	private:
	Time(const Time &old);
	Time &operator = (const Time &old);
	tm *curr;
	public:
	Time();
	~Time();
	void update();
	void introduce() const;
};

#endif
