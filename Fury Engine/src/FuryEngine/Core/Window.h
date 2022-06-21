#pragma once

#include <sstream>

#include "Core.h"

namespace FuryEngine {

	struct WindowProps
	{
		std::string Title;
		u32 Width;
		u32 Height;

		WindowProps(const std::string& title = "Fury Engine", u32 width = 1600, u32 height = 900)
			: Title(title), Width(width), Height(height) {
		}
	};

	class Window {
	public:
		//TODO: implement events
		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual u32 GetWidth() const = 0;
		virtual u32 GetHeight() const = 0;

		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowProps& props = WindowProps());
	};

}