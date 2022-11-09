# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 17:18:54 by fhiedi            #+#    #+#              #
#    Updated: 2022/03/22 18:54:01 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = printf.c get_info.c padding.c flags.c width_precision.c \
	  additional_func.c ./includes/char_utils.c ./includes/hex_utils.c ./includes/nbr_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)
	@echo libftprintf.a created

%.o: %.c ft_printf.h
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -rf $(OBJ)
	@echo object files deleted

fclean: clean
	@rm -rf a.out */a.out $(NAME)
	@echo *.a and binary files deleted

bonus: all


re: fclean all
