/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:53:13 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/04 11:26:07 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_params	*ft_setter(t_params *params)
{
	static t_params *p;

	if (!p)
		p = params;
	return (p);
}

void		ft_list_to_array(t_params *params)
{
	t_point	*list;
	t_point	*point;
	int		y;
	int		x;

	list = params->pthead;
	params->plot = (int **)malloc(sizeof(int *) * (params->lines + 1));
	y = 0;
	while (y < params->lines)
	{
		params->plot[y] = (int *)malloc(sizeof(int) * (params->x_max));
		x = 0;
		while (x < params->x_max)
		{
			point = list;
			params->plot[y][x] = point->z;
			list = list->next;
			free(point);
			x++;
		}
		y++;
	}
	params->pthead = NULL;
	params->plot[y] = NULL;
}

void		ft_init(t_params *params, char *file)
{
	params->points = NULL;
	ft_setter(params);
	params->x_translate = 400;
	params->y_translate = 200;
	params->zoom = 30.0;
	params->z_zoom = 0.1;
	params->maxz = 0;
	params->mouse_down = 0;
	params->width = 480;
	params->projection = ISO;
	params->height = 360;
	params->pthead = NULL;
	params->plot = NULL;
	params->lines = 0;
	if (!(params->mlx_ptr = mlx_init()))
		ft_fatal("unable to initialize mlx\n");
	if (!(params->win_ptr = mlx_new_window(params->mlx_ptr, params->width,
		params->height, file)))
		ft_fatal("unable to creat new window\n");
}

void		ft_loader(t_params *params, char *file)
{
	ft_init(params, file);
	if ((params->fd = open(file, O_RDONLY)) < 0)
		ft_fatal("unable to open map");
	ft_load_map(params);
	ft_list_to_array(params);
	ft_handle_input(params->win_ptr);
	ft_draw(params);
	mlx_loop(params->mlx_ptr);
}

int			main(int argc, char **argv)
{
	t_params	params;

	if (argc > 1)
		ft_loader(&params, argv[1]);
	else
		ft_printf_fd(2, "usage : ./fdf file.map\n");
	return (0);
}
