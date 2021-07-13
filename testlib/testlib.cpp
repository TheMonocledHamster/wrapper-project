#include "testlib.hpp"
#include <iostream>
#include <string>

Print::Print( std::string s )
{
	std::cout << s << std::endl;
}

Print::~Print( void ){}