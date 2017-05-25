/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 21:36:00 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/23 00:37:37 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static t_path		*ft_creat_new_elem_path(t_line *line)
{
	t_path		*new_path;

	if (!(new_path = (t_path *)malloc(sizeof(t_path))))
		exit(EXIT_FAILURE);
	new_path->path = line;
	new_path->next = NULL;
	return (new_path);
}


void				delete_first(t_path **path)
{
	t_path		*delete;

	delete = *path;
	*path = (*path)->next;
	clear_line(&delete->path);
	free(delete);
}

void				push_backpath(t_path **path, t_line *line)
{
	t_path		*new_path;
	t_path		*temp_path;

	if (*path == NULL)
		*path = ft_creat_new_elem_path(line);
	else
	{
		new_path = ft_creat_new_elem_path(line);
		temp_path = *path;
		while (temp_path->next)
			temp_path = temp_path->next;
		temp_path->next = new_path;
	}
}
