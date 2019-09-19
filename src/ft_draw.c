/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:49:01 by sid-bell          #+#    #+#             */
/*   Updated: 2019/09/19 15:50:12 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	line(point0, point1, color);
}

void	ft_init_pts(t_point *d, t_point *s, t_point *p0, t_point *p1)
{
	d->x = abs(p1->x - p0->x);
	s->x = p0->x < p1->x ? 1 : -1;
	d->y = abs(p1->y - p0->y);
	s->y = p0->y < p1->y ? 1 : -1;
}

void	line(t_point *p0, t_point *p1, int color)
{
	t_point	d;
	t_point	s;
	int		e2;
	int		err;

	ft_init_pts(&d, &s, p0, p1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		ft_putpixel(p0->x, p0->y, color);
		if (p0->x == p1->x && p0->y == p1->y)
			break ;
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			p0->x += s.x;
		}
		if (e2 < d.y)
		{
			err += d.x;
			p0->y += s.y;
		}
	}
}

void	ft_draw(t_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	ft_draw_xy(params);
	ft_resetscr(params);
}
