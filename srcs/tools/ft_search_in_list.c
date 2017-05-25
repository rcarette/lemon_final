/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_in_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 01:06:41 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/21 13:02:27 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char		**returns_tab(char *data)
{
	char	**value_data;
	char	*cpy;
	char	*temporary;

	cpy = ft_strdup(data);
	temporary = ft_strchr(cpy, '-');
	*temporary = 4;
	value_data = ft_strsplit(cpy, 4);
	free(cpy);
	return (value_data);
}

e_booleen	ft_search_antlist(t_line *line)
{
	while (line)
	{
		if (line->value == NBR_ANT)
			return (FALSE);
		line = line->next;
	}
	return (TRUE);
}

e_booleen	ft_search_roomlist(t_line *line, char *data)
{
	while (line)
	{
		if (line->value == ROOM)
			if (!ft_strncmp(data, line->content, ft_strlen(data)))
				return (FALSE);
		line = line->next;
	}
	return (TRUE);
}

e_booleen	ft_search_connectlist(t_line *line, char *data)
{
	while (line)
	{
		if (line->value == CONNECT)
			if (!ft_strcmp(data, line->content))
				return (FALSE);
		line = line->next;
	}
	return (TRUE);
}

e_booleen	ft_search_reverse_connectlist(t_line *line, \
												char *data, e_booleen value)
{
	char	**value_data;
	char	**value_line;

	if (value != CONNECT)
		return (TRUE);
	value_data = returns_tab(data);
	while (line)
	{
		if (line->value == CONNECT)
		{
			value_line = returns_tab(line->content);
			if (!ft_strcmp(value_data[0], value_line[1]) \
								&& !ft_strcmp(value_data[1], value_line[0]))
			{
				clear_tab(value_data);
				clear_tab(value_line);
				return (FALSE);
			}
			clear_tab(value_line);
		}
		line = line->next;
	}
	return (TRUE);
}
