#include<iostream>
#include <iterator>
using namespace std;
#ifndef CRC_H_
#define CRC_H_

class Crc {

public:
	string paylaod;
	string rem;
	string encodeData(string data, string key);
	Crc();
	virtual ~Crc();
};

#endif /* CRC_H_ */
