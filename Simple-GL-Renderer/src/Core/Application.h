#pragma once
#include <memory>
#include <array>
#include <GL/glew.h>

#include "Util/Singleton.h"
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

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

	// TODO: Make UIRenderer and it's panels accessible from scene
	UIRenderer m_UIRenderer;

	// TEMPORARY
	std::unique_ptr<VertexShader>   m_VertexShader;
	std::unique_ptr<FragmentShader> m_FragmentShader;

	std::unique_ptr<ShaderProgram> m_Program;

	std::unique_ptr<Mesh> m_QuadMesh;

	std::vector<Vertex> m_Vertices =
	{
		{ glm::vec3(-1.0,  1.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f) }, // TOP LEFT
		{ glm::vec3( 1.0,  1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) }, // TOP RIGHT
		{ glm::vec3( 1.0, -1.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f) }, // BOTTOM RIGHT
		{ glm::vec3(-1.0, -1.0f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f) }  // BOTTOM LEFT
	};

	std::vector<GLushort> m_Indices =
	{
		0, 1, 3,
		1, 2, 3
	};
};