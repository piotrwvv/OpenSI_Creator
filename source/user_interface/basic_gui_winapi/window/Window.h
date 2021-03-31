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
		Window();												//konstruktor domy�lny
//		explicit Window(int) noexcept;							//konstruktor inicjuj�cy
		~Window();												//destruktor
		Window(const Window&) = delete;							//konstruktor kopiuj�cy
		Window& operator= (const Window&) = delete;				//przypisanie kopiuj�ce
		Window(Window&&) = delete;								//konstruktor przenosz�cy
		Window& operator= (Window&&) = delete;					//przypisanie przenosz�ce
		void position_size(short x, short y, short w, short h);
	private:
		bool register_wnd_class();
		bool create_window();
		void destroy_window();
		static bool registered;
		HWND hwnd {nullptr};
		static LRESULT __stdcall window_procedure(HWND hwnd, UINT msg, WPARAM wpar, LPARAM lpar);
	};
}
//