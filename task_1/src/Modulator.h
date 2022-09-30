
#include<iostream>
#include <vector>
#ifndef MODULATOR_H_
#define MODULATOR_H_
using namespace std;

class Modulator
{

public:
	vector<double> real;
	vector<double> img;
    vector<string> modulatorFunc(string modInput,int modOrder);
    Modulator();
   ~Modulator();
};



#endif /* MODULATOR_H_ */
