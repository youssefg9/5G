#include <iterator>
using namespace std;
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include "configFileReader.h"

configFileReader::configFileReader() {
	// TODO Auto-generated constructor stub

}

configFileReader::~configFileReader() {
	// TODO Auto-generated destructor stub
}

vector<string> outputNamesFromConfigFile;
vector<string> outputValuesFromConfigFile;
//inputs (string ethernetType,string crcGenPolynomial,double burstPeriod,double burstSize,double streamPeriod,double maxFrameSize,double lineRate)

vector<string> configFileReader::fileReader(){

	ifstream cFile ("input_config");
	if (cFile.is_open())
	{
		string line;
		while(getline(cFile, line)){
			line.erase(std::remove(line.begin(), line.end(), ' '), line.end());
			if(line[0] == '#' || line.empty())
				continue;
			auto delimiterPos = line.find("=");
			auto name = line.substr(0, delimiterPos);
			outputNamesFromConfigFile.push_back(name);
			auto value = line.substr(delimiterPos +1);
			outputValuesFromConfigFile.push_back(value);
		}
	}
	else {
		std::cerr << "Couldn't open config file for reading.\n";
	}


	return outputValuesFromConfigFile;

}
