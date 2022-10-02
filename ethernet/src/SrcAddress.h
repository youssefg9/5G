#include<iostream>
#include <iterator>
using namespace std;
#ifndef SRCADDRESS_H_
#define SRCADDRESS_H_

class SrcAddress {
private:
	string srcAddress;
public:

	void inputSrcAddress(string input);
	SrcAddress();
	virtual ~SrcAddress();

	const string& getSrcAddress() const {
		return srcAddress;
	}

	void setSrcAddress(const string &srcAddress) {
		this->srcAddress = srcAddress;
	}
};

#endif /* SRCADDRESS_H_ */
