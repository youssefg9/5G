#include"BinToHex.h"
#include "InterFrameGap.h"

InterFrameGap::InterFrameGap() {
	// TODO Auto-generated constructor stub

}

InterFrameGap::~InterFrameGap() {
	// TODO Auto-generated destructor stub
}

string InterFrameGap::IfgFunction(double ifgLength,double ifgPadding){
	string ifg;
	string oneByte;
	BinToHex binToHex;
	oneByte=binToHex.convertBinToHex("00000111");
	for(int i=0;i<ifgLength;i++){
		ifg=ifg+oneByte;
	}
	if(ifgPadding!=0){
		for(int i=0;i<ifgPadding;i++){
				ifg=ifg+oneByte;
			}
	}
	return ifg;
}
