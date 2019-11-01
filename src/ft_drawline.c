/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 04:45:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 05:02:48 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	ft_equal(t_point *start, t_point *end)
{
	return (start->x == end->x && start->y == end->y);
}

void	ft___draw(int sx, int ex, int *dxy, int color)
{
	float		inc;
	float		a;
	float		b;
	int			y;
	t_point		*start;

	start = ft_setter(0)->tmppt0;
	a = dxy[1] / dxy[0];
	b = start->y - a * start->x;
	inc = 1;
	if (fabs(dxy[0]) < fabs(dxy[1]))
		inc = 1 / dxy[1];
	if (inc < 0.07)
		inc = 0.07;
	while (sx < ex)
	{
		if (dxy[1] != 0)
			y = a * sx + b;
		else
			y = start->y;
		ft_putpixel((int)sx, y, color);
		sx += inc;
	}
}

void	ft__draw(t_params *params, float dx, float dy, int color)
{
	float		sx;
	float		ex;
	t_point		*start;
	t_point		*end;
	int			dxy[2];

	start = params->tmppt0;
	end = params->tmppt1;
	sx = start->x;
	ex = end->x;
	if (start->x > end->x)
	{
		sx = end->x;
		ex = start->x;
	}
	dxy[0] = dx;
	dxy[1] = dy;
	ft___draw(sx, ex, dxy, color);
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

	if (ft_equal(start, end))
		return ;
	dx = (end->x - start->x);
	dy = (end->y - start->y);
	params = ft_setter(0);
	params->tmppt0 = start;
	params->tmppt1 = end;
	if (dx != 0)
		ft__draw(params, dx, dy, color);
	else
		ft_draw_vertical(start, end, color);
}
