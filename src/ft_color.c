/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:41:08 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 19:56:58 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getcolor(int z0, int z1, int zmax)
{
	t_params *params;

	params = ft_setter(0);
	if (z0 == z1 && z1 == zmax)
		return (params->pink);
	else if ((z0 == 0 && z1 == 0) || z0 < zmax / 2)
		return (params->white);
	else
		return (params->yellow);
}