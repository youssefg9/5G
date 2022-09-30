#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Decode.h"


Decode::Decode()  //constructor
{

}

Decode::~Decode() //destructor
{

}


string Decode::decoderFunc(string symbol , int rate){
    string decodedString;

    for(int i=0; i < symbol.length() ;i=i+rate){
    	char symb=symbol[i];
    	decodedString.push_back(symb);
        }

    return decodedString;
};



