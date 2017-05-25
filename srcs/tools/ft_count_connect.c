/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_connect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 06:02:05 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/20 06:04:17 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

e_booleen		ft_count_connect(t_line *cpy)
{
	int		size;

	size = 0;
	while (cpy)
	{
		(cpy->value == CONNECT) ? ++size : 0;
		cpy = cpy->next;
	}
	if (size)
		return (TRUE);
	return (FALSE);
}
