# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/25 14:38:43 by fhiedi            #+#    #+#              #
#    Updated: 2022/06/26 16:33:19 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = so_long.c \
	  src/utl_solong/map_processing.c \
	  src/utl_solong/map_processing2.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

PATH_LIBFT = src/libft/
PATH_PRINTF = src/printf/

PREREQUISITE_SOLONG = so_long.h \
					  Makefile \
					  src/libft/libft.a \
			   		  src/printf/libftprintf.a

PREREQUISITE_LIBFT = src/libft/libft_basic/libft.h \
					 src/libft/gnl/get_next_line.h \
					 src/libft/Makefile \

PREREQUISITE_PRINTF = src/printf/ft_printf.h \
					 src/printf/Makefile

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\r"
#	@$(CC) $(MLXFLAGS) $< -o $@
	@${CC} ${CFLAGS} $^ -L. $(PATH_LIBFT)libft.a $(PATH_PRINTF)libftprintf.a -o $@
	@echo "$(GREEN)Ready To Go\nLet's Play!"

%.o: %.c Makefile $(PREREQUISITE_SOLONG)
	@printf "$(YELLOW)$(CURSIVE)---Compiling so_long objects 🚀 %-43.43s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

src/libft/libft.a: $(PREREQUISITE_LIBFT)
	@make -C $(PATH_LIBFT)

src/printf/libftprintf.a: $(PREREQUISITE_PRINTF)
	@make -C $(PATH_PRINTF)

clean:
	@make clean -C $(PATH_LIBFT)
	@make clean -C $(PATH_PRINTF)
	@echo "\n$(RED)Cleaning so_long objects..."
	@rm -rf $(OBJ)
	@echo "$(GRAY)$(CURSIVE)---so_long objects are cleaned!🧹\n"

fclean: clean
	@make fclean -C $(PATH_LIBFT)
	@make fclean -C $(PATH_PRINTF)
	@echo "$(RED)Cleaning $(NAME)"
	@rm -rf $(NAME) a.out .*.swp
	@echo "$(GRAY)$(CURSIVE)---so_long staff & related libraries are completely destroyed!💀\n"

re: fclean all

.PHONY: all clean fclean
