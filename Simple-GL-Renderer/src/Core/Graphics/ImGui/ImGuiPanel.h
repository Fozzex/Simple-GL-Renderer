#pragma once
#include <GL/glew.h>
#include <imgui.h>

#include "Core/Graphics/UIPanel.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/ImGui/imgui_impl_opengl3.h"
#include "Core/Input/Keyboard.h"

class ImGuiPanel : public UIPanel
{
public:

	ImGuiPanel();

	void Update() override;
	bool OnEvent(Event& e) override;

	bool IsActive() override;
	inline void SetActive(bool active) override { m_ShowDemoWindow = active; }

private:

	float m_LastFrameTime = 0.0f;

	bool m_ShowDemoWindow = true;

};