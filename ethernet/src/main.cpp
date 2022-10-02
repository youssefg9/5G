#include <iterator>
using namespace std;
#include "BinToHex.h"
#include "Preamble.h"
#include "DestAddress.h"
#include "SrcAddress.h"
#include "InterFrameGap.h"
#include "Payload.h"
#include "FrameGenerator.h"
#include "Crc.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>



int main() {


	FrameGenerator frameGenerator;
	string generatedStream;
    frameGenerator.generatorFunc();

	return 0;

	}

