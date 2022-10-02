
#ifndef CONFIGFILEREADER_H_
#define CONFIGFILEREADER_H_
#include <string>
#include <vector>
using namespace std;

class configFileReader {
public:
	vector<string> fileReader();
	configFileReader();
	virtual ~configFileReader();
};

#endif /* CONFIGFILEREADER_H_ */
