//
#pragma once

#include "../../basic_gui_facade/window/Window_I.h"

typedef struct HWND__*			HWND;
typedef __int64					LRESULT;
typedef unsigned int			UINT;
typedef unsigned __int64		WPARAM;
typedef __int64					LPARAM;

namespace basic_gui {

	class Window : public Window_I {
	public:
		Window();												//default constructor
		Window(const Window&) = delete;							//copy constructor
		Window(Window&&) = delete;								//move constructor
		~Window();												//destructor
		Window& operator= (const Window&) = delete;				//copy assignment
		Window& operator= (Window&&) = delete;					//move assignment
		void position_size(short x, short y, short w, short h);
	private:
		bool register_wnd_class();
		bool create_window();
		bool destroy_window();
		static bool registered;
		HWND hwnd {nullptr};
		static LRESULT __stdcall window_procedure(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	};
}
//