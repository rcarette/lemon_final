/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_creat_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 14:41:42 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/22 15:12:45 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*static void		ft_debug_creat_tab(int **board, int i, int j)
{
	int		ite;
	int		jte;
	
	ite = -1;
	while (++ite < i)
	{
		jte = -1;
		while (++jte < j)
			printf("%d ", board[ite][jte]);
		printf("\n");
	}
}*/

int		**ft_creat_tab(int i, int j)
{
	int		**board;
	int		ite;
	int		jte;

	ite = -1;
	jte = -1;
	if (!(board = (int **)malloc(sizeof(int *) * i)))
		exit(EXIT_FAILURE);
	while (++ite < i)
		if (!(board[ite] = (int *)malloc(sizeof(int) * j)))
			exit(EXIT_FAILURE);
	ite = -1;
	while (++ite < i)
	{
		jte = -1;
		while (++jte < j)
			board[ite][jte] = 0;
	}
	return (board);
}
