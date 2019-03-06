#pragma once
#include <memory>
#include <array>
#include <GL/glew.h>

#include "Core/Util/Singleton.h"
#include "Core/Util/Timer.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/SceneManager.h"
#include "Core/Graphics/UIRenderer.h"
#include "Core.h"

#include "Core/Graphics/OpenGL/VertexShader.h"
#include "Core/Graphics/OpenGL/FragmentShader.h"
#include "Core/Graphics/OpenGL/ShaderProgram.h"

#include "Core/Graphics/Mesh.h"

#include "Core/Graphics/ImGui/ImGuiPanel.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	void RegisterScene(Scene* scene);
	void RegisterUIPanel(UIPanel* panel);
	
	void OnEvent(Event& e);

	inline ShaderProgram* GetProgram() const { return m_Program.get(); }

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

	UIRenderer m_UIRenderer;
	Timer m_Timer;

	std::unique_ptr<VertexShader>   m_VertexShader;
	std::unique_ptr<FragmentShader> m_FragmentShader;

	std::unique_ptr<ShaderProgram> m_Program;

};