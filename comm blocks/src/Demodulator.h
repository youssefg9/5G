#include <string>
#ifndef DEMODULATOR_H_
#define DEMODULATOR_H_



class Demodulator
{

public:
    vector<string> demodulatorFunc(vector<string> modulatedSymbol,int modOrder);

    Demodulator();
    ~Demodulator();
};

#endif


