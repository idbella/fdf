#include "fdf.h"

t_params *ft_setter(t_params *params)
{
	static t_params *p;

	if (!p)
		p = params;
	return p;
}

void	ft_fatal(char *msg)
{
	ft_printf_fd(1, "%s\n", msg);
	exit(1);
}

void	ft_list_to_array(t_params *params)
{
	t_list	*list;
	t_point *point;
	t_list	*node;
	int	y;
	int	x;

	list = params->points;
	params->plot = (int **)malloc(sizeof(int *) * (params->lines + 1));
	y = 0;
	while(y < params->lines)
	{
		params->plot[y] = (int *)malloc(sizeof(int) * (params->x_max));
		x = 0;
		while (x < params->x_max)
		{
			point = (t_point *)list->content;
			node = list->next;
			params->plot[y][x] = point->z;
			free(point);
			free(list);
			list = node;
			x++;
		}
		y++;
	}
	params->plot[y] = NULL;
}

int ft_close()
{
	exit(0);
	return (0);
}

void ft_init(t_params *params)
{
	params->points = NULL;
	ft_setter(params);
	params->x_translate = 500;
	params->y_translate = 100;
	params->zoom = 10;
	params->z_zoom = 5;
	params->mouse_down = 0;
	params->width = 1080;
	params->height = 720;
}

int	main(int argc, char **argv)
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_params	params;

	if (argc > 1)
	{
		ft_init(&params);
		if ((params.fd = open(argv[1], O_RDONLY)) < 0)
			ft_fatal("unable to open map\n");
		ft_load_map(&params);
		ft_list_to_array(&params);
		mlx_ptr = mlx_init();
		win_ptr = mlx_new_window(mlx_ptr, params.width, params.height, "fdf");
		mlx_hook(win_ptr, 17, 0, &ft_close, NULL);
		mlx_hook(win_ptr, 2, 0, &ft_scroll, NULL);
		mlx_hook(win_ptr, 4, 0, &ft_mouse_press, NULL);
		mlx_hook(win_ptr, 6, 0, &ft_mouse_move, NULL);
		mlx_hook(win_ptr, 5, 0, &ft_mouse_reslease, NULL);
		params.mlx_ptr = mlx_ptr;
		params.win_ptr = win_ptr;
		ft_draw(&params);
		mlx_loop(mlx_ptr);
	}
	else
		ft_printf_fd(2, "usage : ./fdf file.map");
	return (0);
}