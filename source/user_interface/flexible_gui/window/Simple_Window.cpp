//
#include "Simple_Window.h"
#include "../../basic_gui_facade/basic_gui_facade.h"

#include <iostream>

using namespace flexible_gui;

Simple_Window::Simple_Window(basic_gui::Window_I* wnd)
	: wnd{wnd} {
	std::cout << "constructor flexible_gui::Simple_Window\n";
	return;
}

Simple_Window::~Simple_Window() {
	std::cout << "destructor flexible_gui::~Simple_Window\n";
	return;
}

void Simple_Window::position_size(short x, short y, short w, short h) {
	std::cout << "flexible_gui::Simple_Window::position_size()\n";
	wnd->position_size(x,y,w,h);
	return;
}
//