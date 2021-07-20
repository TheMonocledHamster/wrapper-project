#include <iostream>
#include <string>
#include<fstream>
#include <vector>
#include "DBLib.hpp"

using namespace std;

int main()
{
	vector<string> get_colors{};
	DB data;
	string key;
	cout << "Enter 'done' once all the colors are entered" << endl;
	while(true)
	{
		cout << "color name: ";
		cin >> key;
		if(key=="done")
			break;
		get_colors.push_back(key);
	}
	
	for(auto it = get_colors.begin(); it != get_colors.end(); ++it)
	{
	string color = data.retrieve("ANSIcolorcodes.json",*it);
	if (color=="FileNotFound" || color=="ParseError" || color=="KeyNotFound")
		color = "0";
	string out = data.retrieve("SixBitColors.json",*it);
	if(out!="FileNotFound"){
		if(out!="ParseError"){
			if(out!="KeyNotFound"){
				cout<<endl << "Color: " << *it << endl << "Hex code: " << "\033[1;" << color << "m" << out << "\033[0m" << endl;
			}
			else{
				cout << "Key does not exist" << endl;
			}
		}
		else{
			cout << "Couldn't parse datafile, check formatting" << endl;
		}
	}
	else{
		cout << "File does not exist" << endl;
	}
	}
	return 0;
}
