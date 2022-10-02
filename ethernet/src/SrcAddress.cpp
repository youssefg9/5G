#include"BinToHex.h"
#include "DestAddress.h"
#include "SrcAddress.h"

SrcAddress::SrcAddress() {
	// TODO Auto-generated constructor stub

}

SrcAddress::~SrcAddress() {
	// TODO Auto-generated destructor stub
}

void SrcAddress::inputSrcAddress(string input){
	string output;
    output= input;
    setSrcAddress(output);
}
