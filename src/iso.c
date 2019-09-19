/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:25:52 by sid-bell          #+#    #+#             */
/*   Updated: 2019/09/19 15:25:59 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *point, int x, int y, int z)
{
	int			previous_x;
	int			previous_y;
	t_params	*params;

	params = ft_setter(NULL);
	previous_x = x;
	previous_y = y;
	if (ft_setter(NULL)->projection == PARALLEL)
	{
		point->x = x;
		point->y = y;
	}
	else
	{
		point->x = (previous_x - previous_y) * cos(ANGLE);
		point->y = (previous_x + previous_y) * sin(ANGLE) - z;
	}
}
