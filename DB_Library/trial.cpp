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
	Base()
	{
	}
	virtual void fun()
	{
		cout << endl
			 << "Cast Success" << endl;
	}
	virtual void fun(bool status)
	{
		cout << endl
			 << "Cast Failed" << endl;
	}
};

template <class D>
class Derived : public Base<D>
{
public:
	Derived()
	{
	}
	string key;
	vector<D> get_colors;
	DB data;
	void read();
	void getColor();
	void getAllColors();
};

template <class D>
void Derived<D>::read()
{
	cout << "Enter 'end' once all the colors are entered" << endl;
	int i = 0;
	while (true)
	{
		cout << "color " << i++ << " : ";
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
						 << "\033[1;" << color << "m" << *it << "\033[0m" << endl
						 << "Hex code: "
						 << "\033[1;" << color << "m" << out << "\033[0m" << endl;
				}
				else
				{
					cout << endl
						 << "Key does not exist" << endl;
				}
			}
			else
			{
				cout << endl
					 << "Couldn't parse datafile, check formatting" << endl;
			}
		}
		else
		{
			cout << endl
				 << "File does not exist" << endl;
		}
	}
}

template <class D>
void Derived<D>::getAllColors()
{
	cout << data.retrieve("SixBitColors.json");
}

int main()
{
	Base<string> *base = new Derived<string>;
	Derived<string> *derived = dynamic_cast<Derived<string> *>(base);
	if (derived)
	{
		char fetch_type;
		derived->fun();
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
		derived->fun(false);
	}
	return 0;
}