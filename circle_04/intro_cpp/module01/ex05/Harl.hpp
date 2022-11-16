#include <iostream>
#include <string>

#ifndef HARL_HPP
# define HARL_HPP

class Harl
{
private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

	std::string lvl_arr[4];
	void (Harl::* funcs[5]) (void);

public:
	Harl();
	~Harl();
	void complain( std::string level );
};

#endif
