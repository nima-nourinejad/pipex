# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2024/02/10 18:32:35 by nnourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_split_pipex.c \
		ft_io.c \
		scape.c \
		possibility.c\
		path.c \
		root.c \
		helper.c \
		helper2.c \
		args.c \
		rule.c \
		best_rule.c \
		rule_check.c \
		exec_rule2.c \
		exec_rule3.c \
		check_path.c \
		pipex.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

NAME = pipex
all: $(NAME)
$(NAME): $(OBJ)
	make -C libft bonus
	make -C ft_printf all
	cc $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -Lft_printf -lftprintf

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C ft_printf clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C ft_printf fclean

re: fclean all 

.PHONY: all clean fclean re