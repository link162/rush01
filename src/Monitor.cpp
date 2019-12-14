#include "header.hpp"

Monitor::Monitor() : ncurses(false), size(6) {}
Monitor::Monitor(int size) : ncurses(false), size(size) {}
Monitor::~Monitor() {}
Monitor::Monitor(const Monitor &old)
{
	*this = old;
}
Monitor &Monitor::operator = (const Monitor &old)
{
	*this = old;
	return *this;
}
void Monitor::add_module(int i, int act)
{
	if (!act)
		ncurses = true;
	else
		order[i] = act;
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
void Monitor::update()
{
	time_t now = time(0);
	tm *curr = localtime(&now);
	struct_curr_time = curr;
	char str[100];
	strftime(str, 100, "%Y %B %d  %H:%M:%S", curr);
	std::string n(str);
	curr_time = n;
	uptime = exec("uptime");
	username = exec("whoami");
	hostname = exec("hostname");
	cpu_name = exec("sysctl -n machdep.cpu.brand_string");
	cpu_load = stof(exec("ps -A -o %cpu | awk '{s+=$1} END {print s \"%\"}'"));
	cores = stoi(exec("system_profiler SPHardwareDataType | grep Cores | awk '{print $5}'"));
	os_name = exec("sw_vers");
	bytes_in = stoi(exec("top -l 1 | grep 'Networks:' |  cut -d' ' -f3"));
	bytes_out = stoi(exec("top -l 1 | grep 'Networks:' |  cut -d' ' -f5"));
}
void Monitor::run_monitor()
{
	PRINT(size);
	while (1)
	{
		update();
		system("clear");
		introduce();
		wait_one_sec();
	}
}
void Monitor::introduce() const
{
	PRINT(ncurses);
	PRINT(curr_time);
	PRINT(uptime);
	PRINT(username);
	PRINT(hostname);
	PRINT(cpu_name);
	PRINT(cpu_load);
	PRINT(cores);
	PRINT(os_name);
	PRINT(bytes_in);
	PRINT(bytes_out);
}
