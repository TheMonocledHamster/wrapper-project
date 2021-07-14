#include "finalLib.hpp"
#include <iostream>
#include <string>
#include <jsoncpp/json/value.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <string>
using namespace std;

template<class T>
JsonClass<T>::JsonClass(std::string){
    cout<<"JSON"<<endl;
}

template<class T>
T JsonClass<T>::read(string fileName){
    ifstream file(fileName);
    reader.parse(file,data);
    return data;
}

template<class T>
JsonClass<T>::~JsonClass( void ){}