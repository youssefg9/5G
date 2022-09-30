#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Encoder.h"


Encoder::Encoder()  //constructor
{

}

Encoder::~Encoder() //destructor
{

}

string Encoder::encoderFunc(string symbol , int rate){
    string encodedString;

    for(int i=0; i < symbol.length() ;i++){
        encodedString= encodedString + string(rate, symbol[i]);
    }
    if((encodedString.size()%2)!=0){
    	encodedString.push_back('0');
    }

    return encodedString;
};

