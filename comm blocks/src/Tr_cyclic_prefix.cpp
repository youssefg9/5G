//we have total 64 bits (8 symbols), take the last symbol and put it in the beginning of the data.

#include<iostream>
#include <vector> //arraylist in java
using namespace std; //use functions in its scope without writing this prefix
#include "Tr_cyclic_prefix.h"

Tr_cyclic_prefix::Tr_cyclic_prefix()  //constructor
{

}

Tr_cyclic_prefix::~Tr_cyclic_prefix() //destructor
{

}


vector<string> Tr_cyclic_prefix::cpFunc(vector<string> input,int cpLength){ //cpLength=8

string cpTemp="";
vector<string> outputCp;
cpTemp=input.at(cpLength);
input.insert(input.begin(), cpTemp);

outputCp=input;
return outputCp;
}


