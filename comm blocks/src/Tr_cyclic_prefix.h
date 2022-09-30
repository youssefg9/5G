#include<iostream>
#include <vector>
#ifndef TR_CYCLIC_PREFIX_H_
#define TR_CYCLIC_PREFIX_H_
using namespace std;

class Tr_cyclic_prefix
{

public:
    vector<string> cpFunc(vector<string> input,int cpLength);
    Tr_cyclic_prefix();
    ~Tr_cyclic_prefix();
};


#endif /* TR_CYCLIC_PREFIX_H_ */
