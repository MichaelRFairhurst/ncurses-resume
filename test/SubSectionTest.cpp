#include "gmock/gmock.h"
#include "ncurses.h"
#define BOOST_TEST_MODULE SubSectionTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "SubSection.h"
#include "ResumeLinePrinterMock.h"


BOOST_AUTO_TEST_CASE(SubSection_TestPrintNoHighlightedHeader) {
	SubSection subs;
	ResumeLinePrinterMock printer;
	subs.setHeader("my header");
	subs.highlightOff();
	EXPECT_CALL(printer, printLine("my header", A_NORMAL))
		.Times(1);

	subs.print(printer);
}

BOOST_AUTO_TEST_CASE(SubSection_TestPrintHighlightedHeader) {
	SubSection subs;
	ResumeLinePrinterMock printer;
	subs.setHeader("my header");
	subs.highlightOn();
	EXPECT_CALL(printer, printLine("my header", A_BOLD | A_UNDERLINE))
		.Times(1);

	subs.print(printer);
}
