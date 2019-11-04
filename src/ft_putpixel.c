/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpixel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:50:18 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/04 10:24:36 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_putpixel(int x0, int y0, int color)
{
	t_params	*params;

	params = ft_setter(0);
	if (x0 < params->width && y0 < params->height && y0 > 0 && x0 > 0)
		mlx_pixel_put(params->mlx_ptr, params->win_ptr, x0, y0, color);
}
