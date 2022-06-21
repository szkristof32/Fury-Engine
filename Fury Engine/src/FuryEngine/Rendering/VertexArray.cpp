#include "VertexArray.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "PlatformSelection.h"

namespace FuryEngine {

	Ref<VertexArray> VertexArray::Create() {
#ifdef FURY_USE_OPENGL
		return CreateRef<OpenGLVertexArray>();
#else
#error Fury Engine only supports OpenGL!
		return nullptr;
#endif
	}

}