# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/13 18:03:29 by fhiedi            #+#    #+#              #
#    Updated: 2022/01/18 17:40:06 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isalpha.c \
	  ft_isalnum.c \
	  ft_atoi.c \
	  ft_strlen.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_memcpy.c \
	  ft_memcmp.c \
	  ft_memchr.c \
	  ft_memset.c \
	  ft_bzero.c \
	  ft_strnstr.c \
	  ft_memmove.c \
	  ft_strdup.c \
	  ft_strncmp.c \
	  ft_calloc.c \
	  ft_strchr.c \
	  ft_strrchr.c \
	  ft_strlcat.c \
	  ft_strlcpy.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_substr.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_split.c \
	  ft_itoa.c \
	  ft_strmapi.c \
	  ft_striteri.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_putendl_fd.c \
	  ft_putnbr_fd.c
		

OBJ = $(SRC:.c=.o)

FLAGS = -c -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
