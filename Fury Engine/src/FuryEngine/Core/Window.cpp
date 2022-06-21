#include "Window.h"

#include "Platform/Windows/WindowsWindow.h"

namespace FuryEngine {

	Scope<Window> Window::Create(const WindowProps& props) {
#ifdef FURY_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
#error Fury Engine only supports Windows!
		return nullptr;
#endif
	}

}