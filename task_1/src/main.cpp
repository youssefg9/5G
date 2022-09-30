#include<iostream>
#include <iterator>
#include <random>

using namespace std;
#include <vector> //arraylist in java
#include <random>
#include "Encoder.h"
#include "Decode.h"
#include "Mapper.h"
#include"Scrambler.h"
#include"Modulator.h"
#include"Tr_cyclic_prefix.h"
#include"Rec_cyclic_prefix.h"
#include"Demapper.h"
#include"Descrambler.h"
#include"Demodulator.h"
#include "Awgn.h"


//we have ofdm sybmols 21 bits each and we define the following communication block functions
// 1) encoder/decoder (repetition encoding)
// 2) mapper/demapper (series to parallel inversion)
// 3) scrambler/descrambler (matrix transpose)
// 4) ifft/fft ()
// 5) QPSK modulator/demodulator (using switch cases)
// 6) Cyclic Prefix Adder/Remover CP length = 8 Samples
// 7) implement an AWGN Channel by adding noise to our samples input=(modulated data,SNR)

// we have taps , each tap has a gain and a delay


int main(){

//-----------Transmitter------------------------

//test inputs
string symbolStream="101010101111110000001";


Encoder	enc;
Decode dec;
Mapper map;
Scrambler scr;
Modulator mod;
Tr_cyclic_prefix cp;
Rec_cyclic_prefix invCp;
Demapper demap;
Descrambler deScr;
Demodulator demod;
Awgn awgn;


//encoder
cout<<"encoder OUTPUT"<<endl;
string testEncoder=enc.encoderFunc(symbolStream, 3);
cout<< testEncoder <<endl;


cout<< "---------------------------------------" <<endl;
//mapper
cout<<"mapper OUTPUT"<<endl;
vector<string> testMapper=map.mapperFunc(testEncoder,8);
for(int i; i<testMapper.size();i++){
	cout<< testMapper.at(i) <<endl;
}


cout<< "---------------------------------------" <<endl;
//scrambler
cout<<"scrambler OUTPUT"<<endl;

vector<string> testScrambler=scr.scramblerFunc(testMapper);

cout<< "size of scrambler vector= " <<testScrambler.size()<<endl;

for (int i= 0; i< testScrambler.size();i++) {
	cout<<testScrambler.at(i) <<endl;
}


cout<< "---------------------------------------" <<endl;
//QPSK only modulator (currently implementing a general purpose modulator)
cout<<"modulator OUTPUT according to gray code"<<endl;
vector<string> testMod=mod.modulatorFunc(testEncoder, 2);

cout<< "size of mod vector= " <<testMod.size()<<endl;
for (int i = 0; i < testMod.size(); i++) {
	cout<< testMod.at(i) <<endl;
}



cout<< "---------------------------------------" <<endl;
//cyclic prefix
cout<<"cp OUTPUT"<<endl;
vector<string> testCp= cp.cpFunc(testScrambler, 3);

cout<< "size of cp vector= " <<testCp.size()<<endl;
for (int i = 0; i < testCp.size(); i++) {
	cout<< testCp.at(i) <<endl;
}


//-----------Receiver------------------------


cout<< "---------------------------------------" <<endl;
//decoder

cout<<"decoder OUTPUT"<<endl;
string testDecoder=dec.decoderFunc("1111000011111111", 4);
cout<< testDecoder <<endl;


cout<< "---------------------------------------" <<endl;
//demapper

cout<<"demapper OUTPUT"<<endl;
string demapInput;
string testDemapper= demap.demapperFunc(testMapper, 4);
cout<<testDemapper<<endl;


cout<< "---------------------------------------" <<endl;
//descrambler
cout<<"descrambler OUTPUT"<<endl;
vector<string> testDescrambler= deScr.DescramblerFunc(testScrambler);
cout<< "size of descrambler vector= " <<testDescrambler.size()<<endl;
for (int i = 0; i < testDescrambler.size(); i++) {
	cout<< testDescrambler.at(i) <<endl;
}


cout<< "---------------------------------------" <<endl;
//demodulator
cout<<"demodulator OUTPUT"<<endl;

vector<string> testDemodulator= demod.demodulatorFunc(testMod, 2);
cout<< "size of demodulator vector= " <<testDemodulator.size()<<endl;
for (int i = 0; i < testDemodulator.size(); i++) {
	cout<< testDemodulator.at(i) <<endl;
}




cout<< "---------------------------------------" <<endl;
//inverse cyclic prefix
cout<<"inverse CP OUTPUT"<<endl;

vector<string> testInvCp = invCp.InvCpFunc(testCp, 3);
cout<< "size of inverse CP vector= " <<testInvCp.size()<<endl;
for (int i = 0; i < testInvCp.size(); i++) {
	cout<< testInvCp.at(i) <<endl;
}


//AWGN effect
//using normal dist to generate randomness

cout<< "---------------------------------------" <<endl;

cout<< "Awgn testing : real and imaginary parts of the iq samples are shown after passing by a noisy channel" <<endl;

//the AWGN function takes input the modulator class which contains real and imaginary parts if the IQ samples to pass in the AWGN channel and get affected by the noise

vector<double> outAwgnR;
vector<double> outAwgnI;

vector<double> testAwgnReal=mod.real;
vector<double> testAwgnImg=mod.img;
//input for the noisySignal function are Vector of IQ samples real/imaginary and SNR.
outAwgnR=awgn.noisySignal(testAwgnReal, 1);
outAwgnI=awgn.noisySignal(testAwgnImg, 50);

for(int i=0;i<outAwgnR.size();i++){
	cout<<"_real part before noise is: "<<testAwgnReal.at(i)<<endl;
	cout<<"_real part after noise is: "<<outAwgnR.at(i)<<endl;
	cout<<"Error = "<<abs(testAwgnReal.at(i)-outAwgnR.at(i))<<endl;
	cout<<"--------------------"<<endl;
}
cout<<"##########################################################"<<endl;
for(int i=0;i<outAwgnI.size();i++){
	cout<<"_imaginary part before noise is: "<<testAwgnImg.at(i)<<endl;
	cout<<"_imaginary part after noise is: "<<outAwgnI.at(i)<<endl;
	cout<<"Error = "<<abs(testAwgnImg.at(i)-outAwgnI.at(i))<<endl;
	cout<<"--------------------"<<endl;
}



return 0;

}






