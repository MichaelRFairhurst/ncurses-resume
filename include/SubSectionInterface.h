#ifndef HEADER_SUBSECTION_INTERFACE
#define HEADER_SUBSECTION_INTERFACE

#include <string>
#include "SuperSectionInterface.h"
#include "ResumeLinePrinterInterface.h"

using namespace std;

class SuperSectionInterface;

class SubSectionInterface {

	public:
		virtual void setSuperSection(SuperSectionInterface *section)=0;
		virtual void highlightOn()=0;
		virtual void highlightOff()=0;
		virtual void setHeader(string header)=0;
		virtual void print(ResumeLinePrinterInterface& printer)=0;
		virtual ~SubSectionInterface() {}

};

#endif
