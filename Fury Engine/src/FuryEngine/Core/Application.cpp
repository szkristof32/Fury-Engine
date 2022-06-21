#include "Application.h"

#include <iostream>

#include "FuryEngine/Ui/Ui.h"

namespace FuryEngine {

	Application* Application::s_Instance = nullptr;

	Application::Application() {
		s_Instance = this;
		m_Window = Window::Create();
	}

	Application::~Application() {
		
	}

	void Application::Run() {
		while (!m_CloseFlag) {
			m_Window->OnUpdate();
		}
	}

}