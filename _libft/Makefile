# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/11 13:48:57 by fhiedi            #+#    #+#              #
#    Updated: 2022/07/13 19:22:30 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_isdigit.c \
	  ft_isalnum.c \
	  ft_isascii.c \
	  ft_isprint.c \
	  ft_strlen.c \
	  ft_memset.c

OBJ_FOLDER = obj
OBJ = $(SRC:%.c=$(OBJ_FOLDER)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

REQS = libft.h Makefile

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FOLDER) $(OBJ)
	ar rcs $(NAME) $(OBJ_FOLDER)/*

$(OBJ_FOLDER):
	mkdir $(OBJ_FOLDER)

$(OBJ_FOLDER)/%.o: %.c $(REQS)
	$(CC) -c $(CFLAGS) $< -o $@


clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -rf a.out *.a* .DS_Store .*.swp */.*.swp

re: fclean all
