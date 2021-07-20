#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "DBLib.hpp"

using namespace std;

template <class B>
class Base
{
protected:
	vector<B> get_colors;
	DB data;
	public:
	Base() {}
};

template <class D>
class Derived : public Base<D>{
public:
	Derived() {}
	string key;
	vector<D> get_colors;
	DB data;
	void read();
	void getColor();
};

template <class D>
void Derived<D>::read()
{
	cout << "Enter 'done' once all the colors are entered" << endl;
	int i=0;
	while (true)
	{
		cout << "color "<<i++<<" : ";
		cin >> key;
		if (key == "done")
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
						 << "Color: " <<"\033[1;" << color << "m" << *it << "\033[0m" << endl
						 << "Hex code: "
						 << "\033[1;" << color << "m" << out << "\033[0m" << endl;
				}
				else
				{
					cout<<endl << "Key does not exist" << endl;
				}
			}
			else
			{
				cout <<endl<< "Couldn't parse datafile, check formatting" << endl;
			}
		}
		else
		{
			cout <<endl<< "File does not exist" << endl;
		}
	}
}

int main()
{
	Derived<string> derived;
	derived.read();
	derived.getColor();
	return 0;
}