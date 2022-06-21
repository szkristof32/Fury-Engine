#pragma once

#include <memory>

#include "FuryEngine/Core/Core.h"
#include "FuryEngine/Rendering/VertexArray.h"

namespace FuryEngine {

	class UiManager {
		friend class Panel;
	public:
		static void Init();
		static void Update();
		
		static void SetActivePanel(Ref<Panel> panel) { s_ActivePanel = panel; }

	private:
		static Ref<Panel> s_ActivePanel;
	};

	class FURY_API UiComponent {
	public:
		virtual ~UiComponent() = default;

		virtual void Update() = 0;
		virtual void Render() = 0;

		virtual void SetX(u32 x) = 0;
		virtual void SetY(u32 y) = 0;
		virtual void SetWidth(u32 width) = 0;
		virtual void SetHeight(u32 height) = 0;
		virtual void SetPosition(u32 x, u32 y) = 0;
		virtual void SetSize(u32 width, u32 height) = 0;
		virtual void SetBounds(u32 x, u32 y, u32 width, u32 height) = 0;

		virtual u32 GetX() = 0;
		virtual u32 GetY() = 0;
		virtual u32 GetWidth() = 0;
		virtual u32 GetHeight() = 0;
	};

	class FURY_API Panel : public UiComponent {
	public:
		virtual void Update() override;
		virtual void Render() override;

		virtual void SetX(u32 x) override { m_X = x; }
		virtual void SetY(u32 y) override { m_Y = y; }
		virtual void SetWidth(u32 width) override { m_Width = width; }
		virtual void SetHeight(u32 height) override { m_Height = height; }
		virtual void SetPosition(u32 x, u32 y) override { m_X = x; m_Y = y; }
		virtual void SetSize(u32 width, u32 height) override { m_Width = width; m_Height = height; }
		virtual void SetBounds(u32 x, u32 y, u32 width, u32 height) override { m_X = x; m_Y = y; m_Width = width; m_Height = height; }

		virtual u32 GetX() override { return m_X; }
		virtual u32 GetY() override { return m_Y; }
		virtual u32 GetWidth() override { return m_Width; }
		virtual u32 GetHeight() override { return m_Height; }

	private:
		std::vector<UiComponent*> children;
		Scope<VertexArray> m_Vao;
		u32 m_X, m_Y;
		u32 m_Width, m_Height;
	};

}