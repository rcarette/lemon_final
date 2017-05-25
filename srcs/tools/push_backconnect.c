/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backconnect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:53:35 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/22 19:37:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static t_co		*creat_new_connect(t_line *line, char *room)
{
	t_co	*new_link;

	if (!(new_link = (t_co *)malloc(sizeof(t_co))))
		exit(EXIT_FAILURE);
	new_link->room = ft_strdup(room);
	new_link->connect = line;
	new_link->next = NULL;
	return (new_link);
}

void			push_frontconnect(t_co **list_connect, t_line *line , char *room)
{
	t_co	*new_link;

	new_link = creat_new_connect(line, room);
	new_link->next = *list_connect;
	*list_connect = new_link;
}

void			clear_connect(t_co **connect)
{
	t_co		*delete_connect;
	t_line		*temp_line;
	t_line		*delete_li;

	while (*connect)
	{
		delete_connect = *connect;
		temp_line = (*connect)->connect;
		while (temp_line)
		{
			delete_li = temp_line;
			temp_line = temp_line->next;
			free(delete_li->content);
			free(delete_li);
		}
		(*connect) = (*connect)->next;
		free(delete_connect->room);
		free(delete_connect);
	}
}

void			push_backconnect(t_co **list_connect, t_line *line, char *room)
{
	t_co	*new_link;
	t_co	*temporary;

	if (*list_connect == NULL)
		*list_connect = creat_new_connect(line, room);
	else
	{
		new_link = creat_new_connect(line, room);
		temporary = *list_connect;
		while (temporary->next)
			temporary = temporary->next;
		temporary->next = new_link;
	}
}
