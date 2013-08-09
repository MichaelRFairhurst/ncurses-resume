#include "ResumeLinePrinter.h"

#include <cstdio>
#include <ncurses.h>

using namespace std;

void ResumeLinePrinter::printLine(string contents, unsigned long int attributes) {
	attrset(A_NORMAL);
	printw("        ");
	attrset(attributes);
	contents.insert(contents.end(), COLS - 16 - contents.size(), ' ');
	printw((contents + "\n\n").c_str());
}
