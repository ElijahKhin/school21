# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:38:43 by fhiedi            #+#    #+#              #
#    Updated: 2022/07/10 15:45:19 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

SRC = src/clear_bonus.c \
	  src/init_bonus.c \
	  src/philo_simul_bonus.c \
	  src/utils_bonus.c \
	  philo_bonus.c

OBJ = $(SRC:.c=.o)

HEADER = philo_bonus.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m
NO_COLOR = \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\r"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(GRAY)--------------------------------------------------------------------------"
	@echo "$(GREEN)🔁                --- Eat, Sleep And Think! $(RED)[BONUS] $(GREEN)---                 🔁"
	@echo "$(GRAY)--------------------------------------------------------------------------"

%.o: %.c Makefile
	@printf "$(YELLOW)$(CURSIVE)---Compiling philosophers objects 🚀 %-43.43s\r" $@
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ): $(HEADER)

clean:
	@echo "$(RED)Cleaning philosophers objects..."
	@rm -rf $(OBJ)
	@echo "$(GRAY)$(CURSIVE)---philosophers objects are cleaned!\n"

fclean: clean
	@echo "$(RED)Cleaning $(NAME)"
	@rm -rf $(NAME) $(NAME_BONUS) a.out .*.swp
	@echo "$(GRAY)--------------------------------------------------------------------------"
	@echo "$(YELLOW)$(CURSIVE)☠️  --- philosophers staff is completely destroyed! --- ☠️ "
	@echo "$(GRAY)--------------------------------------------------------------------------\n"

re: fclean all

.PHONY: all clean fclean
