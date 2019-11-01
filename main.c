/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:10:43 by sid-bell          #+#    #+#             */
/*   Updated: 2019/10/31 21:56:58 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/includes/fdf.h"
#include <stdio.h>
#include <math.h>

void	*mlx;
void	*win;

char	ft_equal(t_point *start, t_point *end)
{
	return (start->x == end->x && start->y == end->y);
}

void	ft_drawy3(t_point *start, t_point *end, float dx, float dy)
{
	int 	sy;
	int		x;
	float	a;
	float	b;
	int		ey;
	int		y;

	ft_printf_fd(1, "draw3\n");
	sy = start->y;
	ey = end->y;
	if (start->y > end->y)
	{
		ft_printf_fd(1, "ok1\n");
		sy = end->y;
		ey = start->y;
	}
	a = dy/dx;
	b = start->y - a*start->x;
	while (sy < ey)
	{
		if (dy != 0)
		{
			ft_printf_fd(1, "fds\n");
			x = (sy - b)/a;
		}
		else
		{
			x = start->x;
		}
		ft_printf_fd(1, "x = %d\n", x);
		mlx_pixel_put(mlx, win,  x, sy , GREEN);
		sy++;
	}
}

void	ft_drawy2(t_point *start, t_point *end, float dx, float dy)
{
	int 	sx;
	int		y;
	float	a;
	float	b;
	int		ex;

	ft_printf_fd(1, "pky?\n");
	sx = start->x;
	ex = end->x;
	if (start->x > end->x)
	{
		ft_printf_fd(1, "ok?\n");
		sx = end->x;
		ex = start->x;
	}
	a = dy/dx;
	b = start->y - a*start->x;
	while (sx < ex)
	{
		if (dy != 0)
		{
			y = a * sx + b;
		}
		else
		{
			printf("dy = %f\n", dy);
			y = start->y;
		}
		mlx_pixel_put(mlx, win,  sx, y , GREEN);
		sx++;
	}
}

void	ft_drawx2(t_point *start, t_point *end, float dx, float dy)
{
	int sy;
	int	ey;

	sy = start->y;
	ey = end->y;
	if (start->y > end->y)
	{
		ey = start->y;
		sy = end->y;
	}
	while (sy < ey)
	{
		mlx_pixel_put(mlx, win,  start->x, sy , GREEN);
		sy++;
	}
}

void	ft_draw2(t_point *start, t_point *end)
{
	float	dx;
	float	dy;

	if (ft_equal(start, end))
		return ;
	
	dx = ((float)end->x - (float)start->x);
	dy = ((float)end->y - (float)start->y);
	printf( "dx = %f, dy = %f\n", dx, dy);
	if (fabs(dx) < fabs(dy))
		ft_drawy3(start, end, dx, dy);
	if (dx != 0)
		ft_drawy2(start, end, dx, dy);
	else
		ft_drawx2(start, end, dx, dy);
}

int	main(int argc, char **argv)
{
	t_point p1;
	t_point p2;
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1280, 720, "bla bla bla...");
	p1.x = 425;
	p1.y = 245;
//(425,245)(451,290)
	p2.x = 451;
	p2.y = 290;
	ft_draw2(&p1, &p2);
	mlx_loop(mlx);
}
/*

A(1,1)
B(3,2)

f(x) = ax+b


f(Ax) = a*Ax + b = Ay
Ay = a*Ax + b
Ay - a*Ax = b

Ay = a*Ax + b
Ay - a*Ax = b
b = 1 - 1/2

y = a*x + b

y - b = a*x
(y - b)/a = x

y = x+1
x = 
*/