NAME = phone_book 

SRC = main.cpp PhoneBook.cpp Contact.cpp

OBJ = $(SRC:.cpp=.o)

CLR = c++

FLAGS = -std=c++98 -Werror -Wextra -Wall -I.

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CLR) $(FLAGS) $^ -o $(NAME)
	@printf "Compiling source files %-20s\n" "... done ⚡️⚡️⚡️" 

%.o: %.cpp Makefile PhoneBook.hpp Contact.hhp book.hpp
	@printf "Compiling source files... %-20s\r" $@ 
	@$(CLR) $(FLAGS) -c $< -o $@

clean:
	@rm -rf *.o
	@printf "objects files deleted\n" 

fclean: clean
	@rm -rf a.out $(NAME)
	@printf "binaries files deleted\n" 

re: fclean all
