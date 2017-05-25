/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_list_connect.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/21 11:23:25 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/23 16:31:31 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

t_line			*ft_get_connect(t_line *line, char *room)
{
	t_line		*list_connect;
	char		**board;

	list_connect = NULL;
	while (line)
	{
		if (line->value == CONNECT)
		{
			board = returns_tab(line->content);
			if (!ft_strcmp(board[0], room))
				push_backline(&list_connect, board[1], 0);
			clear_tab(board);
		}
		line = line->next;
	}
	return (list_connect);
}

void	ft_graph(t_co **list_connect, char *room_search, char *data)
{
	t_co	*temp_connect;
	t_line	*temp_line;

	temp_connect = *list_connect;
	while (temp_connect)
	{
		temp_line = temp_connect->connect;
		if (!ft_strcmp(temp_connect->room, room_search))
		{
			if (temp_line == NULL)
				push_backline(&temp_connect->connect, data, 0);
			else
			{
				while (temp_line)
				{
					if (!ft_strcmp(data, temp_line->content))
						return ;
					temp_line = temp_line->next;
				}
				push_backline(&temp_connect->connect, data, 0);
			}
		}
		temp_connect = temp_connect->next;
	}
}

void	ft_check_graph(t_line *line, t_co **list_connect)
{
	t_line		*temp_line;
	char		*cpy;
	char		*temporary;
	char		*room_search;

	while (line)
	{
		if (line->value == CONNECT)
		{
			cpy = ft_strdup(line->content);
			temporary = ft_strchr(cpy, '-');
			*temporary = '\0';
			room_search = ft_strdup(temporary + 1);
			ft_graph(list_connect, room_search, cpy);
			ft_memdel((void *)&cpy);
			ft_memdel((void *)&room_search);
		}
		line = line->next;
	}
}

t_co		*ft_creat_graph(t_line *line)
{
	t_co	*list_connect;
	t_line	*temp_line;
	char	*cpy;
	char	*temporary;

	temp_line = line;
	list_connect = NULL;
	while (temp_line)
	{
		cpy = ft_strdup(temp_line->content);
		if ((temporary = ft_strchr(cpy, ' ')))
			*temporary = '\0';
		if (temp_line->value == ROOM)
			push_backconnect(&list_connect, ft_get_connect(line, cpy), cpy);
		free(cpy);
		temp_line = temp_line->next;
	}
	ft_check_graph(line, &list_connect);
	return (list_connect);
}
