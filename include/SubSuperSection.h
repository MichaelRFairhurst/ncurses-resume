#ifndef HEADER_SUBSUPERSECTION
#define HEADER_SUBSUPERSECTION
#include "SubSection.h"
#include "SuperSection.h"

class SubSuperSection : public SubSection, public SuperSection {

	public:
		void highlightOn();
		void highlightOff();
		void print(ResumeLinePrinterInterface& printer);
		SubSuperSection() { selected = false; };
		~SubSuperSection() {};

	private:
		bool selected;

};

#endif
