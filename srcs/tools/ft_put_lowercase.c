/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_lowercase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 23:02:20 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/18 23:14:24 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

char	*ft_put_lowercase(char *str)
{
	char	*new_str;
	int		ite;

	if (!str)
		return (NULL);
	else if (!ft_strlen(str))
		return (str);
	ite = -1;
	new_str = ft_strdup(str);
	while (new_str[++ite])
		if (new_str[ite] >= 65 && new_str[ite] <= 90)
			new_str[ite] += 32;
	return (new_str);
}
