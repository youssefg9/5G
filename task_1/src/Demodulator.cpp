#include <complex>
#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Demodulator.h"


Demodulator::Demodulator()  //constructor
{

}

Demodulator::~Demodulator() //destructor
{

}

vector<string> Demodulator::demodulatorFunc(vector<string> inputStream,int modOrder){

string bits="";
vector<string> outputDemodulator;
for(int i=0;i< inputStream.size(); i++){
		bits=inputStream.at(i);

	//according to gray code sequence
	if(bits.compare("0.707+0.707i")==0){
		outputDemodulator.push_back("00");

	}
	if(bits.compare("0.707-0.707i")==0){
		outputDemodulator.push_back("01");

	}
	if(bits.compare("-0.707+0.707")==0){
		outputDemodulator.push_back("11");

	}
	if(bits.compare("-0.707-0.707i")==0){
		outputDemodulator.push_back("10");

	}

	bits.clear();
	}

return outputDemodulator;
}




