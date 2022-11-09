# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scoach <scoach@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/22 16:49:30 by chasimir          #+#    #+#              #
#    Updated: 2022/03/22 18:12:34 by scoach           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CUB = \
	draw_and_search_dz.c\
	init_struct.c\
	keyhook.c\
	move.c\
	open_txt.c\
	raycast.c\
	rotate.c\

GNL = \
	get_next_line_utils.c\
	get_next_line.c\

PARS =  \
	check_map.c\
	parse_params.c\
	parse_rgb.c\

UTILS = \
	utils.c\
	free.c\
	str_arr_utils.c\
	str_arr_utils2.c\
	pixel.c\

SRC =	$(addprefix srcs/gnl/, ${GNL})\
		$(addprefix srcs/parser/, ${PARS})\
		$(addprefix srcs/utils/, ${UTILS})\
		$(addprefix srcs/cub/, ${CUB})\
		srcs/main.c\

PATH_LIB = srcs/libft/

NAME_LIB = libft.a

LIB = srcs/libft/libft.a

HDRS = srcs/cub.h

OBJ = $(SRC:c=o)
DEP = $(OBJ:o=d)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -MMD

MLX_FLAGS = -L mlx -l mlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n"
	@make -C mlx 2>/dev/null
	@make -C $(PATH_LIB)
	@echo "\033[0;32mCompiling cub3d...✅"
	@$(CC) $(FLAGS) $(MLX_FLAGS) -I mlx $(OBJ) $(LIB) -I. -o $(NAME)
	@echo "\n\033[0;33m🥂Done and ready!🥂"

%.o: %.c
	@printf "\033[0;33mGenerating cub3d objects 🔜 %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[0;31mCleaning libft..."
	@make clean -C $(PATH_LIB)
	@echo "\033[0;31mCleaning mlx..."
	@make clean -C mlx
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ) $(DEP)
	@echo "\n\033[0;32mCleaning process is competed!"

fclean: clean
	@echo "\033[0;31m🧹Cleaning libft🧹..."
	@make fclean -C $(PATH_LIB)
	@echo "\n✂️Deleting executable..."
	@rm -f $(NAME)
	@echo "\n\033[0;32mF_cleaning process is competed!"

re:		fclean all

reclean: re
	$(RM) $(OBJ) $(DEP)
	make clean -C $(PATH_LIB)

.PHONY: all clean fclean

include $(wildcard $(DEP))
