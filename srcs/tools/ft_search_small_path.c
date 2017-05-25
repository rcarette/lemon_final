/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_small_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 05:54:45 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:55:18 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

t_line		*ft_search_small_path(t_save *save)
{
	int			min;
	t_line		*link;

	min = save->nbr_links;
	while (save)
	{
		if (min >= save->nbr_links)
			link = save->path;
		save = save->next;
	}
	return (link);
}
