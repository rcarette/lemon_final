/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dectect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 02:33:11 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 04:36:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

e_booleen		detect_commentaire(char *str)
{
	char		*model;
	e_booleen	value;

	model = ft_put_lowercase(str);
	if (!ft_strcmp(model, "##start"))
		value = START;
	else if (!ft_strcmp(model, "##end"))
		value = END;
	else
		value = COMMENTAIRE;
	free(model);
	model = NULL;
	return (value);
}

e_booleen		detect_room(char *str, t_line *line_cpy)
{
	char		**board;
	char		*cpy;
	e_booleen	value;

	cpy = ft_strdup(str);
	if (cpy[0] == 'L')
		return (FALSE);
	(ft_strchr(cpy, ' ') || ft_strchr(cpy, '\t')) ? replace(&cpy, ' ', 4) : 0;
	if (ft_strlen_tab(board = ft_strsplit(cpy, 4)) == 3 && ft_digit(board[1]) \
					&& ft_digit(board[2]) && ft_overflow(board[1]) \
			&& ft_overflow(board[2]) && ft_search_roomlist(line_cpy, board[0]))
		value = TRUE;
	else
		value = FALSE;
	free(cpy);
	clear_tab(board);
	return (value);
}

e_booleen		detect_connect(char *str, t_line *line_cpy)
{

/*
 * FIX strcmp !!
 *
 */
	char		*cpy;
	char		**board;
	e_booleen	value;
	char		*temporary;

	if (str[0] == '-')
		return (FALSE);
	cpy = ft_strdup(str);
	if ((temporary = ft_strchr(cpy, '-')))
		*temporary = 4;
	if (ft_strlen_tab(board = ft_strsplit(cpy, 4)) == 2 \
		&& ft_search_connectlist(line_cpy, str) && strcmp(board[0], board[1]))
		value = TRUE;
	else
		value = FALSE;
	free(cpy);
	clear_tab(board);
	return (value);
}

e_booleen		detect_nbr_ant(char *str, t_line *line_cpy)
{
	char		**board;
	char		*cpy;
	e_booleen	value;

	cpy = ft_strdup(str);
	(ft_strchr(cpy, ' ') || ft_strchr(cpy, '\t')) ? replace(&cpy, ' ', 4) : 0;
	if (ft_strlen_tab(board = ft_strsplit(cpy, 4)) == 1 && ft_digit(board[0])\
								&& ft_overflow(board[0]) && ft_zero(str) \
												&& ft_search_antlist(line_cpy))
		value = TRUE;
	else
		value = FALSE;
	free(cpy);
	clear_tab(board);
	return (value);
}
