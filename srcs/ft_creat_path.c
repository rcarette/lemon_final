/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 01:14:33 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 19:16:49 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int			lenght_list_connect(t_co *list_connect)
{
	t_line		*temporary;
	int			size;

	size = 0;
	temporary = list_connect->connect;
	while (temporary)
	{
		++size;
		temporary = temporary->next;
	}
	return (size);
}

static t_co		*search_connect(char *room, t_co *connect)
{
	while (connect)
	{
		if (!ft_strcmp(connect->room, room))
			return (connect);
		connect = connect->next;
	}
	return (NULL);
}

static void		prepare_path(t_path **path, t_line *list_connect, char *room)
{
	t_line	*new_list;

	new_list = NULL;
	while (list_connect)
	{
		push_backline(&new_list, room, 0);
		push_backline(&new_list, list_connect->content, 0);
		push_backpath(path, new_list);
		new_list = NULL;
		list_connect = list_connect->next;
	}
}

static char		*get_last_elem(t_line *list)
{
	while (list->next)
		list = list->next;
	return (list->content);
}

int			search_in_list(t_line *list, char *room)
{
	while (list)
	{
		if (!ft_strcmp(list->content, room))
			return (0);
		list = list->next;
	}
	return (1);
}

void		clear_path(t_path **path)
{
	t_line		*temp_line;
	t_path		*temp_path;

	temp_path = *path;
	temp_line = (*path)->path;
	(*path) = (*path)->next;
	clear_line(&temp_line);
	free(temp_path);
}

static void		ft_add_queue(t_co *list_connect, t_path **path, t_line *list)
{
	t_line		*temp_line;
	t_line		*dupliq;

	temp_line = list_connect->connect;
	while (temp_line)
	{
		if (search_in_list(list, temp_line->content))
		{
			dupliq = ft_dupliq_list(list);
			push_backline(&dupliq, temp_line->content, 0);
			push_backpath(path, dupliq);
		}
		temp_line = temp_line->next;
	}
	clear_path(path);
}

int		ft_check_path(t_line *line, char *room_e)
{
	while (line)
	{
		if (!ft_strcmp(room_e, line->content))
			return (1);
		line = line->next;
	}
	return (0);
}

int		ft_count_nbr_path(t_save *list_path)
{
	int		size_list;

	size_list = 0;
	while (list_path)
	{
		++size_list;
		list_path = list_path->next;
	}
	return (size_list);
}

t_save		*ft_creat_path(t_lem *lem, t_save *list_save)
{
	t_path		*path;
	t_co		*list_connect;
	t_line		*temp_line;

	path = NULL;
	list_connect = search_connect(lem->room_s, lem->list_connect);
	prepare_path(&path, list_connect->connect, list_connect->room);
	while (path)
	{
		temp_line = path->path;
		if (ft_check_path(temp_line, lem->room_e))
		{
			ft_save_path(&list_save, temp_line);
			clear_path(&path);
		}
		else
		{
			list_connect = search_connect(get_last_elem(temp_line), \
															lem->list_connect);
			ft_add_queue(list_connect, &path, temp_line);
		}
	}
	lem->nbr_path = ft_count_nbr_path(list_save);
	return (list_save);
}
