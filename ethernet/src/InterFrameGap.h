#include<iostream>
#include <iterator>
using namespace std;

#ifndef INTERFRAMEGAP_H_
#define INTERFRAMEGAP_H_

class InterFrameGap {

public:
	string IfgFunction(double ifgLength,double ifgPadding);
	InterFrameGap();
	virtual ~InterFrameGap();
};

#endif /* INTERFRAMEGAP_H_ */
