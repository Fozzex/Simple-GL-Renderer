#pragma once
#include <memory>
#include <array>
#include <GL/glew.h>

#include "Util/Singleton.h"
#include "Core/Window/Window.h"
#include "Core/Graphics/SceneManager.h"
#include "Core.h"

#include "Core/Graphics/VertexShader.h"
#include "Core/Graphics/FragmentShader.h"
#include "Core/Graphics/ShaderProgram.h"

#include "Core/Graphics/Mesh.h"

class Application : public Singleton
{
	static Application* s_Instance;
public:

	Application(const std::string& title, int width, int height);
	virtual ~Application();

	void RegisterScene(Scene* scene);

	void Run();
	static Application* Get() { return s_Instance; }

private:

	std::unique_ptr<Window> m_Window;
	SceneManager m_SceneManager;

	// TEMPORARY
	std::unique_ptr<VertexShader>   m_VertexShader;
	std::unique_ptr<FragmentShader> m_FragmentShader;

	std::unique_ptr<ShaderProgram> m_Program;

	std::unique_ptr<Mesh> m_QuadMesh;

	std::vector<Vertex> m_Vertices =
	{
		{ glm::vec3(-0.5,  0.5f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f) }, // TOP LEFT
		{ glm::vec3( 0.5,  0.5f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f) }, // TOP RIGHT
		{ glm::vec3( 0.5, -0.5f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f) }, // BOTTOM RIGHT
		{ glm::vec3(-0.5, -0.5f, 0.0f), glm::vec3(1.0f, 1.0f, 1.0f) }  // BOTTOM LEFT
	};

	std::vector<GLushort> m_Indices =
	{
		0, 1, 3,
		1, 2, 3
	};
};