/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:40:20 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 14:20:59 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_x(t_params *params, int x, int y)
{
	int		z0;
	int		z1;
	int		color;
	t_point	*point0;
	t_point	*point1;

	z0 = params->plot[y][x] * params->z_zoom * params->zoom;
	z1 = params->plot[y][x + 1] * params->z_zoom * params->zoom;
	//	ft_printf_fd(1, "color = %d\n", params->tmppt0.color);
	if (params->tmppt0.color)
		color = params->tmppt0.color;
	else
		color = ft_getcolor(params->plot[y][x],
	 		params->plot[y + 1][x], params->maxz);
	y *= params->zoom;
	point0 = &params->tmppt0;
	point1 = &params->tmppt1;
	iso(point0, x * params->zoom, y, z0);
	iso(point1, (x + 1) * params->zoom, y, z1);
	if (!(point0->x + params->x_translate > params->width
		&& point1->x + params->x_translate > params->width))
		if (!(point0->y + params->y_translate > params->height
			&& point1->y + params->y_translate > params->height))
			ft_draw_line(params, point0, point1, color);
}
