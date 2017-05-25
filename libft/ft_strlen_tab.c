/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/15 16:14:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/19 02:18:15 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_tab(char **board)
{
	int		ite;
	int		size;
	
	size = 0;
	ite = -1;
	while (board[++ite])
		++size;
	return (size);
}
