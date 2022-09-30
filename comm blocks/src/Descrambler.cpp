#include<iostream>
#include <vector>
using namespace std; //use functions in its scope without writing this prefix
#include "Descrambler.h"


Descrambler::Descrambler()  //constructor
{

}

Descrambler::~Descrambler() //destructor
{

}

vector<string> Descrambler::DescramblerFunc(vector<string> inStream){
string bit="";
string symbol="";
vector<string> deScrambledData;
for(int i=0; i < inStream.size() ;i++){
	for(int j=0; j <inStream.size() ;j++){
	bit=inStream.at(j).at(i);
	symbol =symbol + bit;
    }
	deScrambledData.push_back(symbol);
	symbol.clear();
	bit.clear();
}
return deScrambledData;
}
