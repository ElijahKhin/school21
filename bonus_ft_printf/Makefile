# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 17:18:54 by fhiedi            #+#    #+#              #
#    Updated: 2022/02/08 16:51:12 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRC = 
SRC_BON = 
		
OBJ = $(SRC:.c=.o)

OBJ_BON = $(SRC_BON:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h
	gcc -c -Wall -Wextra -Werror $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf a.out $(NAME)

bonus: $(OBJ) $(OBJ_BON)
	ar rcs $(NAME) $^

re: clean all bonus
