/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:49:01 by sid-bell          #+#    #+#             */
/*   Updated: 2019/07/22 20:36:39 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	*iso(int x, int y, int z)
{
	int		previous_x;
	int		previous_y;
	t_point	*point;

	point = malloc(sizeof(t_point));
	previous_x = x;
	previous_y = y;
	point->x = (previous_x - previous_y) * cos(0.523599);
	point->y = -z + (previous_x + previous_y) * sin(0.523599);

	return (point);
}

void	ft_draw_plane(t_params *params)
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
				ft_prex(params, x, y);
			if (y < params->lines - 1)
				ft_prey(params, x, y);
			x++;
		}
		y++;
	}
}

void	ft_prex(t_params *params, int x, int y)
{
	int		z0;
	int		z1;
	t_point	*point0;
	t_point	*point1;

	z0 = params->plot[y][x] * params->z_zoom;
	z1 = params->plot[y][x + 1] * params->z_zoom;
	y *= params->zoom;
	point0 = iso(x * params->zoom, y, z0);
	point1 = iso((x + 1) * params->zoom, y, z1);
	if (!(point0->x + params->x_translate > params->width
		&& point1->x + params->x_translate > params->width))
		if (!(point0->y + params->y_translate > params->height
			&& point1->y + params->y_translate > params->height))
			line(params, point0->x + params->x_translate,
			point0->y + params->y_translate, point1->x + params->x_translate,
			point1->y + params->y_translate,
			(z0 && z1) ? RED : GREY);
	free(point0);
	free(point1);
}



void	ft_prey(t_params *params, int x, int y)
{
	int		z0;
	int		z1;
	t_point	*point0;
	t_point	*point1;

	z0 = params->plot[y][x] * params->z_zoom;
	z1 = params->plot[y + 1][x] * params->z_zoom;
	x *= params->zoom;
	point0 = iso(x, y * params->zoom, z0);
	point1 = iso(x, (y + 1) * params->zoom, z1);
	if (!(point0->x + params->x_translate > params->width
		&& point1->x + params->x_translate > params->width))
		if (!(point0->y + params->y_translate > params->height
			&& point1->y + params->y_translate > params->height))
			line(params, point0->x + params->x_translate,
			point0->y + params->y_translate, point1->x + params->x_translate,
			point1->y + params->y_translate,
			(z0 && z1) ? RED : GREY);
	free(point0);
	free(point1);
}

void	line(t_params *params, int x0, int y0, int x1, int y1, int color)
{
	int dx;
	int dy;
	int sx;
	int e2;
	int sy;
	int err;

	dx = abs(x1 - x0);
	sx = x0 < x1 ? 1 : -1;
	dy = abs(y1 - y0);
	sy = y0 < y1 ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		mlx_pixel_put(params->mlx_ptr, params->win_ptr, x0, y0, color);
		if (x0 == x1 && y0 == y1)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += sy;
		}
	}
}

void	ft_draw(t_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	ft_draw_plane(params);
}
