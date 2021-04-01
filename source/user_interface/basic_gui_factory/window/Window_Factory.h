//
#pragma once

namespace basic_gui {

	class Window_I;

	class Window_Factory {
	public:
		Window_Factory();										//default constructor
		~Window_Factory();										//destructor
		Window_I* get_window();
	private:
	};
}
//