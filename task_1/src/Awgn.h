#include<iostream>
#include <vector>
#include "Modulator.h"
#ifndef AWGN_H_
#define AWGN_H_

class Awgn{

	public:
    vector<double> gaussianRndVectorGenerator(double size);
	double squaredSum(vector<double> input);
	vector<double> noisySignal(vector<double> inputSignal,double SNR);

		Awgn();
	   ~Awgn();

};



#endif /* AWGN_H_ */
