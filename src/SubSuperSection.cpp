#include <algorithm>
#include "SubSuperSection.h"
#include "IndentedResumeLinePrinter.h"

void SubSuperSection::highlightOn() {
	SubSection::highlightOn();
	supersection->setPreSelect([&] () -> bool { // @TODO NEEDS TO BE VOID
		if(selected) select(); //defer to subsubsubsupersections
		else { selected = true; highlighted = false; }
		return true;
	});

	supersection->setPreDeselect([&] () -> bool {
		// Not selected, don't propagate signal
		if(!selected) return true;

		// Selected, and our hook says we're clear to deselect
		if(predeselect == NULL || predeselect())  {
			selected = false;
			highlighted = true;

			return false;
		}

		// tell our parent to do nothing, like we did
		return false;
	});

	supersection->setPreUp([&] () -> bool {
		if(selected) {
			up(); // scroll up, calling hooks recursively
			return false;
		}
		return true; // let container go up
	});

	supersection->setPreDown([&] () -> bool {
		if(selected) {
			down(); // scroll down, calling hooks recursively
			return false;
		}
		return true; // let container go down
	});
};

void SubSuperSection::highlightOff() {
	SubSection::highlightOff();
	supersection->setPreSelect(NULL);
	supersection->setPreDeselect(NULL);
	supersection->setPreDown(NULL);
	supersection->setPreUp(NULL);
};

void SubSuperSection::print(ResumeLinePrinterInterface& printer) {
	SubSection::print(printer);
	if(!selected) return;
	IndentedResumeLinePrinter indentificationifieror(&printer);
	for_each(subsections.begin(), subsections.end(), [&] (SubSectionInterface& sub) {
		sub.print(indentificationifieror);
	});
	printer.printLine("------------------------------------", A_NORMAL);
}
