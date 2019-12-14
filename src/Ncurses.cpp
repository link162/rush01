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
void Ncurses::update()
{

	
}
void Ncurses::exit_n()
{
	if (getch() == 27)
	{
		endwin();
		exit(0);
	}
}

void Ncurses::display()
{
	erase();
	getmaxyx(stdscr, w_height, w_width);

	title();
	refresh();
	//_dispWindows(modules);
	//_dispRefresh();
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
	endwin();
}
