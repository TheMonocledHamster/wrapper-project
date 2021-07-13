#pragma once
#ifndef LIBTEST_INCLUDED
	#define LIBTEST_INCLUDED
	#include <string>

	class Print
	{
	public:
		Print ( std::string );
		~Print(void);
	};

#endif


// https://stackoverflow.com/questions/1653958/why-are-ifndef-and-define-used-in-c-header-files
// https://en.wikipedia.org/wiki/Pragma_once