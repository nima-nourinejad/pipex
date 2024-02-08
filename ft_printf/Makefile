# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nnourine <nnourine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 15:48:51 by nnourine          #+#    #+#              #
#    Updated: 2023/11/13 16:49:57 by nnourine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_printf.c \
			ft_printf_s.c \
			ft_printf_c.c \
			ft_printf_di.c \
			ft_printf_u.c \
			ft_printf_x.c \
			ft_printf_xx.c \
			ft_printf_p.c \
			ft_strlen_int.c \
			ft_putchar.c \
			ft_putstr.c
		
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re