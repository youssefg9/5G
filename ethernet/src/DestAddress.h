#include<iostream>
#include <iterator>
using namespace std;
#ifndef DESTADDRESS_H_
#define DESTADDRESS_H_

class DestAddress {
private:
	string destAddress;
public:

	void inputDestAddress(string input);
	DestAddress();
	virtual ~DestAddress();

	const string& getDestAddress() const {
		return destAddress;
	}

	void setDestAddress(const string &destAddress) {
		this->destAddress = destAddress;
	}
};

#endif /* DESTADDRESS_H_ */
