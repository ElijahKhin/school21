#include "PhoneBook.hpp"

int PhoneBook::find_contact(std::string index, int filled_contacts) {
	int i;
	
	i = 0;
	while (i < filled_contacts) {
		if (std::strcmp(contacts[i].index.c_str(), index.c_str()) == 0) {
			contacts[i].display();
			return 1;
		}
		i++;
	}
	return 0;
}


void PhoneBook::get_index (std::string index, int filled_contacts) {
	while (!find_contact(index, filled_contacts)) {
		std::cout << "Wrong index! Select new one: ";
		std::getline(std::cin, index);
	}
}


std::string PhoneBook::format_str(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return std::string(10 - str.length(), ' ') + str;
}


void past_header() {
	std::cout 
		<< "\n     Index" << "|"
		<< "First name" << "|"
		<< " Last name" << "|"
		<< "  Nickname" << "|"
		<< "Phone Num." << std::endl;
}


void PhoneBook::describe(int index_of_contact) {
	int index = -1;
	
	past_header();
	while (++index < index_of_contact) {
		std::cout 
			<< format_str(contacts[index].index) << "|" 
			<< format_str(contacts[index].first_name) << "|"
			<< format_str(contacts[index].last_name) << "|"
			<< format_str(contacts[index].nickname) << "|"
			<< format_str(contacts[index].phone_number) << std::endl;
	}
}

void PhoneBook::add(int index_of_contact) {
	contacts[index_of_contact].fill_contact_fields(index_of_contact);
	if (filled_contacts != 8)
		filled_contacts++;
	if (contact_index== 7)
		contact_index= 0;
	else
		contact_index++;
}
