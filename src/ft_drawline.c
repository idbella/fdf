/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 04:45:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 05:58:53 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	ft_equal(t_point *start, t_point *end)
{
	return (start->x == end->x && start->y == end->y);
}

void	ft_getstart(float *pt, t_point *start, t_point *end)
{
	pt[START] = start->x;
	pt[END] = end->x;
	if (start->x > end->x)
	{
		pt[START] = end->x;
		pt[END] = start->x;
	}
}

void	ft__draw(t_params *params, float dx, float dy, int color)
{
	float		pt[2];
	int			y;
	float		ab[2];
	float		inc;
	t_point		*point[2];

	point[START] = params->tmppt0;
	point[END] = params->tmppt1;
	ft_getstart(pt, point[START], point[END]);
	ab[A] = dy / dx;
	ab[B] = point[START]->y - ab[A] * point[START]->x;
	inc = 1;
	if (fabs(dx) < fabs(dy))
		inc = 1 / dy;
	if (inc < 0.07)
		inc = 0.07;
	while (pt[START] < pt[END])
	{
		if (dy != 0)
			y = ab[A] * pt[START] + ab[B];
		else
			y = point[START]->y;
		ft_putpixel((int)pt[START], y, color);
		pt[START] += inc;
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
