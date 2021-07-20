#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <typeinfo>
#include "DBLib.hpp"

using namespace std;

template <class B>
class Base
{
protected:
	vector<B> get_colors;
	DB data;

public:
	Base(void){}
	virtual void entry()
	{	cout << "Greetings" 
			 << endl;	}
	~Base(void){}
};

template <class D>
class Derived : public Base<D>
{
public:
	Derived(void){}
	string key;
	vector<D> get_colors;
	DB data;
	void read();
	void getColor();
	void getAllColors();
	~Derived(void){}
};

template <class D>
void Derived<D>::read()
{
	cout << "Enter 'end' once all the colors are entered" << endl;
	int i = 0;
	while (true)
	{
		cout << "Color " << i++ << ": ";
		cin >> key;
		if (key == "end")
			break;
		get_colors.push_back(key);
	}
}

template <class D>
void Derived<D>::getColor()
{
	for (auto it = get_colors.begin(); it != get_colors.end(); ++it)
	{
		string color = data.retrieve("ANSIcolorcodes.json", *it);
		if (color == "FileNotFound" || color == "ParseError" || color == "KeyNotFound")
			color = "0";
		string out = data.retrieve("SixBitColors.json", *it);
		if (out != "FileNotFound")
		{
			if (out != "ParseError")
			{
				if (out != "KeyNotFound")
				{
					cout << endl
						 << "Color: "
						 << "\033[1;" << color << "m" << *it << "\033[0m" 
						 << endl
						 << "Hex code: "
						 << "\033[1;" << color << "m" << out << "\033[0m" 
						 << endl;
				}
				else
				{
					cerr << endl 
						 << "Color: "
						 << *it
						 << endl
						 << "Key does not exist" 
						 << endl;
				}
			}
			else
			{
				cerr << "Couldn't parse datafile, check formatting" << endl;
			}
		}
		else
		{
			cerr << "File does not exist / Insufficient permissions" << endl;
		}
	}
}

template <class D>
void Derived<D>::getAllColors()
{
	string out = data.retrieve("SixBitColors.json");
	if (out != "FileNotFound")
	{
		if (out != "ParseError")
		{
			cout << out;
		}
		else
		{
			cerr << "Couldn't parse datafile, check formatting" << endl;
		}
	}
	else
	{
		cerr << "File does not exist / Insufficient permissions" << endl;
	}
}

int main()
{
	try
	{
		Base<string> *base = new Derived<string>;
		Derived<string> *derived = dynamic_cast<Derived<string> *>(base);
		if(derived)
		{
			derived->entry();
			char fetch_type;
			cout << endl
					<< "Enter A to specify the color"
					<< endl
					<< "Enter B to fetch all color codes"
					<< endl;
			cin >> fetch_type;
			cout << endl;
			if(fetch_type==65)
			{
				derived->read();
				derived->getColor();
			}
			else if(fetch_type==66)
			{
				derived->getAllColors();
			}
		}
		else
		{
			throw derived;
		}
	}
		
	catch(const char* e)
	{
		cerr << "Casting failed" << '\n';
	}

	return 0;
}