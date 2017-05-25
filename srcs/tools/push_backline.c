/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_backline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 19:50:36 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 01:00:22 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static t_line		*new_elem_line(char *content, signed char value)
{
	t_line		*new_link;
	int			size_content;

	size_content = (ft_strlen(content) + 1);
	if (!(new_link = (t_line *)malloc(sizeof(t_line))))
		exit(EXIT_FAILURE);
	if (!(new_link->content = (char *)malloc(sizeof(char) * size_content)))
		exit(EXIT_FAILURE);
	ft_memset(new_link->content, '\0', size_content);
	ft_memcpy(new_link->content, content, size_content - 1);
	new_link->next = NULL;
	new_link->value = value;
	new_link->value_room = 0;
	return (new_link);
}

void	push_backline(t_line **line_cpy, char *content, signed char value)
{
	t_line	*new_link;
	t_line	*temp;

	if (*line_cpy == NULL)
		*line_cpy = new_elem_line(content, value);
	else
	{
		new_link = new_elem_line(content, value);
		temp = *line_cpy;
		while (temp->next)
			temp = temp->next;
		temp->next = new_link;
	}
}

void	clear_line(t_line **line_cpy)
{
	t_line	*delete;

	while (*line_cpy)
	{
		delete = *line_cpy;
		free(delete->content);
		(*line_cpy) = (*line_cpy)->next;
		free(delete);
	}
}
