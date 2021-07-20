#pragma once
#ifndef LIBTEST_INCLUDED
	#define LIBTEST_INCLUDED
	#include <iostream>
	#include <string>
	#include <json/json.h>

	class DB
	{
		std::string value;
		Json::Value root;
		Json::Reader reader;
	public:
		DB(void);
		std::string retrieve(std::string filepath);
		std::string retrieve(std::string filepath, std::string key);
		~DB(void);
	};

#endif