#include "SuperSection.h"

using namespace std;

void SuperSection::addSubSection(SubSectionInterface& section) {
	section.setSuperSection(this);

	subsections.size() ? section.highlightOff() : section.highlightOn();

	subsections.push_back(&section);
}

void SuperSection::up() {
	if(preup == NULL || preup())
	if(selectedindex > 0) {
		subsections.at(selectedindex).highlightOff();
		selectedindex--;
		subsections.at(selectedindex).highlightOn();
	}
}

void SuperSection::down() {
	if(predown == NULL || predown())
	if(selectedindex + 1 < subsections.size()) {
		subsections.at(selectedindex).highlightOff();
		selectedindex++;
		subsections.at(selectedindex).highlightOn();
	}
}


void SuperSection::select() {
	preselect != NULL && preselect();
}

void SuperSection::deselect() {
	predeselect != NULL && predeselect();
}

void SuperSection::setPreSelect(function<bool()> f) {
	preselect = f;
}

void SuperSection::setPreDeselect(function<bool()> f) {
	predeselect = f;
}

void SuperSection::setPreUp(function<bool()> f) {
	preup = f;
}

void SuperSection::setPreDown(function<bool()> f) {
	predown = f;
}

void SuperSection::print(ResumeLinePrinterInterface& printer) {
	for_each(subsections.begin(), subsections.end(), [&] (SubSectionInterface& sub) {
		sub.print(printer);
	});
}
