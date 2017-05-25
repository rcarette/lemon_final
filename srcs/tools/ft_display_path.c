/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:52:32 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:51:10 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/main.h"

static void		ft_display_nbr_path(int nbr_path)
{
	char		*nbr;

	nbr = ft_itoa(nbr_path);
	write(1, "\033[33;1;4m", ft_strlen("\033[33;1;4m"));
	write(1, "Number of Path : {", 18);
	write(1, nbr, ft_strlen(nbr));
	write(1, "}\n\n", 3);
	write(1, "\033[0;0;0m", ft_strlen("\033[0;0;0m"));
	ft_memdel((void *)&nbr);
}

static void		ft_display_index(int index, int nbr_links)
{
	write(1, "\033[34;1m", ft_strlen("\033[34;1m"));
	write(1, "Index : ", 8);
	ft_putnbr(index);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\n", 1);
	write(1, "\033[0;1m", ft_strlen("\033[0;1m"));
	write(1, "Number of rooms : ", 18);
	ft_putnbr(nbr_links);
	write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
	write(1, "\n", 2);
}

void	ft_display_path(t_save *save, int nbr_path)
{
	t_line		*line;

	ft_display_nbr_path(nbr_path);
	while (save)
	{
		line = save->path;
		ft_display_index(save->index, save->nbr_links);
		while (line)
		{
			write(1, "\033[31;1m", ft_strlen("\033[31;1m"));
			write(1, line->content, ft_strlen(line->content));
			write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
			if (line->next != NULL)
			{
				write(1, "\033[0;1m", ft_strlen("\033[0;1m"));
				write(1, " --> ", 5);
				write(1, "\033[0;0m", ft_strlen("\033[0;0m"));
			}
			line = line->next;
		}
		if (save->next != NULL)
			write(1, "\n\n", 2);
		save = save->next;
	}
	write(1, "\n\n", 2);
}
