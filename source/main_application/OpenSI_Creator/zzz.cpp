// Temporary code, excluded from build.

	HINSTANCE hinst {nullptr};
	if ((hinst = GetModuleHandle(nullptr)) == nullptr) return 1;

	HINSTANCE hinst {GetModuleHandle(nullptr)};
	if (hinst == nullptr) return 1;

//