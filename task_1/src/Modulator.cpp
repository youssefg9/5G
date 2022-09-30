#include <complex>
#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Modulator.h"

vector<double> real;
vector<double> img;

Modulator::Modulator()  //constructor
{

}

Modulator::~Modulator() //destructor
{

}



vector<string> Modulator::modulatorFunc(string inputStream,int modOrder){

string bits="";
vector<string> outputModulator;
string temp1;
string temp2;
for(int i=0;i< inputStream.size()-1; i=i+2){
		temp1=inputStream.at(i);
		temp2=inputStream.at(i+1);
		bits=temp1.append(temp2);

	//according to gray code sequence
	if(bits.compare("00")==0){
		outputModulator.push_back("0.707+0.707i");
		real.push_back(0.707);
		img.push_back(0.707);
	}
	if(bits.compare("01")==0){
		outputModulator.push_back("0.707-0.707i");
		real.push_back(0.707);
		img.push_back(-0.707);
	}
	if(bits.compare("11")==0){
		outputModulator.push_back("-0.707+0.707");
		real.push_back(-0.707);
		img.push_back(0.707);
	}
	if(bits.compare("10")==0){
		outputModulator.push_back("-0.707-0.707i");
		real.push_back(-0.707);
		img.push_back(-0.707);
	}

	bits.clear();
	temp1.clear();
	temp2.clear();
	}

return outputModulator;
}


/*
char bits="";
vector<string> outputModulator;

for(int i=0;i< symbolTotal.size()/modOrder; i++){
for(int j=0;j< modOrder ; j++){
	bits=symbolTotal.at(j)+symbolTotal.at(j+1);
}


}
//according to gray code sequence
switch (bits) {
case "00":
outputModulator.push_back("0.707+0.707i");
break;
case "01":
  outputModulator.push_back("0.707-0.707i");
break;
case "11":
  outputModulator.push_back("-0.707+0.707");
break;
case "10":
  outputModulator.push_back("-0.707-0.707i");
break;
}
*/

