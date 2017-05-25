/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_data_anthil.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:45:49 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 02:45:41 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static e_booleen	string_analyz(char *str, t_line *line_copy, int *nbr_room)
{
	if (!ft_strlen(str))
		return(INVALID);
	else if (str[0] == '#')
		return (detect_commentaire(str));
	else if (detect_room(str, line_copy))
	{
		(*nbr_room)++;
		return (ROOM);
	}
	else if (detect_connect(str, line_copy))
		return (CONNECT);
	else if (detect_nbr_ant(str, line_copy))
		return (NBR_ANT);
	return (INVALID);
}

t_line				*ft_get_data_anthil(char **copy, int *nbr_room)
{
	t_line		*line_copy;
	char		*string;
	e_booleen	value;

	string = NULL;
	line_copy = NULL;
	while (get_next_line(0, &string))
	{
		ft_strtrim_noleaks(&string);
		(ft_strchr(string, '\t')) ? replace(&string, '\t', ' ') : 0;
		value = string_analyz(string, line_copy, nbr_room);
		if (value == INVALID)
			break ;
		else
			push_backline(&line_copy, string, value);
		strjoin_noleaks(copy, string);
		strjoin_noleaks(copy, "\n");
		(string != NULL) ? free(string) : 0;
		string = NULL;
	}
	(string != NULL) ? free(string) : 0;
	return (line_copy);
}
