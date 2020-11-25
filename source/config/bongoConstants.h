#ifndef B_CONSTANTS_H
#define B_CONSTANTS_H

#include <string>
#include <ncurses.h>
#include <vector>

namespace vars {
	
	const int d_y_press = 0;
	const int d_x_press = 0;
	const int d_y_release = 0;
	const int d_x_release = 0;

	const int d_fg_colour = 15;
	const int d_bg_colour = 0;
	const int d_pressed_fg_colour = 15;
	const int d_pressed_bg_colour = 0;

	const int d_y_centering = 1;
	const int d_x_centering = 1;

	const std::vector<const char*> d_right_pressed = {
		"                 /\\__ ",
		"             .--^    ^^^^--__/\\ ",
		"          .-^  .               | ",
		"^^^---...^       -^-  .  .-.   \\ ",
		"   -    t_.--^...       | @ `   \\ ",
		"   -^             ^^^---.\\..     \\ ",
		"      /   |  `              ^^^^-.i... ",
		"                                      ^^^"};
	const std::vector<const char*> d_left_pressed = {
		"                  /\\__ ",
		"         .-.  .--^    ^^^^--__/\\ ",
		"        | @  ` .                | ",
		"^^^---...\\       -^-  .         \\ ",
		"         ^^^---...               \\ ",
		"                  ^^^---./        \\ ",
		"                   --   t_..-*^^--.i.. ",
		"                     /   |   \\        ^^^"};
	const std::vector<const char*> d_unpressed = {
		"                  /\\__ ",
		"         .-.  .--^    ^^^^--__/\\ ",
		"        | @  ` .                | ",
		"^^^---...\\       -^-  .  .-.    \\ ",
		"         ^^^---...      | @ `    \\ ",
		"                  ^^^---.\\..      \\ ",
		"                            ^^^^--.i.. ",
		"                                      ^^^"};
}

#endif
