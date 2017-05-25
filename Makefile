# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcarette <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/26 12:04:47 by rcarette          #+#    #+#              #
#    Updated: 2017/05/25 07:00:43 by rcarette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in
FLAGS = 
CC = clang $(FLAGS)
INC = include/
LIBFT = libft/
INC_LIB = libft/libft.h
ALL_INC = -I $(INC) -I $(INC_LIB)
OBJS = $(SRCS:%.c=%.o)

SRCS = srcs/main.c\
	   srcs/ft_get_data_anthil.c\
	   srcs/ft_check_data_anthil.c\
	   srcs/tools/push_backline.c\
	   srcs/ft_creat_list_connect.c\
	   srcs/ft_creat_path.c\
	   srcs/ft_save_path.c\
	   srcs/ft_display.c\
	   srcs/ft_treatement_opt.c\
	   srcs/ft_multi_path.c\

TOOLS = srcs/tools/replace.c\
		srcs/tools/ft_put_lowercase.c\
		srcs/tools/ft_digit.c\
		srcs/tools/ft_overflow.c\
		srcs/tools/ft_search_in_list.c\
		srcs/tools/ft_count_connect.c\
		srcs/tools/push_backconnect.c\
		srcs/tools/push_backpath.c\
		srcs/tools/ft_clear_save.c\
		srcs/tools/dectect.c\
		srcs/tools/ft_display_path.c\
		srcs/tools/ft_dupliq_list.c\
		srcs/tools/ft_creat_lists_double.c\
		srcs/tools/ft_search_small_path.c\
		srcs/tools/ft_display_move_ant.c\
		srcs/ft_move_ant.c\
		srcs/ft_move_ant_first_tube.c\
		srcs/tools/ft_search_ant.c\
		srcs/tools/ft_nbr_shots.c\

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	$(CC) -g -o $(NAME) $(SRCS) $(TOOLS) $(ALL_INC)  -L $(LIBFT) -lft

%.o: %.c
	$(CC) -o $@ -c $< $(ALL_INC)

clean:
	@make clean -C $(LIBFT)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
.PHONY: all clean flcean re
