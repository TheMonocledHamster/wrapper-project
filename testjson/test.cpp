#include <iostream>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream file("3BitColour.json");
    Json::Value actualJson;
    Json::Reader reader;
    reader.parse(file, actualJson);
    cout<<"Complete json data : "<<actualJson<<endl;
    cout << endl
         << endl
         << "Accessing particular element" << endl
         << "First one :\n"
         << actualJson[0] << endl;
    cout << "Color : " << actualJson[0]["color"] << endl;
    system("./colorOutput.sh white");
    system("./colorOutput.sh red");
    system("./colorOutput.sh green");
    system("./colorOutput.sh yellow");
    system("./colorOutput.sh blue");
    system("./colorOutput.sh magenta");
    system("./colorOutput.sh cyan");
    system("./colorOutput.sh black");
    return 0;
}