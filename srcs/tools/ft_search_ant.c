/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_ant.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 06:03:14 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 06:03:45 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

int			search_ant(t_road *road)
{
	while (road->next)
	{
		if (road->num_ant != -1)
		{
			write(1, "\n", 1);
			return (1);
		}
		road = road->next;
	}
	write(1, "\n", 1);
	return (0);
}
