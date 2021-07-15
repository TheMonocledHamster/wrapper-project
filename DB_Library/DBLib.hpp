#pragma once
#ifndef LIBTEST_INCLUDED
	#define LIBTEST_INCLUDED
	#include <iostream>
	#include <string>
	#include <jsoncpp/json/json.h>
	#include <jsoncpp/json/value.h>

	class DB
	{
		std::string value;
		Json::Value root;
		Json::Reader reader;
	public:
		DB(void);
		void parse( std::string filepath );
		std::string retrieve( std::string filepath, std::string key );
		~DB(void);
	};

#endif