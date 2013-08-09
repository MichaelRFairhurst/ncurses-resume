#include "gmock/gmock.h"
#define BOOST_TEST_MODULE SuperSection
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/ptr_container/ptr_vector.hpp>
#include <SuperSection.h>
#include <SubSectionMock.h>
#include <string>
#define NO_GMOCK_ARGS

struct InitGMock {
	InitGMock() {
		::testing::GTEST_FLAG(throw_on_failure) = true;

#ifdef NO_GMOCK_ARGS
		int gmargc = 0;
		char ** gmargv = {};
		::testing::InitGoogleMock(&gmargc, gmargv);
#else
		::testing::InitGoogleMock(&boost::unit_test::framework::master_test_suite().argc,
									boost::unit_test::framework::master_test_suite().argv);
#endif
	}
	~InitGMock() { }
};

BOOST_GLOBAL_FIXTURE(InitGMock);

BOOST_AUTO_TEST_CASE(SuperSection_SetSubSections_test) {
	SuperSection s;
	SubSectionMock* highlighted = new SubSectionMock();
	SubSectionMock* nothighlighted = new SubSectionMock();

	EXPECT_CALL((*highlighted), highlightOn());
	EXPECT_CALL((*nothighlighted), highlightOff());
	EXPECT_CALL((*highlighted), setSuperSection(&s));
	EXPECT_CALL((*nothighlighted), setSuperSection(&s));

	s.addSubSection(*highlighted);
	s.addSubSection(*nothighlighted);
}

#define TEST_SUPERSECTION_HOOK(hooksetter, hookcaller) \
	BOOST_AUTO_TEST_CASE( SuperSection_##hooksetter##_test ) { \
		bool hasFired = false; \
		SuperSection s; \
	\
		s.addSubSection(*new ::testing::NiceMock<SubSectionMock>); /* need one */\
	 \
		s.hooksetter([&] () -> bool { \
			hasFired = true; \
			return false; \
		}); \
	 \
		BOOST_CHECK_MESSAGE(!hasFired, #hookcaller" hook called too early"); \
		s.hookcaller(); \
		BOOST_CHECK_MESSAGE(hasFired, #hookcaller" hook not called"); \
	}

TEST_SUPERSECTION_HOOK(setPreSelect, select);
TEST_SUPERSECTION_HOOK(setPreDeselect, deselect);
TEST_SUPERSECTION_HOOK(setPreUp, up);
TEST_SUPERSECTION_HOOK(setPreDown, down);

BOOST_AUTO_TEST_CASE( SuperSection_testHighlightFiresOnUpAndDown )
{
	SubSectionMock* subs[3];
	subs[0] = new ::testing::StrictMock<SubSectionMock>;
	subs[1] = new ::testing::StrictMock<SubSectionMock>;
	subs[2] = new ::testing::StrictMock<SubSectionMock>;
	SuperSection s;
	EXPECT_CALL((*subs[0]), setSuperSection(&s));
	EXPECT_CALL((*subs[0]), highlightOn());
	EXPECT_CALL((*subs[1]), setSuperSection(&s));
	EXPECT_CALL((*subs[1]), highlightOff());
	EXPECT_CALL((*subs[2]), setSuperSection(&s));
	EXPECT_CALL((*subs[2]), highlightOff());

	s.addSubSection(*subs[0]);
	s.addSubSection(*subs[1]);
	s.addSubSection(*subs[2]);

	EXPECT_CALL((*subs[0]), highlightOff());
	EXPECT_CALL((*subs[1]), highlightOn());
	s.down();
	EXPECT_CALL((*subs[1]), highlightOff());
	EXPECT_CALL((*subs[2]), highlightOn());
	s.down();

	// Now test we don't go any farther down :)
	s.down();

	// Now test up
	EXPECT_CALL((*subs[1]), highlightOn());
	EXPECT_CALL((*subs[2]), highlightOff());
	s.up();
	EXPECT_CALL((*subs[0]), highlightOn());
	EXPECT_CALL((*subs[1]), highlightOff());
	s.up();

	// Now test we don't go any farther up :)
	s.up();
}
