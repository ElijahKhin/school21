# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 17:18:54 by fhiedi            #+#    #+#              #
#    Updated: 2022/02/12 19:35:53 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = printf.c print_arg.c ./includes/ft_print_char.c ./includes/ft_print_str.c \
	  ./includes/ft_print_nbr.c ./includes/ft_print_hex.c ./includes/check_flags.c \
	  ./includes/get_width.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@cd libft && make all bonus
	@echo libft.a created
	@cp libft/libft.a $(NAME)
	@ar -rcs $(NAME) $(OBJ)
	@echo libftprintf.a created

%.o: %.c ft_printf.h
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -rf $(OBJ)
	@cd libft && make clean
	@echo object files deleted

fclean: clean
	@rm -rf a.out */a.out $(NAME)
	@cd libft && make fclean
	@echo *.a and binary files deleted


re: fclean all
