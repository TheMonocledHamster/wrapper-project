#pragma once
#ifndef LIBTEST_INCLUDED
	#define LIBTEST_INCLUDED
	#include <iostream>
	#include <string>
	#include <jsoncpp/json/reader.h>
	#include <jsoncpp/json/writer.h>
	#include <jsoncpp/json/value.h>

	template <typename T>
	class DB
	{
		Json::Value value;
		Json::Reader reader;
		Json::Writer writer;
	public:
		DB ( std::string );
		T retrieve(/*Fill in parameters*/);
		void append(/*Fill in parameters*/);
		~DB (void);
	};

#endif