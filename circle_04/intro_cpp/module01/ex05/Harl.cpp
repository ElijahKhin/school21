#include "Harl.hpp"

Harl::Harl()
{
	lvl_arr[0] = "DEBUG";
	lvl_arr[1] = "INFO";
	lvl_arr[2] = "WARNING";
	lvl_arr[3] = "ERROR";

	funcs[0] = &Harl::debug;
	funcs[1] = &Harl::info;
	funcs[2] = &Harl::warning;
	funcs[3] = &Harl::error;
	funcs[4] = NULL;
}

Harl::~Harl()
{
}

void Harl::debug( void ){
	std::cout<<"[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-\
	\nketchup burger. I really do!\n";
};

void Harl::info( void ){
	std::cout<<"[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn't put enough\
	\nbacon in my burger! If you did, I wouldn't be asking for more!\n";
};

void Harl::warning( void ){
	std::cout<<"[ WARNING ]\nI think I deserve to have some extra bacon for free. I've been coming for years\
	\nwhereas you started working here since last month.\n";
};

void Harl::error( void ){
	std::cout<<"[ ERROR ]\nThis is unacceptable! I want to speak to the manager now.\n";
};

void Harl::complain( std::string level ){

	for (int i=0; i < 4; ++i){
		if (level == lvl_arr[i]){
			(this->*funcs[i])();
			return ;
		}
	}
	std::cout<<"[ Probably complaining about insignificant problems ]\n";
}
