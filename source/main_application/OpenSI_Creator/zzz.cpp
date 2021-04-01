// Temporary code, excluded from build.

#ifndef WIN32_LEAN_AND_MEAN
#error WIN32_LEAN_AND_MEAN not defined.
#endif

	HINSTANCE hinst {nullptr};
	if ((hinst = GetModuleHandle(nullptr)) == nullptr) return 1;

	HINSTANCE hinst {GetModuleHandle(nullptr)};
	if (hinst == nullptr) return 1;

//