#include <string>
#include <ncurses.h>
#include <boost/ptr_container/ptr_vector.hpp>
#include "JsonResume.h"
#include "ResumeLinePrinter.h"
#include "SuperSection.h"
#include "SubSection.h"
#include "SubSuperSection.h"

using namespace std;

int main(int argc, char *argv[])
{
	int ch;
	ResumeLinePrinter printer;
	SuperSection topsection;

	initscr();
	cbreak();
	keypad(stdscr, TRUE);

	string json = "{\
		'Top Section': {\
			'Top Sub1 Section': [\
				'Top Sub1 Top Content',\
				'Top Sub1 Mid Content',\
				'Top Sub1 Bot Content',\
			],\
			'Top Sub2 Section': [\
				'Top Sub2 Top Content',\
				'Top Sub2 Mid Content',\
				'Top Sub2 Bot Content',\
			],\
		},\
		'Mid Section': {\
			'Mid Sub1 Section': [\
				'Mid Sub1 Top Content',\
				'Mid Sub1 Mid Content',\
				'Mid Sub1 Bot Content',\
			],\
			'Mid Sub2 Section': [\
				'Mid Sub2 Top Content',\
				'Mid Sub2 Mid Content',\
				'Mid Sub2 Bot Content',\
			],\
		}\
		'Bot Section': {\
			'Bot Sub1 Section': [\
				'Bot Sub1 Top Content',\
				'Bot Sub1 Mid Content',\
				'Bot Sub1 Bot Content',\
			],\
			'Bot Sub2 Section': [\
				'Bot Sub2 Top Content',\
				'Bot Sub2 Mid Content',\
				'Bot Sub2 Bot Content',\
			],\
		}\
	}";

	JsonResume theresume = JsonResume(json);

	addch('\n');
	printer.printLine("THE NCURSES EXPERIMENT", A_REVERSE | A_BOLD);
	topsection.print(printer);

	while((ch = getch()) != 'q') {
		clear();
		addch('\n');
		printer.printLine("THE NCURSES EXPERIMENT", A_REVERSE | A_BOLD);
		switch(ch) {
			case KEY_UP:
				topsection.up();
				break;
			case KEY_DOWN:
				topsection.down();
				break;	
			case KEY_ENTER:
			case 10:
				topsection.select();
				break;	
			case KEY_LEFT:
				topsection.deselect();
				break;	
		}

		for(int i = 0; i < 5; i++)
			sections[i]->print(printer);
	}
		
	endwin();
	return 0;
}
