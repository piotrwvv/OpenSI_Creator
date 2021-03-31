//
#pragma once

namespace basic_gui {

	class Window_I {
	public:
		virtual ~Window_I();
		virtual void position_size(short x, short y, short w, short h) = 0;
	protected:
		Window_I();
	};
}
//