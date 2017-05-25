/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 16:47:28 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:20:06 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

static void		init_lem(t_lem *lem)
{
	lem->copy_line = NULL;
	lem->list_connect = NULL;
	lem->path = NULL;
	lem->possible_list_path = NULL;
	lem->list_path = NULL;
	lem->nbr_rooms = 0;
	lem->room_s = NULL;
	lem->room_e = NULL;
	lem->nbr_path = 0;
	lem->display_path = 0;
	lem->match = 0;
}

static int		ft_exit(t_lem *lem, char **copy)
{
	(lem->copy_line != NULL) ? clear_line(&lem->copy_line) : 0;
	(lem->list_connect != NULL) ? clear_connect(&lem->list_connect) : 0;
	(lem->list_path != NULL) ? ft_clear_save(&lem->list_path) : 0;
	if (lem->possible_list_path != NULL)
		clear_list_road(&lem->possible_list_path);
	(*copy != NULL) ? free(*copy) : 0;
	(lem->room_s != NULL) ? free(lem->room_s) : 0;
	(lem->room_e != NULL) ? free(lem->room_e) : 0;
	exit(0);
	return (0);
}

static void		ft_get_room(t_line *line, char **lem_room, e_booleen value)
{
	char	*temporary;

	while (line)
	{
		if (line->value_room == value)
		{
			*lem_room = ft_strdup(line->content);
			temporary = ft_strchr(*lem_room, ' ');
			*temporary = '\0';
		}
		line = line->next;
	}
}

static void		ft_get_opt(int argc, char **argv, t_lem *lem)
{
	int		ite;

	ite = 0;
	while (++ite < argc)
	{
		if (!ft_strcmp("-p", argv[ite]) || !ft_strcmp("--path", argv[ite]))
			lem->display_path = 1;
		else if (!ft_strcmp("-m", argv[ite]) \
										|| !ft_strcmp("--match", argv[ite]))
			lem->match = 1;
	}
}

int main(int ac, char **av)
{
	t_lem		lem;
	char		*copy;
	t_line		*line;

	copy = NULL;
	init_lem(&lem);
	if (!(lem.copy_line = ft_get_data_anthil(&copy, &lem.nbr_rooms)))
		ft_exit(&lem, &copy);
	if (!ft_check_data_anthil(&lem.copy_line, &lem.nbr_ant))
		ft_exit(&lem, &copy);
	lem.list_connect = ft_creat_graph(lem.copy_line);
	ft_get_room(lem.copy_line, &lem.room_s, START);
	ft_get_room(lem.copy_line, &lem.room_e, END);
	if (!(lem.list_path = ft_creat_path(&lem, NULL)))
		ft_exit(&lem, &copy);
	lem.possible_list_path = ft_multi_path(&lem);
	(ac > 1) ? ft_get_opt(ac, av, &lem) : 0;
	write(1, copy, ft_strlen(copy));
	write(1, "\n", 1);
	ft_display(&lem);
	return (ft_exit(&lem, &copy));
}
