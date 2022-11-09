# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chasimir <chasimir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 16:15:59 by scoach            #+#    #+#              #
#    Updated: 2022/03/21 18:19:26 by chasimir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= ./

SRCS	=	${SRC}ft_memset.c		${SRC}ft_bzero.c		${SRC}ft_memcpy.c \
			${SRC}ft_memccpy.c		${SRC}ft_memmove.c		${SRC}ft_memchr.c \
			${SRC}ft_memcmp.c		${SRC}ft_strlen.c		${SRC}ft_strlcpy.c \
			${SRC}ft_strlcat.c		${SRC}ft_strchr.c		${SRC}ft_strrchr.c \
			${SRC}ft_strnstr.c		${SRC}ft_strncmp.c		${SRC}ft_atoi.c \
			${SRC}ft_isalpha.c		${SRC}ft_isdigit.c		${SRC}ft_isalnum.c \
			${SRC}ft_isascii.c		${SRC}ft_isprint.c		${SRC}ft_toupper.c \
			${SRC}ft_tolower.c		${SRC}ft_calloc.c		${SRC}ft_strdup.c \
			${SRC}ft_substr.c		${SRC}ft_strjoin.c		${SRC}ft_strtrim.c \
			${SRC}ft_split.c		${SRC}ft_itoa.c			${SRC}ft_strmapi.c \
			${SRC}ft_putchar_fd.c	${SRC}ft_putstr_fd.c	${SRC}ft_putnbr_fd.c \
			${SRC}ft_putendl_fd.c

B_SRCS	=	${SRC}ft_lstnew.c		${SRC}ft_lstlast.c		${SRC}ft_lstclear.c \
			${SRC}ft_lstadd_front.c	${SRC}ft_lstadd_back.c	${SRC}ft_lstiter.c \
			${SRC}ft_lstsize.c		${SRC}ft_lstdelone.c	${SRC}ft_lstmap.c

OBJS	= $(SRCS:c=o)
DEP		= $(OBJS:o=d)
B_OBJS	= $(B_SRCS:c=o)

NAME	= libft.a

HEADER	= libft.h

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror -MMD

AR	= ar rcs

all:		${NAME}


${NAME}:	${OBJS}
	@echo "\n"
	@echo "\033[0;32mCompiling libf...✅"
	@${AR} ${NAME} ${OBJS}

%.o: %.c ${HEADER}
	@printf "\033[0;33mGenerating libft objects 🔜 %-33.33s\r" $@
	@gcc ${CFLAGS} -c $< -o $@

bonus:

	@make OBJS="${B_OBJS}" all

clean:
	@${RM} ${OBJS} ${B_OBJS} ${D_FILES} $(DEP)

fclean:	clean
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re bonus

include $(wildcard $(DEP))
