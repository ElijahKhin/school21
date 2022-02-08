SRCS	=	printf.c \
			printf_print_format_mod.c \
			printf_get_size.c \
			printf_check_input.c \
			printf_print_modifier.c \
			printf_utils.c
OBJS	= ${SRCS:.c=.o}
NAME	= libftprintf.a
HEADER	= ft_printf.h
CC	= gcc
RM	= rm -f
FLAGS	= -Wall -Werror -Wextra
%.o:	%.c $(HEADER)
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)

all:	$(NAME)

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:	fclean all

bonus: all

.PHONY:	all clean fclean re bonus