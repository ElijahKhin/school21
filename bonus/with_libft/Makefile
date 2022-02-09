# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sworker <sworker@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/13 02:30:40 by cwindom           #+#    #+#              #
#    Updated: 2022/02/08 20:26:23 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc 
MAKE = make
HEADER = ft_printf.h

SRC = ft_printf.c main_loop.c ./includes/ft_print_arg.c ./includes/ft_utoa.c \
	./includes/ft_print_hex.c ./includes/ft_print_int.c \
	./includes/ft_print_other.c ./includes/ft_print_percent.c \
	./includes/ft_print_ptr.c ./includes/ft_print_str.c \
	./includes/ft_print_unsigned_int.c ./includes/ft_print_utils.c \
	./includes/ft_print_char.c

OBJS = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	cd libft && $(MAKE) bonus
	cp libft/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)
	echo libftprintf.a compiled

%.o:%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) clean -C ./libft
	echo object files deleted

fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C ./libft
	echo libftprintf.a deleted

re: fclean all

.PHONY: all clean fclean re bonus
