# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 17:18:54 by fhiedi            #+#    #+#              #
#    Updated: 2022/07/03 15:25:19 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = printf.c get_info.c padding.c flags.c width_precision.c \
	  additional_func.c ./includes/char_utils.c ./includes/hex_utils.c \
	  ./includes/nbr_utils.c
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\r"
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN)%s is assembled!✅" $(NAME)
	@echo "\n"

%.o: %.c ft_printf.h Makefile
	@printf "$(YELLOW)$(CURSIVE)---Compiling printf objects 🚀 %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "$(RED)Cleaning printf objects..."
	@rm -rf $(OBJ)
	@echo "$(GRAY)$(CURSIVE)---printf objects are cleaned!\n"

fclean:
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf $(NAME) a.out
	@echo "$(GRAY)$(CURSIVE)---printf staff is completely cleaned!\n"

re: fclean all

.PHONY: all clean fclean
