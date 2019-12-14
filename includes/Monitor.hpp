#ifndef MONITOR
#define MONITOR

#include "header.hpp"

class Monitor
{
	int size;
	IMonitorModule **list;
	Monitor(const Monitor &old);
	Monitor &operator = (const Monitor &old);
	public:
	Monitor();
	Monitor(int size);
	~Monitor();
	void add_module(IMonitorModule *mod);
	void run_monitor();
};

#endif
