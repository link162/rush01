#ifndef NCURSES
#define NCURSES

#include "header.hpp"
# define DISP_WHITE        0
# define DISP_RED          1
# define DISP_GREEN        2
# define DISP_BLUE         3
# define DISP_CYAN         4
# define DISP_YELLOW       5
# define DISP_MAGENTA      6
# define TITLE_COLOR       DISP_RED

class Ncurses : public IMonitorDisplay
{
	int w_width;
	int w_height;
	void title();
	void exit_n();
	public:
	Ncurses();
	~Ncurses();
	Ncurses(Ncurses const &old);
	Ncurses &operator = (Ncurses const &old);
	void init();
	void update();
	void display();
};


#endif
