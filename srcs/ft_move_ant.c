/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 06:07:15 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 06:07:35 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void		ft_move_ant(t_road **road)
{
	t_road		*temp_prev;

	temp_prev = (*road)->prev;
	while (temp_prev->prev)
	{
		temp_prev->next->num_ant = temp_prev->num_ant;
		temp_prev->num_ant = -1;
		temp_prev = temp_prev->prev;
	}
}

