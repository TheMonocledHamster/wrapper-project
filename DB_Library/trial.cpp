#include <iostream>
#include <string>
#include<fstream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/value.h>
#include "DBLib.hpp"

using namespace std;

int main()
{
    DB data;
    string key;
    cout << "Colour name: ";
    cin >> key;
    string color = data.retrieve("ANSIcolorcodes.json",key);
    if (color=="FileNotFound" || color=="ParseError" || color=="KeyNotFound")
        color = "0";
    string out = data.retrieve("SixBitColours.json",key);
    if(out!="FileNotFound"){
        if(out!="ParseError"){
            if(out!="KeyNotFound"){
                cout << "Hex code: " << "\033[" << (string)color << ";5m"<< out << "\033[0m" << endl;
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

    return 0;
}