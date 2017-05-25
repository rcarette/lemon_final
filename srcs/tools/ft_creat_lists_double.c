/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_lists_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 22:55:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:05:56 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static t_road		*ft_creat_new_road(char *room)
{
	t_road		*road;

	if (!(road = (t_road *)malloc(sizeof(t_road))))
		exit(EXIT_FAILURE);
	road->next = NULL;
	road->prev = NULL;
	if (!(road->room = ft_strdup(room)))
		exit(EXIT_FAILURE);
	road->num_ant = -1;
	return (road);
}

static void			ft_assembly_road(t_control **control, t_road *new_road)
{
	t_road		*temp_road;

	if ((*control)->next == NULL)
	{
		(*control)->next = new_road;
		(*control)->prev = new_road;
	}
	else
	{
		temp_road = (*control)->next;
		(*control)->prev = new_road;
		while (temp_road->next)
			temp_road = temp_road->next;
		temp_road->next = new_road;
		new_road->prev = temp_road;
	}
}

void	clear_list_road(t_lists		**lists)
{
	t_road		*road;
	t_road		*delete;
	t_control	*list_control;

	while (*lists)
	{
		list_control = (*lists)->control;
		road = list_control->next;
		while (road)
		{
			delete = road;
			free(delete->room);
			road = road->next;
			free(delete);
		}
		free(list_control);
		(*lists) = (*lists)->next;
	}
}



t_control			*ft_creat_list_double(t_line *line)
{
	t_control	*control;
	t_road		*new_road;
	
	new_road = NULL;
	if (!(control = (t_control *)malloc(sizeof(t_control))))
		exit(EXIT_FAILURE);
	control->next = NULL;
	control->prev = NULL;
	while (line)
	{
		new_road = ft_creat_new_road(line->content);
		ft_assembly_road(&control, new_road);
		line = line->next;
	}
	return (control);
}
