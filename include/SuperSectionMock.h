#ifndef HEADER_SUPERSECTION_MOCK
#define HEADER_SUPERSECTION_MOCK
#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "SuperSectionInterface.h"

using namespace std;

class SuperSectionMock : public SuperSectionInterface {

	public:
		MOCK_METHOD1(addSubSection, void(SubSectionInterface& sections));
		MOCK_METHOD0(up, void());
		MOCK_METHOD0(down, void());
		MOCK_METHOD0(select, void());
		MOCK_METHOD0(deselect, void());
		MOCK_METHOD1(setPreSelect, void(function<bool()> f));
		MOCK_METHOD1(setPreDeselect, void(function<bool()> f));
		MOCK_METHOD1(setPreUp, void(function<bool()> f));
		MOCK_METHOD1(setPreDown, void(function<bool()> f));

};

#endif
