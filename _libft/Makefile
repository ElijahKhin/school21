# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:48:57 by fhiedi            #+#    #+#              #
#    Updated: 2022/07/11 14:48:16 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

OBJ_FOLDER = obj

SRC = ft_isalpha.c \

OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)

CC = clang
CFLAGS = -Wall -Wextra -Werror -fsanitize=address

REQS = libft.h Makefile

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_FOLDER):
	mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c $(REQS)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -rf a.out *.a .DS_Store .*.swp */.*.swp

re: fclean all
