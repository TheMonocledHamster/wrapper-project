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
		for(int i=0;i<root["Root"].size();i++)
			std::cout << root["Root"][i]["color"].asString() << ":\t " << root["Root"][i]["value"].asString() << std::endl;
	}
}

std::string DB::retrieve( std::string filepath, std::string key )
{
	std::ifstream fs(filepath);
	if(!fs)
		return "FileNotFound";
	if(reader.parse(fs,root))
	{
		for(int i=0;i<root["Root"].size();i++)
		{
			if(key == root["Root"][i]["color"].asString())
			{
				value = root["Root"][i]["value"].asString();
				return value;
			}
		}
		return "KeyNotFound";
	}
	else
		return "ParseError";
}