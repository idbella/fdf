/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_y.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:41:44 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 14:15:24 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_y(t_params *params, int x, int y)
{
	int		z0;
	int		z1;
	int		color;
	t_point	*point0;
	t_point	*point1;

	z0 = params->plot[y][x] * params->z_zoom * params->zoom;
	z1 = params->plot[y + 1][x] * params->z_zoom * params->zoom;
	if (params->tmppt0.color)
		color = params->tmppt0.color;
	else
		color = ft_getcolor(params->plot[y][x],
	 		params->plot[y + 1][x], params->maxz);
	x *= params->zoom;
	point0 = &params->tmppt0;
	point1 = &params->tmppt1;
	iso(point0, x, y * params->zoom, z0);
	iso(point1, x, (y + 1) * params->zoom, z1);
	if (!(point0->x + params->x_translate > params->width
		&& point1->x + params->x_translate > params->width))
		if (!(point0->y + params->y_translate > params->height
			&& point1->y + params->y_translate > params->height))
			ft_draw_line(params, point0, point1, color);
}
