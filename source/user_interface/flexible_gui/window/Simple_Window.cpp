//
#include "Simple_Window.h"
#include "../../basic_gui_factory/basic_gui_factory.h"
#include "../../basic_gui_facade/basic_gui_facade.h"

#include <iostream>

using namespace flexible_gui;

Simple_Window::Simple_Window() {
	std::cout << "constructor flexible_gui::Simple_Window\n";
	basic_gui::Window_Factory wnd_factory;
	wnd = wnd_factory.get_window();
	return;
}

Simple_Window::~Simple_Window() {
	std::cout << "destructor flexible_gui::~Simple_Window\n";
	if (wnd) delete wnd;
	return;
}

void Simple_Window::position_size(short x, short y, short w, short h) {
	std::cout << "flexible_gui::Simple_Window::position_size()\n";
	wnd->position_size(x,y,w,h);
	return;
}
//