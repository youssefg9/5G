#include <fstream>
#include <chrono>
#include<iostream>
#include <iterator>
#include <cmath>
using namespace std;
#include "FrameGenerator.h"
#include "BinToHex.h"
#include "Preamble.h"
#include "DestAddress.h"
#include "SrcAddress.h"
#include "InterFrameGap.h"
#include "Payload.h"
#include "Crc.h"
#include "configFileReader.h"

FrameGenerator::FrameGenerator() {
	// TODO Auto-generated constructor stub

}

FrameGenerator::~FrameGenerator() {
	// TODO Auto-generated destructor stub
}



void FrameGenerator::generatorFunc(){
	////////////////////////////////////////////////////////////////////////////////////////////////////

	configFileReader textFileReader;
	vector<string> inputsFromTextFile;
	inputsFromTextFile=textFileReader.fileReader();
	string etherType=inputsFromTextFile.at(0);
	string crcGenPolynomial=inputsFromTextFile.at(1);
	string sourceAddress=inputsFromTextFile.at(2);
	string destinationAddress=inputsFromTextFile.at(3);
	//user chooses between only "RANDOM" and "ENTER",where "RANDOM" means that payload will be randomly put and "ENTER" means that users enters data manually.
	string payloadChoice=inputsFromTextFile.at(4);
	double frameSize=stod(inputsFromTextFile.at(5));
	double burstSize=stod(inputsFromTextFile.at(6));
	double streamPeriod=stod(inputsFromTextFile.at(7));
	double burstPeriod=stod(inputsFromTextFile.at(8));
	double lineRate=stod(inputsFromTextFile.at(9));
	double payloadTotalSize=stod(inputsFromTextFile.at(10));



	burstPeriod=burstPeriod*pow(10.0,-6);
	streamPeriod=streamPeriod*pow(10.0,-3);
	lineRate=lineRate*pow(10.0,9);
	lineRate=lineRate/8;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	Preamble preamble;
	BinToHex binToHex;
	//cout << "Preamble Hex = " <<preamble.preambleFunction() <<endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////

	DestAddress destAddress;
	destAddress.inputDestAddress(destinationAddress);
	string destOut= destAddress.getDestAddress();

	////////////////////////////////////////////////////////////////////////////////////////////////////
	SrcAddress srcAddress;
	srcAddress.inputSrcAddress(sourceAddress);
	string srcOut= srcAddress.getSrcAddress();


	////////////////////////////////////////////////////////////////////////////////////////////////////
	Payload payload;
	string payloadInput;
	string payloadData;


	if(payloadChoice=="ENTER"){
		cout<<"enter payload data in binary :"<<endl;
		cin>>payloadInput;
	}
	bool dataRemainingWhileStreamEnded=false;
	string totalEthernetTransmission;
	int iteration=0;

	double streamCapacity=lineRate*streamPeriod;
	double differenceBetweenTransmittedAndActual=streamCapacity-payloadTotalSize; //actual-transmitted

	double burstCapacity=lineRate*burstPeriod;

	////////////////////////////Inter-Frame Gap////////////////////////////////////////////////////////////////////////
	InterFrameGap IFG;
	string ifg;
	int ifgPad;

	double frameDuration=frameSize/lineRate;

	//double actualBurstPeriod=burstPeriod*maxFrameSize*burstSize;
	double sizeRemainingFromBurstPeriod;
	double sizeRemainingFromStreamPeriod;
	string ethernetFrameFromPreambleTillCrc;
	string ethernetFrameFromPreambleTillIFG;


	if(frameSize*burstSize>burstCapacity){
		double timeRemainingFromBurstPeriod=(frameDuration*burstSize)-burstPeriod;
		sizeRemainingFromBurstPeriod=timeRemainingFromBurstPeriod*lineRate;
	}


	double sizeOfTransmission;
	ofstream myfile;
	myfile.open ("Out.txt");

	//to check the size of data needed to be transmitted vs the capacity of the channel
	if(payloadTotalSize<=streamCapacity){
		sizeOfTransmission=payloadTotalSize;
		//differenceBetweenTransmittedAndActual=streamCapacity-sizeOfTotalRandomBytesToBeTransmitted;
	}

	if(payloadTotalSize>streamCapacity){
		sizeRemainingFromStreamPeriod=payloadTotalSize-streamCapacity;
		sizeOfTransmission=streamCapacity;
		//differenceBetweenTransmittedAndActual=streamCapacity-sizeOfTotalRandomBytesToBeTransmitted;
	}


	////////////////////////////////////////////////////////////////////////////////////////////////////
	while(sizeOfTransmission>0){
		////////////////////////////////////////////////////////////////////////////////////////////////////
		payloadData=payload.payLoadData(payloadChoice,payloadTotalSize, payloadInput);
		////////////////////////////////////////////////////////////////////////////////////////////////////
		Crc crc;
		string crcPart;
		string ethernetFrameWithoutCrc=preamble.preambleFunction()+destOut+srcOut+payloadData;
		crcPart=crc.encodeData(ethernetFrameWithoutCrc, crcGenPolynomial);

		ethernetFrameFromPreambleTillCrc=preamble.preambleFunction()+destOut+srcOut+payloadData+crcPart;
		int frameLen=ethernetFrameFromPreambleTillCrc.size();
		string frameLength= to_string(frameLen);
		myfile << ethernetFrameFromPreambleTillCrc;


		////////////////timing part for frame-burst-stream periods///////////////////////


		//case 1
		if(frameSize*burstSize<=burstCapacity && (differenceBetweenTransmittedAndActual>=0)){
			if((frameLen%32)!=0){
				ifgPad=frameLen%32;
			}
			ifg=IFG.IfgFunction(32,ifgPad);

			//ethernetFrameFromPreambleTillIFG=ethernetFrameFromPreambleTillCrc+ifg;
			myfile << ifg;
		}

		//case 2
		else if(frameSize*burstSize>burstCapacity &&(differenceBetweenTransmittedAndActual>=0)){
			if((frameLen%32)!=0){
				ifgPad=frameLen%32;
			}
			ifg=IFG.IfgFunction(32,ifgPad);

			////////////////////////////////////////////////////////////////////////////////////////////////////
			string burstExtraIfgs=IFG.IfgFunction(sizeRemainingFromBurstPeriod, 0);
			//ethernetFrameFromPreambleTillIFG=ethernetFrameFromPreambleTillCrc+ifg+burstExtraIfgs;
			myfile << ifg+burstExtraIfgs;

		}
		//case 3
		else if(frameSize*burstSize<=burstCapacity &&(differenceBetweenTransmittedAndActual<0)){
			if((frameLen%32)!=0){
				ifgPad=frameLen%32;
			}
			ifg=IFG.IfgFunction(32,ifgPad);
			myfile << ifg;
			dataRemainingWhileStreamEnded=true;

		}
		//case 4
		else if(frameSize*burstSize>burstCapacity &&(differenceBetweenTransmittedAndActual<0)){
			if((frameLen%32)!=0){
				ifgPad=frameLen%32;
			}
			ifg=IFG.IfgFunction(32,ifgPad);
			////////////////////////////////////////////////////////////////////////////////////////////////////
			string burstExtraIfgs=IFG.IfgFunction(sizeRemainingFromBurstPeriod, 0);
			myfile << ifg+burstExtraIfgs;
			dataRemainingWhileStreamEnded=true;

		}



		sizeOfTransmission=sizeOfTransmission-frameSize;
		iteration++;

		if(dataRemainingWhileStreamEnded==true && sizeOfTransmission<=0){
			string streamExtraIfgs=IFG.IfgFunction(sizeRemainingFromStreamPeriod, 0);
			myfile <<endl<<streamExtraIfgs;

		}

		myfile << endl;
	}
	////////////////////////////////////////////////////////////////////////////////////////////////////

	myfile.close();

}
