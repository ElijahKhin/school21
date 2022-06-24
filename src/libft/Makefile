# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhiedi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/24 16:42:17 by fhiedi            #+#    #+#              #
#    Updated: 2022/06/24 18:55:22 by fhiedi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIBFT = ft_isalpha.c ft_isalpha.c ft_isalnum.c \
	   	ft_atoi.c lb_strlen.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memcpy.c ft_memcmp.c ft_memchr.c \
		ft_memset.c ft_bzero.c ft_strnstr.c ft_memmove.c \
		ft_strdup.c ft_strncmp.c ft_calloc.c ft_strchr.c \
		ft_strrchr.c ft_strlcat.c ft_strlcpy.c ft_tolower.c \
		ft_toupper.c ft_substr.c ft_strjoin.c ft_strtrim.c \
		ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstmap.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
		ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	   	ft_lstiter.c
GNL = 	get_next_line.c get_next_line_utils.c

SRC = $(addprefix libft_basic/, ${LIBFT})\
	  $(addprefix gnl/, ${GNL})
OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[32m
YELLOW = \033[0;33m
RED = \033[0;31m
GRAY = \033[2;37m
CURSIVE = \033[3m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\r"
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN)%s (incl. GNL) is assembled!✅" $(NAME)
	@echo "\n"

%.o: %.c libft_basic/libft.h gnl/get_next_line.h Makefile
	@printf "$(YELLOW)$(CURSIVE)---Compiling libft objects 🚀 %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\n$(RED)Cleaning libft objects..."
	@rm -rf $(OBJ)
	@echo "$(GRAY)$(CURSIVE)---libft objects are cleaned!🧹\n"

fclean: clean
	@echo "$(RED)Cleaning $(NAME) & executable..."
	@rm -rf $(NAME) a.out
	@echo "$(GRAY)$(CURSIVE)---libft staff is completely cleaned!💀\n"

re: fclean all

.PHONY: all clean fclean

