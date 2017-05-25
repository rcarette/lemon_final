/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 23:14:12 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 05:08:55 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static int		ft_count_nbr_line(t_line *list_link)
{
	int		size_list;

	size_list = 0;
	while (list_link)
	{
		++size_list;
		list_link = list_link->next;
	}
	return (size_list);
}

static t_save		*ft_creat_new_path(t_line *path)
{
	t_save						*new_list;
	t_line						*new_path;
	static		unsigned int	i = 1;

	new_list = NULL;
	new_path = NULL;
	if (!(new_list = (t_save *)malloc(sizeof(t_save))))
		exit(EXIT_FAILURE);
	new_list->nbr_links = ft_count_nbr_line(path);
	while (path)
	{
		push_backline(&new_path, path->content, 0);
		path = path->next;
	}
	new_list->path = new_path;
	new_list->next = NULL;
	new_list->index = i++;

	return (new_list);
}

static void			ft_push_backpath(t_save **path, t_line *list_path)
{
	t_save		*temporary;
	t_save		*new_list;

	if (*path == NULL)
		*path = ft_creat_new_path(list_path);
	else
	{
		new_list = ft_creat_new_path(list_path);
		temporary = *path;
		while (temporary->next)
			temporary = temporary->next;
		temporary->next = new_list;
	}
}

void	ft_save_path(t_save **save, t_line *path)
{
	if (path != NULL)
		ft_push_backpath(save, path);
}
