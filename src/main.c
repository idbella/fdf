/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:53:13 by sid-bell          #+#    #+#             */
/*   Updated: 2019/09/19 16:55:08 by sid-bell         ###   ########.fr       */
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
	ft_fatal(NULL);
	return (0);
}

void		ft_init(t_params *params)
{
	params->points = NULL;
	ft_setter(params);
	params->x_translate = 0;
	params->y_translate = 0;
	params->zoom = 20.0;
	params->z_zoom = 0.1;
	params->maxz = 0;
	params->mouse_down = 0;
	params->width = 1280;
	params->projection = ISO;
	params->height = 720;
	params->tmppt0 = malloc(sizeof(t_point));
	params->tmppt1 = malloc(sizeof(t_point));
	params->pthead = NULL;
	params->ptlast = NULL;
	params->plot = NULL;
	alloc_src(params);
	params->lines = 0;
}

int			main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_params	params;

	if (argc > 1)
	{
		ft_init(&params);
		if ((params.fd = open(argv[1], O_RDONLY)) < 0)
			ft_fatal("unable to open map");
		ft_load_map(&params);
		ft_list_to_array(&params);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, params.width, params.height, "fdf");
		ft_handle_input(win_ptr);
		params.mlx_ptr = mlx_ptr;
		params.win_ptr = win_ptr;
		ft_draw(&params);
		mlx_loop(mlx_ptr);
	}
	else
		ft_printf_fd(2, "usage : ./fdf file.map");
	return (0);
}
