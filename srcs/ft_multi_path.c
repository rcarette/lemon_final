/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multi_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 02:50:14 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 04:55:04 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static t_lists		*ft_creat_new_lists(t_control *list)
{
	t_lists		*new_links;

	if (!(new_links = (t_lists *)malloc(sizeof(t_lists))))
		exit(EXIT_FAILURE);
	new_links->next = NULL;
	new_links->control = list;
	return (new_links);
}

static void			ft_push_back_lists(t_lists **lists, t_control *list)
{
	t_lists		*new_link;
	t_lists		*temp_lists;

	if (*lists == NULL)
		*lists = ft_creat_new_lists(list);
	else
	{
		new_link = ft_creat_new_lists(list);
		temp_lists = *lists;
		while (temp_lists->next)
			temp_lists = temp_lists->next;
		temp_lists->next = new_link;
	}
}

static void			ft_add_paths(t_lists **lists, t_line *line)
{
	t_control	*list_control;

	list_control = NULL;
	list_control = ft_creat_list_double(line);
	ft_push_back_lists(lists, list_control);
}

static int			ft_match(t_line *line, t_lists *lists)
{
	t_control	*list;
	t_road		*road;
	t_line		*temp_line;

	while (lists)
	{
		list = lists->control;
		road = list->next->next;
		while (road->next)
		{
			temp_line = line;
			while (temp_line)
			{
				if (!ft_strcmp(temp_line->content, road->room))
					return (0);
				temp_line = temp_line->next;
			}
			road = road->next;
		}
		lists = lists->next;
	}
	return (1);
}

t_lists				*ft_multi_path(t_lem *lem)
{
	t_save		*list_path;
	t_line		*line;
	t_lists		*lists;

	lists = NULL;
	list_path = lem->list_path;
	while (list_path)
	{
		line = list_path->path;
		if (lists == NULL)
			ft_add_paths(&lists, line);
		else if (ft_match(line, lists))
			ft_add_paths(&lists, line);
		list_path = list_path->next;
	}
	return (lists);
}
