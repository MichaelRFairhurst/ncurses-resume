BUILDDIR = build

EXECUTABLE = $(BUILDDIR)/nresume
TESTS = $(addprefix $(BUILDDIR)/, $(TESTFILES:Test.cpp=.test))

FILES = JsonResume.cpp SubSection.cpp SuperSection.cpp ResumeLinePrinter.cpp IndentedResumeLinePrinter.cpp SubSuperSection.cpp
TESTFILES = SuperSectionTest.cpp SubSectionTest.cpp IndentedResumeLinePrinterTest.cpp SubSuperSectionTest.cpp

OBJECTS = $(addprefix $(BUILDDIR)/, $(FILES:.cpp=.o))
EXEOBJECTS = $(BUILDDIR)/nresume.o $(OBJECTS)

CCMD = g++
CFLG =-Iinclude -I../json-spirit/json_spirit/ -lncurses --std=c++0x -O0 -g -Wall -Wextra
TESTCFLG = -I../gmock/include -I../gmock/gtest/include -lpthread -lboost_unit_test_framework 

# DEFAULT TO EXECUTABLE ONLY
$(EXECUTABLE): $(EXEOBJECTS)
	$(CCMD) $(EXEOBJECTS) $(CFLG) -o $(EXECUTABLE)

.PHONY:
memcheck: $(EXECUTABLE)
	valgrind --leak-check=yes --track-origins=yes $(EXECUTABLE) 2> memlog.log

# TEST AND BUILD WITH make all
all : test $(EXECUTABLE)

# saying this depends on $(TESTS) prevents the deletion of .test artifacts
.PHONY:
test: $(addprefix run__, $(TESTS)) $(TESTS)

.PHONY:
run__$(BUILDDIR)/%.test: $(BUILDDIR)/%.test
	./$<

$(BUILDDIR)/%.test: test/%Test.cpp $(OBJECTS)
	$(CCMD) $(CFLG) $(TESTCFLG) $< $(OBJECTS) /mnt/d/projects/cpp/gmock/make/gmock.a -o $@

$(BUILDDIR)/%.o: src/%.cpp
	$(CCMD) $(CFLG) -c $< -o $@

.PHONY:
clean:
	rm -rf $(BUILDDIR)/*
