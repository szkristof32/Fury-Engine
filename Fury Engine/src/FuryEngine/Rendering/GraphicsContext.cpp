#include "GraphicsContext.h"

#include "Platform/OpenGL/OpenGLContext.h"

namespace FuryEngine {

	Scope<GraphicsContext> GraphicsContext::Create(void* window) {
		//TODO: implement render api selection
		return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
	}

}