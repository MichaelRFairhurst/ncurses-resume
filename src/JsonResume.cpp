#include <vector>
#include "json_spirit_reader_template.h"
#include "json_spirit_writer_template.h"
#include "JsonResume.h"
#include "SubSection.h"

using namespace json_spirit;

JsonResume::JsonResume(std::string json) {
	json_spirit::Value val;
	json_spirit::read_string(json, val);
}

SubSectionInterface* JsonResume::createSubSection(Value v) {
	if(v.type() == obj_type)
		return new SubSection;
	return new SubSection;
}

SuperSectionInterface* JsonResume::getSuperSection() {
	return &topopulate;
}
