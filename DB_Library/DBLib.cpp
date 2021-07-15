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
	if(reader.parse(filepath,root))
	{
		for(int i=0;i<root["RGB Values"].size();i++)
			std::cout << root["RGB Values"][i]["color"] << ":\t " << root["RGB Values"][i]["value"] << std::endl;
	}
}

std::string DB::retrieve( std::string filepath, std::string key )
{
	std::ifstream fs(filepath);
	if(!fs)
		return "FileNotFound";
	if(reader.parse(filepath,root))
	{
		for(int i=0;i<root["RGB Values"].size();i++)
		{
			value = root["RGB Values"][i][key].asString();
			if(value != "")
				return value;
		}
		return "KeyNotFound";
	}
	else
		return "ParseError";
}