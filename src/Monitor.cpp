#include "header.hpp"

Monitor::Monitor() : size(2)
{
	list = new IMonitorModule*[6];
	for (int i = 0; i < size; i++)
		list[i] = NULL;
	list[0] = new Time;
	list[1] = new Hostname;
	/*list[2] = new Network;
	list[3] = new Cpu;
	list[4] = new Ram;
	list[5] = new System;*/
}
Monitor::Monitor(int size)
{
	this->size = size;
	list = new IMonitorModule*[size];
	for (int i = 0; i < size; i++)
		list[i] = NULL;
}
Monitor::~Monitor()
{
	if (list)
	{
		for (int i = 0; i < size && list[i]; i++)
			delete list[i];
		delete list;
	}
}
Monitor::Monitor(const Monitor &old)
{
	*this = old;
}
Monitor &Monitor::operator = (const Monitor &old)
{
	*this = old;
	return *this;
}
void Monitor::add_module(IMonitorModule *mod)
{
	int i;
	for(i = 0; i < size && list[i]; i++);
	list[i] = mod;
}

int get_sec()
{
	time_t now = time(0);
	tm *curr = localtime(&now);
	return curr->tm_sec;
}

void wait_one_sec()
{
	int sec = get_sec();
	sec = sec == 59 ? 0 : sec + 1;
	while (1)
	{
		if (sec == get_sec())
			break;
	}
}
void Monitor::run_monitor()
{
	PRINT(size);
	while (1)
	{
		system("clear");
		for (int i = 0; i < size; i++)
			list[i]->update();
		for (int i = 0; i < size; i++)
			list[i]->introduce();
		wait_one_sec();
	}
}
