#ifndef HEADER_SUPERSECTION
#define HEADER_SUPERSECTION

#include <algorithm>
#include <boost/ptr_container/ptr_vector.hpp>
#include "SuperSectionInterface.h"

class SuperSection : public SuperSectionInterface {

	public:
		void addSubSection(SubSectionInterface& sections);
		void up();
		virtual void down();
		void select();
		void deselect();
		void setPreSelect(function<bool()> f);
		void setPreDeselect(function<bool()> f);
		void setPreUp(function<bool()> f);
		void setPreDown(function<bool()> f);
		SuperSection() { selectedindex = 0; };
		virtual ~SuperSection() {};
		virtual void print(ResumeLinePrinterInterface& printer);

	protected:
		boost::ptr_vector<SubSectionInterface> subsections;
		unsigned int selectedindex;
		function<bool()> preselect;
		function<bool()> predeselect;
		function<bool()> preup;
		function<bool()> predown;

};

#endif
