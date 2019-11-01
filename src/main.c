/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:53:13 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 03:45:47 by sid-bell         ###   ########.fr       */
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

int			ft_close(void)
{
	ft_fatal(NULL, 1);
	return (0);
}

void		ft_init(t_params *params)
{
	params->points = NULL;
	ft_setter(params);
	params->x_translate = 400;
	params->y_translate = 200;
	params->zoom = 30.0;
	params->z_zoom = 0.1;
	params->maxz = 0;
	params->mouse_down = 0;
	params->width = 1920;
	params->projection = ISO;
	params->height = 1080;
	params->tmppt0 = malloc(sizeof(t_point));
	params->tmppt1 = malloc(sizeof(t_point));
	params->pthead = NULL;
	params->plot = NULL;
	params->lines = 0;
}

char ft_loader(t_params *params, char *file, char first)
{
	void		*mlx_ptr;
	void		*win_ptr;
	ft_init(params);
	if ((params->fd = open(file, O_RDONLY)) < 0)
		return (ft_fatal("unable to open map", 0));
	if (!ft_load_map(params))
		return (0);
	if (params->x_max * 10 > params->width)
	{
		params->x_translate += 100;
		params->zoom = 5;
	}
	if (params->x_max * 30 > params->width)
	{
		params->x_translate += 100;
		params->zoom = 2.5;
	}
	ft_list_to_array(params);
	if (first)
	{
		if (!(mlx_ptr = mlx_init()))
			ft_fatal("unable to initialize mlx\n", 1);
		if (!(win_ptr = mlx_new_window(mlx_ptr, params->width, params->height, file)))
			ft_fatal("unable to creat new window\n", 1);
		ft_handle_input(win_ptr);
		params->mlx_ptr = mlx_ptr;
		params->win_ptr = win_ptr;
	}
	params->var = 0;
	params->angle = ANGLE;
	ft_draw(params);
	mlx_loop(params->mlx_ptr);
	return (1);
}

int			main(int argc, char **argv)
{

	t_params	params;
	char		*img;

	if (argc > 1)
	{
		ft_loader(&params, argv[1], 1);
	}
	else
		ft_printf_fd(2, "usage : ./fdf file.map");
	return (0);
}
