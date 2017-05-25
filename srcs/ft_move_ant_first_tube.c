/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_ant_first_tube.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 06:06:27 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 06:06:54 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

void		ft_move_ant_firt_tube(t_road **road, int num_ant)
{
	(*road)->next->num_ant = num_ant;
}
