/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 04:45:34 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 13:09:44 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_swap(t_point *start, t_point *end)
{
	float tmp;

	if (start->x > end->x)
	{
		tmp = start->x;
		start->x = end->x;
		end->x = tmp;
	}
}

float	ft_incr(float dx, float dy)
{
	float inc;

	inc = 1;
	if (fabs(dx) < fabs(dy))
		inc = 1 / dy;
	if (inc < 0.07)
		inc = 0.07;
	return (inc);
}

void	ft__draw(t_params *params, float dx, float dy, int color)
{
	int			xy[2];
	float		ab[2];
	float		inc;
	t_point		*start;
	t_point		*end;

	start = &params->tmppt0;
	end = &params->tmppt1;
	xy[X] = start->x;
	ft_swap(start, end);
	ab[A] = dy / dx;
	ab[B] = start->y - ab[A] * xy[X];
	inc = ft_incr(dx, dy);
	while (start->x < end->x)
	{
		if (dy != 0)
			xy[Y] = ab[A] * start->x + ab[B];
		else
			xy[Y] = start->y;
		ft_putpixel((int)start->x, xy[Y], color);
		start->x += inc;
	}
}

void	ft_draw_vertical(t_point *start, t_point *end, int color)
{
	int			sy;
	int			ey;
	t_params	*params;

	params = ft_setter(0);
	sy = start->y;
	ey = end->y;
	if (start->y > end->y)
	{
		ey = start->y;
		sy = end->y;
	}
	while (sy < ey)
	{
		ft_putpixel((int)start->x, sy, color);
		sy++;
	}
}

void	ft_init_draw(t_point *start, t_point *end, int color)
{
	float		dx;
	float		dy;
	t_params	*params;

	if (start->x == end->x && start->y == end->y)
		return ;
	dx = (end->x - start->x);
	dy = (end->y - start->y);
	params = ft_setter(0);
	params->tmppt0 = *start;
	params->tmppt1 = *end;
	if (dx != 0)
		ft__draw(params, dx, dy, color);
	else
		ft_draw_vertical(start, end, color);
}
