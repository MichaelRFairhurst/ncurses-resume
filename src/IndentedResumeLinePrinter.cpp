#include "IndentedResumeLinePrinter.h"

IndentedResumeLinePrinter::IndentedResumeLinePrinter(ResumeLinePrinterInterface* indentationof) {
	this->indentationof = indentationof;
};

void IndentedResumeLinePrinter::printLine(string text, long unsigned int attributes) {
	indentationof->printLine("+-      " + text, attributes);
};
