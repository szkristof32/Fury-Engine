#pragma once

#include "Core.h"
#include "Window.h"

namespace FuryEngine {

	class FURY_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
		void RequestClose() { m_CloseFlag = true; }

		static Application& Get() { return *s_Instance; }

	private:
		Scope<Window> m_Window;
		bool m_CloseFlag = false;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}