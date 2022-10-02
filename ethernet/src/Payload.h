#include<iostream>
#include <iterator>
using namespace std;
#ifndef PAYLOAD_H_
#define PAYLOAD_H_

class Payload {
public:
	string payLoadData(string choice,int randomLength,string payloadInput);
	Payload();
	virtual ~Payload();
};

#endif /* PAYLOAD_H_ */
