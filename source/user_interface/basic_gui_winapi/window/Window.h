//
#pragma once

#include "../../basic_gui_interface/window/Window_I.h"

using HWND = struct HWND__*;
using LRESULT = __int64;
using UINT = unsigned int;
using WPARAM = unsigned __int64;
using LPARAM = __int64;

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
		//free function?
		bool register_wnd_class() const noexcept;
		bool create_window() noexcept;
		bool destroy_window() const noexcept;
		//free function?
		static LRESULT __stdcall window_procedure(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	private:
		HWND hwnd {nullptr};									//WinAPI window handler
	};
}
//