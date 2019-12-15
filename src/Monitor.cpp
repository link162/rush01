#include "header.hpp"
#include "mlx.h"

void *mlx_ptr;
void *win_ptr;
void *img_ptr;
void *data_ptr;

/////////////////////////////////////////////////////////

void	move(int *data_ptr)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			if (x > SPACETIME)
				data_ptr[WIDTH * y + x - SPACETIME] = data_ptr[WIDTH * y + x];
	}
}

void	move_and_draw(t_vector old[], t_vector n[], int *data_ptr)
{
	move(data_ptr);
	old[0].x -= SPACETIME;	
	old[1].x -= SPACETIME;	
	line_to_image(old[0], n[0], data_ptr);
	line_to_image(old[1], n[1], data_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}

//////////////////////////////////////////////////////
Monitor::Monitor() : ncurses(false), size(6)
{
	for (int i = 1; i <= 6; i++)
	{
		order[i - 1] = i;
	}
}
Monitor::Monitor(int size) : ncurses(false), size(size) {}
Monitor::~Monitor() {}
Monitor::Monitor(const Monitor &old)
{
	*this = old;
}
Monitor &Monitor::operator = (const Monitor &old)
{
	this->size = old.size;
	return *this;
}
void Monitor::add_module(int act)
{
	if (!act)
		ncurses = true;
	else
		order[size++] = act;
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

void	write_time_mlx(Monitor *m, int *y)
{

	char name[] = "CURTIME";
	mlx_string_put(mlx_ptr, win_ptr, 240, *y, 0xFFFFFF, &m->curr_time[0]);
	mlx_string_put(mlx_ptr, win_ptr, 300, *y + 30, 0xF00F0F, name);
	*y += 100;
}

void	write_network_mlx(Monitor *m, int *y)
{


	char str0[30];
	sprintf(str0, "out: %d bytes", m->bytes_in);

	mlx_string_put(mlx_ptr, win_ptr, 250, *y, 0xFFFFFF, str0);
	char s[] = "BYTES IN";
	mlx_string_put(mlx_ptr, win_ptr, 300, *y + 30, 0xF00F0F, s);

	char str1[30];
	sprintf(str1, "out: %d bytes", m->bytes_out);

	mlx_string_put(mlx_ptr, win_ptr, 250, *y + 100, 0xFFFFFF, str1);
	char s2[] = "BYTES OUT";
	mlx_string_put(mlx_ptr, win_ptr, 300, *y + 130, 0xF00F0F, s2);
	*y += 200;
}

void	write_os_mlx(Monitor *m, int *y)
{

	char str[] = "OS NAME";
	mlx_string_put(mlx_ptr, win_ptr, 20, *y, 0xFFFFFF, &m->os_name[0]);
	mlx_string_put(mlx_ptr, win_ptr, 300, *y + 30, 0xF00F0F, str);
	*y += 100;
}

void	write_hostname_mlx(Monitor *m, int *y)
{
	char name[] = "HOSTNAME";

	mlx_string_put(mlx_ptr, win_ptr, 270, *y, 0xFFFFFF, &m->hostname[0]);
	mlx_string_put(mlx_ptr, win_ptr, 300, *y + 30, 0xF00F0F, name);
	*y += 100;
}


int loop_hook(void *p)
{
	Monitor *m = reinterpret_cast<Monitor *>(p);

	m->update();
	static t_vector old[2] = { {500, 20}, {500, 120} };

	t_vector s[2];
	s[0].x = 500;
	s[0].y = (100 - m->cpu_load) / static_cast<float>(3) + 15;

	s[1].x = 500;
	s[1].y = (100 - m->mem_usage) / static_cast<float>(10000) + 110;

	move_and_draw(old, s, static_cast<int *>(data_ptr));

	int c = m->cpu_load;

	char str2[30];
	sprintf(str2, "cpu load: %ld", lround(m->cpu_load));

	mlx_string_put(mlx_ptr, win_ptr, 520, 20, 0xFFFFFF, str2);

	char str3[30];
	sprintf(str3, "mem usage: %d", (m->mem_usage));

	mlx_string_put(mlx_ptr, win_ptr, 520, 120, 0xFFFFFF, str3);



	char cpu[] = "CPU";
	char cores[30];
	sprintf(cores, "Cores: %d", m->cores);
	char memory[] = "MEMORY";
	mlx_string_put(mlx_ptr, win_ptr, 50, 50, 9999999 * c, cpu);
	mlx_string_put(mlx_ptr, win_ptr, 100, 50, 9999999 * c, &m->cpu_name[0]);	
	mlx_string_put(mlx_ptr, win_ptr, 500, 50, 9999999 * c, cores);

	mlx_string_put(mlx_ptr, win_ptr, 300, 150, 0xFF0000, memory);

	int y = 220;
	for (int i = 0; i < m->size; i++)
	{
		if (m->order[i] == 1)
		{
			write_time_mlx(m, &y);
		}
		if (m->order[i] == 2)
		{
			write_hostname_mlx(m, &y);
		}
		if (m->order[i] == 4)
		{
			write_network_mlx(m, &y);
		}

		if (m->order[i] == 6)
		{
			write_os_mlx(m, &y);
		}

	}
	old[0] = s[0];
	old[1] = s[1];
	sleep(1);
	return (1);
}

void Monitor::run_monitor()
{
	if (ncurses)
	{
		Ncurses disp;
		disp.init();
		while(1)
		{
			update();
			disp.display(this);
		}
	}
	else
	{
		update();

		int bpp;
		int sz_l;
		int a;
		char str[] = "rush01";

		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, WIDTH, HEIGHT, str);
		img_ptr = mlx_new_image(mlx_ptr, WIDTH, HEIGHT);
		data_ptr = reinterpret_cast<int *>(mlx_get_data_addr(img_ptr, &bpp, &sz_l, &a));

		mlx_loop_hook(mlx_ptr, (int (*)())(&loop_hook), reinterpret_cast<void *>(this));
		mlx_loop(mlx_ptr);
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
