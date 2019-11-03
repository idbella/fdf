/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:07:29 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/03 17:16:25 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	ft_release_mlx(t_params *params)
{
	if (params->win_ptr)
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
}

int		ft_fatal(char *msg)
{
	t_params	*params;
	t_point		*pt;
	t_point		*tmp;
	int			**plot;
	int			y;

	ft_printf_fd(1, "%s\n", msg ? msg : "");
	params = ft_setter(NULL);
	ft_release_mlx(params);
	pt = params->pthead;
	plot = params->plot;
	while (pt)
	{
		tmp = pt->next;
		free(pt);
		pt = tmp;
	}
	y = 0;
	while (y < params->lines)
		free(plot[y++]);
	params->pthead = NULL;
	params->plot = NULL;
	free(plot);
	exit(1);
	return (0);
}
