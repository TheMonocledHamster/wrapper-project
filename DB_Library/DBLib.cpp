#include "DBLib.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

DB::DB(void){}

DB::~DB(void){}

std::string DB::retrieve(std::string filepath)
{
	std::ifstream fs(filepath);
	if(!fs)
		return "FileNotFound";
	if(reader.parse(fs,root))
	{
		value = "";
		for(int i=0;i<root["Root"].size();i++)
			value = value + root["Root"][i]["color"].asString() + "\t\t" + root["Root"][i]["value"].asString() + "\n";
		return value;
	}
	else 
		return "ParseError";
}

std::string DB::retrieve(std::string filepath, std::string key)
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