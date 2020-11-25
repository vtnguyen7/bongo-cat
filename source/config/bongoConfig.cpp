#include <stdio.h>
#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <ncurses.h>
#include <sys/stat.h>
#include <vector>
#include "config/bongoConfig.h"

using namespace config;
using namespace std;

void config::printall() {
	
	std::cout << y_press << "\n";
	std::cout << x_press << "\n";
	std::cout << y_release << "\n";
	std::cout << x_release << "\n";
	
	std::cout << fg_colour << "\n";
	std::cout << bg_colour << "\n";
	std::cout << pressed_fg_colour << "\n";
	std::cout << pressed_bg_colour << "\n";	

}
std::string config::clear_whitespace( std::string str ) {
	
	str.erase( remove( str.begin(), str.end(), ' ' ), str.end() );
	str.erase( remove( str.begin(), str.end(), '	' ), str.end() );
	
	return str;
}

void config::process( std::string line ) {
	
	line = config::clear_whitespace( line );

	if (line[0] == '#') {

		return;

	}	else {
		
		int eq = line.find('=');
		
		if (eq != string::npos) {
			std::string setting = line.substr( 0, eq );
			
			if ( setting == "y_press" ) config::y_press = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "x_press" ) config::x_press = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "y_release" ) config::y_release = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "x_release" ) config::x_release = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "fg_colour" ) config::fg_colour = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "bg_colour" ) config::bg_colour = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "pressed_fg_colour" ) config::pressed_fg_colour = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "pressed_bg_colour" ) config::pressed_bg_colour = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "y_centering" ) config::y_centering = stoi(line.substr(eq + 1, line.length()));
			if ( setting == "x_centering" ) config::x_centering = stoi(line.substr(eq + 1, line.length()));
		}
	}
	return;
}

void config::set_y_centre( int y, int y_offset ) {
	config::y_press = y/2 - y_offset;
	config::y_release = y/2 - y_offset;
}

void config::set_x_centre( int x, int x_offset ) {
	config::x_press = x/2 - x_offset;
	config::x_release = x/2 - x_offset;
}

int config::get_x_offset( std::vector<const char*> pic ) {
	int max = 0;
	for ( auto i : pic ) {
		if ( strlen(i) > max ) {
			max = strlen(i);
		}
	}
	return max;
}

void config::set_centre( int y_off, int x_off ) {

	int y_dim, x_dim;
	getmaxyx( stdscr, y_dim, x_dim );

	if ( config::y_centering ) {
		clear();
		config::set_y_centre( y_dim, y_off );
	}
	if ( config::x_centering ) {
		clear();
		config::set_x_centre( x_dim, x_off );
	}

}

void config::get_config() {
	
	std::string file_path = std::string{std::getenv( "HOME" )} + "/.config/bongocat/config";
	
	fstream configfile;
	configfile.open(file_path, ios::in);
	
	if( !configfile ) {
		
		return;	

	} else {
		
		std::string line;
		
		while( getline( configfile, line ) ) {
		
			process(line);

		}

		configfile.close();
	}

	return;
}
