#ifndef HEADER_SUPERSECTION
#define HEADER_SUPERSECTION

#include <algorithm>
#include <boost/ptr_container/ptr_vector.hpp>
#include "SuperSectionInterface.h"

class SuperSection : public SuperSectionInterface {

	public:
		void addSubSection(SubSectionInterface& sections);
		void up();
		void down();
		void select();
		void deselect();
		void setPreSelect(function<bool()> f);
		void setPreDeselect(function<bool()> f);
		void setPreUp(function<bool()> f);
		void setPreDown(function<bool()> f);
		virtual ~SuperSection() {};
		virtual void print(ResumeLinePrinterInterface& printer);

	protected:
		boost::ptr_vector<SubSectionInterface> subsections;
		unsigned int selectedindex = 0;
		function<bool()> preselect = 0;
		function<bool()> predeselect = 0;
		function<bool()> preup = 0;
		function<bool()> predown = 0;

};

#endif
