#include<iostream>
#include <vector>
#ifndef MAPPER_H
#define MAPPER_H
using namespace std;

class Mapper
{

public:
     void setOutStream(string inputStream);
     vector<string> getOutStream();
     vector<string> mapperFunc(string serialStream,int mapperDim);


    Mapper();
    ~Mapper();
};

#endif /* MAPPER_H_ */
