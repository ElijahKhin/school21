#include "Contact.hpp"

std::string Contact::fill_field(std::string request, std::string field) {
	field.erase(0, field.length());
	while (field.length() == 0) {
		std::cout << request;
		std::getline(std::cin, field);
	}
	return field;
}


void Contact::display() {
	std::cout << "\nIndex: " << index << std::endl;
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Num.: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}


void Contact::fill_contact_fields(int index_of_contact) {
	index = std::to_string(index_of_contact);
	first_name = fill_field("Enter first name: ", first_name);
	last_name = fill_field("Enter last name: ", last_name);
	nickname = fill_field("Enter nickname: ", nickname);
	phone_number = fill_field("Enter phone number: ", phone_number);
	darkest_secret = fill_field("Enter darkest secret: ", darkest_secret);
	std::cout << std::endl;
}
