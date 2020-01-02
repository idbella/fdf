/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loadmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:48:53 by sid-bell          #+#    #+#             */
/*   Updated: 2020/01/02 16:21:16 by sid-bell         ###   ########.fr       */
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

t_point	*ft_new_point(int x, int y, char **array)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	point->next = NULL;
	point->z = ft_atoi(array[x]);
	return (point);
}

void	ft_getxyz(char **array, t_params *params, int y)
{
	t_point	*point;
	int		x;

	x = 0;
	while (array[x] && x < params->x_max)
	{
		point = ft_new_point(x, y, array);
		if (fabs((float)point->z) > params->maxz)
			params->maxz = fabs((float)point->z);
		if (params->points)
		{
			params->points->next = point;
			params->points = params->points->next;
		}
		else
		{
			params->points = point;
			params->pthead = point;
		}
		x++;
	}
	ft_free_array(array);
}

void	ft_load_map(t_params *params)
{
	char	*line;
	char	**parts;
	int		lenght;
	int		y;

	y = 0;
	lenght = 0;
	while (get_next_line(params->fd, &line))
	{
		parts = ft_strsplit(line, ' ');
		lenght = ft_array_lenght(parts);
		if (y == 0)
			params->x_max = lenght;
		else if (lenght < params->x_max)
			ft_fatal("Map Error1");
		ft_getxyz(parts, params, y);
		y++;
		free(line);
	}
	if (y == 0 && lenght == 0)
		ft_fatal("No data found");
	params->lines = y;
}
