#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <random>
#include <bitset>         // std::bitset
using namespace std; //use functions in its scope without writing this prefix
#include "Awgn.h"
#include "Modulator.h"



Awgn::Awgn()  //constructor
{

}

Awgn::~Awgn() //destructor
{

}

//the AWGN function takes input the modulator class which contains real and imaginary parts if the IQ samples to pass in the AWGN channel and get affected by the noise

double Awgn::squaredSum(vector<double> input)
{
	vector<double> squaredSumOut;
	double temp;
	double squared;
	double accumaltiveSum;
	for(int i=0;i<input.size();i++){
		temp=input.at(i);
		//cout<<"__before squaring__"<<temp<<endl;
		squared=sqrt(pow(temp,2.0));
		squaredSumOut.push_back(squared);
	}
	for(int i=0;i<squaredSumOut.size();i++){
			accumaltiveSum=accumaltiveSum+squaredSumOut.at(i);
		}
	return accumaltiveSum;
}

vector<double> Awgn::gaussianRndVectorGenerator(double size){
	vector<double> squaredSumOut;
	default_random_engine generator(time(0));;
	double gaussianRN;
	for(int i=0;i<size;i++){
	normal_distribution<double> dist(0.0, 1.0);
	gaussianRN= dist(generator);
	squaredSumOut.push_back(gaussianRN);
	}
	return squaredSumOut;
}



vector<double> Awgn::noisySignal(vector<double> inputSignal,double SNR){
	// normal_distribution
	int sigLength = inputSignal.size();
	vector<double> outputNoisy;
	vector<double> scaledNoisy;
	vector<double> awgnNoise=gaussianRndVectorGenerator(inputSignal.size());
	double inputSignalSquaredSum=squaredSum(inputSignal); //squared sum of input signal
	double noiseSignalSquaredSum=squaredSum(awgnNoise); //squared sum of noisy signal

	double pwrSig = inputSignalSquaredSum/sigLength; // signal power
	double pwrNoise = noiseSignalSquaredSum/sigLength; // noise power

	double scaleFactor = (pwrSig/pwrNoise)/SNR; //find scale factor

	for(int i=0;i<inputSignal.size();i++){
		scaledNoisy.push_back(awgnNoise.at(i)*scaleFactor);
	}

	for(int i=0;i<inputSignal.size();i++){
		if (SNR != 0){
			outputNoisy.push_back(scaledNoisy.at(i)+ awgnNoise.at(i)); // add noise
		}
		else{
			outputNoisy.push_back(awgnNoise.at(i)); //pure noise only
		}
	}
return outputNoisy;
}




/*
double Awgn::rand_gen() {
   // return a uniformly distributed random value
   return ( (double)(rand()) + 1. )/( (double)(RAND_MAX) + 1. );
}

double Awgn::normalRandom() {
   // return a normally distributed random value
   double v1=rand_gen();
   double v2=rand_gen();
   return cos(2*3.14*v2)*sqrt(-2.*log(v1));
}

double Awgn::gaussianGenerator(int numSamples,double mean ,double stdDeviation){
	//mean=0 and std deviation=1
	 double sigma =stdDeviation;
	 double Mi = mean;
	 double x;
	   for(int i=0;i<numSamples;i++) {
		   x = normalRandom()*sigma+Mi;
	   }
	  return x;
}

/*vector<string> vector<string> AwgnFunc(vector<string> channelInput,int numSamples, double mean , double stdDeviation){

double rndNum= gaussianGenerator(numSamples,mean,stdDeviation);


}*/











