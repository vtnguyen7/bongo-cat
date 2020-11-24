#include <ncurses.h>
#include <stdio.h>
#include <vector>
#include "writer/bongoWriter.h"

void ncwrite::nc_draw( int y, int x, std::vector<const char*> pic, int colour_pair ) {
	
	attron( COLOR_PAIR( colour_pair ) );
	for (auto i : pic) {
		move( y, x );
		printw(i);
		y++;
	}
	attroff( COLOR_PAIR( colour_pair ) );
	refresh();

}
