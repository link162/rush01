#include "header.hpp"

Ncurses::Ncurses() {}
Ncurses::~Ncurses() {}
Ncurses::Ncurses(Ncurses const &old) { *this = old;}
Ncurses &Ncurses::operator = (Ncurses const &old)
{
	*this = old;
	return *this;
}
void Ncurses::init(void)
{
	initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    start_color();
    init_pair(DISP_WHITE, COLOR_WHITE, COLOR_BLACK);
    init_pair(DISP_RED, COLOR_RED, COLOR_BLACK);
    init_pair(DISP_GREEN, COLOR_GREEN, COLOR_BLACK);
    init_pair(DISP_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(DISP_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(DISP_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(DISP_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
}
void write_hostname(Monitor const *monitor, int *y)
{
    mvprintw(*y, 2, "Host info:");
    mvprintw(*y + 1, 6, monitor->username.c_str());
    mvprintw(*y + 2, 6, monitor->hostname.c_str());
	*y += 4;
	
}
void write_os(Monitor const *monitor, int *y)
{
    mvprintw(*y, 2, "OS info:");
//	*y += 1;
	std::stringstream ss(monitor->os_name);
    std::string token;
    while (std::getline(ss, token, '\n')) {
    	mvprintw(*y + 1, 6, token.c_str());
		*y += 1;
    }
	*y += 2;
	
}
void write_cpu(Monitor const *monitor, int *y)
{
    mvprintw(*y, 2, "CPU info:");
    mvprintw(*y + 1, 6, monitor->cpu_name.c_str());
	char str[30];
	sprintf(str, "Cores: %d", monitor->cores);
    mvprintw(*y + 2, 6, str);
	sprintf(str, "CPU load: %.1f", monitor->cpu_load);
    mvprintw(*y + 3, 6, str);
	*y += 5;

}
void write_network(Monitor const *monitor, int *y)
{
    mvprintw(*y, 2, "Network info:");
	char str[30];
	sprintf(str, "out: %d bytes", monitor->bytes_out);
    mvprintw(*y + 1, 6, str);
	sprintf(str, "in: %d bytes", monitor->bytes_in);
    mvprintw(*y + 2, 6, str);
	*y += 4;
	
}
void write_ram(Monitor const *monitor, int *y)
{
	char str[30];
	sprintf(str, "%d Mb", monitor->mem_usage);
    mvprintw(*y, 2, "RAM usage:");
    mvprintw(*y + 1, 6, str);
	*y += 3;
}
void write_time(Monitor const *monitor, int *y)
{
    mvprintw(*y, 2, "Current time:");
    mvprintw(*y + 1, 7, monitor->curr_time.c_str());
    mvprintw(*y + 2, 2, "Time from start:");
    mvprintw(*y + 3, 6, monitor->uptime.c_str());
	*y += 5;

}
void Ncurses::update(Monitor const *monitor)
{
	int y = 8;
	for (int i = 0; i < monitor->size; i++)
	{
		if (monitor->order[i] == 1)
			write_time(monitor, &y);
		else if (monitor->order[i] == 2)
			write_hostname(monitor, &y);
		else if (monitor->order[i] == 3)
			write_cpu(monitor, &y);
		else if (monitor->order[i] == 4)
			write_network(monitor, &y);
		else if (monitor->order[i] == 5)
			write_ram(monitor, &y);
		else if (monitor->order[i] == 6)
			write_os(monitor, &y);
		else
		{
			endwin();
			exit(1);
		}

	}
}
void Ncurses::exit_n()
{
	if (getch() == 27)
	{
		endwin();
		exit(0);
	}
}

void Ncurses::display(Monitor const *monitor)
{
	erase();
	getmaxyx(stdscr, w_height, w_width);
	title();
	update(monitor);
	refresh();
	exit_n();	
}
void Ncurses::title()
{
    int     position = (w_width - 42) / 2;

    wattron(stdscr, COLOR_PAIR(TITLE_COLOR));
    box(stdscr, 0, 0);
    mvprintw(1, position,"        _             _ _           ");
    mvprintw(2, position,"   __ _| | ___ __ ___| | |_ __ ___  ");
    mvprintw(3, position,"  / _` | |/ / '__/ _ \\ | | '_ ` _ \\ ");
    mvprintw(4, position," | (_| |   <| | |  __/ | | | | | | |");
    mvprintw(5, position,"  \\__, |_|\\_\\_|  \\___|_|_|_| |_| |_|");
    mvprintw(6, position,"  |___/                             ");
    wattroff(stdscr, COLOR_PAIR(TITLE_COLOR));
}
