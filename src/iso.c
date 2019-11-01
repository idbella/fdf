/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:25:52 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 04:19:15 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_point *point, int x, int y, int z)
{
	t_params	*params;

	params = ft_setter(NULL);
	if (params->projection == PARALLEL)
	{
		point->x = x;
		point->y = y;
	}
	else
	{
		point->x = (x - y) * cos(ANGLE);
		point->y = (x + y) * sin(ANGLE) - z;
	}
}
