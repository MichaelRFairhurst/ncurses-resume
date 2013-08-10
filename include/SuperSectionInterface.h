#ifndef HEADER_SUPERSECTION_INTERFACE
#define HEADER_SUPERSECTION_INTERFACE

#include <algorithm>
#include "SubSectionInterface.h"
#include "ResumeLinePrinterInterface.h"

using namespace std;

class SubSectionInterface;

class SuperSectionInterface {

	public:
		virtual void addSubSection(SubSectionInterface& section)=0;
		virtual void up()=0;
		virtual void down()=0;
		virtual void select()=0;
		virtual void deselect()=0;
		virtual void setPreSelect(function<bool()> f)=0;
		virtual void setPreDeselect(function<bool()> f)=0;
		virtual void setPreUp(function<bool()> f)=0;
		virtual void setPreDown(function<bool()> f)=0;
		virtual void print(ResumeLinePrinterInterface& printer)=0;
		virtual ~SuperSectionInterface() {};

};

#endif
