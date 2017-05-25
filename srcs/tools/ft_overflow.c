/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 00:12:16 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/19 20:44:11 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

e_booleen	ft_overflow(char *str)
{
	long long	data;

	if (ft_strlen(str) > 10)
		return (FALSE);
	data = ft_atoi(str);
	if (data < 0 || data > MAX_INT)
		return (FALSE);
	return (TRUE);
}

e_booleen	ft_zero(char *str)
{
	long long	data;

	if (!ft_strlen(str))
		return (FALSE);
	if (!(data = ft_atoi(str)))
		return (FALSE);
	return (TRUE);
}

