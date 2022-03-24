# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahimmi <ahimmi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 01:55:25 by akarafi           #+#    #+#              #
#    Updated: 2022/03/24 20:56:19 by ahimmi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INC = ft_printf.h
AR := ar rc
FLAGS = -Wall -Wextra -Werror
REMOVE := rm -rf
SRCS = ft_printf.c\
        ft_print_uhexa.c\
        ft_print_hexa.c\
        ft_printstr.c\
        ft_putchar_fd.c\
        ft_putnbr_fd.c\
        ft_putnbr_u_fd.c\
        ft_putstr_fd.c\
        ft_strlen.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@$(AR) $@ $^
%.o: %.c $(INC)
	@cc $(FLAGS) -c $< -o $@


clean:
	@$(REMOVE) $(OBJS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all
