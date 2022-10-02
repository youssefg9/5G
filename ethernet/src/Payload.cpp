#include<iostream>
#include <iterator>
using namespace std;
#include "Payload.h"
#include "BinToHex.h"

Payload::Payload() {
	// TODO Auto-generated constructor stub

}

Payload::~Payload() {
	// TODO Auto-generated destructor stub
}

int findRandom()
		{
			int num = ((int)rand() % 2);
			return num;
		}

string generateBinaryString(int N)
{
	rand();
	string S = "";
	for (int i = 0; i < N; i++) {

		int x = findRandom();
		S += to_string(x);
	}
	return S;
}

string Payload::payLoadData(string choice,int randomBitsLength,string payloadInput){
	string payloadOut;
	BinToHex binToHex;
	if(choice=="RANDOM"){
		payloadOut=binToHex.convertBinToHex(generateBinaryString(randomBitsLength*4));
	}
	else if(choice=="ENTER"){
		payloadOut= binToHex.convertBinToHex(payloadInput);
	}

	return payloadOut;
}

