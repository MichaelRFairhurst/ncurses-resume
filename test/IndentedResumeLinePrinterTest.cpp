#include "gmock/gmock.h"
#include "ncurses.h"
#define BOOST_TEST_MODULE IndentedResumeLinePrinterTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "ResumeLinePrinterMock.h"
#include "IndentedResumeLinePrinter.h"

BOOST_AUTO_TEST_CASE(TestIndentedResumeLinePrinter_Prepends) {
	ResumeLinePrinterMock wrapped;
	IndentedResumeLinePrinter indenter(&wrapped);
	EXPECT_CALL(wrapped, printLine("+-      my header", A_BOLD))
		.Times(1);

	indenter.printLine("my header", A_BOLD);
}
