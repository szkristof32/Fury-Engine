#include "Buffers.h"

#include "Platform/OpenGL/OpenGLBuffer.h"
#include "PlatformSelection.h"

namespace FuryEngine {

	Ref<VertexBuffer> VertexBuffer::Create(u32 size) {
#ifdef FURY_USE_OPENGL
		return CreateRef<OpenGLVertexBuffer>(size);
#else
#error Fury Engine only supports OpenGL!
		return nullptr;
#endif
	}

	Ref<VertexBuffer> VertexBuffer::Create(float* vertices, u32 size) {
#ifdef FURY_USE_OPENGL
		return CreateRef<OpenGLVertexBuffer>(vertices, size);
#else
#error Fury Engine only supports OpenGL!
		return nullptr;
#endif
	}

	Ref<IndexBuffer> IndexBuffer::Create(u32* indices, u32 size) {
#ifdef FURY_USE_OPENGL
		return CreateRef<OpenGLIndexBuffer>(indices, size);
#else
#error Fury Engine only supports OpenGL!
		return nullptr;
#endif
	}

}