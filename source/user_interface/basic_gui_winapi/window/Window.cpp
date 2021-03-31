//
#include "Window.h"

#define WIN32_LEAN_AND_MEAN
#ifndef WIN32_LEAN_AND_MEAN
#error Nie zdefiniowano WIN32_LEAN_AND_MEAN.
#endif

#include <iostream>
#include <Windows.h>											//WinAPI

using namespace basic_gui;

bool Window::registered {false};

Window::Window() {
	std::cout << "constructor basic_gui::Window\n";
	if (register_wnd_class() == 1) return;
	if (create_window() == 1) return;
	std::cout << "OK\n";
	return;
}

Window::~Window() {
	std::cout << "destructor basic_gui::~Window\n";
	destroy_window();
	return;
}

void Window::position_size(short x, short y, short w, short h) {
	std::cout << "basic_gui::Window::position_size()\n";
	x = y = w = h = 0;
	return;
}

bool Window::register_wnd_class() {
	if (registered == true) return 0;

	HINSTANCE app {GetModuleHandle(nullptr)};					//plik exe tworz¹cy okno
	if (app == nullptr) return 1;
	HGDIOBJ backg {GetStockObject(DKGRAY_BRUSH)};				//ciemoszary pêdzel
	if (backg == nullptr) return 1;
	HICON icon = LoadIcon(nullptr, IDI_APPLICATION);			//standardowa ikona aplikacji
	if (icon == nullptr) return 1;
	HCURSOR cursor = LoadCursor(nullptr, IDC_ARROW);			//standardowa strza³ka
	if (cursor == nullptr) return 1;

	WNDCLASSEX wcx {};
	wcx.hInstance = app;										//aplikacja zawieraj¹ca procedurê okna
	wcx.lpszClassName = L"WND_CLASS";							//nazwa klasy okna
	wcx.lpfnWndProc = window_procedure;							//procedura okna
	wcx.style = CS_HREDRAW | CS_VREDRAW;						//styl okna

	wcx.hbrBackground = static_cast<HBRUSH>(backg);				//t³o okna
	wcx.hIcon = icon;											//du¿a ikona okna
	wcx.hIconSm = nullptr;										//ma³a ikona okna
	wcx.hCursor = cursor;										//kursor myszy

	wcx.lpszMenuName = nullptr;									//bez zasobu menu
	wcx.cbClsExtra = 0;											//bez dodatkowej pamiêci klasy okien
	wcx.cbWndExtra = 0;											//bez dodatkowej pamiêci okna
	wcx.cbSize = sizeof(WNDCLASSEX);

	if (RegisterClassEx(&wcx) == 0) return 1;
	registered = true;
	return 0;
}

bool Window::create_window() {
	HINSTANCE app {GetModuleHandle(nullptr)};					//plik exe tworz¹cy okno
	if (app == nullptr) return 1;

	hwnd = CreateWindowEx(
		0,														//rozszerzony styl okna
		L"WND_CLASS",											//nazwa klasy okna
		L"Default",												//tytu³ okna
		WS_OVERLAPPEDWINDOW | WS_VISIBLE,						//podstawowy styl okna, OVERLAPPED+BORDER+DLGFRAME+THICKFRAME+SYSMENU+MINIMIZEBOX+MAXIMIZEBOX
		50, 50,													//pozycja okna (wspó³rzêdne)(x, y)
		500, 500,												//rozmiar okna (wymiary)(w, h)
		nullptr,												//rodzic okna
		nullptr,												//bez zasobu menu
		app,													//modu³ powi¹zany z oknem
		this													//wskaŸnik obiektu w dodatkowych danych okna
	);
	if (hwnd == nullptr) return 1;
	return 0;
}

void Window::destroy_window() {
	if (hwnd == nullptr) return;
	if (DestroyWindow(hwnd) == 0) return;
	return;
}

LRESULT CALLBACK Window::window_procedure(HWND f_hwnd, UINT msg, WPARAM wpar, LPARAM lpar) {
	return DefWindowProc(f_hwnd, msg, wpar, lpar);
}
//