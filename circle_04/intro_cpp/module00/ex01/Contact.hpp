#include <iostream>
#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {
public:
	std::string index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	
	void fill_contact_fields(int index_of_contact);
	std::string fill_field(std::string request, std::string field); 
	void display();

private:
	std::string darkest_secret;
	
};

#endif
