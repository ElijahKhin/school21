NAME = sed_is_for_losers 
SRC = main.cpp Replace.cpp
OBJ = $(SRC:.cpp=.o)

CLR = c++

FLAGS = -std=c++98 -Werror -Wextra -Wall -I.

.PHONY: all clean fclean re leaks

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLR) $(FLAGS) $^ -o $(NAME)
	@printf "Compiling source files %-30s\n" "... done ⚡️⚡️⚡️" 

%.o: %.cpp Makefile Replace.hpp sed.hpp
	@printf "Compiling source files... %-30s\r" $@ 
	@$(CLR) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o
	@printf "objects files deleted\n" 

fclean: clean
	@rm -rf a.out $(NAME) *.replace
	@printf "binaries files deleted\n" 

leaks:
	@leaks --atExit -- ./$(NAME) test Hello w

re: fclean all
