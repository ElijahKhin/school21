#include "Contact.hpp"

#ifndef PHONE_BOOK_HPP 
# define PHONE_BOOK_HPP

class PhoneBook {
private:
	Contact contacts[8];

public:
	int contact_index;
	int filled_contacts;
	void add(int index_of_contact);
	std::string format_str(std::string str);
	void describe(int index_of_contact);
	void get_index(std::string index, int filled_contacts);
	int find_contact(std::string index, int filled_contacts);
};

#endif
