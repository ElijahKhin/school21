NAME = libftprintf.a
SRCS = ft_printf.c ft_printf_pointer.c ft_printf_hex.c ft_putnbrs.c
OBJS = ${patsubst %.c, %.o, ${SRCS}}
CC = gcc
FLAG = -Wall -Wextra -Werror
RM = rm -f
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(FLAG) -c $< -o $@

clean:
	$(RM) *.o
 
fclean:	clean
	$(RM) $(NAME)

re:	clean all

.PHONY:	all clean fclean re
