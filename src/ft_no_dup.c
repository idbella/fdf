/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:45:06 by sid-bell          #+#    #+#             */
/*   Updated: 2019/09/19 15:48:52 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	alloc_src(t_params *params)
{
	int	height;

	params->screen = malloc(sizeof(int *) * params->height);
	height = 0;
	while (height < params->height)
	{
		params->screen[height] = malloc(sizeof(int) * params->width);
		*params->screen[height] = 0;
		height++;
	}
}

void	ft_resetscr(t_params *params)
{
	int y;
	int x;

	y = 0;
	while (y < params->height)
	{
		x = 0;
		while (x < params->width)
		{
			params->screen[y][x] = 0;
			x++;
		}
		y++;
	}
}
