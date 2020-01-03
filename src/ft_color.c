/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:41:08 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/03 18:18:40 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getcolor(int z0, int z1, int zmax)
{
	if (z0 == z1 && z1 == zmax)
		return (RED);
	else if ((z0 == 0 && z1 == 0) || z0 < zmax / 2)
		return (GREY);
	else
		return (GREEN);
}
