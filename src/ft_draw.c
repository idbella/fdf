/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:49:01 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 01:47:18 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	ft_equal(t_point *start, t_point *end)
{
	return (start->x == end->x && start->y == end->y);
}

void	ft_drawy2(t_point *start, t_point *end, float dx, float dy, int color)
{
	float		sx;
	int			y;
	float		a;
	float		b;
	float		ex;
	t_params	*params;
	float		inc;

	params = ft_setter(0);
	sx = start->x;
	ex = end->x;
	if (start->x > end->x)
	{
		sx = end->x;
		ex = start->x;
	}
	a = dy / dx;
	b = start->y - a * start->x;
	inc = 1;
	if (fabs(dx) < fabs(dy))
		inc = 1/dy;
	if (inc < 0.07)
		inc = 0.07;
	while (sx < ex)
	{
		if (dy != 0)
			y = a * sx + b;
		else
			y = start->y;
		ft_putpixel(params, (int)sx, y, color);
		sx += inc;
	}
}

void	ft_draw_vertical(t_point *start, t_point *end, float dx, float dy, int color)
{
	int sy;
	int	ey;
	t_params *params;

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
		ft_putpixel(params, (int)start->x, sy, color);
		sy++;
	}
}

void	ft_draw2(t_point *start, t_point *end, int color)
{
	float	dx;
	float	dy;

	if (ft_equal(start, end))
		return ;
	dx = (end->x - start->x);
	dy = (end->y - start->y);
	if (dx != 0)
		ft_drawy2(start, end, dx, dy, color);
	else
		ft_draw_vertical(start, end, dx, dy, color);
}

void	ft_draw_xy(t_params *params)
{
	int y;
	int x;

	y = 0;
	while (y < params->lines)
	{
		x = 0;
		while (x < params->x_max)
		{
			if (x < params->x_max - 1)
				ft_draw_x(params, x, y);
			if (y < params->lines - 1)
				ft_draw_y(params, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw_line(t_params *params, t_point *point0,
		t_point *point1, int color)
{
	point0->x += params->x_translate;
	point0->y += params->y_translate;
	point1->x += params->x_translate;
	point1->y += params->y_translate;
	ft_draw2(point0, point1, color);
}


void	ft_draw(t_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	ft_draw_xy(params);
}
