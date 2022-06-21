#pragma once

#include "FuryEngine/Core/Window.h"
#include "FuryEngine/Core/Core.h"
#include "FuryEngine/Rendering/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace FuryEngine {

	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		unsigned int GetWidth() const override { return m_Data.Width; }
		unsigned int GetHeight() const override { return m_Data.Height; }

		void SetVSync(bool enabled) override;
		bool IsVSync() const override { return m_Data.VSync; }

		virtual void* GetNativeWindow() const { return m_Window; }

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

	private:
		GLFWwindow* m_Window;
		Scope<GraphicsContext> m_Context;

		struct WindowData {
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};
		WindowData m_Data;
	};

}