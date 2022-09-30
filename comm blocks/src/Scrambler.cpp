#include<iostream>
#include <vector>
using namespace std; //use functions in its scope without writing this prefix
#include "Scrambler.h"

Scrambler::Scrambler()  //constructor
{

}

Scrambler::~Scrambler() //destructor
{

}

vector<string> Scrambler::scramblerFunc(vector<string> inStream){
string bit="";
string symbol="";
vector<string> scrambledData;
for(int i=0; i < inStream.size() ;i++){
	for(int j=0; j <inStream.size() ;j++){
	bit=inStream.at(j).at(i);
	symbol =symbol + bit;
    }
	scrambledData.push_back(symbol);
	symbol.clear();
	bit.clear();
}
return scrambledData;
}


/*
vector<string> Scrambler::scramblerFunc(string inStream,int rate){
	//will output a vector of strings where each element is the matrix transpose (scrambled version) of the input data
	vector<string> scrambledData;
	string temp="";
	int counter =0;
	for(int i=0; i < inStream.length() ;i++){
		 if(counter==rate){
			 scrambledData.push_back(temp);
			 temp="";
			 counter=0;
		 }
		counter++;
		string bit = string(1, inStream.at(i));
		temp=temp+bit;
	 }
	scrambledData.push_back(temp);
return scrambledData;
};

*/
