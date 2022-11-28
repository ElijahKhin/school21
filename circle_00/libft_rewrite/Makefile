# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:06:48 by fhiedi            #+#    #+#              #
#    Updated: 2022/11/25 16:39:07 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = \
	ft_isalpha.c ft_isdigit.c ft_toupper.c \
	ft_tolower.c ft_isascii.c ft_isalnum.c \
	ft_isprint.c ft_strlen.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_bzero.c \
	ft_memset.c ft_memcpy.c ft_memchr.c \
	ft_memcmp.c ft_memmove.c ft_strnstr.c


OBJ_FOLDER = obj
OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)


CMPL = gcc
FLAGS = -Wall -Wextra -Werror -I.


GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m

.PHONY: all clean fclean re


all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@echo "\n"
	@ar rc $@ obj/*	
	@ranlib $(NAME)
	@printf "$(GREEN)%s is successfully assembled! 🥂" $(NAME)
	@echo "\n"

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c libft.h Makefile
	@$(CMPL) -c $(FLAGS) $< -o $@
	@printf "$(CURSIVE)Compiling source files 🚀...  $(YELLOW)%-13s ---> $(NO_COLOR)%17.33s ✅\r" $< $@

clean:
	@echo "$(RED)Cleaning libft objects..."
	@rm -rf obj 
	@echo "$(GRAY)$(CURSIVE)---libft objects are cleaned!\n"

fclean: clean
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf *.a a.out .*.swp .DS_Store $(NAME) units
	@echo "$(GRAY)$(CURSIVE)---libft staff is completely cleaned!\n"

re: fclean all

leaks:
	@gcc units.c -L. $(NAME) -o units
	@leaks --atExit -- ./units


