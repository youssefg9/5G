#include "BinToHex.h"
#include "Preamble.h"

Preamble::Preamble() {
	// TODO Auto-generated constructor stub

}

Preamble::~Preamble() {
	// TODO Auto-generated destructor stub
}

string Preamble::preambleFunction(){
    string preambleString;
    string pre;
    string sfd;


    pre="10101010101010101010101010101010101010101010101010101010";
    sfd="10101011";
    BinToHex binToHex;
    preambleString= binToHex.convertBinToHex(pre+sfd);


    return preambleString;
};
