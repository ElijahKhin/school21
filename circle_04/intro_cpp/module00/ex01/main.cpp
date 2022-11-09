#include "book.hpp"

std::string get_command() {
	std::string command;
	std::cout << "\nPlease, select command from the " 
		<< "following list: [ADD, SEARCH, EXIT]\nYour command: ";
	std::getline(std::cin, command);
	return (command);
}

int main(void) {
	PhoneBook book;	
	std::string command;
	std::string chosen_index;
	
	book.contact_index = 0;
	book.filled_contacts = 0;
	command = get_command();
	while (command != "EXIT") {
		if (command == "ADD")
			book.add(book.contact_index);
		if (command == "SEARCH") {
			book.describe(book.filled_contacts);
			if (book.filled_contacts > 0) {
				
				std::cout << "\nSelect index: ";
				std::getline(std::cin, chosen_index);
				book.get_index(chosen_index, book.filled_contacts);
			}
			else
				std::cout << "Phone book is empty." 
				   << "You should add some contacts." << std::endl;
		}
		command = get_command();
	};
	return 0;
};
