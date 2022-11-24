# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 10:06:48 by fhiedi            #+#    #+#              #
#    Updated: 2022/11/24 17:48:26 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a


SRC = \
	ft_isalpha.c ft_isdigit.c


OBJ_FOLDER = obj
OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)


CMPL = gcc
FLAGS = -Wall -Wextra -Werror -I.


GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m


.PHONY: all clean fclean


all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	@echo "\r"
	@ar rc $@ obj/*	
	@ranlib $(NAME)
	@printf "$(GREEN)%s is assembled!✅" $(NAME)
	@echo "\n"

$(OBJ_FOLDER):
	@mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c libft.h Makefile
	@$(CMPL) -c $(FLAGS) $< -o $@
	@printf "$(YELLOW)$(CURSIVE)Compiling source files 🚀 %-33.33s\r" $@

clean:
	@echo "$(RED)Cleaning libft objects..."
	@rm -rf obj 
	@echo "$(GRAY)$(CURSIVE)---libft objects are cleaned!\n"

fclean: clean
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf *.a a.out .*.swp .DS_Store $(NAME) units
	@echo "$(GRAY)$(CURSIVE)---libft staff is completely cleaned!\n"

leaks:
	@gcc units.c -L. $(NAME) -o units
	@leaks --atExit -- ./units


