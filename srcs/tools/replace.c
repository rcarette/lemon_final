/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 21:23:46 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/18 21:45:13 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

void	replace(char **string, char replace, char new_char)
{
	int		ite;

	ite = -1;
	while ((*string)[++ite])
		if ((*string)[ite] == replace)
			(*string)[ite] = new_char;
}
