/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:47:32 by sid-bell          #+#    #+#             */
/*   Updated: 2019/11/01 03:41:48 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include "fcntl.h"
# define GREY   7500402
# define RED   5316608
# define GREEN 5251072// // 6794612
# include <math.h>
# define PARALLEL -1
# define ISO 1
# define ANGLE 0.523599
# include <stdio.h>
#include <glob.h>

typedef struct	s_point
{
	float			x;
	float			y;
	int				z;
	struct s_point	*next;
}				t_point;

typedef	struct	s_params
{
	int		x_max;
	t_point	*points;
	t_point	*pthead;
	int		fd;
	int		**plot;
	int		lines;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	float	zoom;
	float	z_zoom;
	int		x_translate;
	int		y_translate;
	int		projection;
	char	mouse_down;
	int		x;
	int		y;
	char	var;
	int		maxz;
	t_point	*tmppt0;
	t_point	*tmppt1;
	int		width;
	int		height;
	float	angle;
	glob_t	glb;
	int		menudex;
	int		**screen;
}				t_params;

typedef struct s_size
{
	size_t	width;
	size_t	height;
}				t_size;

char			ft_load_map(t_params *params);
char			ft_fatal(char *msg, char _exit);
void			ft_draw_plane(t_params *params);
void			ft_draw(t_params *params);
void			ft_draw_x(t_params *params, int x, int y);
void			ft_draw_y(t_params *params, int x, int y);
void			line(t_point *pt1, t_point *pt2, int color);
int				ft_mouse_press(int keycode, int x, int y);
int				ft_scroll(int keycode);
int				ft_mouse_move(int x, int y);
int				ft_mouse_reslease(int button);
t_params		*ft_setter(t_params *params);
int				ft_close(void);
void			ft_handle_input(void *win_ptr);
void			ft_free_array(char **array);
void			iso(t_point *point, int x, int y, int z);
int				ft_getcolor(int z0, int z1, int zmax);
void			ft_draw_line(t_params *params, t_point *point0,
					t_point *point1, int color);
void			ft_putpixel(t_params *params, int x0, int y0, int color);
char			ft_loader(t_params *params, char *file, char first);
#endif
