/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 08:49:01 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 05:59:18 by sid-bell         ###   ########.fr       */
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
}
