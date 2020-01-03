/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/02 19:14:00 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/03 15:21:49 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_valeur(char c)
{
	int i;

	i = 0;
	if (c >= '0' && c <= 9)
		i = c - '0';
	else if (c >= 'a' && c <= 'f')
		i = c - 'a' + 10;
	else if (c >= 'A' && c <= 'F')
		i = c - 'A' + 10;
	return (i);
}

int		string_to_int(char *color)
{
	int	i;
	int	x;
	int	binary;

	i = 0;
	binary = 0;
	x = 0;
	if (!color)
		return (0);
	while (color[i])
	{
		x = get_valeur(color[i]);
		binary = binary << 4 | x;
		i++;
	}
	return (binary);
}

int		hex_lenght(char *str)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i + 1] == 0)
		{
			while (str[i++])
				n++;
		}
		i++;
	}
	return (n);
}

char	*color_val(char *x)
{
	int		i;
	int		n;
	char	*clr;

	i = 0;
	n = 0;
	clr = 0;
	if (!hex_lenght(x))
		clr = ft_strnew(hex_lenght(x));
	else
		return (NULL);
	while (x[i])
	{
		if (x[i] == ',')
		{
			i += 3;
			while (x[i])
				clr[n++] = x[i++];
		}
		i++;
	}
	return (clr);
}

int		get_color(char *x)
{
	int		val;
	char	*color;

	val = 0;
	color = 0;
	if (!(color = color_val(x)))
		return (0);
	else
		val = string_to_int(color);
	return (val);
}
