#include "WindowsWindow.h"

#include <iostream>

#include "FuryEngine/Core/Application.h"

namespace FuryEngine {

	static u8 s_GLFWWindowCount = 0;

	static void GLFWErrorCallback(int error, const char* description) {
		std::cout << "GLFW Error(" << error << "): " << description << "\n"; //TODO: implement logging
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		if (s_GLFWWindowCount == 0) {
			int success = glfwInit();
			if (success == GLFW_FALSE) {
				std::cout << "Could not initialise GLFW!" << std::endl;
				return;
			}
			glfwSetErrorCallback(GLFWErrorCallback);
		}

		{
			m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
			++s_GLFWWindowCount;
		}

		m_Context = GraphicsContext::Create(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);

		auto vidMode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_Window, (vidMode->width - props.Width) / 2, (vidMode->height - props.Height) / 2);

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window) {
			Application::Get().RequestClose();
		});
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(m_Window);
		--s_GLFWWindowCount;

		if (s_GLFWWindowCount == 0) {
			glfwTerminate();
		}
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
		m_Data.VSync = enabled;
	}

}