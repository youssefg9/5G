#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Demapper.h"


Demapper::Demapper()  //constructor
{

}

Demapper::~Demapper() //destructor
{

}

string Demapper::demapperFunc(vector<string> inStream,int mapperDim){
	string demappedString;

	for(int i=0;i<inStream.size();i++){
		demappedString.append(inStream.at(i));
	}
	return demappedString;

};

