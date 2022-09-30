#ifndef ENCODER_H
#define ENCODER_H
using namespace std;

class Encoder
{
private:
    string outputEnc;
public:
    string encoderFunc(string symbol,int rate);

    Encoder();
    ~Encoder();
};

#endif
