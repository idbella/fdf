/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:48:53 by sid-bell          #+#    #+#             */
/*   Updated: 2019/07/13 01:58:56 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_array_lenght(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		ft_isvalid(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

void	ft_free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i++]);
	}
	free(array);
}

void	ft_getxyz(char **array, t_params *params, int y)
{
	t_point	*point;
	t_list	*node;
	int		x;

	x = 0;
	while (array[x] && x < params->x_max)
	{
		point = (t_point *)malloc(sizeof(t_point));
		point->x = x;
		point->y = y;
		point->z = ft_atoi(array[x]);
		node = ft_lstnew(NULL, 0);
		node->content = point;
		ft_lstadd(&params->points, node);
		x++;
	}
	//ft_free_array(array);
}

void	ft_load_map(t_params *params)
{
	char	*line;
	char	**parts;
	int		lenght;
	int		y;

	y = 0;
	while (get_next_line(params->fd, &line))
	{
		parts = ft_strsplit(line, ' ');
		lenght = ft_array_lenght(parts);
		if (y == 0)
			params->x_max = lenght;
		else if (lenght < params->x_max)
			ft_fatal("Map Error1");
		ft_getxyz(parts, params, y);
		if (y % 10 == 0)
			ft_printf_fd(1, "y = %d/500\n", y);
		y++;
	}
	params->lines = y;
}
