/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dupliq_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 19:14:59 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/24 19:15:30 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_line		*ft_dupliq_list(t_line *list)
{
	t_line	*new_list;

	new_list = NULL;
	while (list)
	{
		push_backline(&new_list, list->content, 0);
		list = list->next;
	}
	return (new_list);
}
