#include<iostream>
#include <vector> //arraylist in java
#include <string>
using namespace std; //use functions in its scope without writing this prefix
#include "Mapper.h"


Mapper::Mapper()  //constructor
{

}

Mapper::~Mapper() //destructor
{

}


vector<string> Mapper::mapperFunc(string inStream,int mapperDim){
	vector<string> outStream;
	string temp="";
	int counter =0;
	for(int i=0; i < inStream.length() ;i++){
		if(counter==mapperDim){
			outStream.push_back(temp);
			temp.clear();
			counter=0;
		}
		counter++;
		string bit = string(1, inStream.at(i));
		temp=temp+bit;
	}
	outStream.push_back(temp);

	return outStream;
};

