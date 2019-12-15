#include "header.hpp"
#include "mlx.h"
void *mlx_ptr;
void *win_ptr;
void *img_ptr;
void *data_ptr;

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
	mem_usage = stoi(exec("top -l 1 | grep 'PhysMem:' |  cut -d' ' -f2"));
	cpu_load = stof(exec("ps -A -o %cpu | awk '{s+=$1} END {print s \"%\"}'"));
	cores = stoi(exec("system_profiler SPHardwareDataType | grep Cores | awk '{print $5}'"));
	os_name = exec("sw_vers");
	bytes_in = stoi(exec("top -l 1 | grep 'Networks:' |  cut -d' ' -f3"));
	bytes_out = stoi(exec("top -l 1 | grep 'Networks:' |  cut -d' ' -f5"));
}


int loop_hook(void *param)
{
	printf("hi2\n");
	return (1);
}
	
int		mouse_move(int x, int y, void *param)
{
	return (1);
}

void Monitor::run_monitor()
{
	if (ncurses)
	{
		while(1)
		{
			update();
			Ncurses disp;
			disp.init();
			disp.display();
		}
	}
	else
	{
		int bpp;
		int sz_l;
		int a;
		char str[] = "rush01";

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, str);
		img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
		data_ptr = (int *)mlx_get_data_addr(img_ptr, &bpp, &sz_l, &a);

//		mlx_loop_hook(mlx_ptr, &do_graphics, (void *)this);
//		mlx_hook(win_ptr, 12, 12, loop_hook, (void *)this);
//		mlx_hook(win_ptr, 6, 6, mouse_move, NULL);
//		mlx_loop(mlx_ptr);
		/*
		while (1)
		{
			update();
//			system("clear");
//			introduce();
//			wait_one_sec();
		}*/
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
	PRINT(mem_usage);
}
