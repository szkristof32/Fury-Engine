#pragma once

#include "FuryEngine/Rendering/Buffers.h"

#include <glad/glad.h>

namespace FuryEngine {

	class FURY_API OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(u32 size);
		OpenGLVertexBuffer(float* vertices, u32 size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void SetData(Data data, u32 size) override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

	private:
		u32 m_Id;
		BufferLayout m_Layout;
	};

	class FURY_API OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(u32* indices, u32 count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual u32 GetCount() const { return m_Count; }

	private:
		u32 m_Id;
		u32 m_Count;
	};

}