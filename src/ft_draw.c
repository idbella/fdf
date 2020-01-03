/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:49:01 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 18:58:14 by ktbatou          ###   ########.fr       */
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
	ft_init_draw(point0, point1, color);
}

void	ft_draw(t_params *params)
{
	mlx_clear_window(params->mlx_ptr, params->win_ptr);
	ft_draw_xy(params);
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 30, 30, WHITE, "MENU :");
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 45, 50, PINK, "-> Zoom       : sroll.");
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 45, 65, PINK, "-> Projection : space.");
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 45, 80, PINK, "-> Move       : mouse.");
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 45, 95, PINK, "-> Altitude   : +/-.");
	mlx_string_put(params->mlx_ptr,
	params->win_ptr, 45, 110, PINK, "-> Exite      : ESC.");
}
