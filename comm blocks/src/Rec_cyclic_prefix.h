#include<iostream>
#include <vector>
using namespace std;
#ifndef REC_CYCLIC_PREFIX_H_
#define REC_CYCLIC_PREFIX_H_


class Rec_cyclic_prefix
{

public:
    vector<string> InvCpFunc(vector<string> input,int cpLength);
    Rec_cyclic_prefix();
   ~Rec_cyclic_prefix();
};



#endif /* REC_CYCLIC_PREFIX_H_ */
