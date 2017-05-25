/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 17:55:31 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:05:17 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_line		*ft_search_small_path(t_save *save)
{
	int			min;
	t_line		*link;

	min = save->nbr_links;
	while (save)
	{
		if (min >= save->nbr_links)
			link = save->path;
		save = save->next;
	}
	return (link);
}

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

void		ft_move_ant_firt_tube(t_road **road, int num_ant)
{
	(*road)->next->num_ant = num_ant;
}

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

void	ft_display(t_lem *lem)
{
	t_line		*line;
	t_control	*control;
	t_road		*road;
	int			num_ant;

	ft_treatement_opt(lem);
	num_ant = 0;
	line = ft_search_small_path(lem->list_path);
	control = ft_creat_list_double(line);
	control->nbr_ant = lem->nbr_ant;
	ft_move_ant_firt_tube(&control->next, ++num_ant);
	control->nbr_ant--;
	ft_display_move_ant(control->prev);
	while (control->nbr_ant)
	{
		write(1, "\n", 1);
		++num_ant;
		ft_move_ant(&control->prev);
		ft_move_ant_firt_tube(&control->next, num_ant);
		ft_display_move_ant(control->prev);
		control->nbr_ant--;
	}
	while (search_ant(control->next))
	{
		ft_move_ant(&control->prev);
		ft_display_move_ant(control->prev);
	}
	//clear_list_road(&control);
}
