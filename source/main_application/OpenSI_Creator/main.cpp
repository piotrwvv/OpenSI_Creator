//
#include "../../user_interface/flexible_gui/flexible_gui.h"

#include <iostream>
#include <chrono>
#include <thread>

int main() {
	std::cout << "Hello World!\n";

	flexible_gui::Simple_Window main_wnd {};

	main_wnd.position_size(50, 50, 300, 300);

// simple - complex
// basic - advanced

	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	return 0;
}
//