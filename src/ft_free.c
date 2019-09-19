/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:07:29 by sid-bell          #+#    #+#             */
/*   Updated: 2019/09/19 15:48:34 by sid-bell         ###   ########.fr       */
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

void	ft_fatal(char *msg)
{
	t_params	*params;
	t_point		*pt;
	t_point		*tmp;
	int			**plot;
	int			y;

	if (msg)
		ft_printf_fd(1, "%s\n", msg);
	params = ft_setter(NULL);
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
	free(plot);
	exit(1);
}
