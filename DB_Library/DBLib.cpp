#include "DBLib.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

DB::DB(void){}

DB::~DB(void){}

void DB::parse( std::string filepath )
{
	std::ifstream fs(filepath);
	if(!fs)
		return;
	if(reader.parse(fs,root))
	{
		for(int i=0;i<root["RGB Values"].size();i++)
			std::cout << root["RGB Values"][i]["color"].asString() << ":\t " << root["RGB Values"][i]["value"].asString() << std::endl;
	}
}

std::string DB::retrieve( std::string filepath, std::string key )
{
	std::ifstream fs(filepath);
	if(!fs)
		return "FileNotFound";
	if(reader.parse(fs,root))
	{
		for(int i=0;i<root["RGB Values"].size();i++)
		{
			if(key == root["RGB Values"][i]["color"].asString())
			{
				value = root["RGB Values"][i]["value"].asString();
				return value;
			}
		}
		return "KeyNotFound";
	}
	else
		return "ParseError";
}