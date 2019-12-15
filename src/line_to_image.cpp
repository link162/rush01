/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpokalch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 21:39:20 by tpokalch          #+#    #+#             */
/*   Updated: 2019/12/15 16:48:21 by tpokalch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int			in_bounds(float x, float y)
{
	return ((lround)(x) < WIDTH && (lround)(y) < HEIGHT
	&& (lround)(x) >= 0 && (lround)(y) >= 0);
}
/*
int			colo(int i, t_vector s, t_global *g)
{
	if (g->col % 4 == 0)
		return (100000);
	else if (g->col % 4 == 1)
		return (200000 * i);
	else if (g->col % 4 == 2)
		return (10000000 + i);
	else if (g->col % 4 == 3)
		return (100000 * s.x);
	return (0);
}
*/
void		line_to_image(t_vector s, t_vector e, int *data_ptr)
{
	float	slope;
	int		size;
	int		i;
	float	x;
	float	y;

	i = 1;
	slope = (e.y - s.y) / (float)(e.x - s.x);
	if (ABS(slope) > 1)
		size = ABS(e.y - s.y) + 1;
	else
		size = ABS(e.x - s.x) + 1;
	x = s.x;
	y = s.y;
	while (i <= size)
	{
		if (in_bounds(x, y))
			(data_ptr)[WIDTH * lround(y) + lround(x)] = 0xFFFFFF;
		x = x + STEPX(slope) * copysign(1, e.x - s.x);
		y = y + (STEPY(slope)) * copysign(1, e.y - s.y);
		i++;
	}
}
