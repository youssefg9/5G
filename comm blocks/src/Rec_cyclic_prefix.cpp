//we have total 64 bits (8 symbols),re invert the 1st symbol to be at the last position

#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Rec_cyclic_prefix.h"

Rec_cyclic_prefix::Rec_cyclic_prefix()  //constructor
{

}

Rec_cyclic_prefix::~Rec_cyclic_prefix() //destructor
{

}


vector<string> Rec_cyclic_prefix::InvCpFunc(vector<string> input,int cpLength){ //cpLength=8

	string cpTemp="";
	vector<string> outputCp;
	cpTemp=input.at(cpLength);
	input.insert(input.begin(), cpTemp);
	input.pop_back();

	outputCp=input;
	return outputCp;
}
