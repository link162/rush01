
#include "header.hpp"
#include <unistd.h>
#include "mlx.h"

void *mlx_ptr;
void *win_ptr;
void *img_ptr;
void *data_ptr;

void	move(int *data_ptr)
{
	for (int y = 0; y < HEIGHT; y++)
	{
		for (int x = 0; x < WIDTH; x++)
			if (x > SPACETIME)
				data_ptr[WIDTH * y + x - SPACETIME] = data_ptr[WIDTH * y + x];
	}
}

void	move_and_draw(t_vector old, t_vector n, int *data_ptr)
{
	move(data_ptr);
	old.x -= SPACETIME;
	line_to_image(old, n, data_ptr);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
}
