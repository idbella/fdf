/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 11:20:34 by sid-bell          #+#    #+#             */
/*   Updated: 2019/07/12 14:15:26 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_mouse_press(int keycode, int x, int y)
{
	t_params *params;

	ft_printf_fd(1, "key = %d\n", keycode);
	params = ft_setter(NULL);
	if (keycode == 1)
    {
		params->x = x;
        params->y = y;
        params->mouse_down = 1;
    }
	if (keycode == 4 || keycode == 5)
	{
		if (keycode == 4)
			params->zoom += 1;
		if (keycode == 5)
			params->zoom -= 1;
		params->zoom = params->zoom ? params->zoom : 1;
		ft_draw(params);
	}
	return (0);
}

int ft_mouse_reslease(int button)
{
    t_params *params;
    params = ft_setter(NULL);
    if (button == 1)
        params->mouse_down = 0;
    return 0;
}

int ft_mouse_move(int x, int y)
{
    t_params *params;
    int dx;
    int dy;

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
    return 0;
}

int ft_scroll(int keycode)
{
	t_params *params;

	params = ft_setter(NULL);
	if (keycode == 124)
		params->x_translate -= 10;
	if (keycode == 123)
		params->x_translate += 10;
	if (keycode == 125)
		params->y_translate -= 10;
	if (keycode == 126)
		params->y_translate += 10;
	if (keycode == 69)
		params->z_zoom += 1;
	if (keycode == 78)
		params->z_zoom -= 1;
	ft_draw(params);
	return (0);
}
