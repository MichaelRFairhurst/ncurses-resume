#ifndef HEADER_SUBSECTION
#define HEADER_SUBSECTION

#include <string>
#include <ncurses.h>
#include "SubSectionInterface.h"

using namespace std;

class SubSection : public SubSectionInterface {

	public:
		void setSuperSection(SuperSectionInterface *section);
		virtual void highlightOn();
		virtual void highlightOff();
		void setHeader(string header);
		virtual void print(ResumeLinePrinterInterface& printer);
		virtual ~SubSection() {};

	protected:
		bool highlighted = false;
		SuperSectionInterface* supersection = NULL;
		string header = "";

};

#endif
