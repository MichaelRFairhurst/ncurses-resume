#include <ncurses.h>
#include <string>
#include "SubSection.h"

using namespace std;

void SubSection::setSuperSection(SuperSectionInterface* section) {
	supersection = section;
}

void SubSection::setHeader(string header) {
	this->header = header;
};

void SubSection::print(ResumeLinePrinterInterface& printer) {
	printer.printLine(header, highlighted ? A_BOLD | A_UNDERLINE : A_NORMAL);
}

void SubSection::highlightOn() {
	highlighted = true;
}

void SubSection::highlightOff() {
	highlighted = false;
}
