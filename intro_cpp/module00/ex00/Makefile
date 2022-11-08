NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

CLR = c++

FLAGS = -std=c++98 -Werror -Wextra -Wall

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLR) $(FLAGS) $^ -o $(NAME)

%.o: %.cpp Makefile
	@printf "Compiling source files... %-100s\r" $@ 
	@$(CLR) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean: clean
	@rm -rf a.out $(NAME)

re: fclean all
