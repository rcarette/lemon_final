/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcarette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:27:14 by rcarette          #+#    #+#             */
/*   Updated: 2017/05/25 05:05:37 by rcarette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include "../libft/libft.h"

typedef enum		booleen
{
	FALSE,
	TRUE,
	START,
	END,
	COMMENTAIRE,
	ROOM,
	CONNECT,
	NBR_ANT,
	INVALID = -1
}					e_booleen;

typedef struct		s_line
{
	char			*content;
	signed char		value;
	signed char		value_room;
	struct s_line	*next;
}					t_line;

typedef struct		s_co
{
	char			*room;
	t_line			*connect;
	struct s_co		*next;
}					t_co;

typedef struct		s_path
{
	t_line			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_save
{
	t_line			*path;
	int				index;
	int				nbr_links;
	struct s_save	*next;
}					t_save;

typedef struct		s_road
{
	struct s_road	*next;
	struct s_road	*prev;
	char			*room;
	int				num_ant;
}					t_road;

typedef struct		s_control
{
	t_road			*next;
	t_road			*prev;
	int				nbr_ant;
}					t_control;

typedef struct		s_lists
{
	t_control		*control;
	struct s_lists	*next;
}					t_lists;

typedef struct		s_lem
{
	int				nbr_ant;
	int				nbr_rooms;
	t_line			*copy_line;
	t_co			*list_connect;
	t_path			*path;
	t_save			*list_path;
	t_lists			*possible_list_path;
	char			*room_s;
	char			*room_e;
	int				nbr_path;
	int				display_path;
	int				match;
}					t_lem;

t_line		*ft_get_data_anthil(char **copy, int *nbr_rooms);
e_booleen	ft_check_data_anthil(t_line **line_cpy, int *nbr_ant);
t_co		*ft_creat_graph(t_line *line_cpy);
t_save		*ft_creat_path(t_lem *lem, t_save *list_path);
void		ft_save_path(t_save **path, t_line *list_path);
void		ft_display(t_lem *lem);
void		ft_display_path(t_save *save, int nbr_path);

/*
 * Function :  Verification of data !
 *
*/

/*
 * Function : Put all the characters in lower case !
 */
char	*ft_put_lowercase(char *string);

/*
 * Function : Counts the number of words. The delimiters are the spaces and tab !
 */
e_booleen	ft_count_number_of_words(char *string);

/*
 * Function : If the characters are just numbers !
 */
e_booleen	ft_digit(char *string);


/*
 * Function : Check Overflow
 */

e_booleen	ft_overflow(char *string);
e_booleen	ft_zero(char *str);

/*
 * Function : Replace tab
 */
void		replace(char **string, char replace, char new_char);

/*
 * Function : search obj in list !
 */
e_booleen	ft_search_antlist(t_line *line);
e_booleen	ft_search_roomlist(t_line *line, char *data);
e_booleen	ft_search_connectlist(t_line *line, char *data);
e_booleen	ft_search_reverse_connectlist(t_line *line, char *data, \
															e_booleen value);

/*
 * Function : count the number connect !
 */
e_booleen		ft_count_connect(t_line *cpy);

/*
 * Function(s) : ADD list !
 */
void		push_backline(t_line **line_cpy, char *content, signed char value);
void		push_backconnect(t_co **connect, t_line *line, char *room);
void		push_backpath(t_path **path, t_line *line);
void		push_frontconnect(t_co **connect, t_line *line, char *room);
void		delete_first(t_path **path);
void		clear_line(t_line **line_cpy);
void		debug_line(t_line *line_cpy);
void		debug_connect(t_co *connect);
void		clear_connect(t_co **connect);

/*
 * Function : sauve copy data
 *
 */

char			**returns_tab(char *data);
t_line			*ft_dupliq_list(t_line *list);
void			ft_clear_save(t_save **list);
e_booleen		detect_nbr_ant(char *str, t_line *line_cpy);
e_booleen		detect_connect(char *str, t_line *line_cpy);
e_booleen		detect_room(char *str, t_line *line_cpy);
e_booleen		detect_commentaire(char *str);
t_line			*ft_dupliq_list(t_line *list);
t_control		*ft_creat_list_double(t_line *line);
t_lists			*ft_multi_path(t_lem *lem);
void			clear_list_road(t_lists **lists);
void			ft_treatement_opt(t_lem *lem);
#endif
