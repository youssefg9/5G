#include<bits/stdc++.h>
#include<iostream>
#include <iterator>
using namespace std;
#include "Crc.h"

Crc::Crc() {
	// TODO Auto-generated constructor stub

}

Crc::~Crc() {
	// TODO Auto-generated destructor stub
}


string payload;
string  rem;

// Returns XOR of 'a' and 'b'
// (both of same length)
string xor1(string a, string b)
{

	// Initialize result
	string result = "";

	int n = b.length();

	// Traverse all bits, if bits are
	// same, then XOR is 0, else 1
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

// Performs Modulo-2 division
string mod2div(string divident, string divisor)
{

	// Number of bits to be XORed at a time.
	int pick = divisor.length();

	// Slicing the divident to appropriate
	// length for particular step
	string tmp = divident.substr(0, pick);

	int n = divident.length();

	while (pick < n)
	{
		if (tmp[0] == '1')

			// Replace the divident by the result
			// of XOR and pull 1 bit down
			tmp = xor1(divisor, tmp) + divident[pick];
		else

			// If leftmost bit is '0'.
			// If the leftmost bit of the dividend (or the
			// part used in each step) is 0, the step cannot
			// use the regular divisor; we need to use an
			// all-0s divisor.
			tmp = xor1(std::string(pick, '0'), tmp) +
				divident[pick];

		// Increment pick to move further
		pick += 1;
	}

	// For the last n bits, we have to carry it out
	// normally as increased value of pick will cause
	// Index Out of Bounds.
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);

	return tmp;
}

// Function used at the sender side to encode
// data by appending remainder of modular division
// at the end of data.
string Crc::encodeData(string data, string key)
{
	int l_key = key.length();

	// Appends n-1 zeroes at end of data
	string appended_data = (data +
							std::string(
								l_key - 1, '0'));

	string remainder = mod2div(appended_data, key);

	// Append remainder in the original data
	payload=data;
	rem=remainder;
	string codeword = remainder;
	//cout << "Remainder : "
		//<< remainder << "\n";
return codeword;
}
