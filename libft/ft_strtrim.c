/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 12:12:39 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/19 21:56:50 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		size_s;
	int		end;

	start = 0;
	end = 0;
	if (s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	while (s[start] && ft_issspace(s[start]))
		++start;
	if (start == size_s)
		return (ft_strnew(0));
	while (ft_issspace(s[size_s - end - 1]))
		++end;
	return (ft_strsub(s, start, size_s - end - start));
}

void	ft_strtrim_noleaks(char **s)
{
	char	*cpy_str;

	cpy_str = ft_strdup(*s);
	free(*s);
	*s = ft_strtrim(cpy_str);
	free(cpy_str);
}
