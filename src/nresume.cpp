#include <string>
#include <assert.h>
#include <ncurses.h>
#include <boost/ptr_container/ptr_vector.hpp>
#include "Resume.h"
#include "ResumeLinePrinter.h"
#include "SuperSection.h"
#include "SubSection.h"
#include "SubSuperSection.h"

using namespace std;

int main(int argc, char *argv[])
{
	int ch;
	ResumeLinePrinter printer;
	Resume resume;
	SuperSectionInterface* topsection = resume.getSuperSection();

	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	addch('\n');
	printer.printLine("THE NCURSES EXPERIMENT", A_REVERSE | A_BOLD);
	topsection->print(printer);

	assert(topsection != NULL);

	while((ch = getch()) != 'q') {
		clear();
		addch('\n');
		printer.printLine("THE NCURSES EXPERIMENT", A_REVERSE | A_BOLD);
		switch(ch) {
			case KEY_UP:
				topsection->up();
				break;
			case KEY_DOWN:
				topsection->down();
				break;	
			case KEY_ENTER:
			case 10:
				topsection->select();
				break;	
			case KEY_LEFT:
				topsection->deselect();
				break;	
		}

		topsection->print(printer);
	}
		
	endwin();
	delete topsection;
	return 0;
}
