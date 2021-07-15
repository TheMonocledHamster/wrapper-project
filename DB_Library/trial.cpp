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
    // ifstream f("SixBitColours.json");
    // Json::Reader r;
    // Json::Value v;
    // r.parse(f,v);
    // cout<<v<<endl;
    //data.parse("SixBitColours.json");
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