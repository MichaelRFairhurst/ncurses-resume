#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SubSectionInterface.h"

class SubSectionMock : public SubSectionInterface {

	public:
		SubSectionMock() {};
		MOCK_METHOD1(setSuperSection, void(SuperSectionInterface *section));
		MOCK_METHOD0(highlightOn, void());
		MOCK_METHOD0(highlightOff, void());
		MOCK_METHOD1(setHeader, void(string header));
		MOCK_METHOD1(print, void(ResumeLinePrinterInterface& printer));
		~SubSectionMock() {
		};

};
