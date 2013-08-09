#ifndef HEADER_RESUMELINEPRINTERMOCK
#define HEADER_RESUMELINEPRINTERMOCK
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>
#include "ResumeLinePrinterInterface.h"

using namespace std;

class ResumeLinePrinterMock: public ResumeLinePrinterInterface {

	public:
		ResumeLinePrinterMock() {};
		MOCK_METHOD2(printLine, void(string text, long unsigned int attributes));

};

#endif
