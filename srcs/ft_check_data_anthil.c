/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_data_anthil.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 22:49:02 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 03:05:30 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static e_booleen		ft_check_data_ant(t_line *line_cpy, int *ant)
{
	while (line_cpy)
	{
		if (line_cpy->value == NBR_ANT)
			if (ft_overflow(line_cpy->content) && ft_zero(line_cpy->content))
			{
				*ant = ft_atoi(line_cpy->content);
				return (TRUE);
			}
		line_cpy = line_cpy->next;
	}
	return (FALSE);
}

static e_booleen		ft_check_command(t_line *cpy)
{
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (cpy)
	{
		if (cpy->value == START || cpy->value == END)
		{
			if (cpy->next == NULL)
				break ;
			else if (cpy->value == START && cpy->next->value == ROOM)
			{
				cpy->next->value_room = START;
				++start;
			}
			else if (cpy->value == END && cpy->next->value == ROOM)
			{
				cpy->next->value_room = END;
				++end;
			}
		}
		cpy = cpy->next;
	}
	return ((start != 1 || end != 1) ? FALSE : TRUE);
}

static e_booleen		search_connect_in_room(t_line *cpy, char *connect)
{
	while (cpy)
	{
		if (cpy->value == ROOM)
			if (!ft_strncmp(cpy->content, connect, ft_strlen(connect)))
				return (TRUE);
		cpy = cpy->next;
	}
	return (FALSE);
}

static e_booleen		ft_check_connect(t_line *cpy)
{
	char		**board;
	char		*temp_content;
	t_line		*temporary_cpy;
	char		*cpy_str;

	temporary_cpy = cpy;
	while (temporary_cpy)
	{
		if (temporary_cpy->value == CONNECT)
		{
			cpy_str = ft_strdup(temporary_cpy->content);
			temp_content = ft_strchr(cpy_str, '-');
			*temp_content = 4;
			board = ft_strsplit(cpy_str, 4);
			ft_memdel((void *)&cpy_str);
			if (search_connect_in_room(cpy, board[0]) == 0 \
								|| search_connect_in_room(cpy, board[1]) == 0)
				return (clear_tab(board));
			clear_tab(board);
		}
		temporary_cpy = temporary_cpy->next;
	}
	return (TRUE);
}

e_booleen				ft_check_data_anthil(t_line **line_copy, int *nbr_ant)
{
	if (!ft_check_data_ant(*line_copy, nbr_ant))
	{
		printf("Problem ant !\n");
		return (FALSE);
	}
	else if (!ft_check_command(*line_copy)) /* Start | END */
	{
		printf("Problem command start end !\n");
		return (FALSE);
	}
	else if (!ft_count_connect(*line_copy) || !ft_check_connect(*line_copy))
	{
		printf("Problem Connect !\n");
		return (FALSE);
	}
	return (TRUE);
}
