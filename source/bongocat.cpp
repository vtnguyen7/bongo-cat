#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <iostream>
#include <ncurses.h>
#include <vector>
#include "config/bongoConfig.h"
#include "writer/bongoWriter.h"
#include "config/bongoConstants.h"

#define PRESSED_PAIR 1
#define UNPRESSED_PAIR 2

using namespace ncwrite;

int config::y_press = vars::d_y_press;
int config::x_press = vars::d_x_press;
int config::y_release = vars::d_y_release;
int config::x_release = vars::d_x_release;

int config::fg_colour = vars::d_fg_colour;
int config::bg_colour = vars::d_bg_colour;
int config::pressed_fg_colour = vars::d_pressed_fg_colour;
int config::pressed_bg_colour = vars::d_pressed_bg_colour;	

int config::y_centering = vars::d_y_centering;
int config::x_centering = vars::d_x_centering;

std::vector<const char*> config::left_pressed = vars::d_left_pressed;
std::vector<const char*> config::right_pressed = vars::d_right_pressed;
std::vector<const char*> config::unpressed = vars::d_unpressed;

int y_offset = config::unpressed.size()/2;
int x_offset = config::get_x_offset( config::unpressed )/2;

int main( int argc, char **argv ) {
	
	config::get_config();
		
	// Stuff for X11
	Display *display;
	XEvent xevent;
	Window root;
	Window curFocus;
	int revert;
	int alt = 1;

	if( ( display = XOpenDisplay( NULL ) ) == NULL )
		return -1;

	// Get the focussed window, get inputs for that selected window
	XGetInputFocus ( display, &curFocus, &revert );
	XSelectInput( display, 
			curFocus, 
			KeyPressMask | KeyReleaseMask | FocusChangeMask );

	int ffocus = curFocus;

	initscr();
	noecho();
	cbreak();
	curs_set( 0 );

	start_color();
	init_pair( PRESSED_PAIR, config::pressed_fg_colour, config::pressed_bg_colour );
	init_pair( UNPRESSED_PAIR, config::fg_colour, config::bg_colour );

	config::set_centre( y_offset, x_offset );

	while( 1 ) {
		XNextEvent( display, &xevent );										// Listen for events
		switch( xevent.type ) {
			case FocusOut :
				XGetInputFocus ( display, &curFocus, &revert );	// Get new focus
				if ( curFocus == PointerRoot )
					curFocus = root;														// Change focus to root
				XSelectInput( display, 
						curFocus, 
						KeyPressMask | KeyReleaseMask | FocusChangeMask );
				break;
			case KeyPress :
				if ( xevent.xkey.keycode == 27 && curFocus == ffocus ) {
					config::get_config();
					config::set_centre( y_offset, x_offset );
					init_pair( PRESSED_PAIR, config::pressed_fg_colour, config::pressed_bg_colour );
					init_pair( UNPRESSED_PAIR, config::fg_colour, config::bg_colour );
					clear;
				}
					
				if ( alt ) {
					nc_draw( config::y_press, config::x_press, config::left_pressed, PRESSED_PAIR );
				} else {
					nc_draw( config::y_press, config::x_press, config::right_pressed, PRESSED_PAIR );
				}
				alt = !alt;
				break;
			case KeyRelease :
				nc_draw( config::y_release, config::x_release, config::unpressed, UNPRESSED_PAIR );
				break;
		}
	}
	
	endwin();
	
	return 0;
}
