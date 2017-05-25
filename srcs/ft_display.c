/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:55:31 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 06:59:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		ft_start_display(t_control *control, t_lem *lem)
{
	int			num_ant;
	int			coups;

	coups = 0;
	num_ant = 0;
	ft_move_ant_firt_tube(&control->next, ++num_ant);
	control->nbr_ant--;
	ft_display_move_ant(control->prev);
	while (control->nbr_ant)
	{
		write(1, "\n", 1);
		++coups;
		++num_ant;
		ft_move_ant(&control->prev);
		ft_move_ant_firt_tube(&control->next, num_ant);
		ft_display_move_ant(control->prev);
		control->nbr_ant--;
	}
	while (search_ant(control->next))
	{
		++coups;
		ft_move_ant(&control->prev);
		ft_display_move_ant(control->prev);
	}
	(lem->nbr_shots) ? ft_nbr_shots(coups) : 0;
}

static void		ft_clear_list_road(t_control **control)
{
	t_road		*road;
	t_road		*delete;

	road = (*control)->next;
	while (road)
	{
		delete = road;
		free(delete->room);
		road = road->next;
		free(delete);
	}
	free(*control);
}

void			ft_display(t_lem *lem)
{
	t_line		*line;
	t_control	*control;
	t_road		*road;

	ft_treatement_opt(lem);
	line = ft_search_small_path(lem->list_path);
	control = ft_creat_list_double(line);
	control->nbr_ant = lem->nbr_ant;
	ft_start_display(control, lem);
	ft_clear_list_road(&control);
}
