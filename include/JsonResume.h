#ifndef HEADER_JSON_RESUME
#define HEADER_JSON_RESUME
#include "json_spirit_reader_template.h"
#include "SubSectionInterface.h"
#include "SuperSection.h"

using namespace std;
using namespace json_spirit;

class JsonResume {

	public:
		JsonResume(string content);
		SuperSectionInterface* getSuperSection();

	private:
		SubSectionInterface* createSubSection(Value v);
		SuperSection topopulate;
};

#endif
