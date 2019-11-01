/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:20:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 04:03:09 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_button(t_params *params, glob_t *glb);

int		ft_mouse_press(int keycode, int x, int y)
{
	t_params	*params;
	float		d;
	
	params = ft_setter(NULL);
	params->var = 0;
	if (x <= 0 || y < 0)
	{
		ft_draw(params);
		return (0);
	}
	if (keycode == 1)
	{
		params->x = x;
		params->y = y;
		params->mouse_down = 1;
	}
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4 && (d = 1.05))
			params->zoom *= d;
		if (keycode == 5 && (d = 0.95))
			params->zoom *= d;
		ft_draw(params);
	}
	return (0);
}

int		ft_mouse_release(int button)
{
	t_params *params;

	params = ft_setter(NULL);
	if (button == 1)
		params->mouse_down = 0;
	return (0);
}

int		ft_mouse_move(int x, int y)
{
	t_params	*params;
	int			dx;
	int			dy;

	params = ft_setter(NULL);
	if (params->mouse_down)
	{
		dx = params->x - x;
		dy = params->y - y;
		params->x_translate -= dx;
		params->y_translate -= dy;
		ft_draw(params);
		params->x = x;
		params->y = y;
	}
	return (0);
}

void	ft_darawbox(t_params *params, t_size *size, t_point *pos, int color)
{
	t_point st;
	t_point	en;

	st.y = pos->y;
	en.x = pos->x + size->width;
	en.y = st.y + size->height;
	while (st.y < en.y)
	{
		st.x = pos->x;
		while (st.x < en.x)
		{
			mlx_pixel_put(params->mlx_ptr, params->win_ptr, st.x, st.y, color);
			st.x++;
		}
		st.y++;
	}
}

void	ft_button(t_params *params, glob_t *glb)
{
	t_point	pt;
	t_size	sz;
	int		add;

	sz.width = 400;
	sz.height = 30;
	pt.x = params->width/2 - sz.width/2;
	pt.y = 30;
	int i = 0;
	add = params->height - (glb->gl_pathc * sz.height) - 60;
	add = add / glb->gl_pathc;
	while (i < glb->gl_pathc)
	{
		ft_darawbox(params, &sz, &pt, params->menudex == i ? GREEN : GREY);
		mlx_string_put(params->mlx_ptr, params->win_ptr, pt.x + 50, pt.y + 7 ,0, glb->gl_pathv[i]);
		pt.y += (sz.height + add);
		i++;
	}
	mlx_do_sync(params->mlx_ptr);
}

void	ft_menu(t_params *params)
{
	glob("*.fdf", 0, NULL, &params->glb);
	glob("*/*.fdf", GLOB_APPEND, NULL, &params->glb);
	ft_button(params, &params->glb);
	params->var = 1;
}

int		ft_scroll(int keycode)
{
	t_params *params;

	params = ft_setter(NULL);
	if (keycode == 53)
		ft_fatal(NULL, 1);
	if (keycode == 124)
		params->x_translate += 10;
	if (keycode == 123)
		params->x_translate -= 10;
	if (keycode == 125)
	{
		if (params->var)
		{
			params->menudex++;
			if (params->menudex >= params->glb.gl_pathc)
				params->menudex = 0;
			ft_button(params, &params->glb);
			return 0;
		}
		params->y_translate += 10;
	}
	if (keycode == 126)
	{
		if (params->var)
		{
			params->menudex--;
			if (params->menudex < 0)
				params->menudex = params->glb.gl_pathc - 1;
			ft_button(params, &params->glb);
			return 0;
		}
		params->y_translate -= 10;
	}
	if (keycode == 69)
		params->z_zoom += 0.1;
	if (keycode == 78)
		params->z_zoom -= 0.1;
	if (keycode == 49)
		params->projection *= -1;
	if (keycode == 36)
	{
		if (params->var)
		{
			if (!fork())
			{
				char *argv[3] = {"", params->glb.gl_pathv[params->menudex] , NULL};
				execve("./fdf", argv, NULL);
				exit(0);
			}
			//ft_loader(params, params->glb.gl_pathv[params->menudex], 0);
			return 0;
		}
	}
	if (keycode == 46)
	{
		if (!params->var)
		{
			ft_menu(params);
			return 0;
		}
		else
			params->var = 0;
		
	}
	ft_draw(params);
	return (0);
}

void	ft_handle_input(void *win_ptr)
{
	mlx_hook(win_ptr, 17, 0, &ft_close, NULL);
	mlx_hook(win_ptr, 2, 0, &ft_scroll, NULL);
	mlx_hook(win_ptr, 4, 0, &ft_mouse_press, NULL);
	mlx_hook(win_ptr, 6, 0, &ft_mouse_move, NULL);
	mlx_hook(win_ptr, 5, 0, &ft_mouse_release, NULL);
}
