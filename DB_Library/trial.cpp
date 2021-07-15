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
    string out = data.retrieve("SixBitColours.json",key);
    if(out!="FileNotFound"){
        if(out!="ParseError"){
            if(out!="KeyNotFound"){
                cout << "Hex code: " << "\x1B[31m"<< out << "\033[0m\t\t" << endl;
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