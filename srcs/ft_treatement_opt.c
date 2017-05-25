/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatement_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 01:31:40 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:48:19 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		ft_display_index(int i)
{
	write(1, "\033[34;1m", ft_strlen("\033[34;1m"));
	write(1, "Index : ", 8);
	ft_putnbr(i);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\n", 1);
}

static void		ft_display_room(char *room)
{
	write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
	write(1, room, ft_strlen(room));
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\033[0;1m", ft_strlen("\033[0;1m"));
}

static void		ft_display_number_link(int number_room)
{
	write(1, "\n", 2);
	write(1, "\033[0;1m", ft_strlen("\033[0;1m"));
	write(1, "Number of room(s) : ", 20);
	ft_putnbr(number_room);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\n\n", 2);
}

static void		ft_display_no_match_path(t_lists *lists)
{
	t_control	*lists_control;
	t_road		*road;
	int			i;
	int			number_room;

	i = 0;
	while (lists)
	{
		++i;
		number_room = 0;
		lists_control = lists->control;
		road = lists_control->next;
		ft_display_index(i);
		while (road)
		{
			ft_display_room(road->room);
			(road->next != NULL) ? write(1, " --> ", 5) : 0;
			write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
			road = road->next;
			++number_room;
		}
		ft_display_number_link(number_room);
		lists = lists->next;
	}
}

void			ft_treatement_opt(t_lem *lem)
{
	if (lem->display_path)
		ft_display_path(lem->list_path, lem->nbr_path);
	if (lem->match)
	{
		write(1, "\033[33;1;4m", ft_strlen("\033[33;1;4m"));
		write(1, "Absolutely different path\n\n", 27);
		write(1, "\033[0;0;0m", ft_strlen("\033[0;0;0m"));
		ft_display_no_match_path(lem->possible_list_path);
	}
}
