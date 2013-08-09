#ifndef HEADER_INDENTEDRESUMELINEPRINTER
#define HEADER_INDENTEDRESUMELINEPRINTER

#include "ResumeLinePrinterInterface.h"

class IndentedResumeLinePrinter : public ResumeLinePrinterInterface {

	public:
		IndentedResumeLinePrinter(ResumeLinePrinterInterface* indentationof);
		void printLine(string text, long unsigned int attributes);

	private:
		ResumeLinePrinterInterface* indentationof = NULL;
		IndentedResumeLinePrinter() {};

};

#endif
