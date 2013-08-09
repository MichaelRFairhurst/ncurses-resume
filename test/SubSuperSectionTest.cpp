#include "gmock/gmock.h"
#define BOOST_TEST_MODULE SubSuperSectionTest
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "SubSectionMock.h"
#include "SuperSectionMock.h"
#include "SubSuperSection.h"
#include "ResumeLinePrinterMock.h"

MATCHER(IsNullCallback, "") { return arg == NULL; }
MATCHER(IsNotNullCallback, "") { return arg != NULL; }

BOOST_AUTO_TEST_CASE(TestSubSuperSection_setsHooksOnSuperSection_WhenHighlighted) {
	SubSuperSection sut;
	SuperSectionMock parent;
	sut.setSuperSection(&parent);

	EXPECT_CALL(parent, setPreSelect(IsNotNullCallback()));
	EXPECT_CALL(parent, setPreDeselect(IsNotNullCallback()));
	EXPECT_CALL(parent, setPreUp(IsNotNullCallback()));
	EXPECT_CALL(parent, setPreDown(IsNotNullCallback()));
	sut.highlightOn();
}

BOOST_AUTO_TEST_CASE(TestSubSuperSection_removesHooksOnSuperSection_WhenHighlighted) {
	SubSuperSection sut;
	SuperSectionMock parent;
	sut.setSuperSection(&parent);

	EXPECT_CALL(parent, setPreSelect(IsNullCallback()));
	EXPECT_CALL(parent, setPreDeselect(IsNullCallback()));
	EXPECT_CALL(parent, setPreUp(IsNullCallback()));
	EXPECT_CALL(parent, setPreDown(IsNullCallback()));
	sut.highlightOff();
}

BOOST_AUTO_TEST_CASE(TestSubSuperSection_NotDelegatesHighlightDownOrUp_whenNotSelected) {
	SubSuperSection* sut = new SubSuperSection;
	SuperSection parent;
	parent.addSubSection(*sut);

	SubSectionMock* highlightedonce = new SubSectionMock;
	SubSectionMock* dehighlightedonce = new SubSectionMock;
	
	EXPECT_CALL(*highlightedonce, highlightOn());
	EXPECT_CALL(*dehighlightedonce, highlightOff());
	EXPECT_CALL(*highlightedonce, setSuperSection(sut));
	EXPECT_CALL(*dehighlightedonce, setSuperSection(sut));

	sut->addSubSection(*highlightedonce);
	sut->addSubSection(*dehighlightedonce);

	// Overkill why not
	parent.down();
	parent.down();
	parent.down();
	parent.up();
	parent.up();
	parent.up();
}

BOOST_AUTO_TEST_CASE(TestSubSuperSection_DelegatesHighlightDownOrUp_whenNotSelected) {
	SubSuperSection* sut = new SubSuperSection;
	SuperSection parent;
	parent.addSubSection(*sut);

	SubSectionMock* firstitem = new SubSectionMock;
	SubSectionMock* seconditem = new SubSectionMock;
	
	EXPECT_CALL(*firstitem, highlightOn());
	EXPECT_CALL(*seconditem, highlightOff());
	EXPECT_CALL(*firstitem, setSuperSection(sut));
	EXPECT_CALL(*seconditem, setSuperSection(sut));

	sut->addSubSection(*firstitem);
	sut->addSubSection(*seconditem);

	parent.select();
	
	EXPECT_CALL(*firstitem, highlightOff());
	EXPECT_CALL(*seconditem, highlightOn());

	parent.down();

	EXPECT_CALL(*firstitem, highlightOn());
	EXPECT_CALL(*seconditem, highlightOff());

	parent.up();
}

BOOST_AUTO_TEST_CASE(TestSubSuperSection_IndentsPrintOfSubSections_WhenSelected_AndNotHighlighted) {
	SubSuperSection* sut = new SubSuperSection;
	SuperSection parent;
	parent.addSubSection(*sut);
	parent.select();
	sut->setHeader("Section Header");
	SubSection* first = new SubSection;
	SubSection* second = new SubSection;
	first->setHeader("First Test Header");
	second->setHeader("Second Test Header");

	sut->addSubSection(*first);
	sut->addSubSection(*second);

	ResumeLinePrinterMock printer;

	EXPECT_CALL(printer, printLine("Section Header", A_NORMAL));
	EXPECT_CALL(printer, printLine("+-      First Test Header", A_BOLD | A_UNDERLINE));
	EXPECT_CALL(printer, printLine("+-      Second Test Header", A_NORMAL));
	EXPECT_CALL(printer, printLine("------------------------------------", A_NORMAL));

	sut->print(printer);
}

BOOST_AUTO_TEST_CASE(TestSubSuperSection_PrintsJustSelf_WhenNotSelected) {
	SubSuperSection* sut = new SubSuperSection;
	SuperSection parent;
	parent.addSubSection(*sut);
	sut->setHeader("Section Header");
	SubSection* first = new SubSection;
	SubSection* second = new SubSection;
	first->setHeader("First Test Header");
	second->setHeader("Second Test Header");

	sut->addSubSection(*first);
	sut->addSubSection(*second);

	::testing::StrictMock<ResumeLinePrinterMock> printer;

	EXPECT_CALL(printer, printLine("Section Header", A_UNDERLINE | A_BOLD));

	sut->print(printer);
}
