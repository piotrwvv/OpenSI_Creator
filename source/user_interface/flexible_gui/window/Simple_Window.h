//
#pragma once

namespace basic_gui { class Window_I; }

namespace flexible_gui {

	class Simple_Window {
	public:
		Simple_Window();
		~Simple_Window();
		void position_size(short x, short y, short w, short h);
	private:
		basic_gui::Window_I* wnd {nullptr};
	};
}
//