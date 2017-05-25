/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_move_ant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 06:05:38 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 06:06:01 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void		ft_display_move_ant(t_road *road)
{
	while (road)
	{
		if (road->num_ant != -1)
		{
			write(1, "L", 1);
			ft_putnbr(road->num_ant);
			write(1, "-", 1);
			write(1, road->room, ft_strlen(road->room));
			write(1, " ", 1);
		}
		road = road->prev;
	}
}
