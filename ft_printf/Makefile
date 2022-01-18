NAME = libftprintf.a
SRCS = ft_printf.c ft_putstr.c ft_printf_hex.c ft_putnbrs.c
OBJS = $(SRCS:.c=.o)
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
	$(RM) $(NAME) a.out

re:	clean all

.PHONY:	all clean fclean re
