/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktbatou <ktbatou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 19:39:03 by ktbatou           #+#    #+#             */
/*   Updated: 2020/01/04 19:44:37 by ktbatou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	random_color(t_params *params)
{
	params->white = rand();
	params->pink = rand();
	params->yellow = rand();
}
