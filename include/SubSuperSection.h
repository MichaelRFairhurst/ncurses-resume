#ifndef HEADER_SUBSUPERSECTION
#define HEADER_SUBSUPERSECTION
#include "SubSection.h"
#include "SuperSection.h"

class SubSuperSection : public SubSection, public SuperSection {

	public:
		void highlightOn();
		void highlightOff();
		void print(ResumeLinePrinterInterface& printer);
		~SubSuperSection() {};

	private:
		bool selected = false;

};

#endif
