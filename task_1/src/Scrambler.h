#include<iostream>
#include <vector>
#ifndef SCRAMBLER_H_
#define SCRAMBLER_H_
using namespace std;

class Scrambler
{

public:
    vector<string> scramblerFunc(vector <string> inputToScrambler); //takes input as a serial string or we can add an overloading function taking a matrix (easier)
    Scrambler();
   ~Scrambler();
};

#endif

