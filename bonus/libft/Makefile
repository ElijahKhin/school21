# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 17:18:54 by fhiedi            #+#    #+#              #
#    Updated: 2022/02/09 17:38:13 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = 	ft_isalpha.c ft_isalpha.c ft_isalnum.c \
	    ft_atoi.c ft_strlen.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memcmp.c ft_memchr.c \
		ft_memset.c ft_bzero.c ft_strnstr.c ft_memmove.c \
		ft_strdup.c ft_strncmp.c ft_calloc.c ft_strchr.c \
		ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_tolower.c \
		ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putstr.c

SRC_BON = ft_lstmap.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
		  ft_lstiter.c
		
OBJ = $(SRC:.c=.o)

OBJ_BON = $(SRC_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf a.out $(NAME)

bonus: $(OBJ_BON)
	@ar rcs $(NAME) $<

re: clean all bonus

