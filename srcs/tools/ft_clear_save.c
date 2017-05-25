/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 00:39:20 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 00:39:55 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	ft_clear_save(t_save **list)
{
	t_line		*delete;
	t_save		*delete_save;

	while ((*list))
	{
		delete = (*list)->path;
		delete_save = (*list);
		clear_line(&delete);
		(*list) = (*list)->next;
		free(delete_save);
	}
}
