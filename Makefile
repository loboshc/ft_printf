# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 20:51:23 by dlobos-m          #+#    #+#              #
#    Updated: 2020/01/10 20:27:35 by dlobos-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libftprintf.a
SRC=ft_printf.c  ft_d.c ft_checkflags.c \
	ft_d2.c ft_c.c ft_s.c ft_x.c ft_itoa.c\
	ft_strlen.c ft_isdigit.c ft_atoi.c\
	ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c\
	ft_pct.c ft_utils.c

MAIN=main.c
OBJ=${SRC:.c=.o}

all : $(NAME)

$(NAME): $(SRC) ft_printf.h
	gcc -Wall -Werror -Wextra $(SRC) -c
	ar rc ${NAME} $(OBJ)
	ranlib $(NAME)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

