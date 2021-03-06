/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sid-bell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 01:21:25 by sid-bell          #+#    #+#             */
/*   Updated: 2018/10/12 05:10:13 by sid-bell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t lenght;

	lenght = 0;
	if (s)
		while (*s != '\0')
		{
			lenght++;
			s++;
		}
	return (lenght);
}
