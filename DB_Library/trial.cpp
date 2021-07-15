#include <iostream>
#include <string>
#include "DBLib.hpp"

using namespace std;

int main()
{
    DB data;
    string out = data.retrieve("SixBitColours.json","red");
    if(out!="FileNotFound"){
        if(out!="ParseError"){
            if(out!="KeyNotFound"){
                cout << "Hex code: " << out << endl;
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