#ifndef MONITOR
#define MONITOR

#include "header.hpp"

class Monitor : public IMonitorModule
{
	bool ncurses;
	int size;
	int order[6];
	tm *struct_curr_time;
	std::string curr_time;
	std::string uptime;
	std::string username;
	std::string hostname;
	std::string cpu_name;
	std::string os_name;
	float cpu_load;
	int cores;
	int mem_usage; //Mb
	int bytes_in;
	int bytes_out;
	
	public:
	void update();
	Monitor(const Monitor &old);
	Monitor &operator = (const Monitor &old);
	Monitor();
	Monitor(int size);
	~Monitor();
	void add_module(int i, int act);
	void introduce()const;
	void run_monitor();
};
/*
 * 1-time
 * 2-hostname
 * 3-CPU
 * 4-Network
 * 5-RAM
 * 6-OS
 */
#endif
