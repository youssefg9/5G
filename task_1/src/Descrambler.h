#include<iostream>
#include <vector>

#ifndef DESCRAMBLER_H_
#define DESCRAMBLER_H_

class Descrambler
{
public:
    vector<string> DescramblerFunc(vector<string> inputToDescrambler); //takes input as a serial string or we can add an overloading function taking a matrix (easier)

    Descrambler();
   ~Descrambler();
};



#endif /* DESCRAMBLER_H_ */
