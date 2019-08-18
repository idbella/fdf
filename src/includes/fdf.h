/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <sid-bell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 04:47:32 by sid-bell          #+#    #+#             */
/*   Updated: 2019/07/12 14:35:59 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "mlx.h"
# include "fcntl.h"
# define GREY  9737620
# define RED 16711747
# define GREEN 6794612
# include <math.h>
# define PARALLEL 0
# define ISO 1

typedef	struct	s_params
{
	int		x_max;
	t_list	*points;
	int		fd;
	int		**plot;
	int		lines;
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	float	z_zoom;
	int		x_translate;
	int		y_translate;
	int		projection;
	char	mouse_down;
	int		x;
	int		y;
	int		width;
	int		height;
}				t_params;
typedef struct	s_point
{
	int	x;
	int	y;
	int z;
}				t_point;
void			ft_load_map(t_params *params);
void			ft_fatal(char *msg);
void			ft_draw_plane(t_params *params);
void			ft_draw(t_params *params);
void			ft_prex(t_params *params, int x, int y);
void			ft_prey(t_params *params, int x, int y);
void			line(t_params *params, int x0, int y0, int x1, int y1, int color);
int				ft_mouse_press(int keycode, int x, int y);
int				ft_scroll(int keycode);
int				ft_mouse_move(int x, int y);
int				ft_mouse_reslease(int button);
t_params		*ft_setter(t_params *params);
#endif
