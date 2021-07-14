#pragma once
#ifndef LIBTEST_INCLUDED
	#define LIBTEST_INCLUDED
	#include <string>
    #include<iostream>
    #include <iostream>
    #include <jsoncpp/json/value.h>
    #include <jsoncpp/json/json.h>

    template<class T>
	class JsonClass
	{
        T content;
        Json::Value data;
        Json::Reader reader;
	public:
		JsonClass (std::string jsonString);
        T read(std::string fileName);
		~JsonClass(void);
	};

#endif