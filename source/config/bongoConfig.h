#ifndef B_CONFIG_H
#define B_CONFIG_H

#include <string>
#include <vector>

namespace config {

	extern int y_press;
	extern int x_press;
	extern int y_release;
	extern int x_release;

	extern int fg_colour;
	extern int bg_colour;
	extern int pressed_fg_colour;
	extern int pressed_bg_colour;	

	extern int y_centering;
	extern int x_centering;

	extern std::vector<const char*> left_pressed;
	extern std::vector<const char*> right_pressed;
	extern std::vector<const char*> unpressed;

	void get_config();
	std::string clear_whitespace( std::string );
	void process( std::string );
	void printall();
	void set_y_centre( int y, int y_offset );
	void set_x_centre( int x, int x_offset );
	void set_centre( int y_off, int x_off );
	int get_x_offset( std::vector<const char*> );
}

#endif
