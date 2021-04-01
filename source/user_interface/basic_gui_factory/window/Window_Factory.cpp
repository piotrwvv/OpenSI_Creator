//
#include "Window_Factory.h"
#include "../../basic_gui_winapi/window/Window.h"				//PLATFORM = Windows

#include <iostream>

using namespace basic_gui;

Window_Factory::Window_Factory() {
	std::cout << "constructor basic_gui::Window_Factory\n";
	return;
}

Window_Factory::~Window_Factory() {
	std::cout << "destructor basic_gui::~Window_Factory\n";
	return;
}

Window_I* Window_Factory::get_window() {
	return new Window {};
}
//