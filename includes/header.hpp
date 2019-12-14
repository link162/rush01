#ifndef HEADER
#define HEADER
#include <functional>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <exception>
#include <map>
#include <queue>
#include <deque>
#include <sys/sysctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <net/route.h>
#include <sstream>
#include <ncurses.h>
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "Monitor.hpp"
#include "Ncurses.hpp"

#include <math.h>
#include "mlx.h"
#include <unistd.h>
# define ABS(x) ((2 * ((x) > 0) - 1) * (x))
# define STEPX(x) ((x == 0) ? 1 : (ABS((ABS(x) <= 1) + (1 / x) * (ABS(x) > 1))))
# define STEPY(x) (1/x == 0) ? 1 : (ABS((ABS(x) >= 1) + x * (ABS(x) < 1)))
# define MODT(x) (x < 0) ? (2 * M_PI + x) : x
#define WIDTH 300
#define HEIGHT 300
#define	SPACETIME 10

#define PRINT(s) std::cout << (s) << std::endl
std::string exec(const char *cmd);

typedef struct s_vector
{
	int x;
	int y;
}		t_vector;



void	move_and_draw(t_vector old, t_vector n, int *data_ptr);

void line_to_image(t_vector s, t_vector e, int *data_ptr);
void *mlx_ptr;
void *win_ptr;
void *img_ptr;
void *data_ptr;

#endif
