#ifndef HEADER_RESUMELINEPRINTERINTERFACE
#define HEADER_RESUMELINEPRINTERINTERFACE

#include <string>

using namespace std;

class ResumeLinePrinterInterface {

	public:
		virtual void printLine(string text, long unsigned int attributes)=0;

};

#endif
