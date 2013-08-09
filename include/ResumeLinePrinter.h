#ifndef HEADER_RESUMELINEPRINTER
#define HEADER_RESUMELINEPRINTER

using namespace std;

#include "ResumeLinePrinterInterface.h"

class ResumeLinePrinter : public ResumeLinePrinterInterface {

	public:
		void printLine(string text, long unsigned int attributes);

};

#endif
