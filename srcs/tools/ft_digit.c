/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:00:06 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/19 00:04:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

e_booleen	ft_digit(char *str)
{
	int		ite;

	ite = -1;
	while (str[++ite])
		if (!ft_isdigit(str[ite]))
			return (FALSE);
	return(TRUE);
}
